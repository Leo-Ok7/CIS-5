/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 11, 2024, 7:30 PM
 * Purpose: Positive and Negative Sums
 */

// System Libraries
#include <iostream>

using namespace std;

int main() {
    // Declare all Variables
    int value;
    int sumPos = 0, sumNeg = 0, sumTtl = 0;
    int cntPos = 0, cntNeg = 0, ttlCnt = 0;

    // Initialize all Variables
    cout << "This program sums 10 +- Integers" << endl;
    cout << "Input 10 +- Integers" << endl;

    // Map inputs to outputs -> The Process
    cin >> value;
    sumPos += (value > 0) ? value : 0;
    sumNeg += (value <= 0) ? value : 0;
    sumTtl += value;
    cntPos += (value > 0) ? 1 : 0;
    cntNeg += (value <= 0) ? 1 : 0;
    ttlCnt++;

    cin >> value;
    sumPos += (value > 0) ? value : 0;
    sumNeg += (value <= 0) ? value : 0;
    sumTtl += value;
    cntPos += (value > 0) ? 1 : 0;
    cntNeg += (value <= 0) ? 1 : 0;
    ttlCnt++;

    cin >> value;
    sumPos += (value > 0) ? value : 0;
    sumNeg += (value <= 0) ? value : 0;
    sumTtl += value;
    cntPos += (value > 0) ? 1 : 0;
    cntNeg += (value <= 0) ? 1 : 0;
    ttlCnt++;

    cin >> value;
    sumPos += (value > 0) ? value : 0;
    sumNeg += (value <= 0) ? value : 0;
    sumTtl += value;
    cntPos += (value > 0) ? 1 : 0;
    cntNeg += (value <= 0) ? 1 : 0;
    ttlCnt++;

    cin >> value;
    sumPos += (value > 0) ? value : 0;
    sumNeg += (value <= 0) ? value : 0;
    sumTtl += value;
    cntPos += (value > 0) ? 1 : 0;
    cntNeg += (value <= 0) ? 1 : 0;
    ttlCnt++;

    cin >> value;
    sumPos += (value > 0) ? value : 0;
    sumNeg += (value <= 0) ? value : 0;
    sumTtl += value;
    cntPos += (value > 0) ? 1 : 0;
    cntNeg += (value <= 0) ? 1 : 0;
    ttlCnt++;

    cin >> value;
    sumPos += (value > 0) ? value : 0;
    sumNeg += (value <= 0) ? value : 0;
    sumTtl += value;
    cntPos += (value > 0) ? 1 : 0;
    cntNeg += (value <= 0) ? 1 : 0;
    ttlCnt++;

    cin >> value;
    sumPos += (value > 0) ? value : 0;
    sumNeg += (value <= 0) ? value : 0;
    sumTtl += value;
    cntPos += (value > 0) ? 1 : 0;
    cntNeg += (value <= 0) ? 1 : 0;
    ttlCnt++;

    cin >> value;
    sumPos += (value > 0) ? value : 0;
    sumNeg += (value <= 0) ? value : 0;
    sumTtl += value;
    cntPos += (value > 0) ? 1 : 0;
    cntNeg += (value <= 0) ? 1 : 0;
    ttlCnt++;

    cin >> value;
    sumPos += (value > 0) ? value : 0;
    sumNeg += (value <= 0) ? value : 0;
    sumTtl += value;
    cntPos += (value > 0) ? 1 : 0;
    cntNeg += (value <= 0) ? 1 : 0;
    ttlCnt++;

    // Display Output
    cout << "Sum of positive numbers: " << sumPos << endl;
    cout << "Average of positive numbers: " << static_cast<float>(sumPos) / cntPos << endl;
    cout << "Sum of non positive numbers: " << sumNeg << endl;
    cout << "Average of non positive numbers: " << static_cast<float>(sumNeg) / cntNeg << endl;
    cout << "Sum of all positive and non positive numbers: " << sumTtl << endl;
    cout << "Average of all numbers: " << static_cast<float>(sumTtl) / ttlCnt << endl;
    
    //Exit stage right
    return 0;
}
