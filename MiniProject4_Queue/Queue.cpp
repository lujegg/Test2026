#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() {
first = 0;
last = -1;
count = 0;
}
void Queue::enqueue(double item) {
if (isFull() == true) {
    cout <<"Full Queue"<< endl;
}
else {
    last = (last + 1) % max;
    array[last] = item;
    count++;
}
}
//=================
double Queue::dequeue() {
if (isEmpty() == true) {
    cout << "Empty Queue" << endl;
    return -1;
}
else {
    double item = array[first];
    first = (first + 1) % max;
    count--;
    return item;
}
}
//=================
double Queue::peek() {
if (isEmpty() == true) {
        cout << "Empty Queue" << endl;
        return -1;
    }
else {
return array[first];
}
}
//=================
bool Queue::isEmpty() { 
if (count == 0) {
    return true;
}
else {
    return false;
}
}
//=================
bool Queue::isFull() {
if (count == max) {
    return true;
}
else {
    return false;
}
}
//=================
int Queue::size() {
return count;
}
//=================
void Queue::clear() {
    first = 0;
    last = -1;
    count = 0;
}