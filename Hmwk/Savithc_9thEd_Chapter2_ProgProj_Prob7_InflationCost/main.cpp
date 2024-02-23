/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 9, 2024, 3:30 PM
 * Purpose: Gauge the expected cost of an item in a specified number of years
 */

// System Libraries
#include <iostream>
using namespace std;

int main() {
    // Declare all variables
    float inCst, inflRt, years;

    //Initialize all Variables
    cout << "Enter the initial cost of the item: $";
    cin >> inCst;
    
    cout << "Enter the inflation rate in a percent: ";
    cin >> inflRt;

    cout << "Enter the number of years from now the item will be purchased: ";
    cin >> years;

    inflRt /= 100; // Convert percentage to fraction


    for (int i = 1; i <= years; ++i) {
        inCst += inCst * inflRt;
    }

    //Display Output
    cout << "The estimated cost of the item after " << years << " years: $" << inCst << endl;

    return 0;
}
