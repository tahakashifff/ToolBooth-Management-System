README.md
Toll Booth Management System 🚧

A C++ Toll Booth Management System that demonstrates important Object-Oriented Programming (OOP) concepts, dynamic memory management, constructors/destructors, copy constructors, operator overloading, static members, friend functions, and dynamic arrays.

The program allows users to manage multiple toll booths, record paying and non-paying vehicles, maintain transaction history, and generate a final report for each booth.

Features
Create multiple toll booth objects dynamically.
Assign a custom location to each toll booth.
Record paying cars with a fixed toll of $50.
Record non-paying cars.
Maintain the last few vehicle transactions using a dynamic history array.
Display:
Total number of cars
Number of paying cars
Number of non-paying cars
Total collected amount
Transaction history
Audit booth information using a friend function.
Track the number of TollBooth objects using a static member.
Use a copy constructor for deep copying dynamic memory.
Use an overloaded + operator to combine statistics from two toll booths.
Use keyboard controls for quick vehicle entry.
Dynamically allocate and deallocate booth objects.
OOP Concepts Demonstrated
1. Encapsulation

The class keeps its data members private and provides public member functions to access and modify the required information.

private:
    char* location;
    double* history;
    int capacity;
    int used;

2. Constructors

The program contains:

Default constructor
Parameterized constructor
Copy constructor
TollBooth();
TollBooth(const char* loc, int cap = 10);
TollBooth(const TollBooth& other);

3. Destructor

The destructor releases dynamically allocated memory:

TollBooth::~TollBooth()
{
    delete[] location;
    delete[] history;
}

4. Dynamic Memory Allocation

The program dynamically allocates memory for:

Booth locations
Transaction history
The array of toll booth objects
TollBooth* booths = new TollBooth[n];

5. Deep Copy

Because TollBooth uses dynamic memory, a custom copy constructor is implemented to prevent multiple objects from sharing the same memory.

TollBooth::TollBooth(const TollBooth& other)

6. Static Data Member

boothCount keeps track of the number of TollBooth objects created.

static int boothCount;


It can be accessed through:

TollBooth::getBoothCount();

7. Friend Function

The auditBooth() function is declared as a friend so that it can directly access private members of TollBooth.

friend void auditBooth(
    const TollBooth& b,
    unsigned int& cars,
    double& amount
);

8. Operator Overloading

The + operator combines the statistics of two toll booths.

TollBooth operator+(const TollBooth& other);


For example, it combines:

Total cars
Paying cars
Non-paying cars
Total amount
9. Dynamic Transaction History

Each booth maintains a history of transactions. A paying car stores 50, while a non-paying car stores 0.

When the history becomes full, the oldest transaction is removed and the newest transaction is added.

How the Program Works

When the program starts, the user is asked to enter the number of toll booths.

Enter number of Toll Booths: 3


The user then provides a location for each booth:

Enter location for Booth 1: Islamabad
Enter location for Booth 2: Lahore
Enter location for Booth 3: Rawalpindi


After that, the user selects a booth:

Enter booth number (1-3):


Inside the selected booth, the following controls are available:

Key	Action
Y	Record a paying car
N	Record a non-paying car
BACKSPACE	Return to booth selection
ESC	Exit the program

A paying car increases the total amount by $50.

A non-paying car increases the vehicle count but does not increase the collected amount.

Example

A booth receives the following vehicles:

Y
Y
N
Y
N


The resulting statistics would be approximately:

Total cars: 5
Paid: 3
Not Paid: 2
Total amount: $150.00

History (5): $50 $50 $0 $50 $0

Final Report

When the user presses ESC, the program generates a report for every booth.

Example:

================================================
        BOOTH 1 - Islamabad
================================================
Total cars: 5 | Paid: 3 | Not Paid: 2
Total amount: $150.00
History (5): $50 $50 $0 $50 $0
Audit: 5 cars, $150.00
================================================


At the end, the program also displays the number of TollBooth objects created:

Total Booth Objects Created: 4


The number may be higher than the number of booths entered because the overloaded + operator creates a temporary TollBooth object when used.

Requirements

To compile and run this project, you need:

C++ compiler
Windows environment recommended
Support for <conio.h> and _getch()
Standard C++ libraries

The program uses:

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstring>


Note: <conio.h> and _getch() are commonly available with Microsoft Visual C++/Visual Studio but are not part of the standard C++ library. Therefore, the program may require modification when compiling with some Linux/macOS compilers.

Compilation
Visual Studio

Create a C++ Console Application and add the source code to the project.

Build and run the project using:

Ctrl + F5

MinGW / g++

On a Windows environment with a compatible MinGW compiler, you can try:

g++ main.cpp -o TollBooth


Then run:

TollBooth.exe

Project Structure
TollBooth-Management-System/
│
├── main.cpp
└── README.md

Class Overview

The main class in the project is:

class TollBooth


Important member functions include:

void payingCar();
void nopayCar();
void display(...);
void setLocation(const char* loc);
const char* getLocation() const;
int getHistoryCount() const;
double getHistory(int i) const;
static int getBoothCount();
TollBooth operator+(const TollBooth& other);

Memory Management

The program uses dynamic memory and therefore explicitly releases allocated resources.

Location:

location = new char[strlen(loc) + 1];


History:

history = new double[capacity];


Booth array:

TollBooth* booths = new TollBooth[n];


The booth array is released at the end:

delete[] booths;


The destructor releases each booth's internal dynamic memory:

delete[] location;
delete[] history;

Learning Objectives

This project is useful for practicing:

Classes and objects
Constructors and destructors
Copy constructors
Encapsulation
Dynamic memory allocation
Deep copying
Static class members
Friend functions
Operator overloading
Dynamic arrays
Input validation
Character-based keyboard input
Basic memory management in C++
Future Improvements

Possible improvements include:

Add a configurable toll price instead of a fixed $50.
Store date/time for every transaction.
Save transaction history to a file.
Load previous booth data when the program starts.
Add a graphical user interface.
Replace raw pointers with std::string and std::vector.
Add an assignment operator (operator=) to follow the Rule of Three completely.
Improve portability by replacing _getch() with a cross-platform input method.
Add statistics such as average toll collected per paying vehicle.
Allow users to reset individual booth statistics.
Add a search function for booth locations.
Author

Developed as a C++ Object-Oriented Programming project demonstrating practical use of classes, dynamic memory, constructors, destructors, friend functions, static members, and operator overloading.

License

This project is available for educational and learning purposes.
