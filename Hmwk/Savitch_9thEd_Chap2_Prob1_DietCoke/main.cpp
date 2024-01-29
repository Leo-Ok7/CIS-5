/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 9, 2024, 4:49 PM
 * Purpose: Display the number of cans of soda the user can consume before he/she hits the expiration quantity.
 */
//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float CNVLBSG=45359.2/100;//Conversion lbs to grams CNVLBSG

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float dsrdWt,     //Desired Weight lbs  dsrdWt
          msMass,     //Mass of the Mouse grams  msMass
          msKill,     //Mass of sweetner with kills the mouse grams msKill
          msCokCn,    //Mass of can of diet coke grams mCokCn
          cncnt8n,    //Concentration of Sweetner in Coke Can  Decimal
          wtKill,     //Calculate Wt Kill a Person -> msKill/msMass*dsrdWt in lbs
          dsKill,     //Same calculate converted to grams
          ms1Can;     //Amount of Sweetner in 1 Can of coke grams
    int   nCans;      //How many cans of coke are required to kill the dieter
    
    //Initialize or input i.e. set variable values
    cout<<"Program to calculate the limit of Soda Pop Consumption."<<endl;
    cout<<"Input the desired dieters weight in lbs."<<endl;
    cin>>dsrdWt;
    msMass=35;
    msKill=5;
    msCokCn=350;
    cncnt8n=0.001f;
    

    
    //Map inputs -> outputs
    wtKill=msKill/msMass*dsrdWt;//Simple ratio, proportionality
    dsKill=wtKill*CNVLBSG;      //Conversion to mass
    ms1Can=msCokCn*cncnt8n;     //Calculating the mass of sweetner in a Can
    nCans=dsKill/ms1Can;        //How many cans of coke to cause possilbe death
    
    //Display the outputs
    cout<<"The maximum number of soda pop cans"<<endl;
    cout<<"which can be consumed is "<<nCans<<" cans";

    //Exit stage right or left!
    return 0;
}