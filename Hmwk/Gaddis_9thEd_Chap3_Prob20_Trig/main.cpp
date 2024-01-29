/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 9, 2024, 3:26 PM
 * Purpose: Display the sine, cosine, and tangent of the angle.
 */
//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Formatting Library 
#include <cmath> // Trig Functions Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
float PI = 3.14159265;
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
   float anglDgr, anglRad, sine, cosine, tangent;
   
   
    //Initialize or input i.e. set variable values
    cin >> anglDgr;
    

    sine = sin(anglDgr * (PI / 180));
    cosine = cos(anglDgr * (PI / 180));
    tangent = tan(anglDgr * (PI / 180));
    
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "Calculate trig functions" << endl;
    cout << "Input the angle in degrees." << endl;
    cout << "sin(" << fixed << setprecision(0) << anglDgr << ") = " << fixed << setprecision(4) << sine << endl;
    cout << "cos(" << fixed << setprecision(0) << anglDgr << ") = " << fixed << setprecision(4) << cosine << endl;
    cout << "tan(" << fixed << setprecision(0) << anglDgr << ") = " << fixed << setprecision(4) << tangent;

    //Exit stage right or left!
    return 0;
}