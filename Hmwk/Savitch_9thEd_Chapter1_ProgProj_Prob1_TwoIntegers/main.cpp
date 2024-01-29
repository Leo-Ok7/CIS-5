/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 3, 2024, 1:45 PM
 * Purpose : Display sum and product of two integers
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
     int frstint, scndint, sum, product;
        
    //Initialize all Variables
    frstint = 2; // Initializing first integer with 2
    scndint = 2; // Initializing second integer with 2
    
    //Map inputs to outputs -> The Process
    cout << "First integer: ";
    cin >> frstint;
    
    cout << "Second integer: ";
    cin >> scndint;

    sum = frstint + scndint;
    product = frstint * scndint;
    
    //Display Output
    cout << "The sum of the two integers is: " << sum << endl;
    cout << "The product of the two integers is: " << product << endl;

    //Exit stage right
    return 0;
}