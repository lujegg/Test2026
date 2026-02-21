#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <numeric>

using namespace std;
int main() {
string inputpath, outputpath;
int iterations;
cout<<"Enter input file path: "<<endl;
cin>>inputpath;
cout<<"Enter output file path: "<<endl;
cin>>outputpath;
cout<<"Enter number of iterations: "<<endl;
cin>>iterations;
// image loading
int rows=0,cols=0;
ifstream inputfile(inputpath);
if (!inputfile) {
    cout << "Error opening file: " << inputpath << endl;
    return 1;
}

inputfile >> rows >> cols;
cout << "SUCCESS: Loading " << rows << " rows and " << cols << " columns." << endl;
vector<vector<int>> image(rows, vector<int>(cols));
for (int x = 0; x < rows; x++) {    
    for (int y = 0; y < cols; y++) {
        inputfile >> image[x][y];
    }
}
inputfile.close();
// zero padding border
for (int k = 0; k < iterations; k++) {
vector<vector<int>> padded(rows + 2, vector<int>(cols + 2, 0));
for (int x = 0; x < rows; x++) {
    for (int y = 0; y < cols; y++) {
        padded[x + 1][y + 1] = image[x][y];
    }
}
vector<vector<int>> newImage(rows, vector<int>(cols));

// mean filter
for (int x = 0; x < rows; x++) {
    for (int y = 0; y < cols; y++) {
        int sum = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                sum += padded[x + 1 + i][y + 1 + j];
            }
        }
        //clamp 0 to 255
        int avg = sum / 9;
        if (avg > 255) {
            avg = 255;
        }
        if (avg < 0) {
            avg = 0;
        }
        newImage[x][y] = avg;
        }
    }
image = newImage;
}
//output
ofstream outputfile(outputpath);
if (!outputfile) {
    cout << "Error opening file: " << outputpath << endl;
    return 1;
}
outputfile << rows << " " << cols << endl;
for (int x = 0; x < rows; x++) {
    for (int y = 0; y < cols; y++) {
        outputfile << image[x][y] << (y == cols - 1 ? "" : " ");
    }
outputfile << endl;
}
outputfile.close();
return 0;
}
