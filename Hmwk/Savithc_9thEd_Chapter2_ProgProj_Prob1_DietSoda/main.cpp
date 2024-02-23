/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 8, 2024, 4:00 PM
 * Purpose: Calculate the limit of diet soda pop consumption
 */

//System Libraries
#include <iostream>
using namespace std;

// Global Constants
const float CNVLBSG = 45359.2 / 100; // Conversion factor from lbs to grams

// Function Prototypes

// Execution Begins Here
int main(int argc, char** argv) {
    // Declare all Variables
    float dsrdWt, wtKill, dsKill, ms1Can, mMouse, ldMouse, mCan, pSwtnr ;
    int nCans;

    // Initialize or input, i.e., set variable values
    cout << "Program to calculate the limit of Soda Pop Consumption." << endl;
    cout << "Input the desired dieter's weight in lbs: ";
    cin >> dsrdWt;

    // Assuming these values stay constant, no need to prompt the user
    mMouse = 35;
    ldMouse = 5;
    mCan = 350;
    pSwtnr = 0.001f;

    // Map inputs to outputs
    wtKill = ldMouse / mMouse * dsrdWt;        // Simple ratio, proportionality
    dsKill = wtKill * CNVLBSG;                 // Conversion to mass
    ms1Can = mCan * pSwtnr;                // Calculating the mass of sweetener in a Can
    nCans = dsKill / ms1Can;                   // How many cans of coke to cause possible death

    // Display the outputs
    cout << "The maximum number of soda pop cans" << endl;
    cout << "you can consume is " << nCans << " cans" << endl;

    // Exit stage right
    return 0;
}

