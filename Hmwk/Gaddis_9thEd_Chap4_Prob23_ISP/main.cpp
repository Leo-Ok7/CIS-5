/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 12, 2024, 2:54 PM
 * Purpose: display the total amount due for ISP subscription.
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
    char pck;
    int hrs;
    float perMnth, addHrs, mnthBill;
    //Initialize or input i.e. set variable values
    cout << "ISP Bill" << endl;
    cout << "Input Package and Hours" << endl;
    cin >> pck;
    cin >> hrs;
    
    //Map inputs -> outputs
   switch (pck) {
        case 'A':
            perMnth = 9.95;
            if (hrs <= 10) {
                mnthBill = perMnth;
            } else {
                mnthBill = perMnth + ((hrs - 10) * 2);
            }
            break;
        case 'B':
            perMnth = 14.95;
            if (hrs <= 20) {
                mnthBill = perMnth;
            } else {
                mnthBill = perMnth + ((hrs - 20) * 1);
            }
            break;
        case 'C':
            perMnth = 19.95;
            mnthBill = perMnth;
            break;
        default:
            return 1;
    }
    //Display the outputs
    cout << "Bill = $ " << mnthBill;
    //Exit stage right or left!
    return 0;
}