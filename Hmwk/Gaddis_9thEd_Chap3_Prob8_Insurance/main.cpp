/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 9, 2024, 2:03 PM
 * Purpose: Display the minimum amount of insurance he or she should buy for the property..
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
    int rplcCst, minInsr;
    //Initialize or input i.e. set variable values
    cin >> rplcCst;
    
    minInsr = rplcCst * 0.8; // Minimum insurance required
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "Insurance Calculator" << endl;
    cout << "How much is your house worth?" << endl;
    cout << "You need $" << minInsr << " of insurance.";
    //Exit stage right or left!
    return 0;
}