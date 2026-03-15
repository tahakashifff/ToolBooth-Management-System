#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;

class TollBooth {

private:
    char* location;  // dynamic string for booth location
    double* history;  // stores last few transaction amounts
    int capacity;  // max history size(in this program it is set to 10)
    int used;  // how many history slots are currently used

    unsigned int totalCar;
    unsigned int paidCar;
    unsigned int nonPayingCar;
    double totalAmount;
    static int boothCount;  // keeps track of how many booth objects created

public:
    TollBooth();
    TollBooth(const char* loc, int cap = 10);
    TollBooth(const TollBooth& other);  // Copy Constructor
    ~TollBooth();  // Destructor for dynamic memory 
    void payingCar();
    void nopayCar();
    void display(unsigned int& cars, unsigned int& paidCar, unsigned int& nonPayingcar, double& amount)const;
    void setLocation(const char* loc);
    const char* getLocation()const;
    int getHistoryCount()const;
    double getHistory(int i)const;
    static int getBoothCount();
    TollBooth operator+(const TollBooth& other);

    friend void auditBooth(const TollBooth& b, unsigned int& cars, double& amount);

};

// Static variable shared by all objects of the class.
// It keeps track of how many TollBooth objects have been created.
int TollBooth::boothCount = 0;

// Default Constructor
TollBooth::TollBooth()
{
    location = NULL;
    setLocation("Unknown");
    capacity = 10;
    history = new double[capacity];
    used = 0;
    totalCar = 0;
    totalAmount = 0;
    paidCar = 0;
    nonPayingCar = 0;
    boothCount++;
}

// Parameterized Constructor
TollBooth::TollBooth(const char* loc, int cap)
{
    location = NULL;
    setLocation(loc);

    // valid capacity check
    if (cap > 0)
    {
        capacity = cap;
    }
    else {
        capacity = 10;
    }

    history = new double[capacity];
    used = 0;
    totalCar = 0;
    totalAmount = 0;
    paidCar = 0;
    nonPayingCar = 0;
    boothCount++;
}

// Copy constructor is required here because the class uses dynamic memory.
// If we used the default copy constructor, both objects would point to the
// same memory which could cause problems like double deletion.
// So we perform a deep copy of the history array and location string.
TollBooth::TollBooth(const TollBooth& other)
{
    location = NULL;
    setLocation(other.location);

    capacity = other.capacity;
    used = other.used;
    history = new double[capacity];
    for (int i = 0; i < used; i++)
    {
        history[i] = other.history[i];
    }
    totalCar = other.totalCar;
    paidCar = other.paidCar;
    nonPayingCar = other.nonPayingCar;
    totalAmount = other.totalAmount;

    boothCount++;
}

// Destructor to free dynamic memory
TollBooth::~TollBooth()
{
    delete[] location;
    delete[] history;
}

// function for paying car
void TollBooth::payingCar()
{
    totalCar += 1;
    paidCar += 1;
    totalAmount += 50; // fixed toll price

    // store transaction in history
    if (used < capacity)
    {
        history[used] = 50;
        used++;
    }
    else
    {
        // shift history left if full
        for (int i = 0; i < capacity - 1; i++)
            history[i] = history[i + 1];
        history[capacity - 1] = 50;
    }
}

// function for non paying car
void TollBooth::nopayCar()
{
    totalCar += 1;
    nonPayingCar += 1;

    if (used < capacity)
    {
        history[used] = 0;
        used++;
    }
    else
    {
        // again shifting when history is full
        for (int i = 0; i < capacity - 1; i++)
            history[i] = history[i + 1];
        history[capacity - 1] = 0;
    }
}

void TollBooth::display(unsigned int& cars, unsigned int& paid, unsigned int& unpaid, double& amount)const
{
    cars = totalCar;
    amount = totalAmount;
    paid = paidCar;
    unpaid = nonPayingCar;

}

// sets location dynamically
void TollBooth::setLocation(const char* loc)
{
    if (location)
    {
        delete[] location;  // free previous memory
    }

    if (!loc)
    {
        loc = "Unknown";
    }
    location = new char[strlen(loc) + 1];
    strcpy_s(location, strlen(loc) + 1, loc);
}

// returns location
const char* TollBooth::getLocation()const
{
    return location;
}

// how many transactions stored in history
int TollBooth::getHistoryCount()const
{
    return used;
}

// get specific history entry
double TollBooth::getHistory(int i)const
{
    return history[i];
}

TollBooth TollBooth::operator+(const TollBooth& other)
{
    TollBooth temp;

    temp.totalCar = totalCar + other.totalCar;
    temp.paidCar = paidCar + other.paidCar;
    temp.nonPayingCar = nonPayingCar + other.nonPayingCar;
    temp.totalAmount = totalAmount + other.totalAmount;

    return temp;
}

// Friend function used for auditing purposes.
// It can access private members of TollBooth directly without
// using getter functions.
void auditBooth(const TollBooth& b, unsigned int& cars, double& amount)
{
    cars = b.totalCar;
    amount = b.totalAmount;
}

int TollBooth::getBoothCount()
{
    return boothCount;
}

int main()
{
    int n;

    cout << "\n";
    cout << "================================================" << endl;
    cout << "   === TOLL BOOTH MANAGEMENT SYSTEM ===" << endl;
    cout << "================================================" << endl;
    cout << endl;

    cout << "Enter number of Toll Booths: ";
    cin >> n;

    // input validation check
    while (cin.fail() || n < 1)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a positive number: ";
        cin >> n;
    }
    cin.ignore();

    // dynamically creating booths
    TollBooth* booths = new TollBooth[n];

    char loc[50];

    // taking locations names from user
    for (int i = 0; i < n; i++)
    {
        cout << "Enter location for Booth " << i + 1 << ": ";
        cin.getline(loc, 50);

        booths[i].setLocation(loc);
    }

    int boothIndex;
    char choice;


    while (true)
    {
        cout << "\nEnter booth number (1-" << n << "): ";
        cin >> boothIndex;
        if (cin.fail() || boothIndex < 1 || boothIndex > n)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid booth!" << endl;
            continue;
        }

        cout << "\nInside Booth " << boothIndex << " (" << booths[boothIndex - 1].getLocation() << ")" << endl;
        cout << "Press Y = Paying Car" << endl;
        cout << "Press N = Non-Paying Car" << endl;
        cout << "Press BACKSPACE = Return to booth menu" << endl;
        cout << "Press ESC = Exit program" << endl;

        while (true)
        {
            char choice = _getch();  // instant key input , no need to use cin and enter

            if (choice == 27)
            {
                cout << "Program Terminated." << endl;
                goto endProgram;  // quick exit
            }
            else if (choice == 8)
            {
                cout << "Returning to booth menu..." << endl;
                break;
            }
            else if (choice == 'Y' || choice == 'y')
            {
                booths[boothIndex - 1].payingCar();
                cout << "Paying car counted." << endl;
            }
            else if (choice == 'N' || choice == 'n')
            {
                booths[boothIndex - 1].nopayCar();
                cout << "Non-paying car counted." << endl;
            }
            else
            {
                cout << "Invalid key!" << endl;
            }
        }
    }

endProgram:

    // showing final report of each booth
    for (int i = 0; i < n; i++)
    {
        unsigned int cars, paid, unpaid;
        double amount;

        booths[i].display(cars, paid, unpaid, amount);

        cout << "\n================================================" << endl;
        cout << "        BOOTH " << i + 1 << " - " << booths[i].getLocation() << endl;
        cout << "================================================" << endl;
        cout << "Total cars: " << cars << " | Paid: " << paid << " | Not Paid: " << unpaid << endl;
        cout << "Total amount: $" << fixed << setprecision(2) << amount << endl;

        int count = booths[i].getHistoryCount();
        cout << "History (" << count << "): ";
        for (int j = 0; j < count; j++)
            cout << "$" << fixed << setprecision(0) << booths[i].getHistory(j) << " ";
        cout << endl;

        // using friend function for audit
        unsigned int auditCars;
        double auditAmount;

        auditBooth(booths[i], auditCars, auditAmount);

        cout << "Audit: " << auditCars << " cars, $" << fixed << setprecision(2) << auditAmount << endl;
        cout << "================================================" << endl;
    }

    cout << "Total Booth Objects Created: " << TollBooth::getBoothCount() << endl;

    delete[] booths;   // freeing booth array

    return 0;
}