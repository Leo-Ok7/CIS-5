/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 3, 2024, 1:00 PM
 * Purpose : Display peas in all pods
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
    //Initialize the Random Number Seed
    
    //Declare all Variables
    int width, height, totalLength;
        
    //Initialize all Variables
    cout << "Press return after entering a number.\n";
    cout << "Enter the width of the area:\n";
    cin >> width;
    cout << "Enter the height of the area:\n";
    cin >> height;
   

    //Map inputs to outputs -> The Process
    
   
   totalLength = width * height; 
   
    //Display Output
   
    
    cout << "If you have ";
    cout << width;
    cout << " feet long area\n";
    cout << "and ";
    cout << height;
    cout << " feet tall area, then\n";
    cout << "you would need ";
    cout << totalLength;
    cout << " feet of fencing.\n";


    //Exit stage right
    return 0;
}
