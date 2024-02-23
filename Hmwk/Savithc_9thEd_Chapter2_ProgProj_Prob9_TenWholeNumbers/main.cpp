/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 9, 2024, 5:30 PM
 * Purpose: Positive and Negative Sums
 */

// System Libraries

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Declare all Variables
     int value;
    int sumPos, sumNeg, sumTtl;

    //Initialize all Variables
    cout << "This program sums 10 +- Integers" << endl;
    cout << "Input 10 +- Integers : " << endl;
    sumPos = sumNeg = sumTtl = 0;

    //Map inputs to outputs -> The Process
    cin >> value;
    sumPos += value > 0 ? value : 0;
    sumNeg += value < 0 ? value : 0;
    sumTtl += value;
    cin >> value;
    sumPos += value > 0 ? value : 0;
    sumNeg += value < 0 ? value : 0;
    sumTtl += value;
    cin >> value;
    sumPos += value > 0 ? value : 0;
    sumNeg += value < 0 ? value : 0;
    sumTtl += value;
    cin >> value;
    sumPos += value > 0 ? value : 0;
    sumNeg += value < 0 ? value : 0;
    sumTtl += value;
    cin >> value;
    sumPos += value > 0 ? value : 0;
    sumNeg += value < 0 ? value : 0;
    sumTtl += value;
    cin >> value;
    sumPos += value > 0 ? value : 0;
    sumNeg += value < 0 ? value : 0;
    sumTtl += value;
    cin >> value;
    sumPos += value > 0 ? value : 0;
    sumNeg += value < 0 ? value : 0;
    sumTtl += value;
    cin >> value;
    sumPos += value > 0 ? value : 0;
    sumNeg += value < 0 ? value : 0;
    sumTtl += value;
    cin >> value;
    sumPos += value > 0 ? value : 0;
    sumNeg += value < 0 ? value : 0;
    sumTtl += value;
    cin >> value;
    sumPos += value > 0 ? value : 0;
    sumNeg += value < 0 ? value : 0;
    sumTtl += value;
    

    //Display Output
    cout << "Sum of positive numbers: " << sumPos << endl;
    cout << "Sum of negative numbers: " << sumNeg << endl;
    cout << "Total sum of all numbers: " << sumTtl << endl;
        
    
    //Exit stage right
    return 0;
}
