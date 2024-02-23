/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 9, 2024, 6:40 PM
 * Purpose: reads in ten whole numbers and that outputs the sum of all the numbers greater than zero, the sum of all the numbers less than zero (which will be a negative number or zero), and the sum of all the numbers, whether positive, negative, or zero.
 */
//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    short x,sumPos, sumNeg;
    char counter, nTimes;
    
    //Initialize or input i.e. set variable values
    sumPos = sumNeg = counter=0;
    nTimes = 10;
    
    //Map inputs -> outputs
    cout << "Input 10 numbers, any order, positive or negative : " << endl;
    while(++counter<=nTimes) {
        cin >> x;
        sumPos += x>0?x:0;
        sumNeg += x<0?x:0;
    }
    //Display the outputs
cout << "Negative sum = " << setw(3) << sumNeg << endl;
cout << "Positive sum = " << setw(3) << sumPos << endl;
cout << "Total sum    = " << setw(3) << sumNeg+sumPos;
    //Exit stage right or left!
    return 0;
}