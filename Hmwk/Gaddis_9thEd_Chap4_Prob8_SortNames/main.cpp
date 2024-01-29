/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 12, 2024, 1:00 PM
 * Purpose: Sorting the 3 given names
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    string Nm1,Nm2,Nm3;
    //Initialize or input i.e. set variable values
    cout << "Sorting Names" << endl;
    cout << "Input 3 names" << endl;
    cin >> Nm1 >> Nm2 >> Nm3;
    
    //Map inputs -> outputs
  if (Nm1 < Nm2 && Nm1 < Nm3) {
        cout << Nm1 << endl;
        if (Nm2 < Nm3) {
            cout << Nm2 << endl;
            cout << Nm3;
        } else {
            cout << Nm3 << endl;
            cout << Nm2;
        }
    } else if (Nm2 < Nm1 && Nm2 < Nm3) {
        cout << Nm2 << endl;
        if (Nm1 < Nm3) {
            cout << Nm1 << endl;
            cout << Nm3;
        } else {
            cout << Nm3 << endl;
            cout << Nm1;
        }
    } else {
        cout << Nm3 << endl;
        if (Nm1 < Nm2) {
            cout << Nm1 << endl;
            cout << Nm2;
        } else {
            cout << Nm2 << endl;
            cout << Nm1;
        }
    }

    //Display the outputs
   
    //Exit stage right or left!
    return 0;
}