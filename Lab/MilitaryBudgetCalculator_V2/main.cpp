/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 8, 2024, 4:20 PM
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
    milBdgt = 7.0539e11f;
    fedBdgt = 4.8e12f;

    mlPrcnt = (milBdgt / fedBdgt) * 100;

    // Display Output
    cout << "Military Budget as a percentage of the Federal Budget (2021): " << mlPrcnt << "%" << endl;


    // Exit stage right
    return 0;
}
