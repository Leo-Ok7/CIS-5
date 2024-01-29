/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 8, 2024, 4:00 PM
 * Purpose : Calculate the military budget as a percentage of the federal budget
 */

// System Libraries
#include <iostream>
using namespace std;

// Function Prototypes

// Execution Begins Here
int main(int argc, char** argv) {
    // Declare all Variables
    float milBdgt, fedBdgt, mlPrcnt;

    //Initialize All Variables
    milBdgt = 7.0e11f;    // Military Budget = 700 Billion
    fedBdgt = 4.1e12f;    // Federal Budget = 4.1 Trillion

    mlPrcnt = (milBdgt / fedBdgt) * 100;

    cout << "Military Budget as a percentage of the Federal Budget : " << mlPrcnt << "%" << endl;



    // Exit stage right
    return 0;
}
