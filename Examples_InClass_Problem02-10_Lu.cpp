//

//Problem 2
#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;
    
    cout << "You entered: " << age << endl;
    return 0;
}

//Problem 3
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    double b = 3.5;

    double result = (double)a / b; 

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "Result of a / b " << result << endl;
    
    return 0;
}

//Problem 4
#include <iostream>
using namespace std;

int main() {
    int x = 8;
    int y = 3;

    cout << "x + y = " << x + y << endl;
    cout << "x - y = " << x - y << endl;
    cout << "x * y = " << x * y << endl;
    cout << "x / y = " << x / y << endl;
    cout << "x % y = " << x % y << endl;

    return 0;
}

//Problem 5
#include <iostream>
using namespace std;

int main() {
    int day = 3;
    if (temp > 25)
        cout << "It's hot outside!" << endl;
    else
        cout << "It's cool outside." << endl;

    return 0;
}

//Problem 6
#include <iostream>
using namespace std;

int main() {
    int day = 3;

    switch(day) {
        case 1: cout << "Monday"; break;
        case 2: cout << "Tuesday"; break;
        case 3: cout << "Wednesday"; break;
        default: cout << "Invalid day"; break;
    }
    
    return 0;
}

//Problem 7
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 5; i++) {
        cout << "Count: " << i << endl;
    }
    return 0;
}

//Problem 8
#include <iostream>
using namespace std;

void greet()
{
    cout << "Hello from a function!" << endl;
}

int main()
{
    greet();
    return 0;
}

//Problem 9
#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int result = add(4, 6);
    cout << "Sum = " << result << endl
    return 0;
}

//Problem 10
#include <iostream>
using namespace std;

double area(double width, double height)
{
    return width * height;
}

int main()
{
    double w, h;
    cout << "Enter width: ";
    cin >> w;
    cout << "Enter height: ";
    cin >> h;
    
    cout << "Area = " << area(w, h) << endl;
    return 0;
}