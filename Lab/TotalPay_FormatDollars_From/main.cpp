/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 17, 2024, 12:25 PM
 * Purpose : Write to a file our daily pay to outputting the dollars
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
    fstream in,out; //Input the daily pay, Output the daily pay
    unsigned int pay,dSum=1; //Pay per day and Daily Sum
    char fName1[]="dollar.dat";
    string fName2 = "sum.dat";
    
    
    
    //Initialize all Variables
    in.open(fName2, ios::in);
    out.open(fName1, ios::out);
    
    
    
    //Map inputs to outputs -> The Process
    for(int day = 1; day <= 31; day++) {
        in >> dSum;
        int dollar = dSum / 100;
        int penny = dSum%100;
        out << setw(10) << "$" << dollar << "." 
                << ((penny < 10) ?"0":"")
                << penny << endl;
    }
    
    
    //Display Output
   


    //Exit stage right
    in.close();
    out.close();

    return 0;
}