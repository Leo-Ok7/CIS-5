/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 8, 2024, 4:30 PM
 * Purpose: Calculate retroactive pay and new salary for any number of months
 */

//System Libraries
#include <iostream>
#include <iomanip> // Include iomanip library for formatting
using namespace std;

//Global Constants
const float inc = 0.076f; // 7.6% pay increase

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    char rpt;
    
    do {
        // Declare All Variables
        float prvSal, rtrPay, nwSal, nwMonSal;

        // Initialize all Variables
        cout << "Enter the previous annual salary: $";
        cin >> prvSal;

        // Map inputs to outputs -> The Process
        rtrPay = prvSal * inc / 2; // Retroactive pay for 6 months
        nwSal = prvSal * (1 + inc); // New annual salary
        nwMonSal = nwSal / 12; // New monthly salary

        // Display Output
        cout << fixed << setprecision(2);
        cout << "Retroactive pay: $" << rtrPay << endl;
        cout << "New annual salary: $" << nwSal << endl;
        cout << "New monthly salary: $" << nwMonSal << endl;

        cout << "Do you want to repeat the calculation? (y or n) ";
        cin >> rpt;

    } while (rpt == 'y');

    cout << "Thank you!" << endl;
    //Exit stage right
    return 0;
}
