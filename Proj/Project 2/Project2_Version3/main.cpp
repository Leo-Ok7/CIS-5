/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on February 5, 2024, 4:38 PM
 * Purpose: Creating Card War Game Version 3
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
void disCard(char& p1Crd, char& p1Suit, char& p2Crd, char& p2Suit, int& p1Value, int& p2Value, const string& CARDS, const string& SUITS);//Deal and Display Cards
void disBttl(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream& out); //Display Battle
void otFile(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream& out); //Write to file
bool plBttl(int& btlNum, char& strtBtl, char& p1Crd, char& p1Suit, char& p2Crd, char& p2Suit, int& p1Value, int& p2Value, ofstream& out, const string& CARDS, const string& SUITS); //Play Battle
void disWar(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream& out); //Display War
bool plWar(int& btlNum, char& strtBtl, char& p1Crd, char& p1Suit, char& p2Crd, char& p2Suit, int& p1Value, int& p2Value, ofstream& out, const string& CARDS, const string& SUITS, int& p1Wins, int& p2Wins); //Play War

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const string CARDS = "23456789TJQKA";
    const string SUITS = "CDHS";

    ofstream out("card.dat", ios::out);
    if (!out.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    int btlNum = 1;
    char strtBtl;

    cout << "+++War Card Game+++" << endl;
    out << "+++War Card Game+++" << endl;

    do {
        cout << "Press 'b' to battle: ";
        cin >> strtBtl;
        cout << endl;

        if (strtBtl == 'b') {
            char p1Crd, p1Suit, p2Crd, p2Suit;
            int p1Value, p2Value;

            // Call the playBattle function and check for a tie or war
            if (!plBttl(btlNum, strtBtl, p1Crd, p1Suit, p2Crd, p2Suit, p1Value, p2Value, out, CARDS, SUITS))
                continue;

            // Check for a war and call the playWar function
            while (plWar(btlNum, strtBtl, p1Crd, p1Suit, p2Crd, p2Suit, p1Value, p2Value, out, CARDS, SUITS)) {
                // Continue the loop until a battle occurs (not a war)
                if (!plBttl(btlNum, strtBtl, p1Crd, p1Suit, p2Crd, p2Suit, p1Value, p2Value, out, CARDS, SUITS))
                    break;
            }
        } else {
            cout << "Invalid option. The game will continue as a tie." << endl;
            continue;
        }

        btlNum++;
        cout << endl;

    } while (strtBtl == 'b' && btlNum <= 52);

    out.close();
    return 0;
}

// Implement the functions
void disCard(char& p1Crd, char& p1Suit, char& p2Crd, char& p2Suit, int& p1Value, int& p2Value, const string& CARDS, const string& SUITS) {
    int p1Idx = rand() % CARDS.size();
    int p2Idx = rand() % CARDS.size();

    p1Crd = CARDS[p1Idx];
    p1Suit = SUITS[p1Idx / 13];

    p2Crd = CARDS[p2Idx];
    p2Suit = SUITS[p2Idx / 13];

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
    cout << setw(10) << "Player 1 Card: " << p1Crd << p1Suit << endl;
    cout << setw(10) << "Player 2 Card: " << p2Crd << p2Suit << endl;
}

void otFile(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream& out) {
    out << "+ Battle " << btlNum << " +" << endl;
    out << "Player 1 Card: " << p1Crd << p1Suit << "(Battle)" << endl;
    out << "Player 2 Card: " << p2Crd << p2Suit << "(Battle)" << endl;
}

bool plBttl(int& btlNum, char& strtBtl, char& p1Crd, char& p1Suit, char& p2Crd, char& p2Suit, int& p1Value, int& p2Value, ofstream& out, const string& CARDS, const string& SUITS) {
    // Deal and display the cards for the battle
    disCard(p1Crd, p1Suit, p2Crd, p2Suit, p1Value, p2Value, CARDS, SUITS);
    disBttl(btlNum, p1Crd, p1Suit, p2Crd, p2Suit, out);
    otFile(btlNum, p1Crd, p1Suit, p2Crd, p2Suit, out);

    // Check for the winner in the battle
    if (p1Value > p2Value) {
        cout << "Player 1 wins the battle!" << endl;
        return true;  // Not a tie or war
    } else if (p1Value < p2Value) {
        cout << "Player 2 wins the battle!" << endl;
        return true;  // Not a tie or war
    } else {
        // Tie scenario, initiate war
        cout << "Both players tied and got a '" << p1Crd << "'. " << endl;
        cout << "Press 'w' to start a war: ";
        cin >> strtBtl;

        return false;  // Indicates a tie or war
    }
}

void disWar(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream& out) {
    cout << "+ War " << btlNum << " +" << endl;
    cout << setw(10) << "Player 1 Card: " << p1Crd << p1Suit << endl;
    cout << setw(10) << "Player 2 Card: " << p2Crd << p2Suit << endl;
}

bool plWar(int& btlNum, char& strtBtl, char& p1Crd, char& p1Suit, char& p2Crd, char& p2Suit, int& p1Value, int& p2Value, ofstream& out, const string& CARDS, const string& SUITS) {
    // Initialize vectors to store the faced-down cards
    vector<char> p1Down(3);
    vector<char> p2Down(3);
    vector<int> p1DownValues(3);
    vector<int> p2DownValues(3);

    // Draw three cards face down for each player
    for (int i = 0; i < 3; ++i) {
        disCard(p1Down[i], p1Suit, p2Down[i], p2Suit, p1DownValues[i], p2DownValues[i], CARDS, SUITS);
    }

    // Draw the fourth card face up
    disCard(p1Crd, p1Suit, p2Crd, p2Suit, p1Value, p2Value, CARDS, SUITS);

    // Check the values of the face-up cards to determine the winner
    if (p1Value > p2Value) {
        cout << "Player 1 wins the war!" << endl;
        return false;  // Indicates a battle, not a war
    } else if (p1Value < p2Value) {
        cout << "Player 2 wins the war!" << endl;
        return false;  // Indicates a battle, not a war
    } else {
        // War continues, display the tied cards
        disWar(btlNum, p1Crd, p1Suit, p2Crd, p2Suit, out);
        cout << "It's a tie in the war!" << endl;
        cout << "Player 1 cards: ";
        for (int i = 0; i < 4; ++i) {
            cout << p1Down[i] << " ";
        }
        cout << endl;

        cout << "Player 2 cards: ";
        for (int i = 0; i < 4; ++i) {
            cout << p2Down[i] << " ";
        }
        cout << endl;

        // Press 'w' to continue the war or any other key to end it
        cout << "Press 'w' to continue the war: ";
        cin >> strtBtl;

        return (strtBtl == 'w');  // Indicates whether to continue the war
    }
}
