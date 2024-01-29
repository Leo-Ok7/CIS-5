/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 9, 2024, 4:30 PM
 * Purpose: Calculate time required to pay loan
 */

// System Libraries
#include <iostream>
using namespace std;

int main() {
    //Declare all Variables
    const float initDbt = 1000.0f;      // Initial debt amount
    const float mntlPymt = 50.0f;  // Monthly payment
    const float intrsRt = 0.18f; //Interest rate
    const float mntlRt = intrsRt / 12.0f; // Monthly interest rate

    float debt = initDbt;
    float ttlIntrs = 0.0f;
    int months = 0;
    //Initialize all Variables
    
    //Map inputs to outputs -> The Process
    while (debt > 0.0f) {
        float mntIntr = debt * mntlRt;
        ttlIntrs += mntIntr;

        float mntPrPy = (mntlPymt > debt) ? debt : (mntlPymt - mntIntr);

        debt -= mntPrPy;

        ++months;
    }
    //Display Output
    cout << "It will take " << months << " months to pay off the loan." << endl;
    cout << "Total interest paid: $" << ttlIntrs << endl;
    //Exit stage right
    return 0;
}
