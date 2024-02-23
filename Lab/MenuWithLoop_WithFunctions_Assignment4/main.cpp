    /* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 20, 2024, 1:34 PM
 * Purpose : Menu with functions for Assignment 4
 */

//System Libraries
#include <iostream>
#include <iomanip> //Format Library
using namespace std;

//User Libraries

//Global Constants

//Mathematical/Physics/Conversions, Higher dimensioned arrays

//Function Prototypes
void prblm1 ();
void prblm2 ();
void prblm3 ();
void prblm4 ();
void prblm5 ();
void prblm6 ();
void prblm7 ();
void prblm8 ();
void prblm9 ();
void prblm10 ();

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare all Variables
    char nMnuItm;
    unsigned short probNum;
    
    //Initialize all Variables
    nMnuItm = 10;
    
    //Display Menu
    do {
        cout << endl << "Input the Problem Number to Run" << endl;
        cout << "Type 1 problem 1 : Sum " << endl;
        cout << "Type 2 problem 2 : Pay in Pennies" << endl;
        cout << "Type 3 problem 3 : Min Max" << endl;
        cout << "Type 1 problem 4 : Rectangle" << endl;
        cout << "Type 2 problem 5 : Pattern" << endl;
        cout << "Type 3 problem 6 : MPG" << endl;
        cout << "Type 1 problem 7 : Fuel Efficiency" << endl;
        cout << "Type 2 problem 8 : Inflation" << endl;
        cout << "Type 3 problem 9 : Estimated Cost" << endl;
        cout << "Type 10 problem 10 : 2 or 3 Max Parameters" << endl;
        cin >> probNum;

        //Execute the Menu/Problem Number
        switch(probNum){
            case 1 : prblm1(); break; 
            case 2 : prblm2(); break;
            case 3 : prblm3(); break;
            case 4 : prblm4(); break;
            case 5 : prblm5(); break;
            case 6 : prblm6(); break;
            case 7 : prblm7(); break;
            case 8 : prblm8(); break;
            case 9 : prblm9(); break;
            case 10 : prblm10(); break;
            default : cout << "Exiting the Menu" << endl;
        }
    } while (probNum > 0 && probNum <= nMnuItm);
    
    return 0;
}
    
    //Display Output

void prblm1() {
    //Declare Variables
    int Input, ttlSum;
    
    //Initialize or input i.e. set variable values
    ttlSum = 0;
    cout << "Input a positive integer value" << endl;
    cin >> Input;
    //Map inputs -> outputs
    for(int counter = 1; counter <= Input; counter++) {
        ttlSum += counter;
    }
    //Display the outputs
    cout << "The total sum from 1 up to the number inputted is : Sum = " << ttlSum;
}

void prblm2() {
    //Declare Variables
    int numDays;
    float earnings = 0.01f;
    //Initialize or input i.e. set variable values
    cout << "Input the number of days worked." << endl;
    cin >> numDays;
    //Map inputs -> outputs
    while (numDays < 1) {
        cin >> numDays;
    }
    
    for (int day = 2; day <= numDays; day++) {
        earnings *= 2; 
        earnings += 0.01;
    }
    

    
    //Display the outputs
    cout << fixed << setprecision(2) << "Pay = $" << earnings;
}

void prblm3(){
   //Declare Variables
    int num, smllst, lrgst;
    //Initialize or input i.e. set variable values
    cout << "Input a series of integers. (Input -99 to signal the end of the series" << endl;
    cin >> num;
    smllst = lrgst = num;
    //Map inputs -> outputs
    
    while (true) {
        cin >> num;

        if (num == -99) {
            break; 
        }

        if (num < smllst) {
            smllst = num;
        } else if (num > lrgst) {
            lrgst = num;
        }
    }
    //Display the outputs
    cout << "Smallest number in the series is " <<  smllst << endl;
    cout << "Largest  number in the series is " <<  lrgst;
}

void prblm4() {
    //Declare Variables
    int lngth;
    char chrctr;
    //Initialize or input i.e. set variable values
    cout << "Input a positive integer no greater than 15 and the character you want to use." << endl;
    cin >> lngth >> chrctr;
    //Map inputs -> outputs
    
    //Display the outputs
      for (int row = 0; row < lngth; row++) {
        for (int col = 0; col < lngth; col++) {
            cout << chrctr;
        } if(row < lngth -1) {
        cout << endl;   
        }
    }
}

void prblm5() {
    //Declare Variables
    int height;
    //Initialize or input i.e. set variable values
    cout << "Input the height for the pattern." << endl;
    cin >> height;
    //Map inputs -> outputs
    for (int row = 1; row <= height; row++) {
        if (row > 1) {
            cout << endl;
        }
        for (int col = 0; col < row; col++) {
            cout << "+";
        }
        cout << endl;
    }

    for (int row = height - 1; row > 0; row--) {
        cout << endl; 
        for (int col = 0; col < row; col++) {
            cout << "+";
        }
        if(row > 1) {
            cout << endl;
        }
    }
}

void prblm6(){
    //Global Constants, no Global Variables are allowed
    const float liter = 0.264179; // Liter to Gallon
    //Declare Variables
    int lGas, nMiles;
    float nMilesG;
    char repeat;
    //Initialize or input i.e. set variable values
    do {
    cout << "Enter number of liters of gasoline:" << endl;
    cout << endl;
    cin >> lGas;
    
    cout << "Enter number of miles traveled:" << endl;
    cout << endl;
    cin >> nMiles;
    
    //Map inputs -> outputs
    nMilesG = nMiles / (lGas * liter) ;
    
    //Display the outputs
    cout << "miles per gallon:" << endl;
    cout << fixed << setprecision(2) << nMilesG << endl;
   
    cout << "Again:" << endl;
    cin >> repeat;
    if (repeat == 'y') {
        cout << endl;  
    }
    
} while (repeat == 'y');
}

void prblm7() {
    //Global Constants, no Global Variables are allowed
    const float liter = 0.264179; // Liter to Gallon
     //Declare Variables
    int lGas, nMiles;
    float nMilesG1, nMilesG2;
    char repeat;
    //Initialize or input i.e. set variable values
    do {
    //Car 1
    cout << "Car 1" << endl;
    cout << "Enter number of liters of gasoline:" << endl;
    cin >> lGas;
    
    cout << "Enter number of miles traveled:" << endl;
    cin >> nMiles;
    
    //Map inputs -> outputs
    nMilesG1 = nMiles / (lGas * liter);
    
    //Display the outputs
    cout << "miles per gallon: " << fixed << setprecision(2) << nMilesG1 << endl;
    cout << endl;

    //Car 2
    cout << "Car 2" << endl;
    cout << "Enter number of liters of gasoline:" << endl;
    cin >> lGas;
    
    cout << "Enter number of miles traveled:" << endl;
    cin >> nMiles;
    
    //Map inputs -> outputs
    nMilesG2 = nMiles / (lGas * liter);
    
    //Display the outputs
    cout << "miles per gallon: " << fixed << setprecision(2) << nMilesG2 << endl;
    cout << endl;

    if(nMilesG1 > nMilesG2) {
        cout << "Car 1 is more fuel efficient" << endl;
        cout << endl;
    }   else {
        cout << "Car 2 is more fuel efficient" << endl;
        cout << endl;
    }
    cout << "Again:" << endl;
    cin >> repeat;
    if (repeat == 'y') {
        cout << endl;  
    }
    
} while (repeat == 'y');
}

void prblm8() {
    //Declare Variables
    float curPrc, oldPrc, inflRt;
    //Initialize or input i.e. set variable values
    char repeat;
     do {
        cout << "Enter current price:" << endl;
        cin >> curPrc;

        cout << "Enter year-ago price:" << endl;
        cin >> oldPrc;

        //Map inputs -> outputs
        inflRt = (curPrc - oldPrc) / oldPrc;
        inflRt *= 100;
        //Display the outputs
        cout << "Inflation rate: " << fixed << setprecision(2) << inflRt << "%" << endl;
        cout << endl;
        cout << "Again:" << endl;
        cin >> repeat;
        if (repeat == 'y') {
        cout << endl;  
    }

    } while (repeat == 'y');
}

void prblm9(){
    //Declare Variables
    float curPrc, oldPrc, inflRt, inflRtP, inflRt1, inflRt2;
    //Initialize or input i.e. set variable values
    char repeat;
     do {
        cout << "Enter current price:" << endl;
        cin >> curPrc;

        cout << "Enter year-ago price:" << endl;
        cin >> oldPrc;

        //Map inputs -> outputs
        inflRt = (curPrc - oldPrc) / oldPrc; //Calculate inflation rate
        inflRtP = 100 * inflRt; //Convert decimal to percentage
        inflRt1 = curPrc * (1 + inflRt);
        inflRt2 = inflRt1 * (1 + inflRt);
        
        //Display the outputs
        cout << "Inflation rate: " << fixed << setprecision(2) << inflRtP << "%" << endl;
        cout << endl;
        cout << "Price in one year: $" << inflRt1 << endl;
        cout << "Price in two year: $" << inflRt2 << endl;
        cout << endl;
        cout << "Again:" << endl;
        cin >> repeat;
        if (repeat == 'y') {
        cout << endl;  
    }

    } while (repeat == 'y');

}

void prblm10(){
    //Declare Variables
    float num1, num2, num3;
    //Initialize or input i.e. set variable values
    cout << "Enter first number:" << endl;
    cin >> num1;
    cout << endl;
    cout << "Enter Second number:" << endl;
    cin >> num2;
    cout << endl;
    cout << "Enter third number:" << endl;
    cin >> num3;
    cout << endl;
    
    //Map inputs -> outputs
    float lrgst2 = num1; // 2 parameter
    if(num2 > lrgst2) {
        lrgst2 = num2;
    }
    
    float lrgst3 = lrgst2;
    if(num3 > lrgst3) {
        lrgst3 = num3;
    }
    //Display the outputs
    cout << "Largest number from two parameter function:" << endl;
    cout << lrgst2 << endl;
    cout << endl;
    cout << "Largest number from three parameter function:" << endl;
    cout << lrgst3 << endl;
}