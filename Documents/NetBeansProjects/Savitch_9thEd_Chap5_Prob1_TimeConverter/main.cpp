/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 29, 2024, 4:15 PM
 * Purpose : program that converts from 24-hour notation to 12-hour notation. 
 */

//System Libraries
#include <iostream>
using namespace std;

// Function Prototypes
void getInput(string &milTime);
bool convertTo12Hour(const string &milTime, int &hour, int &minute, string &ampm);
void displayOutput(const string &milTime, int hour, int minute, const string &ampm);

int main() {
    char choice;

    cout << "Military Time Converter to Standard Time" << endl;
    cout << "Input Military Time hh:mm" << endl;
    do {
        string milTime;
        int hour, minute;
        string ampm;

        // Input without displaying "Input" message
        getInput(milTime);

        // Conversion
        if (convertTo12Hour(milTime, hour, minute, ampm)) {
            // Output
            displayOutput(milTime, hour, minute, ampm);
        }

        // Ask the user if they want to repeat
        cout << "Would you like to convert another time (y/n)" << endl;
        cin >> choice;
 
    } while (choice == 'Y' || choice == 'y');

    return 0;
}

void getInput(string &milTime) {
    cin >> milTime;
}

bool convertTo12Hour(const string &milTime, int &hour, int &minute, string &ampm) {
    if (milTime.length() == 5 && milTime[2] == ':') {
        char hourTen = milTime[0];
        char hourOne = milTime[1];
        char minuteTen = milTime[3];
        char minuteOne = milTime[4];

        if (isdigit(hourTen) && isdigit(hourOne) && isdigit(minuteTen) && isdigit(minuteOne)) {
            hour = (hourTen - '0') * 10 + (hourOne - '0');
            minute = (minuteTen - '0') * 10 + (minuteOne - '0');

            if (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59) {
                if (hour >= 12) {
                    ampm = "PM";
                    if (hour > 12) {
                        hour -= 12;
                    }
                } else {
                    ampm = "AM";
                    if (hour == 0) {
                        hour = 12;
                    }
                }
                return true;
            }
        }
    }

    cout << milTime << " is not a valid time" << endl;
    return false;
}

void displayOutput(const string &milTime, int hour, int minute, const string &ampm) {
    cout << milTime << " = " << hour << ":" << (minute < 10 ? "0" : "") << minute << " " << ampm << endl;
}
