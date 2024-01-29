/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 4, 2024, 3:00 PM
 * Purpose : Display total distance of drop
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Mathematical/Physics/Conversions, Higher dimensioned arrays

//Function Prototypes

//Execution Begins Here
int main() {
    //Initialize the Random Number Seed
    
    //Declare Variables
    
    int time, distance, acceleration;
    
    //Initialize Variables
    
    
    //Map inputs to outputs -> The Process
    cout << "Enter time in seconds: ";
    cin >> time; 
    
    //Constant acceleration
    acceleration = 32; //feet per second^2
    
    //Distance Formula
    distance = (acceleration * time * time) / 2;
            
    //Display Results
    cout << "If an object falls for " << time << " seconds,\n";
    cout << "It would drop about " << distance << " feet." << endl;

    //Exit stage right
    return 0;
}