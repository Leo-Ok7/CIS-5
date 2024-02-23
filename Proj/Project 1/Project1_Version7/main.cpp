/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 29, 2024, 4:33 PM
 * Purpose :  Creating Card War Game Version 7 (Final Version)
 */

// System Libraries
#include <iostream>  // Input-Output Library
#include <fstream>   // File Library
#include <cstdlib>   // srand Library
#include <ctime>     // Time Library
#include <iomanip>   // Format Library
#include <cmath>     // Math Library
#include <string>    // String Library
using namespace std;

// Execution Begins Here
int main(int argc, char** argv) {
    // Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));

    // Declare all Variables
    const int numCrds = 14; // Number of Cards
    const int numPlyr = 2;  // Number of Players
    char p1Crd;             // Player 1 Card
    char p2Crd;             // Player 2 Card
    fstream out;
    string fileName;
    int btlNum; // Tracks the battle number
    float p1Win;  // Tracks Player 1 Wins
    float p2Win;  // Tracks Player 2 Wins
    int p1Value, p2Value; // Value for Player 1 and Player 2 Card
    int p1Idx, p2Idx; // Stores Index of Cards for Player 1 and Player 2
    char strtBtl; // Starts each Battle
    char plAgain; // Play Again after games over
    char strtWar;  // Starts each War
    bool crdsWar; // Enough Cards for War
    // Initialize all Variables
    fileName = "card.dat";  
    out.open(fileName, ios::out);
    btlNum = 1;
    p1Win = 0;
    p2Win = 0;
    // Map inputs to outputs -> The Process
    cout << "+++War Card Game+++" << endl;
    out << "+++War Card Game+++" << endl;

    // Game Loop
    do {
        p1Win = 0; // Reset wins for each game
        p2Win = 0;
        btlNum = 1; // Reset battle number for each game

        // Ask to play battle
        cout << "Press 'b' to battle: ";
        cin >> strtBtl;
        cout << endl;

        while (strtBtl == 'b' && p1Win < numCrds && p2Win < numCrds) {
            // Deal and display player cards
            p1Idx = rand() % numCrds;
            p2Idx = rand() % numCrds;

            // Check if player card index is in bound
            if (p1Idx >= 0 && p1Idx < numCrds && p2Idx >= 0 && p2Idx < numCrds) {
                p1Crd = (p1Idx <= 8) ? ('2' + p1Idx) : ((p1Idx == 9) ? 'T' : (p1Idx == 10) ? 'J' : (p1Idx == 11) ? 'Q' : 'K');
                p2Crd = (p2Idx <= 8) ? ('2' + p2Idx) : ((p2Idx == 9) ? 'T' : (p2Idx == 10) ? 'J' : (p2Idx == 11) ? 'Q' : 'K');
            }

            // Assign values based on the face of the card
            switch (p1Crd) {
                case 'A': p1Value = 14; break;
                case 'K': p1Value = 13; break;
                case 'Q': p1Value = 12; break;
                case 'J': p1Value = 11; break;
                case 'T': p1Value = 10; break;
                default: p1Value = pow(10, p1Crd - '0'); break;
            }

            switch (p2Crd) {
                case 'A': p2Value = 14; break;
                case 'K': p2Value = 13; break;
                case 'Q': p2Value = 12; break;
                case 'J': p2Value = 11; break;
                case 'T': p2Value = 10; break;
                default: p2Value = pow(10, p2Crd - '0'); break;
            }

            // Display Output
            cout << "+ Battle " << btlNum << " +" << endl;
            cout << fixed << setw(10) << "Player 1 Card: " << p1Crd << endl;
            cout << fixed << setw(10) << "Player 2 Card: " << p2Crd << endl;

            // Write the cards to the file
            out << "+ Battle " << btlNum << " +" << endl;
            out << "Player 1 Card: " << to_string(p1Crd) << "(Battle)" << endl;
            out << "Player 2 Card: " << to_string(p2Crd) << "(Battle)" << endl;

            if (p1Value > p2Value) {
                cout << "Player 1 wins the battle!" << endl;
                p1Win++;
            } else if (p1Value < p2Value) {
                cout << "Player 2 wins the battle!" << endl;
                p2Win++;
            } else {
                cout << "Both players tied and got a '" << p1Crd << "'. " << endl;
                cout << "Press 'w' to start a war: " << endl;
                cin >> strtWar;

                if (strtWar == 'w') {
                    // War logic
                    cout << "++War Started!++" << endl;
                    out << "++War Started++" << endl;
                    // Check if both players have enough cards for the war
                    crdsWar = (p1Win + 3 < numCrds) && (p2Win + 3 < numCrds);
                    if (crdsWar) {
                        cout << "-Placing two cards face down for each player-" << endl;
                        // Place the next two cards face down for each player and Recalculate Card Value
                        for (int i = 0; i < 2; i++) {
                            p1Idx = rand() % numCrds;
                            p1Crd = (p1Idx <= 8) ? ('2' + p1Idx) : ((p1Idx == 9) ? 'T' : (p1Idx == 10) ? 'J' : (p1Idx == 11) ? 'Q' : 'K');

                            p2Idx = rand() % numCrds;
                            p2Crd = (p2Idx <= 8) ? ('2' + p2Idx) : ((p2Idx == 9) ? 'T' : (p2Idx == 10) ? 'J' : (p2Idx == 11) ? 'Q' : 'K');

                            // Display and write the cards to the file
                            cout << "Player 1 card face down: " << p1Crd << endl;
                            cout << "Player 2 card face down: " << p2Crd << endl;
                            cout << endl;
                            out << "++War started!++" << endl;
                            out << "Player 1 Card: " << p1Crd << " (face down War)" << endl;
                            out << "Player 2 Card: " << p2Crd << " (face down War)" << endl;
                        }

                        // Place the third card faced up and Recalculate Card Value
                        cout << "-Placing third card face up for each player-" << endl;
                        p1Idx = rand() % numCrds;
                        p1Crd = (p1Idx <= 8) ? ('2' + p1Idx) : ((p1Idx == 9) ? 'T' : (p1Idx == 10) ? 'J' : (p1Idx == 11) ? 'Q' : 'K');

                        p2Idx = rand() % numCrds;
                        p2Crd = (p2Idx <= 8) ? ('2' + p2Idx) : ((p2Idx == 9) ? 'T' : (p2Idx == 10) ? 'J' : (p2Idx == 11) ? 'Q' : 'K');

                        // Display and write the cards to the file
                        cout << "Player 1 card faced up: " << p1Crd << endl;
                        cout << "Player 2 card faced up: " << p2Crd << endl;
                        out << "Player 1 Card: " << p1Crd << " (faced up War)" << endl;
                        out << "Player 2 Card: " << p2Crd << " (faced up War)" << endl;

                        // Recalculate values after new cards are generated
                        switch (p1Crd) {
                            case 'A': p1Value = 14; break;
                            case 'K': p1Value = 13; break;
                            case 'Q': p1Value = 12; break;
                            case 'J': p1Value = 11; break;
                            case 'T': p1Value = 10; break;
                            default: p1Value = p1Crd - '0'; break;
                        }

                        switch (p2Crd) {
                            case 'A': p2Value = 14; break;
                            case 'K': p2Value = 13; break;
                            case 'Q': p2Value = 12; break;
                            case 'J': p2Value = 11; break;
                            case 'T': p2Value = 10; break;
                            default: p2Value = p2Crd - '0'; break;
                        }

                        if (p1Value > p2Value) {
                            cout << "Player 1 wins the war and takes all 3 cards!" << endl;
                            p1Win += 3;
                        } else if (p1Value < p2Value) {
                            cout << "Player 2 wins the war and takes all 3 cards!" << endl;
                            p2Win += 3;
                        } else {
                            cout << "It's a tie in the war! No one wins the cards." << endl;
                        }
                    } else {
                        // Not enough cards for war, the other player wins
                        cout << "One of the players doesn't have enough cards for the war. The other player wins!" << endl;
                    }
                } else {
                    cout << "Invalid option. The game will continue as a tie." << endl;
                    continue;
                }
            }
            btlNum++; // Increase battle number by 1 each time
            cout << endl;

            // Ask to play battle again
            cout << "Press 'b' to battle: ";
            cin >> strtBtl;
            cout << endl;
        }

        // Check for game winner
        if (p1Win == numCrds) {
            cout << "Player 1 wins the game!" << endl;
            out << "Player 1 wins the game!" << endl;
        } else if (p2Win == numCrds) {
            cout << "Player 2 wins the game!" << endl;
            out << "Player 2 wins the game!" << endl;
        }

        // Ask to play game again
        cout << "Press 'y' to play again: ";
        cin >> plAgain;
        cout << endl;

    } while (plAgain == 'y');

    // Exit stage right
    out.close();
    return 0;
}
