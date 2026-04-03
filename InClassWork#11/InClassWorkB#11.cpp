
#include <iostream>
#include <memory>
#include <string>
using namespace std;

struct SmartListNode {
    int id;
    string name;
    unique_ptr<SmartListNode> next;

    SmartListNode(int i, string n, unique_ptr<SmartListNode> nx)
        : id(i), name(n), next(move(nx)) {}
};

class SmartNodeList {
private:
    unique_ptr<SmartListNode> head;
    int count;

public:
    SmartNodeList() : head(nullptr), count(0) {}

    void addNode(int id, string name) {
        head = make_unique<SmartListNode>(id, name, move(head));
        count++;
    }

    void removeNode(int id) {
        if (!head) return;
        if (head->id == id) {
            head = move(head->next);
            count--;
            return;
        }
        SmartListNode* prev = head.get();
        while (prev->next && prev->next->id != id)
            prev = prev->next.get();
        if (prev->next) {
            prev->next = move(prev->next->next);
            count--;
        }
    }

    void display() const {
        SmartListNode* curr = head.get();
        while (curr) {
            cout << "[" << curr->id << ": "
                 << curr->name << "] -> ";
            curr = curr->next.get();
        }
        cout << "null" << endl;
    }
};

int main() {
    SmartNodeList list;
    list.addNode(1, "Firewall");
    list.addNode(2, "Switch");
    list.addNode(3, "Router");

    cout << "Initial:       "; list.display();

    list.removeNode(2);
    cout << "Remove mid(2): "; list.display();

    list.removeNode(3);
    cout << "Remove head(3):"; list.display();

    list.removeNode(1);
    cout << "Remove tail(1):"; list.display();

    list.removeNode(99);
    cout << "Remove missing:"; list.display();

    return 0;
}