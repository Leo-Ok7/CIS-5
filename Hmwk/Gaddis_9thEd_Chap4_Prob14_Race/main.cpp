/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 12, 2024, 2:23 PM
 * Purpose: Display who came in first, second, and third place.
 */
//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int time1, time2, time3;
    string rnr1, rnr2, rnr3;
    
    //Initialize or input i.e. set variable values
    cout << "Race Ranking Program" << endl;
    cout << "Input 3 Runners" << endl;
    cout << "Their names, then their times" << endl;
    cin >> rnr1 >> time1;
    cin >> rnr2 >> time2;
    cin >> rnr3 >> time3;
    //Map inputs -> outputs
    
   

    //Display the outputs
if (time1 < time2 && time1 < time3) {
    cout << rnr1 << "\t" << right << setw(3) << time1 << endl;
if (time2 < time3) {
        cout << rnr2 << "\t" << right << setw(3) << time2 << endl;
        cout << rnr3 << "\t" << right << setw(3) << time3;
} else {
        cout << rnr3 << "\t" << right << setw(3) << time3 << endl;
        cout << rnr2 << "\t" << right << setw(3) << time2;
    }
} else if (time2 < time1 && time2 < time3) {
    cout << rnr2 << "\t" << right << setw(3) << time2 << endl;
if (time1 < time3) {
        cout << rnr1 << "\t" << right << setw(3) << time1 << endl;
        cout << rnr3 << "\t" << right << setw(3) << time3;
} else {
        cout << rnr3 << "\t" << right << setw(3) << time3 << endl;
        cout << rnr1 << "\t" << right << setw(3) << time1;
    }
} else if (time3 < time1 && time3 < time2) {
    cout << rnr3 << "\t" << right << setw(3) << time3 << endl;
if (time1 < time2) {
        cout << rnr1 << "\t" << right << setw(3) << time1 << endl;
        cout << rnr2 << "\t" << right << setw(3) << time2;
} else {
        cout << rnr2 << "\t" << right << setw(3) << time2 << endl;
        cout << rnr1 << "\t" << right << setw(3) << time1;
    }
}
    //Exit stage right or left!
    return 0;
}