#include <iostream>
#include <conio.h>
using namespace std;

class TollBooth {

private:
    unsigned int totalCar;
    double totalAmount;

public:
    TollBooth();
    void payingCar();
    void nopayCar();
    void display(unsigned int& cars, double& amount)const;

};

TollBooth::TollBooth()
{
    totalCar = 0;
    totalAmount = 0;
}

void TollBooth::payingCar()
{
    totalCar += 1;
    totalAmount += 50;
}

void TollBooth::nopayCar()
{
    totalCar += 1;
}

void TollBooth::display(unsigned int& cars, double& amount)const
{
    cars = totalCar;
    amount = totalAmount;
}

int main()
{
    TollBooth t1;
    char choice;
    unsigned int cars;
    double amount;

    cout << "===== BRIDGE TOOLBOOTH =====" << endl;
    cout << "Enter 'Y' if car pays and Enter 'N' if it goes without paying(Press ESC to terminate the program):" << endl;

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
    }

    t1.display(cars, amount);

    cout << "Total cars: " << cars << endl;
    cout << "Total amount " << amount << endl;

}

