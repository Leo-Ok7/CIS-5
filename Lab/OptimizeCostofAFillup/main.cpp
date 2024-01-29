/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 4, 2024, 1: PM
 * Compare 2 Gas Stations
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Mathematical/Physics/Conversions, Higher dimensioned arrays

//Function Prototypes

//Execution Begins Here
int main( int argc, char** argv) {    
    //Declare Variables
    float mpg;//Miles/Gallon
          fGage//Fuel Gauge Reading
          tnkSize//Tank Size
          fillTnk//Gallons to fill the tank
    //Initialize Variables
    mpg=2.4e1f;//24 miles to the gallon
    fGage=2.5e-1f;//Quarter Tank
    tnkSize=3.06e1f;//Number of gallons in tank 30.6
            
    
    //Map inputs to outputs -> The Process
    fillTnk=tnkSize*(1-fGage);
    
    //Display Results
    cout<<mpg<<" = Fuel Gage Display"<<endl;
    cout<<fGage<<" = Fuel Gauge Display"<<endl;
    cout<<tnkSize<<" = Size of Gas Tank"<<endl;
    cout<<endl<<fillTnk<<" How Many Gallons to Fill Tank"<<endl;
    
    
    //Exit stage right
    return 0;
}