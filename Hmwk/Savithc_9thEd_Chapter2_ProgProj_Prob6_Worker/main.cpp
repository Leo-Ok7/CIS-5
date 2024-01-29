/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 9, 2024, 3:00 PM
 * Purpose: Worker Salary Calculate based on Dependents
 */

// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char repeat;

    do {
        // Declare all variables
        float hRate = 16.78f;
        float oRate = hRate * 1.5f;
        int rgHrs, ovrHrs, dpndnts;

        //Initialize all Variables
        cout << "Enter the hours you worked in a week: ";
        cin >> rgHrs;
        cout << "Enter your number of dependents: ";
        cin >> dpndnts;
       
        //Map inputs to outputs -> The Process
        float gPay;
        if (rgHrs <= 40)
            gPay = rgHrs * hRate;
        else {
            ovrHrs = rgHrs - 40;
            gPay = 40 * hRate + ovrHrs * oRate;
        }
        
       
        float sst = 0.06f * gPay;
        float fit = 0.14f * gPay;
        float sit = 0.05f * gPay;
        float uDue = 10.0f;
        float hIns = (dpndnts >= 3) ? 35.0f : 0.0f;

        float nPay = gPay - sst - fit - sit - uDue - hIns;

        //Display Output
        cout << fixed << setprecision(2);
        cout << "Gross Pay: $" << gPay << endl;
        cout << "Social Security Tax: $" << sst << endl;
        cout << "Federal Income Tax: $" << fit << endl;
        cout << "State Income Tax: $" << sit << endl;
        cout << "Union Dues: $" << uDue << endl;
        cout << "Health Insurance: $" << hIns << endl;
        cout << "Net Take-Home Pay: $" << nPay << endl;

        cout << "Do you want to calculate for another worker? (y or n): ";
        cin >> repeat;

    } while (repeat == 'y');

    cout << "Thank you!" << endl;
    //Exit stage right
    return 0;
}

