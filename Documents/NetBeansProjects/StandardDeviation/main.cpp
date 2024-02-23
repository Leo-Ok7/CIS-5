/* 
 * File:   main.cpp
 * Author:
 * Created on:
 * Purpose: Standard Deviation
 */

// System Libraries
#include <iostream>  // Input/Output Library
#include <cstdlib>   // Srand
#include <ctime>     // Time to set random number seed
#include <cmath>     // Math Library
#include <iomanip>   // Format Library
using namespace std;

// Global Constants, no Global Variables are allowed
// Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float MAXRAND = pow(2, 31) - 1;

// Function Prototypes
void init(float[], int);    // Initialize the array
void init2(float[], int);    // Initialize the second array
void print(float[], float[], int); // Print both arrays
float avgX(float[], int);   // Calculate the Average
float stdX(float[], int);   // Calculate the standard deviation

// Execution Begins Here!
int main(int argc, char** argv) {
    // Set the random number seed
    srand(static_cast<unsigned>(time(0)));

    // Declare Variables
    const int SIZE = 20;
    float test[SIZE];
    
    // Initialize or input i.e. set variable values
    init(test, SIZE);

    // Display the outputs
    cout << "The average            = " << fixed << setprecision(7) << avgX(test, SIZE) << endl;
    cout << "The standard deviation = " << fixed << setprecision(7) << stdX(test, SIZE) << endl;

    // Exit stage right or left!
    return 0;
}

void init(float arr[], int size) {
    float values[] = {
        0.0000000, 1.0000000, 2.0000000, 3.0000000, 4.0000000,
        5.0000000, 6.0000000, 7.0000000, 8.0000000, 9.0000000,
        10.0000000, 11.0000000, 12.0000000, 13.0000000, 14.0000000,
        15.0000000, 16.0000000, 17.0000000, 18.0000000, 19.0000000
    };

    for (int i = 0; i < size; i++) {
        arr[i] = values[i];
    }
}



void print(float arr[], int size, int perLine) {
    for (int i = 0; i < size; i++) {
        cout << setw(12) << arr[i];
        if ((i + 1) % perLine == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

float avgX(float arr[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

float stdX(float arr[], int size) {
    float mean = avgX(arr, size);
    float sumSqDiff = 0;
    for (int i = 0; i < size; i++) {
        float diff = arr[i] - mean;
        sumSqDiff += diff * diff;
    }
    return sqrt(sumSqDiff / (size - 1));
}
