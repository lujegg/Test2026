#include <iostream>
#include <string>
using namespace std;
//==========================================================================
// Class Declaration -- Student
class Student
{
private:
int idNum;
string lastName;
double gpa;
public:
// Constructor
Student(int id, string name, double studentGpa)
{
idNum = id;
lastName = name;
gpa = studentGpa;
}
// Function Prototype
void displayStudentData();
};
//==========================================================================
// Function Implementation
void Student::displayStudentData()
{
cout << "Student # " << idNum
<< " Name: " << lastName << endl;
cout << "GPA: " << gpa << endl;
}
//==========================================================================
//Class Declaration -- Course
class Course
{
private:
string department;
int courseNum;
int seats;
int maxSeats;
public:
Course() : department(""), courseNum(0), seats(0), maxSeats(0) {}
Course(const string& dept, int num, int maxS)
: department(dept), courseNum(num), seats(0), maxSeats(maxS) {}
//================================================================
void setDepartment(const string& dept) { department = dept; }
void setCourseNum(int num) { courseNum = num; }
void setMaxSeats(int maxS) { maxSeats = maxS; }
void setSeats(int s) { seats = s; }
void addSeat() { if (seats < maxSeats) seats++; }
void removeSeat() { if (seats > 0) seats--; }
//================================================================
string getDepartment() const { return department; }
int getCourseNum() const { return courseNum; }
int getSeats() const { return seats; }
int getMaxSeats() const { return maxSeats; }
bool hasAvailableSeats() const
{
return seats < maxSeats;
}
void display() const
{
cout << "Course: " << department << " " << courseNum
<< " Seats: " << seats << "/" << maxSeats << endl;
}
};
//Class Declaration -- Registration
class Registration
{
private:
Student& student;
Course& course;
bool isRegistered;
static int regCount;
public:
// Constructor
Registration(Student& s, Course& c)
: student(s), course(c), isRegistered(false) {}
// Register student
bool registerStudent()
{
if (isRegistered)
{
cout << "Student already registered.\n";
return false;
}
if (!course.hasAvailableSeats())
{
cout << "Cannot register: Course is full.\n";
return false;
}
course.addSeat();
isRegistered = true;
regCount++;
cout << "Registration successful.\n";
return true;
}
// Drop student
bool dropStudent()
{
if (!isRegistered)
{
cout << "Student is not registered.\n";
return false;
}
course.removeSeat();
isRegistered = false;
regCount--;
cout << "Dropped successfully.\n";
return true;
}
// registration info
void display() const {
cout << "Total Active Registrations: " << Registration::getTotalRegs() << endl;
cout << "Status: "
<< (isRegistered ? "Registered" : "Not Registered")
<< endl;
}
// Static function to get total registrations
static int getTotalRegs()
{
return regCount;
}
};
// Static variable definition (must be outside class)
int Registration::regCount = 0;

//==========================================================================
// Main Function
int main()
{
// Test 1 & 2
Student s1(1001, "Smith", 3.85);
Course c1("EECE", 2140, 30);
c1.setSeats(29);
Registration reg1(s1, c1);
reg1.registerStudent();
reg1.display();
cout << "-----------------------------\n";
reg1.registerStudent();
cout << "Total Active Registrations: " << Registration::getTotalRegs() << endl;
cout << "-----------------------------\n";

// Test 3
Student s2(1002, "Johnson", 3.40);
Student s3(1003, "Williams", 3.10);
Course c2("EECE", 5626, 1);
Registration reg2(s2, c2);
reg2.registerStudent();
Registration reg3(s3, c2);
reg3.registerStudent();
cout << "Total Active Registrations: " << Registration::getTotalRegs() << endl;
cout << "-----------------------------\n";

// Test 4
Student s4(1004, "Brown", 2.70);
Course c3("EECE", 5626, 25);
c3.setSeats(10);
Registration reg4(s4, c3);
reg4.registerStudent();
reg4.dropStudent();
reg4.display();
cout << "-----------------------------\n";

// Test 5
Student s5(1005, "Davis", 2.95);
Course c4("EECE", 2160, 20);
c4.setSeats(5);
Registration reg5(s5, c4);
reg5.dropStudent();
cout << "Total Active Registrations: " << Registration::getTotalRegs() << endl;
return 0;
}