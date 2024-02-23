/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 24, 2024, 4:02 PM
 * Purpose :  Creating Card War Game Version 3
 */


//System Libraries
#include <iostream> //Input-Output Library
#include <fstream>  //File Library
#include <cstdlib>  //srand Library
#include <ctime>    //Time Library
using namespace std;

//User Libraries

//Global Constants

//Mathematical/Physics/Conversions, Higher dimensioned arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
      // Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));

    // Declare all Variables
    const int numCrds = 14; // Number of Cards
    const int numPlyr = 2;  // Number of Players
    const int cardsPP = numCrds / numPlyr; // Cards Per Player
    char p1Crd; // Player 1 Card
    char p2Crd; // Player 2 Card
    fstream out;
    string fileName;
    int btlNum = 1; // Tracks the battle number
    int p1Win = 0;  // Tracks Player 1 Wins
    int p2Win = 0;  // Tracks Player 2 Wins
    int p1Value;    // Value for Player 1 Card
    int p2Value;    // Value for Player 2 Card

    // Initialize all Variables
    fileName = "card.dat";
    out.open(fileName, ios::out);

    // Map inputs to outputs -> The Process

    // Game Loop
    while (p1Win < numCrds && p2Win < numCrds) {
        // Deal and display player cards for Player 1
        int p1CrdIdx = rand() % numCrds;
        if (p1CrdIdx == 0) {
            p1Crd = '2';
        } else if (p1CrdIdx == 1) {
            p1Crd = '3';
        } else if (p1CrdIdx == 2) {
            p1Crd = '4';
        } else if (p1CrdIdx == 3) {
            p1Crd = '5';
        } else if (p1CrdIdx == 4) {
            p1Crd = '6';
        } else if (p1CrdIdx == 5) {
            p1Crd = '7';
        } else if (p1CrdIdx == 6) {
            p1Crd = '8';
        } else if (p1CrdIdx == 7) {
            p1Crd = '9';
        } else if (p1CrdIdx == 8) {
            p1Crd = 'T';
        } else if (p1CrdIdx == 9) {
            p1Crd = 'J';
        } else if (p1CrdIdx == 10) {
            p1Crd = 'Q';
        } else if (p1CrdIdx == 11) {
            p1Crd = 'K';
        } else {
            p1Crd = 'A';
        }

        // Repeat the same for Player 2
        int p2CrdIdx = rand() % numCrds;
        if (p2CrdIdx == 0) {
            p2Crd = '2';
        } else if (p2CrdIdx == 1) {
            p2Crd = '3';
        } else if (p2CrdIdx == 2) {
            p2Crd = '4';
        } else if (p2CrdIdx == 3) {
            p2Crd = '5';
        } else if (p2CrdIdx == 4) {
            p2Crd = '6';
        } else if (p2CrdIdx == 5) {
            p2Crd = '7';
        } else if (p2CrdIdx == 6) {
            p2Crd = '8';
        } else if (p2CrdIdx == 7) {
            p2Crd = '9';
        } else if (p2CrdIdx == 8) {
            p2Crd = 'T';
        } else if (p2CrdIdx == 9) {
            p2Crd = 'J';
        } else if (p2CrdIdx == 10) {
            p2Crd = 'Q';
        } else if (p2CrdIdx == 11) {
            p2Crd = 'K';
        } else {
            p2Crd = 'A';
        }

        // Display Output
        cout << "Player 1 Card: " << p1Crd << endl;
        cout << "Player 2 Card: " << p2Crd << endl;

        // Write the cards to the file
        out << "Player 1 Card: " << p1Crd << endl;
        out << "Player 2 Card: " << p2Crd << endl;

        // Battle section
        cout << "Battle " << btlNum << ":" << endl;
        cout << "Player 1: " << p1Crd << endl;
        cout << "Player 2: " << p2Crd << endl;

       // Assign values based on the face of the card for Player 1
        if (p1Crd >= '2' && p1Crd <= '9') {
            p1Value = p1Crd - '0';
        } else if (p1Crd == 'T') {
            p1Value = 10;
        } else if (p1Crd == 'J') {
            p1Value = 11;
        } else if (p1Crd == 'Q') {
            p1Value = 12;
        } else if (p1Crd == 'K') {
            p1Value = 13;
        } else {
            p1Value = 14;
        }

        // Repeat the same for Player 2
        if (p2Crd >= '2' && p2Crd <= '9') {
            p2Value = p2Crd - '0';
        } else if (p2Crd == 'T') {
            p2Value = 10;
        } else if (p2Crd == 'J') {
            p2Value = 11;
        } else if (p2Crd == 'Q') {
            p2Value = 12;
        } else if (p2Crd == 'K') {
            p2Value = 13;
        } else {
            p2Value = 14;
        }


        if (p1Value > p2Value) {
            cout << "Player 1 wins the battle!" << endl;
            p1Win++;
        } else if (p1Value < p2Value) {
            cout << "Player 2 wins the battle!" << endl;
            p2Win++;
        }
        btlNum++; // Increase battle number by 1 each time
    }

    // Check for game winner
    if (p1Win == numCrds) {
        cout << "Player 1 wins the game!" << endl;
    }
    if (p2Win == numCrds) {
        cout << "Player 2 wins the game!" << endl;
    }

    // Exit stage right
    out.close();
    return 0;
}