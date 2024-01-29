/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 9, 2024, 6:40 PM
 * Purpose: Determines whether a meeting room is in violation of fire law regulations regarding the maximum room capacity.
 */
//System Libraries
#include <iostream>
using namespace std;

int main() {
    char repeat;

    do {
        // Declare all variables
        int mxCpcty, nmppl;
        
        //Initialize all Variables
        cout << "Input the maximum room capacity and the number of people" << endl;
        cin >> mxCpcty >> nmppl;

        //Map inputs to outputs -> The Process

        //Display Output
        if (nmppl <= mxCpcty) {
            int addlPpl = mxCpcty - nmppl;
            cout << "Meeting can be held." << endl;
            cout << "Increase number of people by " << addlPpl << " will be allowed without violation.";
        } else {
            int pplExcl = nmppl - mxCpcty;
            cout << "Meeting cannot be held." << endl;
            cout << "Reduce number of people by " << pplExcl << " to avoid fire violation.";
        }
        
    } while (repeat == 'y');  // Added this line to close the do-while loop

    //Exit stage right
    return 0;
}