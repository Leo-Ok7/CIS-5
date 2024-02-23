/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 8, 2024, 5:50 PM
 * Purpose: Calculate Face value and monthly payment
 */

// System Libraries
#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;

int main() {
    char repeat;

    do {
        // Declare variables
        float amntNdd, intrsRt, durntn, fcVal, mntPymt;

        //Initialize all Variables
        cout << "Enter your amount needed : $";
        cin >> amntNdd;

        cout << "Enter the interest rate (in percentage): ";
        cin >> intrsRt;

        cout << "Enter the duration of the loan in months: ";
        cin >> durntn;

        //Map inputs to outputs -> The Process
        float annlIntrstRt = intrsRt / 100.0f;
        fcVal = amntNdd / (1 - (annlIntrstRt * durntn / 12.0f));
        mntPymt = fcVal / durntn;

        //Display Output
        cout << fixed << setprecision(2);
        cout << "Face value required: $" << fcVal << endl;
        cout << "Monthly payment: $" << mntPymt << endl;

        cout << "Do you want to repeat the calculation? (y or n): ";
        cin >> repeat;

    } while (repeat == 'y');

    cout << "Thank you!" << endl;
    //Exit stage right
    return 0;
}
