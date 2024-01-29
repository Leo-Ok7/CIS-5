/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 16, 2024, 3:36 PM
 * Purpose : Create the Truth Table
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Mathematical/Physics/Conversions, Higher dimensioned arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    bool x, y;

    //Heading
    cout << "X Y !X !Y X||Y X&&Y X^Y X^Y^Y X^Y^X !X||Y !X&&Y !(X&&Y) !(X||Y)" << endl

    //Row 1
    x = true;
    y = true;
    cout << (x ? 'T' : 'F') << " ";
    cout << (y ? 'T' : 'F') << " ";
    cout << (!x ? 'T' : 'F') << " ";
    cout << (!y ? 'T' : 'F') << " ";
    cout << (x || y ? 'T' : 'F') << " ";
    cout << (x && y ? 'T' : 'F') << " ";
    cout << (x ^ y ? 'T' : 'F') << " ";
    cout << (x ^ y ^ y ? 'T' : 'F') << " ";
    cout << (x ^ y ^ x ? 'T' : 'F') << " ";
    cout << (!x || y ? 'T' : 'F') << " ";
    cout << (!x && y ? 'T' : 'F') << " ";
    cout << (!(x && y) ? 'T' : 'F') << " ";
    cout << (!(x || y) ? 'T' : 'F') << endl;
    
    cout << endl;

    //Row 2
    y = false;
    cout << (x ? 'T' : 'F') << " ";
    cout << (y ? 'T' : 'F') << " ";
    cout << (!x ? 'T' : 'F') << " ";
    cout << (!y ? 'T' : 'F') << " ";
    cout << (x || y ? 'T' : 'F') << " ";
    cout << (x && y ? 'T' : 'F') << " ";
    cout << (x ^ y ? 'T' : 'F') << " ";
    cout << (x ^ y ^ y ? 'T' : 'F') << " ";
    cout << (x ^ y ^ x ? 'T' : 'F') << " ";
    cout << (!x || y ? 'T' : 'F') << " ";
    cout << (!x && y ? 'T' : 'F') << " ";
    cout << (!(x && y) ? 'T' : 'F') << " ";
    cout << (!(x || y) ? 'T' : 'F') << endl;

    cout << endl;

    //Row 3
    x = false;
    y = true;
    cout << (x ? 'T' : 'F') << " ";
    cout << (y ? 'T' : 'F') << " ";
    cout << (!x ? 'T' : 'F') << " ";
    cout << (!y ? 'T' : 'F') << " ";
    cout << (x || y ? 'T' : 'F') << " ";
    cout << (x && y ? 'T' : 'F') << " ";
    cout << (x ^ y ? 'T' : 'F') << " ";
    cout << (x ^ y ^ y ? 'T' : 'F') << " ";
    cout << (x ^ y ^ x ? 'T' : 'F') << " ";
    cout << (!x || y ? 'T' : 'F') << " ";
    cout << (!x && y ? 'T' : 'F') << " ";
    cout << (!(x && y) ? 'T' : 'F') << " ";
    cout << (!(x || y) ? 'T' : 'F') << endl;;

    cout << endl;

    //Row 4
    x = false;
    y = false;
    cout << (x ? 'T' : 'F') << " ";
    cout << (y ? 'T' : 'F') << " ";
    cout << (!x ? 'T' : 'F') << " ";
    cout << (!y ? 'T' : 'F') << " ";
    cout << (x || y ? 'T' : 'F') << " ";
    cout << (x && y ? 'T' : 'F') << " ";
    cout << (x ^ y ? 'T' : 'F') << " ";
    cout << (x ^ y ^ y ? 'T' : 'F') << " ";
    cout << (x ^ y ^ x ? 'T' : 'F') << " ";
    cout << (!x || y ? 'T' : 'F') << " ";
    cout << (!x && y ? 'T' : 'F') << " ";
    cout << (!(x && y) ? 'T' : 'F') << " ";
    cout << (!(x || y) ? 'T' : 'F') << endl;

    //Exit the Program
    return 0;
}