/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 22, 2024, 4:14 PM
 * Purpose : Creating Card War Game Version 1
 */

// System Libraries
#include <iostream> // Input-Output Library
#include <fstream>  // File Library
#include <cstdlib>  // srand Library
#include <ctime>    // Time Library
#include <string>   // String Library
using namespace std;

// User Libraries

// Global Constants

// Mathematical/Physics/Conversions, Higher dimensioned arrays

// Function Prototypes

// Execution Begins Here
int main(int argc, char** argv) {
    // Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));

    // Declare all Variables
    const int numCrds = 14; // Number of Cards
    const int numPlyr = 2; // Number of Players
    const int cardsPP = numCrds / numPlyr; // Cards Per Player, also makes it easier to calculate if there are more players
    string face = "A23456789TJQK";
    char p1Crd; // Player 1 Card
    char p2Crd; // Player 2 Card
    fstream out;
    string fileName;

    // Initialize all Variables
    fileName = "card.dat";
    out.open(fileName, ios::out);

    // Map inputs to outputs -> The Process
    // Deal and display player cards
    for (int i = 0; i < cardsPP; ++i) {
        int crdIdx = rand() % numCrds;
        p1Crd = face[crdIdx];

        crdIdx = rand() % numCrds;
        p2Crd = face[crdIdx];

        // Display Output
        cout << "Player 1 Card: " << p1Crd << endl;
        cout << "Player 2 Card: " << p2Crd << endl;

        // Write the cards to the file
        out << "Player 1 Card: " << p1Crd << endl;
        out << "Player 2 Card: " << p2Crd << endl;
    }

    // Exit stage right
    out.close();
    return 0;
}
