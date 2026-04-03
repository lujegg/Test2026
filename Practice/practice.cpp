#include "practice.h"
#include <iostream>

using namespace std;
class Student
{
    public:
    void printarray(double arr[], int size) {
        cout << "Grades: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    private:
};
int main() 
{
    const int n = 5;
    static double grades[n] = {85.5, 90.0, 78.3, 92.0, 88.6};
    printarray(grades, n);
    return 0;
}