/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 9, 2024, 1:00 PM
 * Purpose: Calculate the average test score and display it
 */
//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Formatting Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float score1, score2, score3, score4, score5, average;
    
    //Initialize or input i.e. set variable values
    cout << "Input 5 numbers to average." << endl;
    cin >> score1 >> score2 >> score3 >> score4 >> score5;
    
   average = (score1 + score2 + score3 + score4 + score5) / 5.0f;
    
    //Map inputs -> outputs
    
    //Display the outputs
    cout << fixed << setprecision(1); //formatted in fixed-point
    cout << "The average = " << average;
    //Exit stage right or left!
    return 0;
}
