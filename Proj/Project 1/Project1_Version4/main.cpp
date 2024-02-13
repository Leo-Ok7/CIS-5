/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 25, 2024, 4:36 PM
 * Purpose :  Creating Card War Game Version 4
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
    char p1Crd; // Player 1 Card
    char p2Crd; // Player 2 Card
    fstream out;
    string fileName;
    int btlNum = 1; // Tracks the battle number
    int p1Win = 0;  // Tracks Player 1 Wins
    int p2Win = 0;  // Tracks Player 2 Wins
    int p1Value, p2Value; // Value for Player 1 and Player 2 Card
    int p1CrdIdx, p2CrdIdx; // Stores Index of Cards for Player 1 and Player 2

    // Initialize all Variables
    fileName = "card.dat";
    out.open(fileName, ios::out);

    // Map inputs to outputs -> The Process

    // Game Loop
    while (p1Win < numCrds && p2Win < numCrds) {
        // Deal and display player cards
        for (int player = 0; player < numPlyr; player++) {
            p1CrdIdx = rand() % numCrds;
            p1Crd = (p1CrdIdx < 9) ? ('2' + p1CrdIdx) : (p1CrdIdx == 9 ? 'T' : (p1CrdIdx == 10 ? 'J' : (p1CrdIdx == 11 ? 'Q' : (p1CrdIdx == 12 ? 'K' : 'A'))));

            p2CrdIdx  = rand() % numCrds;
            p2Crd = (p2CrdIdx < 9) ? ('2' + p2CrdIdx) : (p2CrdIdx == 9 ? 'T' : (p2CrdIdx == 10 ? 'J' : (p2CrdIdx == 11 ? 'Q' : (p2CrdIdx == 12 ? 'K' : 'A'))));

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

            // Assign values based on the face of the card
            p1Value = (p1Crd >= '2' && p1Crd <= '9') ? (p1Crd - '0') : ((p1Crd == 'T') ? 10 : ((p1Crd == 'J') ? 11 : ((p1Crd == 'Q') ? 12 : ((p1Crd == 'K') ? 13 : 14))));
            p2Value = (p2Crd >= '2' && p2Crd <= '9') ? (p2Crd - '0') : ((p2Crd == 'T') ? 10 : ((p2Crd == 'J') ? 11 : ((p2Crd == 'Q') ? 12 : ((p2Crd == 'K') ? 13 : 14))));

            if (p1Value > p2Value) {
                cout << "Player 1 wins the battle!" << endl;
                p1Win++;
                p2Win--;
            } else if (p1Value < p2Value) {
                cout << "Player 2 wins the battle!" << endl;
                p2Win++;
                p1Win--;
            } else {
                cout << "It's a tie!" << endl;
            }
            btlNum++; // Increase battle number by 1 each time
        }

        // Check for game winner
        if (p1Win == numCrds) {
            cout << "Player 1 wins the game!" << endl;
            break;
        }
        if (p2Win == numCrds) {
            cout << "Player 2 wins the game!" << endl;
            break;
        }
    }

    // Exit stage right
    out.close();
    return 0;
}