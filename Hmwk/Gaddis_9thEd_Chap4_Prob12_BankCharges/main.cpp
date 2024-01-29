/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 12, 2024, 1:47 PM
 * Purpose: Displays the number of points awarded based on amount of purchased books.
 */
/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> // Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float bnkBlnc, nmCks, cksFee, mntFee, lwBal, nwBal;
    //Initialize or input i.e. set variable values
    cout << "Monthly Bank Fees" << endl;
    cout << "Input Current Bank Balance and Number of Checks" << endl;
    cin >> bnkBlnc;
    cin >> nmCks;
    
    //Map inputs -> outputs
    
    if (bnkBlnc < 0) {
    cout << "The account is overdrawn.";
    return 0; // exit the program
}

if (nmCks < 0) {
    cout << "The account is overdrawn.";
    return 0; // exit the program
}

    mntFee = 10;
    
    if(bnkBlnc<=400){
        lwBal = 15;
    } else {
        lwBal = 0;
    }
    
   if (nmCks <= 20) {
   cksFee = 0.1 * nmCks;
   } else if (nmCks <= 39) {
   cksFee = 0.08 * nmCks;
   } else if (nmCks <= 59) {
   cksFee = 0.06 * nmCks;
   } else {
   cksFee = 0.04 * nmCks;
}

    
    nwBal = bnkBlnc - mntFee - cksFee - lwBal;
    //Display the outputs
    cout << "Balance     $    " << fixed << setprecision(2) << setw(5) << bnkBlnc << endl;
    cout << "Check Fee   $    " << fixed << setprecision(2) << setw(5) << cksFee << endl;
    cout << "Monthly Fee $    " << fixed << setprecision(2) << setw(5) << mntFee << endl;
    cout << "Low Balance $    " << fixed << setprecision(2) << setw(5) << lwBal << endl;
    cout << "New Balance $    " << fixed << setprecision(2) << setw(5) << nwBal;
    //Exit stage right or left!
    return 0;
}