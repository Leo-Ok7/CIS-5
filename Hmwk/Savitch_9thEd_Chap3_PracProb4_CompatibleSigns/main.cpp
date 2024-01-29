/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 14, 2024, 3:21 PM
 * Purpose: Display compatible element signs.
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
    string sign1, sign2, result;
    //Initialize or input i.e. set variable values
    cout << "Horoscope Program which examines compatible signs." << endl;
    cout << "Input 2 signs." << endl;
    cin >> sign1;
    cin >> sign2;
    //Map inputs -> outputs
      if((sign1=="Aries" || sign1=="Leo" || sign1=="Sagittarius") && (sign2=="Aries" || sign2=="Leo" || sign2=="Sagittarius")) {
      result = " are compatible Fire signs.";  
    } else if((sign1=="Taurus" || sign1=="Virgo" || sign1=="Capricorn") && (sign2=="Taurus" || sign2=="Virgo" || sign2=="Capricorn")) {
      result = " are compatible Earth signs."; 
    } else if((sign1=="Gemini" || sign1=="Libra" || sign1=="Aquarius") && (sign2=="Gemini" || sign2=="Libra" || sign2=="Aquarius")) {
      result = " are compatible Air signs.";   
    } else if((sign1=="Cancer" || sign1=="Scorpio" || sign1=="Pisces") && (sign2=="Cancer" || sign2=="Scorpio" || sign2=="Pisces")) {
      result = " are compatible Water signs."; 
    } else {
      result = " are not compatible signs.";
    }
    //Display the outputs
    cout << sign1 << " and " << sign2 << result;
    //Exit stage right or left!
    return 0;
}