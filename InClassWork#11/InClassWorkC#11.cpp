#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int id;
    string name;
    ListNode* next;
};

class NodeList {
private:

public:
    ListNode* head;
    int count;
    NodeList() : head(nullptr), count(0) {}

    ~NodeList() {
        //ListNode* current = head;
        //while (current != nullptr) {
        //    ListNode* next = current->next;
        //    delete current;
        //    current = next;
        //}
        head = nullptr; 
    }


    NodeList(const NodeList& other) : head(nullptr), count(0) {
        if (other.head == nullptr) return;

        ListNode* otherCurr = other.head;
        ListNode* thisLast = nullptr;

        while (otherCurr != nullptr) {
            ListNode* newNode = new ListNode{otherCurr->id, otherCurr->name, nullptr};
            if (head == nullptr) head = newNode; 
            else thisLast->next = newNode; 
            
            thisLast = newNode;
            otherCurr = otherCurr->next;
            count++;
        }
    }

    NodeList& operator=(const NodeList& other) {
        if (this == &other) return *this;

        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        count = 0;

        ListNode* otherCurr = other.head;
        ListNode* thisLast = nullptr;
        while (otherCurr != nullptr) {
            ListNode* newNode = new ListNode{otherCurr->id, otherCurr->name, nullptr};
            if (head == nullptr) head = newNode;
            else thisLast->next = newNode;
            
            thisLast = newNode;
            otherCurr = otherCurr->next;
            count++;
        }
        return *this;
    }

    void addNode(int id, string name) {
        ListNode* n = new ListNode{id, name, head};
        head = n;
        count++;
    }

    void removeNode(int id) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr && curr->id != id) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr) return;
        if (prev) prev->next = curr->next;
        else head = curr->next;
        delete curr;
        count--;
    }

    void display() const {
        ListNode* curr = head;
        while (curr) {
            cout << "[" << curr->id << ": " << curr->name << "] -> ";
            curr = curr->next;
        }
        cout << "null" << endl;
    }
};

int main() {
    NodeList list;
    list.addNode(1, "Firewall");
    list.addNode(2, "Switch");
    list.addNode(3, "Router");
    list.display();

    
    //ListNode* stolen = list.head;
    //list.removeNode(list.head->id);
    //delete stolen;

    //ListNode* ptr = list.head;
    //list.removeNode(ptr->id);
    //cout << ptr->name << endl;  

    return 0;
}