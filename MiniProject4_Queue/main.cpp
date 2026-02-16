#include <iostream>
#include "Queue.h"
// t
using namespace std;
int main() {
Queue queue;
bool work = 1;
int x = 0;
double item = 0;
while (work == 1) {
    cout<<"------------------------------"<<endl;
    cout<< "Enter number corresponding to option"<<endl;
    cout<< "1. Enqueue"<<endl;
    cout<< "2. Dequeue"<<endl;
    cout<< "3. Peek"<<endl;
    cout<< "4. Size"<<endl;
    cout<< "5. Clear"<<endl;
    cout<< "6. Exit"<<endl;
    cin>>x;
    if (x == 1) {
        cout<<"Queue item"<<endl;
        cin>>item;
        cout<<"Queued "<<item<<endl;
        queue.enqueue(item);
    }
    if (x == 2) {
        cout<<"Dequeued "<<queue.dequeue()<<endl;
    }
    if (x == 3) {
        cout<<queue.peek()<<endl;
    }
    if (x == 4) {
        cout<<queue.size()<<endl;
    }
    if (x == 5) {
        queue.clear();
    }
    if (x == 6) {
        work = 0;
    }
}
}