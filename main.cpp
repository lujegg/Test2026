#include <iostream>
#include <limits>
using namespace std;
 
// ══════════════════════════════════════════════════════════════════════════════
//  ArrayHandler class
// ══════════════════════════════════════════════════════════════════════════════
class ArrayHandler {
public:
    ArrayHandler() : size(100), filled(0) {}
 
    // Bulk-load the array from an external array of a given length.
    void setArray(int* val, int length) {
        filled = (length < size) ? length : size;
        for (int i = 0; i < filled; i++) {
            *(arr + i) = *(val + i);
        }
    }
 
    // Set a single element by index. Expands the filled region if needed.
    bool setElement(int index, int val) {
        if (index < 0 || index >= size) {
            cout << "  [ERROR] Index " << index
                 << " is out of bounds (capacity: " << size << ").\n";
            return false;
        }
        *(arr + index) = val;
        if (index >= filled) filled = index + 1;
        return true;
    }
 
    // Print every filled element, one per line with its index.
    void displayArray() {
        if (filled == 0) { cout << "  [INFO] Array is empty.\n"; return; }
        for (int i = 0; i < filled; i++) {
            cout << "  [" << i << "] " << *(arr + i) << "\n";
        }
    }
 
    // Read a single element by index into outVal.
    bool getElement(int index, int& outVal) {
        if (index < 0 || index >= filled) {
            cout << "  [ERROR] Index " << index
                 << " is out of filled range (filled: " << filled << ").\n";
            return false;
        }
        outVal = *(arr + index);
        return true;
    }
 
    // Reverse the filled portion in-place.
    void reverseArray() {
        if (filled <= 1) { cout << "  [INFO] Nothing to reverse.\n"; return; }
        for (int i = 0; i < filled / 2; i++) {
            int* front = arr + i;
            int* back  = arr + (filled - 1 - i);
            int  x     = *front;
            *front     = *back;
            *back      = x;
        }
    }
 
    // Clear the array (reset filled counter).
    void clearArray() { filled = 0; }
 
    int getFilled() const { return filled; }
    int getSize()   const { return size;   }
 
private:
    int arr[100];
    int size;
    int filled;
};
 
 
// ══════════════════════════════════════════════════════════════════════════════
//  Helper: safely read an integer, flushing bad input
// ══════════════════════════════════════════════════════════════════════════════
int readInt(const string& prompt) {
    int val;
    while (true) {
        cout << prompt;
        if (cin >> val) { return val; }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  [INPUT ERROR] Please enter a whole number.\n";
    }
}
 
 
// ══════════════════════════════════════════════════════════════════════════════
//  Automated validation suite
// ══════════════════════════════════════════════════════════════════════════════
void runValidation() {
    int passed = 0, failed = 0;
 
    auto check = [&](const string& name, bool condition) {
        if (condition) { cout << "  [PASS] " << name << "\n"; passed++; }
        else           { cout << "  [FAIL] " << name << "\n"; failed++; }
    };
 
    cout << "\n══════════ VALIDATION SUITE ══════════\n";
 
    // ── 1. setArray / displayArray ────────────────────────────────────────────
    cout << "\n[1] setArray + displayArray\n";
    {
        ArrayHandler h;
        int src[] = {10, 20, 30, 40, 50};
        h.setArray(src, 5);
        check("filled == 5 after setArray", h.getFilled() == 5);
 
        int v = 0;
        h.getElement(0, v); check("arr[0] == 10", v == 10);
        h.getElement(4, v); check("arr[4] == 50", v == 50);
    }
 
    // ── 2. reverseArray ───────────────────────────────────────────────────────
    cout << "\n[2] reverseArray (odd length)\n";
    {
        ArrayHandler h;
        int src[] = {1, 2, 3, 4, 5};
        h.setArray(src, 5);
        h.reverseArray();
        int v = 0;
        h.getElement(0, v); check("arr[0] == 5 after reverse", v == 5);
        h.getElement(2, v); check("arr[2] == 3 (middle unchanged)", v == 3);
        h.getElement(4, v); check("arr[4] == 1 after reverse", v == 1);
    }
 
    cout << "\n[3] reverseArray (even length)\n";
    {
        ArrayHandler h;
        int src[] = {7, 8, 9, 10};
        h.setArray(src, 4);
        h.reverseArray();
        int v = 0;
        h.getElement(0, v); check("arr[0] == 10", v == 10);
        h.getElement(3, v); check("arr[3] == 7",  v == 7);
    }
 
    // ── 3. setElement / getElement ────────────────────────────────────────────
    cout << "\n[4] setElement + getElement\n";
    {
        ArrayHandler h;
        bool ok = h.setElement(0, 42);
        check("setElement(0, 42) returns true", ok);
        int v = 0;
        h.getElement(0, v);
        check("getElement(0) == 42", v == 42);
 
        ok = h.setElement(99, 77);
        check("setElement(99, 77) within capacity", ok);
        check("filled == 100 after writing index 99", h.getFilled() == 100);
        h.getElement(99, v);
        check("getElement(99) == 77", v == 77);
    }
 
    // ── 4. Out-of-bounds protection ───────────────────────────────────────────
    cout << "\n[5] Bounds checking\n";
    {
        ArrayHandler h;
        bool bad = h.setElement(100, 1);  // exactly at capacity — invalid
        check("setElement(100) correctly rejected", !bad);
 
        bad = h.setElement(-1, 1);
        check("setElement(-1)  correctly rejected", !bad);
 
        int v = 0;
        bad = h.getElement(0, v);         // nothing filled yet
        check("getElement on empty array rejected", !bad);
    }
 
    // ── 5. Garbage-value / partial-fill guard ─────────────────────────────────
    cout << "\n[6] Garbage-value guard\n";
    {
        ArrayHandler h;
        int src[] = {1, 2, 3};
        h.setArray(src, 3);               // only 3 of 100 slots filled
        h.reverseArray();                 // must swap only those 3
        check("filled stays 3 after reverse", h.getFilled() == 3);
        int v = 0;
        h.getElement(0, v); check("arr[0] == 3 (no garbage at front)", v == 3);
        h.getElement(2, v); check("arr[2] == 1 (no garbage at back)",  v == 1);
    }
 
    // ── 6. Edge cases ─────────────────────────────────────────────────────────
    cout << "\n[7] Edge cases\n";
    {
        ArrayHandler h;
        h.reverseArray();                 // empty — should not crash
        check("reverseArray on empty array is safe", true);
 
        int one[] = {99};
        h.setArray(one, 1);
        h.reverseArray();                 // single element
        int v = 0;
        h.getElement(0, v);
        check("single-element reverse unchanged", v == 99);
 
        h.clearArray();
        check("clearArray resets filled to 0", h.getFilled() == 0);
    }
 
    // ── 7. Double reverse ─────────────────────────────────────────────────────
    cout << "\n[8] Double reverse == original\n";
    {
        ArrayHandler h;
        int src[] = {5, 10, 15, 20};
        h.setArray(src, 4);
        h.reverseArray();
        h.reverseArray();
        int v = 0;
        h.getElement(0, v); check("arr[0] == 5  after double-reverse", v == 5);
        h.getElement(3, v); check("arr[3] == 20 after double-reverse", v == 20);
    }
 
    // ── 8. setArray overwrites previous data ─────────────────────────────────
    cout << "\n[9] setArray overwrites previous contents\n";
    {
        ArrayHandler h;
        int a[] = {1, 2, 3, 4, 5};
        int b[] = {9, 8};
        h.setArray(a, 5);
        h.setArray(b, 2);
        check("filled == 2 after second setArray", h.getFilled() == 2);
        int v = 0;
        h.getElement(0, v); check("arr[0] == 9", v == 9);
        h.getElement(1, v); check("arr[1] == 8", v == 8);
    }
 
    // ── Summary ───────────────────────────────────────────────────────────────
    cout << "\n══════════ RESULTS: "
         << passed << " passed, " << failed << " failed ══════════\n";
}
 
 
// ══════════════════════════════════════════════════════════════════════════════
//  Interactive menu
// ══════════════════════════════════════════════════════════════════════════════
void printMenu() {
    cout << "\n╔══════════════════════════════════╗\n"
         << "║       ArrayHandler  Menu         ║\n"
         << "╠══════════════════════════════════╣\n"
         << "║  1. Load array (bulk input)      ║\n"
         << "║  2. Display array                ║\n"
         << "║  3. Reverse array                ║\n"
         << "║  4. Set single element           ║\n"
         << "║  5. Get single element           ║\n"
         << "║  6. Clear array                  ║\n"
         << "║  7. Run validation suite         ║\n"
         << "║  0. Quit                         ║\n"
         << "╚══════════════════════════════════╝\n"
         << "Choice: ";
}
 
int main() {
    ArrayHandler handler;
    int choice;
 
    cout << "ArrayHandler — Interactive Menu\n";
 
    do {
        printMenu();
        choice = readInt("");
 
        switch (choice) {
 
        case 1: {   // ── Bulk load ────────────────────────────────────────────
            int n = readInt("  How many values? ");
            if (n <= 0 || n > handler.getSize()) {
                cout << "  [ERROR] Enter a count between 1 and "
                     << handler.getSize() << ".\n";
                break;
            }
            int* buf = new int[n];
            for (int i = 0; i < n; i++) {
                buf[i] = readInt("  Value [" + to_string(i) + "]: ");
            }
            handler.setArray(buf, n);
            delete[] buf;
            cout << "  [OK] Array loaded with " << n << " value(s).\n";
            break;
        }
 
        case 2:     // ── Display ──────────────────────────────────────────────
            cout << "\n  --- Array contents ---\n";
            handler.displayArray();
            break;
 
        case 3:     // ── Reverse ──────────────────────────────────────────────
            handler.reverseArray();
            cout << "  [OK] Array reversed.\n";
            break;
 
        case 4: {   // ── Set single element ───────────────────────────────────
            int idx = readInt("  Index to set: ");
            int val = readInt("  New value:    ");
            if (handler.setElement(idx, val))
                cout << "  [OK] arr[" << idx << "] = " << val << "\n";
            break;
        }
 
        case 5: {   // ── Get single element ───────────────────────────────────
            int idx = readInt("  Index to get: ");
            int val = 0;
            if (handler.getElement(idx, val))
                cout << "  arr[" << idx << "] = " << val << "\n";
            break;
        }
 
        case 6:     // ── Clear ────────────────────────────────────────────────
            handler.clearArray();
            cout << "  [OK] Array cleared.\n";
            break;
 
        case 7:     // ── Validation ───────────────────────────────────────────
            runValidation();
            break;
 
        case 0:
            cout << "  Goodbye.\n";
            break;
 
        default:
            cout << "  [ERROR] Unknown option. Choose 0–7.\n";
        }
 
    } while (choice != 0);
 
    return 0;
}