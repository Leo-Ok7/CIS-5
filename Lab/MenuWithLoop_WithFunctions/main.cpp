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
void prblm1 ();
void prblm2 ();
void prblm3 ();

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare all Variables
    char nMnuItm;
    unsigned short probNum;
    
    //Initialize all Variables
    nMnuItm = 3;
    
    //Display Menu
    do {
        cout << "This is an example Menu Program" << endl;
        cout << "Input the Problem Number to Run" << endl;
        cout << "Type 1 problem 1" << endl;
        cout << "Type 2 problem 2" << endl;
        cout << "Type 3 problem 3" << endl;
        cin >> probNum;

        //Execute the Menu/Problem Number
        switch(probNum){
            case 1 : prblm1(); break;
            case 2 : prblm2(); break;
            case 3 : prblm3(); break;
            default : cout << "Exiting the Menu" << endl;
        }
    } while (probNum > 0 && probNum <= nMnuItm);
    
    //Display Output
    switch(probNum){
        case 1 : cout << "Output for problem 1" << endl; break;
        // Add cases for other problems if needed
    }

    //Exit stage right
    return 0;
}

void prblm1 () {
    cout << "Solution for problem 1" << endl << endl;
}

void prblm2 () {
    cout << "Solution for problem 2" << endl << endl;
}

void prblm3 (){
    cout << "Solution for problem 3" << endl << endl;
}