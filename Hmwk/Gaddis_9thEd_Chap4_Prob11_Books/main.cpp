/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 12, 2024, 1:25 PM
 * Purpose: Displays the number of points awarded based on amount of purchased books.
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int books, points;
    //Initialize or input i.e. set variable values
    cout << "Book Worm Points" << endl;
    cout << "Input the number of books purchased this month." << endl;
    cin >> books;
    
    //Map inputs -> outputs
if (books == 0) {
    points = 0;
} else if (books == 1) {
    points = 5;
} else if (books == 2) {
    points = 15;
} else if (books == 3) {
    points = 30;
} else if (books >= 4) {
    points = 60;
}
    //Display the outputs
    cout << "Books purchased =  " << books << endl;
    cout << "Points earned   = " << points;
    //Exit stage right or left!
    return 0;
}