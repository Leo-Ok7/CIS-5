/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 9, 2024, 4:12 PM
 * Purpose: Calculate the gross pay
 */
//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float pyRt, hrs, pyChck; 
    //Initialize or input i.e. set variable values
    cout << "This program calculates the gross paycheck."<< endl;
    cout << "Input the pay rate in $'s/hr and the number of hours." << endl;\
    cin >> pyRt;
    cin >> hrs;
    
    if(hrs<=40) {
    
    pyChck = pyRt * hrs;
    
    }else {
    
      pyChck = pyRt * 40 + 2 * (pyRt * (hrs - 40));
    }
    //Map inputs -> outputs
    
    //Display the outputs
     cout << "Paycheck = $ " << fixed << setprecision(2) << pyChck;
    //Exit stage right or left!
    return 0;
}