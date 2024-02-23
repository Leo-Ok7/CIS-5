/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 17, 2024, 12:25 PM
 * Purpose : Write to a file our daily pay
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <fstream> //File Stream Library
#include <iomanip> // Format Library
using namespace std;

//User Libraries

//Global Constants

//Mathematical/Physics/Conversions, Higher dimensioned arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables
    fstream out; //Output the daily pay
    unsigned int pay;
    char fName[]="pay.dat";  
    //Initialize all Variables
    out.open(fName, ios::out);
    pay = 1; //Pay in Pennies
    //Map inputs to outputs -> The Process
    for(int day = 1; day <= 31; day++) {
        out << setw(10) << pay << endl;
        pay*=2; //pay = 2 * pay
    }
    
    
    //Display Output
   


    //Exit stage right
    return 0;
}