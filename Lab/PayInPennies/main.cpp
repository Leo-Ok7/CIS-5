/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 17, 2024, 1:06 PM
 * Purpose : Code-E problem solution
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <fstream>  //File Stream Library
#include <iomanip>  // Format Library
#include <cstdlib>  //For random function
#include <ctime>    //Time Library
#include <cmath>    //Power
using namespace std;

//User Libraries

//Global Constants

//Mathematical/Physics/Conversions, Higher dimensioned arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare all Variables
    unsigned int pyPDay, paySum; //Pay per day, and Daily sum
    unsigned short nDays; //Number of days to run Calculation
   
    //Initialize all Variables
    pyPDay = 1; // In Pennies
    paySum = 0; //In Pennies
    nDays = rand()%31+1;//[1,31]
    
    //Map inputs to outputs -> The Process
    for(int day = 1; day <= nDays; day++) {
        paySum += pyPDay;
        //pyPDay *= 2; //Double each day
        pyPDay<<=1; //Double each day
    }
    
    
    //Display Output
   int dollar = paySum / 100;
   int penny = paySum%100;
   cout << "Recursive Implementation The pay for " << nDays << " days" << endl;
   cout << "$" << setw(10) << dollar << "." 
        << ((penny < 10) ?"0":"")
        << penny << endl;

    //Calculation using bit-shifting or power
   pyPDay = 1;
   paySum = (pyPDay << nDays) -1;
   dollar = paySum / 100;
   penny = paySum%100;
   cout << "Bit Shifting or Power Implementation The pay for " << nDays << " days" << endl;
   cout << "$" << setw(10) << dollar << "." 
        << ((penny < 10) ?"0":"")
        << penny << endl;
   
   //Calculation using the power function
   paySum = pow(2,nDays) -1;
   dollar = paySum / 100;
   penny = paySum%100;
   cout << "CMath Power Implementation The pay for " << nDays << " days" << endl;
   cout << "$" << setw(10) << dollar << "." 
        << ((penny < 10) ?"0":"")
        << penny << endl;
   
   //Exit stage right

    return 0;
}