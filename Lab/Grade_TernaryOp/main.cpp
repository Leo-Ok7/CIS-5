/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 11, 2024, 12:34 PM
 * Purpose : Grade 
 */

//System Libraries
#include <iostream>
#include <cstdlib> //Random Library
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
//Mathematical/Physics/Conversions, Higher dimensioned arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int> (time(0)));   
    //Declare Variables
    char grade;//Letter Grade
    char score;//0-100 
        
    //Initialize all Variables
    score = rand()%51+50;//[0-100]
    
    //Map inputs to outputs -> The Process
    grade = score >= 90?'A':
            score >= 80?'B':
            score >= 70?'C':
            score >= 60?'D':'F';
    
    //Display the output
    cout << "Score = " <<static_cast<int>(score);
            cout << " gives Grade = " << grade << endl;

    //Exit stage right
    return 0;
}