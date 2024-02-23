/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 8, 2024, 4:00 PM
 * Purpose : 
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <fstream> 
using namespace std;

//User Libraries

//Global Constants

//Mathematical/Physics/Conversions, Higher dimensioned arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare all Variables
    const int NCARDS=52;//Number of Cards
    fstream out;
    char suit;
    char face;
    
        
    //Initialize all Variables
    out.open("cards.dat",ios::out);
    
    //Map inputs to outputs -> The Process
     for(int card=0;card<NCARDS;card++){
        switch(card/13){
            case 0:suit='S';break;
            case 1:suit='D';break;
            case 2:suit='C';break;
            default:suit='H';
        }
     char cmod=card%13;
        face=cmod==0?'A':
             cmod==1?'2':
             cmod==2?'3':
             cmod==3?'4':
             cmod==4?'5':
             cmod==5?'6':
             cmod==6?'7': 
             cmod==7?'8':
             cmod==8?'9':
             cmod==9?'T':
             cmod==10?'J':
             cmod==11?'Q':'K';
        out<<face<<suit<<endl;
        cout<<face<<suit<<endl;
     }
    
    
    //Display Output
    out.close();



    //Exit stage right
    return 0;
}