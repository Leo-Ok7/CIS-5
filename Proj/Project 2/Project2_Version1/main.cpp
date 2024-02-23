/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on February 2, 2024, 3:12 PM
 * Purpose: Creating Card War Game Version 1
 */

// System Libraries
#include <iostream>  // Input-Output Library
#include <iomanip>   // Format Library
#include <fstream>   // File Library
#include <string>    // String Library
#include <cmath>     // Math Library
#include <cstdlib>   // srand Library
#include <ctime>     // Time Library

using namespace std;

void disCard(char& p1Crd, char& p2Crd, int& p1Value, int& p2Value, int numCrds, ofstream& out, const string& CARDS, const string& SUITS);
void disBttl(int btlNum, char p1Crd, char p2Crd, ofstream& out);
void otFile(int btlNum, char p1Crd, char p2Crd, ofstream& out);
void plBttl(int& btlNum, char& strtBtl, char& p1Crd, char& p2Crd, int& p1Value, int& p2Value, int numCrds, ofstream& out, const string& CARDS, const string& SUITS);

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));

    const int numCrds = 52;
    char p1Crd;
    char p2Crd;
    ofstream out;
    string fileName;
    int btlNum;
    int p1Value, p2Value;
    char strtBtl;
    string CARDS = "23456789TJQKA";
    string SUITS = "CDHS";

    fileName = "card.dat";
    out.open(fileName, ios::out);
    btlNum = 1;

    cout << "+++War Card Game+++" << endl;
    out << "+++War Card Game+++" << endl;

    do {
        cout << "Press 'b' to battle: ";
        cin >> strtBtl;
        cout << endl;

        if (strtBtl == 'b') {
            plBttl(btlNum, strtBtl, p1Crd, p2Crd, p1Value, p2Value, numCrds, out, CARDS, SUITS);
        } else {
            cout << "Invalid option. The game will continue as a tie." << endl;
            continue;
        }

        btlNum++;
        cout << endl;

        cout << "Press 'b' to battle: ";
        cin >> strtBtl;
        cout << endl;

    } while (strtBtl == 'b' && btlNum < numCrds);

    out.close();
    return 0;
}

void disCard(char& p1Crd, char& p2Crd, int& p1Value, int& p2Value, int numCrds, ofstream& out, const string& CARDS, const string& SUITS) {
    int p1Idx = rand() % numCrds;
    int p2Idx = rand() % numCrds;

    // Correct assignments
    p1Crd = CARDS[p1Idx % 13];
    p1Crd = SUITS[p1Idx / 13]; 

    p2Crd = CARDS[p2Idx % 13];
    p2Crd = SUITS[p2Idx / 13]; 

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

    cout << "+ Battle +" << endl;
    cout << fixed << setw(10) << "Player 1 Card: " << p1Crd << endl;
    cout << fixed << setw(10) << "Player 2 Card: " << p2Crd << endl;

    out << "+ Battle +" << endl;
    out << "Player 1 Card: " << p1Crd << "(Battle)" << endl;
    out << "Player 2 Card: " << p2Crd << "(Battle)" << endl;
}

void disBttl(int btlNum, char p1Crd, char p2Crd, ofstream& out) {
    cout << "+ Battle " << btlNum << " +" << endl;
    cout << fixed << setw(10) << "Player 1 Card: " << p1Crd << endl;
    cout << fixed << setw(10) << "Player 2 Card: " << p2Crd << endl;

    out << "+ Battle " << btlNum << " +" << endl;
    out << "Player 1 Card: " << p1Crd << "(Battle)" << endl;
    out << "Player 2 Card: " << p2Crd << "(Battle)" << endl;
}

void otFile(int btlNum, char p1Crd, char p2Crd, ofstream& out) {
    out << "+ Battle " << btlNum << " +" << endl;
    out << "Player 1 Card: " << p1Crd << "(Battle)" << endl;
    out << "Player 2 Card: " << p2Crd << "(Battle)" << endl;
}

void plBttl(int& btlNum, char& strtBtl, char& p1Crd, char& p2Crd, int& p1Value, int& p2Value, int numCrds, ofstream& out, const string& CARDS, const string& SUITS) {
    disCard(p1Crd, p2Crd, p1Value, p2Value, numCrds, out, CARDS, SUITS);
    disBttl(btlNum, p1Crd, p2Crd, out);
    otFile(btlNum, p1Crd, p2Crd, out);

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
