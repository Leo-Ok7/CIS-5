/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 9, 2024, 2:36 PM
 * Purpose: Converts Fahrenheit temperatures to Celsius temperatures.
 */
//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Format
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float F, C; // Fahrenheit and Celsius
    
    //Initialize or input i.e. set variable values
    cin >> F;
    
    C = (5.0/9.0) * (F - 32);
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "Temperature Converter" << endl;
    cout << "Input Degrees Fahrenheit" << endl;
    cout << fixed << setprecision(1) << F << " Degrees Fahrenheit = " << fixed << setprecision(1) << C << " Degrees Centigrade";

    //Exit stage right or left!
    return 0;
}