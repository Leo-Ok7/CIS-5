/*
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on February 11, 2024, 2:05 PM
 * Purpose: Creating Card War Game Version 7
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
void disMenu(); // Display Menu
bool valInpt(char &input); // Validate Input
void disCard(char &p1Crd, char &p1Suit, char &p2Crd, char &p2Suit, int &p1Value, int &p2Value, const string &CARDS, const string &SUITS); // Deal and Display Cards
void disBttl(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream &out); // Display Battle
void otFile(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream &out); // Write to file
bool plBttl(int &btlNum, char &strtBtl, char &p1Crd, char &p1Suit, char &p2Crd, char &p2Suit, int &p1Value, int &p2Value, ofstream &out, const string &CARDS, const string &SUITS, int &p1Wins, int &p2Wins); // Play Battle
void disWar(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream &out); // Display War
bool plWar(int &btlNum, char &strtBtl, char &p1Crd, char &p1Suit, char &p2Crd, char &p2Suit, int &p1Value, int &p2Value, ofstream &out, const string &CARDS, const string &SUITS, int &p1Wins, int &p2Wins); // Play War

// Arrays and Vectors
void disArry(const int arr[], int size, ofstream &out); // Display Array
void disVect(const vector<int> &vec, ofstream &out);      // Display Vector
void iniArry(int arr[], int size);                       // Initialize Array
void iniVect(vector<int> &vec, int size);                 // Initialize Vector
void ArryVal(int arr[], int size, ofstream &out);        // Pass Array by Value
bool ArryRef(int arr[], int size, ofstream &out);         // Pass Array by reference
bool VectRef(vector<int> &vec, ofstream &out);            // Pass Vector by Reference
int sumArry(const int arr[], int size);                   // Sum Array
int sumVect(const vector<int> &vec);                      // Sum Vector

// Functions for sorting and searching
void bblSort(int arr[], int size, ofstream &out); // Bubble Sort
void slcSort(int arr[], int size, ofstream &out); // Selection Sort
bool linSrch(const int arr[], int size, int trgt, ofstream &out); // Linear Search
bool binSrch(const int arr[], int size, int trgt, ofstream &out); // Binary Search

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    const string CARDS = "23456789TJQKA";
    const string SUITS = "CDHS";

    ofstream out("card.dat", ios::out);

    int btlNum = 1;
    char strtBtl;

    cout << "+++War Card Game+++" << endl;
    out << "+++War Card Game+++" << endl;

    int p1Wins = 0;
    int p2Wins = 0;

    bool contGme;

    // Initialize arrays and vectors
    const int ARSIZE = 5;
    int intArray[ARSIZE];
    vector<int> intVector;

    iniArry(intArray, ARSIZE);
    iniVect(intVector, ARSIZE);

    // Call functions to demonstrate array and vector operations
    disArry(intArray, ARSIZE, out);
    disVect(intVector, out);

    ArryVal(intArray, ARSIZE, out);

    if (ArryRef(intArray, ARSIZE, out))
    {
        out << "Array changed" << endl;
        disArry(intArray, ARSIZE, out);
    }
    else
    {
        out << "Array didnt change" << endl;
    }

    if (VectRef(intVector, out))
    {
        out << "Vector changed" << endl;
        disVect(intVector, out);
    }
    else
    {
        out << "Vector didnt change" << endl;
    }

    out << "Sum of array elements: " << sumArry(intArray, ARSIZE) << endl;
    out << "Sum of vector elements: " << sumVect(intVector) << endl;

    bblSort(intArray, ARSIZE, out);
    slcSort(intArray, ARSIZE, out);

    // Continue with the rest of the game...

    do
    {
        bool contWar = true;

        disMenu();
        cin >> strtBtl;

        if (!valInpt(strtBtl))
        {
            cout << "Exiting the game." << endl;
            contGme = false;
            break;
        }

        if (strtBtl == 'b')
        {
            char p1Crd, p1Suit, p2Crd, p2Suit;
            int p1Value, p2Value;

            if (!plBttl(btlNum, strtBtl, p1Crd, p1Suit, p2Crd, p2Suit, p1Value, p2Value, out, CARDS, SUITS, p1Wins, p2Wins))
                continue;

            while (contWar && plWar(btlNum, strtBtl, p1Crd, p1Suit, p2Crd, p2Suit, p1Value, p2Value, out, CARDS, SUITS, p1Wins, p2Wins))
{
    // The correct function to call here is plWar, not plBttl
    contWar = plWar(btlNum, strtBtl, p1Crd, p1Suit, p2Crd, p2Suit, p1Value, p2Value, out, CARDS, SUITS, p1Wins, p2Wins);
}

        }

        strtBtl = 'b';
        btlNum++;
        cout << endl;

        if ((p1Wins + p2Wins) >= 52)
        {
            if (p1Wins > p2Wins)
            {
                cout << "Player 1 won the Game!";
            }
            else if (p1Wins < p2Wins)
            {
                cout << "Player 2 won the Game!";
            }
            contGme = false;
        }
        else
        {
            contGme = true;
        }

    } while (contGme);

    out.close();
    return 0;
}

// Function implementations...

void disCard(char &p1Crd, char &p1Suit, char &p2Crd, char &p2Suit, int &p1Value, int &p2Value, const string &CARDS, const string &SUITS)
{
    int p1Idx = rand() % CARDS.size();
    int p2Idx = rand() % CARDS.size();

    p1Crd = CARDS[p1Idx];
    p1Suit = SUITS[p1Idx % 4];

    p2Crd = CARDS[p2Idx];
    p2Suit = SUITS[p2Idx % 4];

    switch (p1Crd)
    {
    case 'A':
        p1Value = 14;
        break;
    case 'K':
        p1Value = 13;
        break;
    case 'Q':
        p1Value = 12;
        break;
    case 'J':
        p1Value = 11;
        break;
    case 'T':
        p1Value = 10;
        break;
    default:
        p1Value = p1Crd - '0';
        break;
    }

    switch (p2Crd)
    {
    case 'A':
        p2Value = 14;
        break;
    case 'K':
        p2Value = 13;
        break;
    case 'Q':
        p2Value = 12;
        break;
    case 'J':
        p2Value = 11;
        break;
    case 'T':
        p2Value = 10;
        break;
    default:
        p2Value = p2Crd - '0';
        break;
    }
}

void disBttl(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream &out)
{
    cout << "+ Battle " << btlNum << " +" << endl;
    cout << setw(17) << "Player 1 Card: " << p1Crd << p1Suit << endl;
    cout << setw(17) << "Player 2 Card: " << p2Crd << p2Suit << endl;

    otFile(btlNum, p1Crd, p1Suit, p2Crd, p2Suit, out);
}

void otFile(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream &out)
{
    out << "+ Battle " << btlNum << " +" << endl;
    out << "Player 1 Card: " << p1Crd << p1Suit << "(Battle)" << endl;
    out << "Player 2 Card: " << p2Crd << p2Suit << "(Battle)" << endl;
}

bool plBttl(int &btlNum, char &strtBtl, char &p1Crd, char &p1Suit, char &p2Crd, char &p2Suit, int &p1Value, int &p2Value, ofstream &out, const string &CARDS, const string &SUITS, int &p1Wins, int &p2Wins)
{
    disCard(p1Crd, p1Suit, p2Crd, p2Suit, p1Value, p2Value, CARDS, SUITS);
    disBttl(btlNum, p1Crd, p1Suit, p2Crd, p2Suit, out);

    if (p1Value > p2Value)
    {
        cout << "Player 1 wins the battle!" << endl;
        p1Wins++;
        return true;
    }
    else if (p1Value < p2Value)
    {
        cout << "Player 2 wins the battle!" << endl;
        p2Wins++;
        return true;
    }
   else
{
    cout << "Both players tied and got a '" << p1Crd << "'. " << endl;
    cout << "Press 'w' to start a war: ";
    cin >> strtBtl;
    // Remove the following line to correctly continue the war
    // strtBtl = 'b';
    return (strtBtl == 'w');
}

}

void disWar(int btlNum, char p1Crd, char p1Suit, char p2Crd, char p2Suit, ofstream &out)
{
    cout << "++War Started!++" << endl;
    cout << "-Placed three cards face down for each player-" << endl;
    cout << "Faced down cards are hidden" << endl;

    cout << "-Placing fourth card face up for each player-" << endl;
    cout << "Player 1 card faced up: " << p1Crd << endl;
    cout << "Player 2 card faced up: " << p2Crd << endl;

    // Write to file for the War as well
    out << "++War Started!++" << endl;
    out << "-Placed three cards face down for each player-" << endl;
    out << "Faced down cards are hidden" << endl;

    out << "-Placing fourth card face up for each player-" << endl;
    out << "Player 1 card faced up: " << p1Crd << endl;
    out << "Player 2 card faced up: " << p2Crd << endl;
}

bool plWar(int &btlNum, char &strtBtl, char &p1Crd, char &p1Suit, char &p2Crd, char &p2Suit, int &p1Value, int &p2Value, ofstream &out, const string &CARDS, const string &SUITS, int &p1Wins, int &p2Wins)
{
    if (strtBtl != 'w')
    {
        return false;
    }

    vector<char> p1Down(3);
    vector<char> p2Down(3);
    vector<int> p1DownValues(3);
    vector<int> p2DownValues(3);

    for (int i = 0; i < 3; i++)
    {
        disCard(p1Down[i], p1Suit, p2Down[i], p2Suit, p1DownValues[i], p2DownValues[i], CARDS, SUITS);
    }

    disCard(p1Crd, p1Suit, p2Crd, p2Suit, p1Value, p2Value, CARDS, SUITS);

    cout << "-Placing three cards faced down..." << endl;
    cout << "Player 1: " << p1Down[0] << "   Player 2: " << p2Down[0] << endl;
    cout << "Player 1: " << p1Down[1] << "   Player 2: " << p2Down[1] << endl;
    cout << "Player 1: " << p1Down[2] << "   Player 2: " << p2Down[2] << endl;

    cout << "Fourth card faced up..." << endl;
    cout << "Player 1: " << p1Crd << "   Player 2: " << p2Crd << endl;

    // Write to file for the War
    out << "-Placing three cards faced down..." << endl;
    out << "Player 1: " << p1Down[0] << "   Player 2: " << p2Down[0] << endl;
    out << "Player 1: " << p1Down[1] << "   Player 2: " << p2Down[1] << endl;
    out << "Player 1: " << p1Down[2] << "   Player 2: " << p2Down[2] << endl;

    out << "Fourth card faced up..." << endl;
    out << "Player 1: " << p1Crd << "   Player 2: " << p2Crd << endl;

    if (p1Value > p2Value)
    {
        cout << "Player 1 wins the war and takes all 4 cards!" << endl;
        p1Wins += 4;
    }
    else if (p1Value < p2Value)
    {
        cout << "Player 2 wins the war and takes all 4 cards!" << endl;
        p2Wins += 4;
    }
    else
    {
        cout << "It's a tie in the war!" << endl;
        cout << "Press 'w' to continue the war: ";
        cin >> strtBtl;
        return (strtBtl == 'w');
    }

    btlNum++;

    return false;
}

void disMenu()
{
    cout << "Press 'b' to battle : ";
}

bool valInpt(char &input)
{
    return (input == 'b' || isalpha(input));
}

void disArry(const int arr[], int size, ofstream &out)
{
    out << "Array elements: ";
    for (int i = 0; i < size; ++i)
    {
        out << arr[i] << " ";
    }
    out << endl;
}

void disVect(const vector<int> &vec, ofstream &out)
{
    out << "Vector elements : ";
    for (int num : vec)
    {
        out << num << " ";
    }
    out << endl;
}

void iniArry(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100;
    }
}

void iniVect(vector<int> &vec, int size)
{
    vec.resize(size);
    for (int i = 0; i < size; ++i)
    {
        vec[i] = rand() % 100;
    }
}

void ArryVal(int arr[], int size, ofstream &out)
{
    out << "Array passed by value : ";
    for (int i = 0; i < size; ++i)
    {
        out << arr[i] << " ";
    }
    out << endl;
}

bool ArryRef(int arr[], int size, ofstream &out)
{
    out << "Changing array by reference : " << endl;
    for (int i = 0; i < size; ++i)
    {
        arr[i] *= 2;
    }
    return true;
}

bool VectRef(vector<int> &vec, ofstream &out)
{
    out << "Changing vector by reference : " << endl;
    for (int &num : vec)
    {
        num *= 2;
    }
    return true;
}

int sumArry(const int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    return sum;
}

int sumVect(const vector<int> &vec)
{
    int sum = 0;
    for (int num : vec)
    {
        sum += num;
    }
    return sum;
}

void bblSort(int arr[], int size, ofstream &out)
{
    out << "Sorting array using Bubble Sort : " << endl;
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    disArry(arr, size, out);
}

void slcSort(int arr[], int size, ofstream &out)
{
    out << "Sorting array using Selection Sort : " << endl;
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndx = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[minIndx])
            {
                minIndx = j;
            }
        }
        swap(arr[i], arr[minIndx]);
    }
    disArry(arr, size, out);
}

bool linSrch(const int arr[], int size, int trgt, ofstream &out)
{
    out << "Searching array using Linear Search : " << endl;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == trgt)
        {
            out << trgt << " found at index " << i << endl;
            return true;
        }
    }
    out << trgt << " not found in the array" << endl;
    return false;
}

bool binSrch(const int arr[], int size, int trgt, ofstream &out)
{
    out << "Searching array using Binary Search : " << endl;
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == trgt)
        {
            out << trgt << " found at index " << mid << endl;
            return true;
        }
        else if (arr[mid] < trgt)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    out << trgt << " not found in the array" << endl;
    return false;
}
