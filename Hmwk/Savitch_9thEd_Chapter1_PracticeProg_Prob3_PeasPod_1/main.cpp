/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 3, 2024, 1:20 PM
 * Purpose : Display peas in all pods
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Mathematical/Physics/Conversions, Higher dimensioned arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare all Variables
    int number_of_pods, peas_per_pod, total_peas;
        
    //Initialize all Variables
    cout << "Hello\n";
    cout << "Press return after entering a number.\n";
    cout << "Enter the number of pods:\n";
    cin >> number_of_pods;
    cout << "Enter the number of peas in a pod:\n";
    cin >> peas_per_pod;
   

    //Map inputs to outputs -> The Process
    
   
   total_peas = number_of_pods / peas_per_pod; 
    //Display Output
   
    
    cout << "If you have ";
    cout << number_of_pods;
    cout << " pea pods\n";
    cout << "and ";
    cout << peas_per_pod;
    cout << " peas in each pod, then\n";
    cout << "you have ";
    cout << total_peas;
    cout << " peas in all the pods.\n";

    cout << "Good-bye\n";

    //Exit stage right
    return 0;
}