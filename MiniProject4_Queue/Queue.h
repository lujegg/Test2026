#ifndef QUEUE_H

#define QUEUE_H

class Queue {
public:
Queue();
static const int max = 10; 
double array[max];
int first;
int last;
int count;
/*this is enqueue, which has double item as it needs to receive the value from
outside, and this works by first checking if the queue is full, and if not
it adds the item to the circular queue, after which it adds the input item
to the back of the queue, and finally increases the count by one. it is void
as it doesnt require a returned value, instead just altering with references.
*/
void enqueue(double item);
/* this is dequeue, basically the opposite of enqueue, it checks if the queue
is empty and if not it removes the value at the front and increases front by 1,
decreases count by 1, and returning the front value, which is also assigned
to double item so as to minimize variables. this is double to return the 
value of the dequeued item.
*/
double dequeue();
/* this is peek, which just checks if the queue is empty and if not it returns
the first value of the array. it is double to accomodate for this.
*/
double peek();
/* this is isempty which just checks if the count is 0, if it is then it returns
true when prompted by functions like dequeue and peek. it is a bool as it 
only needs to return true or false.
*/
bool isEmpty();
/* similar to isempty, this checks if the count is equal to max, and if it is
then it returns true when prompted by enqueue, and is bool for the same reason as peek.
*/
bool isFull();
/* this is size, which just returns the count of the queue, and is int as it 
needs to return a number.
*/
int size();
/* this is clear, which just sets all values back to the initial values,
so first goes to 0, last goes to -1, count goes to 0. it wasn't actually explicitly
mentioned in the menu section of the assignment so I didn't include it, but
I created the queue.cpp before the main.cpp so I'm just going to leave it here
to show I did do it. (On second thought, I'm going to include it in the menu.)
*/
void clear();
};
#endif // QUEUE_H
