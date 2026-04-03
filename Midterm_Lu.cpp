//Jack Lu
//EECE 2140 Section 3
#include <iostream>
#include <string>
using namespace std;

#ifndef GRADEBOOK_H
#define GRADEBOOK_H
class GradeBook {
    private:
    string courseName;
    int grades[100];
    int count;
    static int totalGradeBooks;
    public:
    GradeBook(string name) : courseName(name), count(0) {
        totalGradeBooks++;
}
    void addGrade(int  g) {
        if (count < 100 && g >= 0 && g <= 100) {
            this -> grades[count] = g;
            count++;
        } else  {
            cout << "error" << endl;
        }
    }
    double getAverage() const {
        if (count == 0) return 0.0;
        double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += *(grades+i);
    }
    return sum / count;
    }
    int getHighest() const {
        int high = *(grades+0);
        for (int i = 0; i < count; i++) {
            if (*(grades+i) > high) {
                high = *(grades+i);
            }
        }
        return high;
    }
    void display() const {
        cout << "Course: " << courseName << endl;
        cout << "Count: " << count << endl;
        cout << "Average: " << getAverage() << endl;
        cout << "Highest: " << getHighest() << endl;
    }
    static int getCount() {
        return totalGradeBooks;
    }
};
int GradeBook::totalGradeBooks = 0;
#endif // GRADEBOOK_H

int main() {
GradeBook gb1("EECE2140");
gb1.addGrade(100);
gb1.addGrade(90);
gb1.addGrade(80);
gb1.addGrade(70);
gb1.addGrade(60);
gb1.display();
GradeBook gb2("MATH2341");
gb2.addGrade(50);
gb2.addGrade(40);
gb2.addGrade(30);
gb2.addGrade(20);
gb2.addGrade(10);
gb2.display();
cout << GradeBook::getCount() << endl;
return 0;
}