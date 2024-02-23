/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 9, 2024, 5:56 PM
 * Purpose: Display the amount of retroactive pay due the employee, the new annual salary, and the new monthly salary.
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
        cout << "Input previous annual salary." << endl;
        cin >> prvSal;

        // Map inputs to outputs -> The Process
        rtrPay = prvSal * inc / 2; // Retroactive pay for 6 months
        nwSal = prvSal * (1 + inc); // New annual salary
        nwMonSal = nwSal / 12; // New monthly salary

        // Display Output
        cout << fixed << setprecision(2);
        cout << "Retroactive pay    = $  " << rtrPay << endl;
        cout << "New annual salary  = $" << nwSal << endl;
        cout << "New monthly salary = $ " << setprecision(2) << nwMonSal;

        cin >> rpt;

    } while (rpt == 'y');

    //Exit stage right
    return 0;
}
