/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 8, 2024, 4:00 PM
 * Purpose : 
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <iomanip> //Format Library
#include <fstream> //File Library
using namespace std;

//User Libraries

//Global Constants

//Mathematical/Physics/Conversions, Higher dimensioned arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare all Variables
    const int numCrds = 52; //Number of Cards
    char face[]="A23456789TJQK";
    char suit[]="SDCH";
    fstream out;
    string fileName;
    string strCard = "  ";
    
    //Initialize all Variables
    fileName = "card.dat";  
    out.open(fileName, ios::out);
    
    //Map inputs to outputs -> The Process
    for(unsigned char card=0;card<numCrds;card++){
        strCard[0]=face[card%13];
        strCard[1]=suit[card/13];
        out<<strCard<<endl;
        cout<<strCard<<endl;
    }
    //Display Output
   


    //Exit stage right
    out.close();
    return 0;
}