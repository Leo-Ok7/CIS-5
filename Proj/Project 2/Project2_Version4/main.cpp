/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on February 7, 2024, 3:06 PM
 * Purpose: Creating Card War Game Version 4
 */

// System Libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// Function prototypes
void disCard(char& p1Crd, char& p1Suit, char& p2Crd, char& p2Suit, float& p1Value, float& p2Value, const string& CARDS, const string& SUITS);
void disBttl(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream& out);
void otFile(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream& out);
bool plBttl(int& btlNum, char& strtBtl, char& p1Crd, char& p1Suit, char& p2Crd, char& p2Suit, float& p1Value, float& p2Value, ofstream& out, const string& CARDS, const string& SUITS, int& p1Wins, int& p2Wins);
void disWar(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream& out);
bool plWar(int& btlNum, char& strtBtl, char& p1Crd, char& p1Suit, char& p2Crd, char& p2Suit, float& p1Value, float& p2Value, ofstream& out, const string& CARDS, const string& SUITS, int& p1Wins, int& p2Wins);

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const string CARDS = "23456789TJQKA";
    const string SUITS = "CDHS";

    ofstream out("card.dat", ios::out);

    int btlNum = 1;
    char strtBtl;

    cout << "+++War Card Game+++" << endl;
    out << "+++War Card Game+++" << endl;

    int p1Wins = 0;  // Counter for Player 1 wins
    int p2Wins = 0;  // Counter for Player 2 wins

    bool continueGame = true;
    bool continueWar;

    while (continueGame) {
        continueWar = true;  // Reset the war flag for each battle

        cout << "Press 'b' to battle: ";
        cin >> strtBtl;
        cout << endl;

        if (strtBtl == 'b') {
            char p1Crd, p1Suit, p2Crd, p2Suit;
            float p1Value, p2Value;

            // Call the playBattle function and check for a tie or war
            if (!plBttl(btlNum, strtBtl, p1Crd, p1Suit, p2Crd, p2Suit, p1Value, p2Value, out, CARDS, SUITS, p1Wins, p2Wins))
                continue;

            // Check for a war and call the playWar function
            while (continueWar && plWar(btlNum, strtBtl, p1Crd, p1Suit, p2Crd, p2Suit, p1Value, p2Value, out, CARDS, SUITS, p1Wins, p2Wins)) {
                // Continue the loop until a battle occurs (not a war)
                continueWar = !plBttl(btlNum, strtBtl, p1Crd, p1Suit, p2Crd, p2Suit, p1Value, p2Value, out, CARDS, SUITS, p1Wins, p2Wins);
            }
        }

        btlNum++;
        cout << endl;

       
        if (p1Wins >= 52) {
            cout << "Player 1 won the Game!";
            continueGame = false;  // Set the flag to exit the loop
        }else if(p2Wins >= 52){
            cout << "Player 2 won the Game!";
            continueGame = false;  // Set the flag to exit the loop
        }
    }
    
    out.close();
    return 0;
}

// Implement the functions
void disCard(char& p1Crd, char& p1Suit, char& p2Crd, char& p2Suit, float& p1Value, float& p2Value, const string& CARDS, const string& SUITS) {
    int p1Idx = rand() % CARDS.size();
    int p2Idx = rand() % CARDS.size();

    p1Crd = CARDS[p1Idx];
    p1Suit = SUITS[p1Idx % 4];  // Use modulo to get the correct suit for player 1

    p2Crd = CARDS[p2Idx];
    p2Suit = SUITS[p2Idx % 4];  // Use modulo to get the correct suit for player 2

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
}


void disBttl(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream& out) {
    cout << "+ Battle " << btlNum << " +" << endl;
    cout << setw(17) << "Player 1 Card: " << p1Crd << p1Suit << endl;
    cout << setw(17) << "Player 2 Card: " << p2Crd << p2Suit << endl;
}

void otFile(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream& out) {
    out << "+ Battle " << btlNum << " +" << endl;
    out << "Player 1 Card: " << p1Crd << p1Suit << "(Battle)" << endl;
    out << "Player 2 Card: " << p2Crd << p2Suit << "(Battle)" << endl;
}

bool plBttl(int& btlNum, char& strtBtl, char& p1Crd, char& p1Suit, char& p2Crd, char& p2Suit, float& p1Value, float& p2Value, ofstream& out, const string& CARDS, const string& SUITS, int& p1Wins, int& p2Wins) {

    // Deal and display the cards for the battle
    disCard(p1Crd, p1Suit, p2Crd, p2Suit, p1Value, p2Value, CARDS, SUITS);
    disBttl(btlNum, p1Crd, p1Suit, p2Crd, p2Suit, out);
    otFile(btlNum, p1Crd, p1Suit, p2Crd, p2Suit, out);

    // Check for the winner in the battle
    if (p1Value > p2Value) {
        cout << "Player 1 wins the battle!" << endl;
        p1Wins++;   // Increment Player 1's wins
        return true;  // Not a tie or war
    } else if (p1Value < p2Value) {
        cout << "Player 2 wins the battle!" << endl;
        p2Wins++;  // Increment Player 2's wins
        return true;  // Not a tie or war
    } else {
        // Tie scenario, initiate war
        cout << "Both players tied and got a '" << p1Crd << "'. " << endl;
        cout << "Press 'w' to start a war: ";
        cin >> strtBtl;

        return (strtBtl == 'w');  // Indicates whether to continue with the war
    }
}

void disWar(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream& out) {
    cout << "++War Started!++" << endl;
    cout << "-Placed three cards face down for each player-" << endl;
    cout << "Faced down cards are hidden" << endl;

    cout << "-Placing fourth card face up for each player-" << endl;
    cout << "Player 1 card faced up: " << p1Crd << endl;
    cout << "Player 2 card faced up: " << p2Crd << endl;
}

bool plWar(int& btlNum, char& strtBtl, char& p1Crd, char& p1Suit, char& p2Crd, char& p2Suit, float& p1Value, float& p2Value, ofstream& out, const string& CARDS, const string& SUITS, int& p1Wins, int& p2Wins) {
    // Check if the user wants to start the war
    if (strtBtl != 'w') {
        return false;  // No war, continue with battles
    }

    // Initialize vectors to store the faced-down cards
    vector<char> p1Down(3);
    vector<char> p2Down(3);
    vector<int> p1DownValues(3);
    vector<int> p2DownValues(3);

    // Draw three cards face down for each player
    for (int i = 0; i < 3; i++) {
        disCard(p1Down[i], p1Suit, p2Down[i], p2Suit, p1DownValues[i], p2DownValues[i], CARDS, SUITS);
    }

    // Draw the fourth card face up
    disCard(p1Crd, p1Suit, p2Crd, p2Suit, p1Value, p2Value, CARDS, SUITS);

    // Display the faced-down cards
    cout << "-Placing three cards faced down..." << endl;
    cout << "Player 1: " << p1Down[0] << "   Player 2: " << p2Down[0] << endl;
    cout << "Player 1: " << p1Down[1] << "   Player 2: " << p2Down[1] << endl;
    cout << "Player 1: " << p1Down[2] << "   Player 2: " << p2Down[2] << endl;

    // Display the fourth card faced up
    cout << "Fourth card faced up..." << endl;
    cout << "Player 1: " << p1Crd << "   Player 2: " << p2Crd << endl;

    // Check the values of the face-up cards to determine the winner
    if (p1Value > p2Value) {
        cout << "Player 1 wins the war and takes all 4 cards!" << endl;
        p1Wins += 4;  // Increment Player 1's wins
    } else if (p1Value < p2Value) {
        cout << "Player 2 wins the war and takes all 4 cards!" << endl;
        p2Wins += 4;  // Increment Player 2's wins
    } else {
        // War continues, prompt to continue the war
        cout << "It's a tie in the war!" << endl;
        cout << "Press 'w' to continue the war: ";
        cin >> strtBtl;
        return (strtBtl == 'w');  // Indicates whether to continue the war
    }

    // Update the number of battles
    btlNum++;

    return false;  // Indicates a battle, not a war
}
