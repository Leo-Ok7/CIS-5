/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 28, 2024, 5:46 PM
 * Purpose :  Creating Card War Game Version 6
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <fstream>  //File Library
#include <cstdlib>  //srand Library
#include <ctime>    //Time Library
#include <iomanip>  //Format Library
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));

    // Declare all Variables
    const int numCrds = 14; // Number of Cards
    const int numPlyr = 2;  // Number of Players
    const int cardsPP = numCrds / numPlyr; // Cards Per Player, also makes it easier to calculate if there are more players
    char p1Crd; // Player 1 Card
    char p2Crd; // Player 2 Card
    fstream out;
    string fileName;
    int btlNum = 1; // Tracks the battle number
    int p1Win = 0;  // Tracks Player 1 Wins
    int p2Win = 0;  // Tracks Player 2 Wins
    int p1Value, p2Value;  // Value for Player 1 and Player 2 Card
    int p1CrdIdx, p2CrdIdx; // Stores Index of Cards for Player 1 and Player 2
    char strtBtl; // Starts each Battle
    char plAgain; // Play Again after the game's over
    char strtWar;  // Starts each War

    // Initialize all Variables
    fileName = "card.dat";  
    out.open(fileName, ios::out);
    
    // Map inputs to outputs -> The Process

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
    for (int player = 0; player < numPlyr; player++) {
        p1CrdIdx = rand() % numCrds;
        p1Crd = (p1CrdIdx <= 8) ? ('2' + p1CrdIdx) : ((p1CrdIdx == 9) ? 'T' : (p1CrdIdx == 10) ? 'J' : (p1CrdIdx == 11) ? 'Q' : 'K');
                
        p2CrdIdx = rand() % numCrds;
        p2Crd = (p2CrdIdx <= 8) ? ('2' + p2CrdIdx) : ((p2CrdIdx == 9) ? 'T' : (p2CrdIdx == 10) ? 'J' : (p2CrdIdx == 11) ? 'Q' : 'K');

        // Display Output
        // Don't Display this if there's a War
        if (p1Crd != p2Crd) {
            // Write the cards to the file
            out << "Player 1 Card: " << p1Crd << endl;
            out << "Player 2 Card: " << p2Crd << endl;

            // Battle section
            cout << "+ Battle " << btlNum << " +" << endl;
            cout << fixed << setw(16) << "Player " << (player % numPlyr + 1) << " Card : " << p1Crd << endl;
            cout << fixed << setw(16) << "Player " << ((player + 1) % numPlyr + 1) << " Card : " << p2Crd << endl;
            cout << endl;
        }
    

            // Assign values based on the face of the card
            p1Value = (p1Crd == 'A') ? 14 : (p1Crd == 'K') ? 13 : (p1Crd == 'Q') ? 12 : (p1Crd == 'J') ? 11 : (p1Crd == 'T') ? 10 : (p1Crd - '0');
            p2Value = (p2Crd == 'A') ? 14 : (p2Crd == 'K') ? 13 : (p2Crd == 'Q') ? 12 : (p2Crd == 'J') ? 11 : (p2Crd == 'T') ? 10 : (p2Crd - '0');

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
                        cout << "++War started!++" << endl;

                        // Check if both players have enough cards for the war
                        if (p1Win + 3 < numCrds && p2Win + 3 < numCrds) {
                            cout << "-Placing two cards face down for each player-" << endl;
                            // Place the next two cards face down for each player
                            for (int i = 0; i < 2; i++) {
                                p1CrdIdx = rand() % numCrds;
                                p2CrdIdx = rand() % numCrds;

                                char p1CrdDown = (p1CrdIdx <= 8) ? ('2' + p1CrdIdx) : ((p1CrdIdx == 9) ? 'T' : (p1CrdIdx == 10) ? 'J' : (p1CrdIdx == 11) ? 'Q' : 'K');
                                char p2CrdDown = (p2CrdIdx <= 8) ? ('2' + p2CrdIdx) : ((p2CrdIdx == 9) ? 'T' : (p2CrdIdx == 10) ? 'J' : (p2CrdIdx == 11) ? 'Q' : 'K');

                                cout << "Player 1 card face down: " << p1CrdDown << endl;
                                cout << "Player 2 card face down: " << p2CrdDown << endl;
                                out << "Player 1 Card: " << p1CrdDown << " (face down)" << endl;
                                out << "Player 2 Card: " << p2CrdDown << " (face down)" << endl;
                            }

                            // Place the third card faced up
                            cout << "-Placing third card faced up for each player-" << endl;
                            p1CrdIdx = rand() % numCrds;
                            p2CrdIdx = rand() % numCrds;

                            char p1CrdUp = (p1CrdIdx <= 8) ? ('2' + p1CrdIdx) : ((p1CrdIdx == 9) ? 'T' : (p1CrdIdx == 10) ? 'J' : (p1CrdIdx == 11) ? 'Q' : 'K');
                            char p2CrdUp = (p2CrdIdx <= 8) ? ('2' + p2CrdIdx) : ((p2CrdIdx == 9) ? 'T' : (p2CrdIdx == 10) ? 'J' : (p2CrdIdx == 11) ? 'Q' : 'K');

                            cout << "Player 1 card faced up: " << p1CrdUp << endl;
                            cout << "Player 2 card faced up: " << p2CrdUp << endl;
                            out << "Player 1 Card: " << p1CrdUp << " (faced up)" << endl;
                            out << "Player 2 Card: " << p2CrdUp << " (faced up)" << endl;

                            int p1Value, p2Value;
                            //Values for 
                            switch (p1CrdUp) {
                                case 'A': p1Value = 14; break;
                                case 'K': p1Value = 13; break;
                                case 'Q': p1Value = 12; break;
                                case 'J': p1Value = 11; break;
                                case 'T': p1Value = 10; break;
                                default: p1Value = (p1CrdUp - '0'); break;
                            }

                            switch (p2CrdUp) {
                                case 'A': p2Value = 14; break;
                                case 'K': p2Value = 13; break;
                                case 'Q': p2Value = 12; break;
                                case 'J': p2Value = 11; break;
                                case 'T': p2Value = 10; break;
                                default: p2Value = (p2CrdUp - '0'); break;
                            }

                            if (p1Value > p2Value) {
                                cout << "Player 1 wins the war and takes all 3 cards!" << endl;
                                p1Win += 4;
                            } else if (p1Value < p2Value) {
                                cout << "Player 2 wins the war and takes all 3 cards!" << endl;
                                p2Win += 4;
                            } else {
                                cout << "It's a tie in the war! No one wins the cards." << endl;
                            }
                        } else {
                            // Not enough cards for war, the other player wins
                            cout << "One of the players doesn't have enough cards for the war. The other player wins!" << endl;
                            break;
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
                break;
            }

            if (p2Win == numCrds) {
                cout << "Player 2 wins the game!" << endl;
                break;
            }
        }

        // Ask to play game again
        cout << "Press 'y' to play again: ";
        cin >> plAgain;

    } while (plAgain == 'y');

    // Exit stage right
    out.close();
    return 0;
}