This project was made under the assumption that you wanted an "array based circular queue". I wasn't sure what that meant, so I googled it and got my answer.
I've defined 7 variables to use, those being max, first, last, count, x, work, and item. These 7 variables define the beginning and ending points for this circular queue, as well as various other information. work defines whether the while function continues to run, and x determines which function to use based off your input. 
Queue.h is my header file, which defines the queue class as well as the public API. Queue.cpp is where I have the functions take place, and after inputting a command in the terminal it tells the Queue which function to use within the Queue.cpp file. The main.cpp is the file that users are looking off of, and this contains the menu as well as knowing which function to send the user to depending on their want. Lastly, I have the tests folder, which contains my best try of putting the queue testing into vs code. 
Build/Run commands: g++ Queue.cpp main.cpp -o Queue
./Queue
1. Enqueue
2. Dequeue
3. Peek
4. Size
5. Clear
6. Exit
Enter the file using cd MiniProject4_Queue, and then compile the code using the first command on line 4. Then enter ./Queue, and pick which menu option you'd like by entering the number corresponding to the option. Do as many queue and dequeues as you'd like, before exiting by pressing 6 in the menu.

In the tests file, I wasn't quite sure of how to show the wrap around text so I'm writing it here. I queued up to the max(3), before dequeuing all of them, and then queuing 1 value and checking the size. This way it demonstrated that the array could only hold 3 numbers, and that it wasn't ever deleting any slots from the array, instead circling through them to fill previous slots. In the next test for mixed operations, I set the max a bit higher.
This assignment took a long time, but the biggest issue I ran into was probably getting used to OOP. This is the first assignment we've had after briefly learning it in class, and the syntax in the header file often times would mess up the entire program. I also struggled a lot with getting the peek to work because I wasn't sure how to create a circular queue, and was just throwing values around for first and last.