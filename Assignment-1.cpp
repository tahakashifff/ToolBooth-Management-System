#include <iostream>
#icnlude <string>   
#include <conio.h>
using namespace std;

class TollBooth {

private:
    unsigned int totalCar;
    unsigned int paidCar;
    unsigned int nonPayingCar;
    double totalAmount;
    
    

public:
    TollBooth();
    
    void payingCar();
    void nopayCar();
    
    static unsigned int totalBoothsCreated;
    
    void display(unsigned int& cars,unsigned int& paidCar,unsigned int& nonPayingcar, double& amount)const;
    
    ~TollBooth()
    {

    }
};



TollBooth::TollBooth()
{
    totalCar = 0;
    totalAmount = 0;
    paidCar = 0;
    nonPayingCar = 0;
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

int main()
{
    int n;
    cout << "Enter how many tollbooths you want to create: ";
    cin >> n;

    TollBooth* booths = new TollBooth[n];

    cout << "Total booths created so far: " << TollBooth::getTotalBoothsCreated() << "\n";

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

