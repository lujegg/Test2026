Run tests using the following command lines:
cd MiniProject3
g++ main.cpp -o test
./test
Tests/testin.txt
Tests/testout.txt
1
For the expected outcomes of the testin, this is the example file given in the assignment. The expected value for the top left value should be (10 + 10 + 10 + 200 + 0 + 0 + 0 + 0 + 0)/9, which 25.55, and the remainder gets truncated rather than rounded. We can see that in the testout.txt folder, this is the case and that the top right value has become 25. A better example of this is smallin.txt and smallout.txt, which has 9 as the middle value, so it does (9+9+9+9+9+9+9+9+9)/9, and that is equal to 9. This is verified by the smallout.txt. Both smallin.txt and borderin.txt verify that the zero padding is working, and shows that through how values in the corners, which are exposed to more zeroes, have lower values than values in the sides, and that those have lower values than values in the middle. Impulsein.txt stands to demonstrate how a single out of place integer affects the entire image, and that is shown through how it has the same value as the integer next to it after the iteration, as both of them are composed of 8 130s and 1 13. 