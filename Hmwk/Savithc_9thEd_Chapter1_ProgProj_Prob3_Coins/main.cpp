/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 4, 2024, 2:30 PM
 * Purpose : Display total coins worth
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
    int quarters, dimes, nickels, total;
        
    //Initialize all Variables
    quarters = dimes = nickels = total = 0;

    
    //Map inputs to outputs -> The Process
    cout << "Enter the number of quarters: ";
    cin >> quarters;

    cout << "Enter the number of dimes: ";
    cin >> dimes;

    cout << "Enter the number of nickels: ";
    cin >> nickels;
    
    total = quarters * 25 + dimes * 10 + nickels * 5;

    //Display Output
  
    cout << "The coins are worth " << total << " cents." <<endl; 

    //Exit stage right
    return 0;
}