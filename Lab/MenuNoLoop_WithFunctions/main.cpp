    /* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 18, 2024, 12:41 PM
 * Purpose : Menu with functions
 */

//System Libraries
#include <iostream>
#include <iomanip> //Format Library
using namespace std;

//User Libraries

//Global Constants

//Mathematical/Physics/Conversions, Higher dimensioned arrays

//Function Prototypes
void prblm (1);
void prblm (2);
void prblm (3);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare all Variables
    char nMnuItm;
    unsigned short probNum;
    
    //Initialize all Variables
    nMnuItm = 3;
    
    //Display Menu
    cout << "This is an example Menu Program" << endl;
    cout << "Input the Problem Number to Run" << endl;
    cout << "Type 1 problem 1" << endl;
    cout << "Type 2 problem 2" << endl;
    cout << "Type 3 problem 3" << endl;
    cin >> probNum;
    
    //Execute the Menu/Problem Number
    switch(probNum){
        case 1 : cout << prblm1 << endl;
        case 2 : cout << prblm2 << endl;
        case 3 : cout << prblm3 << endl;
        default : cout << "Exiting the Menu" << endl;
    }
    //Display Output
    switch(probNum){
        case 1 : cout << 
    }

void prblm1 () {
    
    cout << "Solution for problem 1";
    
}
void prblm2 () {
    
    cout << "Solution for problem 1";

    
}
void prblm3 (){
    
    cout << "Solution for problem 1";

    
    
}

    //Exit stage right
    return 0;
}