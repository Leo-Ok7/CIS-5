/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 8, 2024, 6:30 PM
 * Purpose: Check if legal to hold meeting in room
 */

// System Libraries
#include <iostream>
using namespace std;

int main() {
    char repeat;

    do {
        // Declare all variables
        int mxCpcty, nmppl;
        
        //Initialize all Variables
        cout << "Enter the maximum room capacity: ";
        cin >> mxCpcty;
        cout << "Enter the number of people coming to the meeting: ";
        cin >> nmppl;
       
        //Map inputs to outputs -> The Process

        //Display Output
        if (nmppl <= mxCpcty) {
            int addlPpl = mxCpcty - nmppl;
            cout << "It is legal to hold the meeting." << endl;
            cout << "Additional people allowed: " << addlPpl << endl;
        } else {
            int pplExcl = nmppl - mxCpcty;
            cout << "The meeting cannot be held as planned due to fire regulations." << endl;
            cout << "People to exclude to meet regulations: " << pplExcl << endl;
        }

        cout << "Do you want to check another meeting? (y or n): ";
        cin >> repeat;

    } while (repeat == 'y');

    cout << "Thank you!" << endl;
    //Exit stage right
    return 0;
}
