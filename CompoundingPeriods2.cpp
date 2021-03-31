#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;
// Prototype
double getFinalBalance(double, int, int, double);
int main()
{
    double principal, interestRate;
    int years, cperiods, invnum = 1;

    ifstream inFile;
    inFile.open("investAll.txt");
    if (!inFile){
        cout << "File did not open." << endl;
    } else {

        while(!inFile.eof()){
            cout << fixed << showpoint << setprecision(2);
    cout << setfill(' ')<< setw(40) << "Investment #" << invnum << endl;
    invnum++;
    inFile >> principal >> years >> cperiods >> interestRate;
    cout << "Principal Amount" << setfill ('.') << setw (50) << "$" << principal << endl;
    cout << "Interest Rate" << setfill ('.') << setw (56) <<  interestRate << "%" << endl;
    cout << "Years Invested" << setfill ('.') << setw (51) << "" << years << endl;
    cout << "Compounding Periods" << setfill ('.') << setw (46) << "" << cperiods << endl;
    cout << "FINAL BALANCE" << setfill ('.') << setw (53) << "$" << getFinalBalance(principal, years, cperiods, interestRate) << endl << endl;
        } // end of while
    } // end of else
    return 0;
}

double getFinalBalance(double principal, int years, int cperiods, double interestRate){
return principal * pow((1 + ((interestRate/100)/cperiods)), cperiods*years);
}
