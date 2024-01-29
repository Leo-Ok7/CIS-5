/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 4, 2024, 3:35 PM
 * Purpose : Display Text
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
    
    //Declare all Variables
    char inputChar;
    
    //Initialize all Variables
    inputChar = ' ';
    
    //Map inputs to outputs -> The Process
    cout << "Enter a character: ";
    cin >> inputChar; 
    
    //Display Output
    cout << inputChar << ' ' << inputChar << ' ' << inputChar << endl;
    cout << inputChar << ' ' << inputChar << endl;
    cout << inputChar << endl;
    cout << inputChar << endl;
    cout << inputChar << endl;
    cout << inputChar << endl;
    cout << inputChar << endl;
    cout << inputChar << ' ' << inputChar << endl;
    cout << inputChar << ' ' << inputChar << ' ' << inputChar << endl;

    //Exit stage right
    return 0;
}