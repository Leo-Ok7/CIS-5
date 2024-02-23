/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 8, 2024, 5:00 PM
 * Purpose: Calculate retroactive pay and new salary for any number of months
 */

// System Libraries
#include <iostream>
#include <iomanip> // Include iomanip library for formatting
using namespace std;

// Global Constants
const float inc = 0.076f; // 7.6% pay increase

// Function Prototypes

// Execution Begins Here
int main(int argc, char** argv) {
    char rpt;

    do {
        // Declare All Variables
        float prvSal, rtrPay, nwSal, nwMonSal;
        int months; // Number of months for retroactive pay

        // Initialize all Variables
        cout << "Enter the previous annual salary: $";
        cin >> prvSal;

        cout << "Enter the number of months for retroactive pay: ";
        cin >> months;

        // Map inputs to outputs -> The Process
        rtrPay = prvSal * inc * months; // Retroactive pay for any number of months
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
