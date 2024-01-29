/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 18, 2024, 2:00 PM
 * Purpose : Display bar graph based on sales
 */

//System Libraries
#include <iostream> //Input-Output Library
using namespace std;

//User Libraries

//Global Constants

//Mathematical/Physics/Conversions, Higher dimensioned arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {    
    //Declare all Variables
    const int sPerA = 100;
    const int numStr = 5;
    
    int sales1, sales2, sales3, sales4, sales5;
        
    //Initialize all Variables
    cout << "Program that displays bar graph based on sales" << endl;
    
    cout << "Input today's sales for Store 1: ";
    cin >> sales1;

    cout << "Input today's sales for Store 2: ";
    cin >> sales2;

    cout << "Input today's sales for Store 3: ";
    cin >> sales3;

    cout << "Input today's sales for Store 4: ";
    cin >> sales4;

    cout << "Input today's sales for Store 5: ";
    cin >> sales5;
    
    //Map inputs to outputs -> The Process
    cout << "Store 1: ";
    for (int slStore = 1; slStore <= sales1 / sPerA; slStore++) {
        cout << "*";
    }
    cout << endl;

    cout << "Store 2: ";
    for (int slStore = 1; slStore <= sales2 / sPerA; slStore++) {
        cout << "*";
    }
    cout << endl;

    cout << "Store 3: ";
    for (int slStore = 1; slStore <= sales3 / sPerA; slStore++) {
        cout << "*";
    }
    cout << endl;

    cout << "Store 4: ";
    for (int slStore = 1; slStore <= sales4 / sPerA; slStore++) {
        cout << "*";
    }
    cout << endl;

    cout << "Store 5: ";
    for (int slStore = 1; slStore <= sales5 / sPerA; slStore++) {
        cout << "*";
    }
    cout << endl;
    
    //Display Output
    
    
 

    //Exit stage right
    return 0;
}