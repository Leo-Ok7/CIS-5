/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 9, 2024, 1:30 PM
 * Purpose: Display how many total calories were consumed.
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
    int cPerBag = 40; // Bag of cookies holds 40 cookies
    int sPerBag = 10; // 10 servings in the bag
    int cPerS = 300; // Serving equals 300 calories
    
    int cksEtn; // cookies eaten
    int cCnsmd; // calories consumed
    //Initialize or input i.e. set variable values
    cout << "Calorie Counter" << endl;
    cout << "How many cookies did you eat?" << endl;
    cin >> cksEtn;
    
    cCnsmd = (cksEtn * cPerS) / (cPerBag/sPerBag);
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "You consumed " << cCnsmd << " calories.";
    
    //Exit stage right or left!
    return 0;
}