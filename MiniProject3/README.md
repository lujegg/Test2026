In this program, copilot mainly served to help create the input and output files as we hadn't learned how to do that yet. Through using fstream, it took in values from a .txt file and outputted values into a seperate .txt file. I worked on the mean filter, which set the main value as x,y, and then used i and j to increment across each value in the 3x3 column and sum them. I also worked to verify the zero padding through verifying that there were indeed a hidden row of zeros surrounding the numbers, so that way the summing always had something to add. A bug that copilot had missed was that it skipped over line 78, which was outputfile << endl;. This caused the output to be a long string of numbers rather than a row and column system. 
Design notes: I spent an abnormally long amount of time trying to understand how the 2D arrays worked, and how they worked in combination with each other. 
vector<vector<int>> newImage(rows, vector<int>(cols));
This took a very long time to get due to how I wasn't understand vector<vector<int>> is actually a type, and I instead had tried treating it as an actual variable/array. 

Run tests using the following command lines:
cd MiniProject3
g++ main.cpp -o test
./test
Tests/testin.txt
Tests/testout.txt
1

TERMINAL OUTPUT SNIPPET:
doors@MSI:~/eece2140/MiniProject3$ ./test
Enter input file path: 
Tests/testin.txt
Enter output file path: 
Tests/testout.txt
Enter number of iterations: 
1
SUCCESS: Loading 4 rows and 5 columns.