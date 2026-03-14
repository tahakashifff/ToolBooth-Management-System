#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

class TollBooth {

private:
    char *location;
    double *history;
    int capacity;
    int used;
   
    unsigned int totalCar;
    unsigned int paidCar;
    unsigned int nonPayingCar;
    double totalAmount;
    static int boothCount;

public:
    TollBooth();
    TollBooth(const char* loc, int cap = 10);
    TollBooth(const TollBooth& other);
    ~TollBooth();
    void payingCar();
    void nopayCar();
    void display(unsigned int& cars,unsigned int& paidCar,unsigned int& nonPayingcar, double& amount)const;
    void setLocation(const char* loc);
    static int getBoothCount();

};

int TollBooth::boothCount = 0;

TollBooth::TollBooth()
{
    setLocation("Unknown");
    capacity = 10;
    history = new double[capacity];
    totalCar = 0;
    totalAmount = 0;
    paidCar = 0;
    nonPayingCar = 0;
    boothCount++;
}

TollBooth::TollBooth(const char* loc, int cap = 10) 
{
    setLocation(loc);
    if (cap > 0) {
    capacity = cap;
} else {
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

TollBooth::TollBooth(const TollBooth& other) 
{
    setLocation(other.location);

    capacity = other.capacity;
    used = other.used;
    history = new double[capacity];
    for (int i = 0; i < used; i++) history[i] = other.history[i];

    totalCar = other.totalCar;
    paidCar = other.paidCar;
    nonPayingCar = other.nonPayingCar;
    totalAmount = other.totalAmount;

    boothCount++;
}

TollBooth::~TollBooth()
{
    delete[] location;
    delete[] history;
}

void TollBooth::payingCar()
{
    totalCar += 1;
    paidCar += 1;
    totalAmount += 50;
}

void TollBooth::nopayCar()
{
    totalCar += 1;
    nonPayingCar += 1;
}

void TollBooth::display(unsigned int& cars,unsigned int& paid,unsigned int& unpaid, double& amount)const
{
    cars = totalCar;
    amount = totalAmount;
    paid = paidCar;
    unpaid = nonPayingCar;
    
}

void TollBooth::setLocation(const char* loc)
{
    if(!loc)
    {
        loc = "Unknown";
    }
    else{
        location = new char[strlen(loc)];
        strcpy(location,loc);
    }
}

int TollBooth::getBoothCount()
{
    return boothCount;
}

int main()
{
    TollBooth t1;
    char choice;
    unsigned int cars,paid,unpaid;
    double amount;

    cout << "===== BRIDGE TOLL BOOTH ====="<<endl;
    cout << "Press Y = Paying Car"<<endl;
    cout << "Press N = Non-Paying Car"<<endl;
    cout << "Press ESC = Exit"<<endl;

    while (true)
    {
        choice = _getch();

        if (choice == 27)
        {
            cout << "Program Terminated." << endl;
            break;
        }
        else if (choice == 'Y' || choice == 'y')
        {
            t1.payingCar();
            cout << "Paying car counted." << endl;
        }
        else if (choice == 'N' || choice == 'n')
        {
            t1.nopayCar();
            cout << "Non-paying car counted." << endl;
        }
        else {
            cout<<"Invalid Key!"<<endl;
        }
    }

    t1.display(cars,paid,unpaid,amount);

    cout << "Total cars: " << cars << endl;
    cout << "Cars that paid: " << paid << endl;
    cout << "Cars that did not paid: " << unpaid << endl;
    cout << "Total amount: $" << amount << endl;

}

