Jack Lu 002379813
cd Assignment06_Project1-8_Lu
Employee:
g++ main.cpp Employee.cpp -o Employee
Square:
No expected output/main file required
Cat:
No expected output/main file required
TV:
g++ mainTV.cpp TV.cpp -o TV
./TV

Employee.cpp is my .cpp file for the Employee problem, and possesses all the functions that can be requested by main.cpp. The main.cpp is where
functions are requested and values are given, and the Employee.h is the header file where the private values, constructors, and functions are
declared. The class is also declared in the header file. Employee.h has functions such as getAge and SetAge, which are implemented by the
Employee.cpp file, and that is requested by the main.cpp file. There were thresholds implemented in the Employee.cpp file so that Employees
could not have an age of 0 or negative salary. I went and did both the bonus questions, for implementing a display function,
as well as demonstrated constructor overloading by creating a constructor for several situations. I also kept the previous work from before 
creating the display function within the main.cpp file as comments for validation and general testing purposes.
Square.cpp was my .cpp file for the Square program. Similar to both TV and Cat, the corrected syntax and explanations to the tasks are located 
within either their .h or .cpp file. Additionally, as only a constructor that took side as a parameter was asked, I only made 1 constructor. 
When creating my additional variable to use for setSide, I decided on s as I couldn't think of anything else as relevant as the first letter.
Within the header file, I declared my functions and private and public values.
Cat.cpp is my .cpp file for the Cat problem, and implements the various commands that are requested such as meow and displayInfo. Cat.h is the
header file, and declares private values, public functions and constructors. There was also validation so that the cat could not have 0 age and 
such. I assumed that because there was no main file for Cat shown in the file structure, nor was there a specified output, that the Cat program
did not require a main file. 
TV.h is the header file for the TV problem, and declares the functions used in the TV.cpp file. Due to how this program only had 1 parameter,
I only had to create 2 constructors, one for when the station was provided, and one for when it wasn't, in which the value was set to 1. Upon
reaching the threshold of 999 using channelUp in the TV.cpp file, it would reset back to 1. The opposite was also true, where using channelDown
when the value is 1 set it equal to 999. This way the station remains between 1 and 999.

One issue in regards to the constructors were that I created them in a decreasing fashion, as seen in the employee constructor. However, while
takes into account several of the situations, it doesn't take into account cases such as when age isnt defined, but years and salary is. 
