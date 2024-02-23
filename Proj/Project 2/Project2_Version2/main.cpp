/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on February 3, 2024, 3:02 PM
 * Purpose: Creating Card War Game Version 2
 */

// System Libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void disCard(char& p1Crd, char& p1Suit, char& p2Crd, char& p2Suit, int& p1Value, int& p2Value, const string& CARDS, const string& SUITS);
void disBttl(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream& out);
void otFile(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream& out);
void plBttl(int& btlNum, char& strtBtl, char& p1Crd, char& p1Suit, char& p2Crd, char& p2Suit, int& p1Value, int& p2Value, ofstream& out, const string& CARDS, const string& SUITS);

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
            plBttl(btlNum, strtBtl, p1Crd, p1Suit, p2Crd, p2Suit, p1Value, p2Value, out, CARDS, SUITS);
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

    out << "+ Battle " << btlNum << " +" << endl;
    out << "Player 1 Card: " << p1Crd << p1Suit << "(Battle)" << endl;
    out << "Player 2 Card: " << p2Crd << p2Suit << "(Battle)" << endl;
}

void otFile(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream& out) {
    out << "+ Battle " << btlNum << " +" << endl;
    out << "Player 1 Card: " << p1Crd << p1Suit << "(Battle)" << endl;
    out << "Player 2 Card: " << p2Crd << p2Suit << "(Battle)" << endl;
}

void plBttl(int& btlNum, char& strtBtl, char& p1Crd, char& p1Suit, char& p2Crd, char& p2Suit, int& p1Value, int& p2Value, ofstream& out, const string& CARDS, const string& SUITS) {
    disCard(p1Crd, p1Suit, p2Crd, p2Suit, p1Value, p2Value, CARDS, SUITS);
    disBttl(btlNum, p1Crd, p1Suit, p2Crd, p2Suit, out);
    otFile(btlNum, p1Crd, p1Suit, p2Crd, p2Suit, out);

    if (p1Value > p2Value) {
        cout << "Player 1 wins the battle!" << endl;
    } else if (p1Value < p2Value) {
        cout << "Player 2 wins the battle!" << endl;
    } else {
        cout << "Both players tied and got a '" << p1Crd << "'. " << endl;
        cout << "Press 'w' to start a war: ";
        char strtWar;
        cin >> strtWar;

        if (strtWar == 'w') {

        } else {
            cout << "Invalid option. The game will continue as a tie." << endl;
        }
    }
}
