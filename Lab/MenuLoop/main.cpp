    /* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 16, 2024, 2:00 PM
 * Purpose : Menu Program for Assignment 3
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    // Declare and initialize variables
    char nMnuItm = 8;
    unsigned short probNum = 0;

    // Display Menu
do {
        cout << "This is a Menu Program for Assignment 3" << endl;
        cout << "Input the Problem Number to Run" << endl;
        cout << "Type 1 problem 1 : Sort Names" << endl;
        cout << "Type 2 problem 2 : Books" << endl;
        cout << "Type 3 problem 3 : Bank Charges" << endl;
        cout << "Type 4 problem 4 : Race" << endl;
        cout << "Type 5 problem 5 : ISP" << endl;
        cout << "Type 6 problem 6 : Rock Paper Scissors" << endl;
        cout << "Type 7 problem 7 : Roman Conversion" << endl;
        cout << "Type 8 problem 8 : Compatible Signs" << endl;
        cin >> probNum;


        switch (probNum) {
            case 1: {
                string Nm1, Nm2, Nm3;
                cout << "Sorting Names" << endl;
                cout << "Input 3 names" << endl;
                cin >> Nm1 >> Nm2 >> Nm3;

                if (Nm1 < Nm2 && Nm1 < Nm3) {
                    cout << Nm1 << endl;
                    if (Nm2 < Nm3) {
                        cout << Nm2 << endl;
                        cout << Nm3;
                    } else {
                        cout << Nm3 << endl;
                        cout << Nm2;
                    }
                } else if (Nm2 < Nm1 && Nm2 < Nm3) {
                    cout << Nm2 << endl;
                    if (Nm1 < Nm3) {
                        cout << Nm1 << endl;
                        cout << Nm3;
                    } else {
                        cout << Nm3 << endl;
                        cout << Nm1;
                    }
                } else {
                    cout << Nm3 << endl;
                    if (Nm1 < Nm2) {
                        cout << Nm1 << endl;
                        cout << Nm2;
                    } else {
                        cout << Nm2 << endl;
                        cout << Nm1;
                    }
                }
                break;
            }
            case 2: {
                int books, points;
                cout << "Book Worm Points" << endl;
                cout << "Input the number of books purchased this month." << endl;
                cin >> books;

                if (books == 0) {
                    points = 0;
                } else if (books == 1) {
                    points = 5;
                } else if (books == 2) {
                    points = 15;
                } else if (books == 3) {
                    points = 30;
                } else if (books >= 4) {
                    points = 60;
                }

                cout << "Books purchased =  " << books << endl;
                cout << "Points earned   = " << points;
                break;
            }
            case 3: {
                float bnkBlnc, nmCks, cksFee, mntFee, lwBal, nwBal;
                cout << "Monthly Bank Fees" << endl;
                cout << "Input Current Bank Balance and Number of Checks" << endl;
                cin >> bnkBlnc >> nmCks;

                if (bnkBlnc < 0 || nmCks < 0) {
                    cout << "The account is overdrawn.";
                    return 0;
                }

                mntFee = 10;
                lwBal = (bnkBlnc <= 400) ? 15 : 0;

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

                cout << "Balance     $ " << fixed << setprecision(2) << setw(8) << bnkBlnc << endl;
                cout << "Check Fee   $ " << fixed << setprecision(2) << setw(8) << cksFee << endl;
                cout << "Monthly Fee $ " << fixed << setprecision(2) << setw(8) << mntFee << endl;
                cout << "Low Balance $ " << fixed << setprecision(2) << setw(8) << lwBal << endl;
                cout << "New Balance $ " << fixed << setprecision(2) << setw(8) << nwBal;
                break;
            }
            case 4: {
                int time1, time2, time3;
                string rnr1, rnr2, rnr3;

                cout << "Race Ranking Program" << endl;
                cout << "Input 3 Runners" << endl;
                cin >> rnr1 >> time1 >> rnr2 >> time2 >> rnr3 >> time3;

                if (time1 < time2 && time1 < time3) {
                    cout << rnr1 << "\t" << right << setw(3) << time1 << endl;
                    if (time2 < time3) {
                        cout << rnr2 << "\t" << right << setw(3) << time2 << endl;
                        cout << rnr3 << "\t" << right << setw(3) << time3;
                    } else {
                        cout << rnr3 << "\t" << right << setw(3) << time3 << endl;
                        cout << rnr2 << "\t" << right << setw(3) << time2;
                    }
                } else if (time2 < time1 && time2 < time3) {
                    cout << rnr2 << "\t" << right << setw(3) << time2 << endl;
                    if (time1 < time3) {
                        cout << rnr1 << "\t" << right << setw(3) << time1 << endl;
                        cout << rnr3 << "\t" << right << setw(3) << time3;
                    } else {
                        cout << rnr3 << "\t" << right << setw(3) << time3 << endl;
                        cout << rnr1 << "\t" << right << setw(3) << time1;
                    }
                } else if (time3 < time1 && time3 < time2) {
                    cout << rnr3 << "\t" << right << setw(3) << time3 << endl;
                    if (time1 < time2) {
                        cout << rnr1 << "\t" << right << setw(3) << time1 << endl;
                        cout << rnr2 << "\t" << right << setw(3) << time2;
                    } else {
                        cout << rnr2 << "\t" << right << setw(3) << time2 << endl;
                        cout << rnr1 << "\t" << right << setw(3) << time1;
                    }
                }
                break;
            }
            
                break;
            case 5: {
                char pck;
                int hrs;
                float perMnth, addHrs, mnthBill;

                cout << "ISP Bill" << endl;
                cout << "Input Package and Hours" << endl;
                cin >> pck >> hrs;

                switch (pck) {
                    case 'A':
                        perMnth = 9.95;
                        if (hrs > 10) {
                            mnthBill = perMnth + ((hrs - 10) * 2);
                        } else {
                            mnthBill = perMnth;
                        }
                        break;
                    case 'B':
                        perMnth = 14.95;
                        if (hrs > 20) {
                            mnthBill = perMnth + ((hrs - 20) * 1);
                        } else {
                            mnthBill = perMnth;
                        }
                        break;
                    case 'C':
                        perMnth = 19.95;
                        mnthBill = perMnth;
                        break;
                    default:
                        return 1;
                }
                cout << "Bill = $ " << mnthBill;
                break;
            }
            case 6: {
                char player1, player2;
                string msg;

                cout << "Rock Paper Scissors Game" << endl;
                cout << "Input Player 1 and Player 2 Choices" << endl;
                cin >> player1 >> player2;

                player1 -= (player1 >= 97) ? 32 : 0;
                player2 -= (player2 >= 97) ? 32 : 0;

                msg = (player1 == player2) ? "Nobody wins." : msg;
                if (player1 == 'R') {
                    if (player2 == 'P') {
                        msg = "Paper covers rock.";
                    } else {
                        msg = "Rock breaks scissors.";
                    }
                } else if (player1 == 'P') {
                    if (player2 == 'R') {
                        msg = "Paper covers rock.";
                    } else {
                        msg = "Scissors cuts paper.";
                    }
                } else if (player1 == 'S') {
                    if (player2 == 'R') {
                        msg = "Rock breaks scissors.";
                    } else {
                        msg = "Scissors cuts paper.";
                    }
                }

                cout << msg;
                break;
            }
            case 7: {
                unsigned char n1, n10, n100, n1000;
                unsigned short x;
                string msg;
                cin >> x;
                msg = "";

                if (x < 1000 || x > 3000) {
                    msg = " is Out of Range!";
                } else {
                    n1 = (x) % 10;
                    n10 = (x / 10) % 10;
                    n100 = (x / 100) % 10;
                    n1000 = (x / 1000) % 10;

                    switch (n1000) {
                        case 3:
                            msg += "M";
                        case 2:
                            msg += "M";
                        case 1:
                            msg += "M";
                    };

                    msg += (n100 == 9) ? "CM" :
                           (n100 == 8) ? "DCCC" :
                           (n100 == 7) ? "DCC" :
                           (n100 == 6) ? "DC" :
                           (n100 == 5) ? "D" :
                           (n100 == 4) ? "CD" :
                           (n100 == 3) ? "CCC" :
                           (n100 == 2) ? "CC" :
                           (n100 == 1) ? "C" : "";

                    if (n10 == 9) msg += "XC";
                    if (n10 == 8) msg += "LXXX";
                    if (n10 == 7) msg += "LXX";
                    if (n10 == 6) msg += "LX";
                    if (n10 == 5) msg += "L";
                    if (n10 == 4) msg += "XL";
                    if (n10 == 3) msg += "XXX";
                    if (n10 == 2) msg += "XX";
                    if (n10 == 1) msg += "X";

                    if (n1 == 9) msg += "IX";
                    else if (n1 == 8) msg += "VIII";
                    else if (n1 == 7) msg += "VII";
                    else if (n1 == 6) msg += "VI";
                    else if (n1 == 5) msg += "V";
                    else if (n1 == 4) msg += "IV";
                    else if (n1 == 3) msg += "III";
                    else if (n1 == 1) msg += "I";

                    msg = " is equal to " + msg;
                }

                cout << "Arabic to Roman numeral conversion." << endl;
                cout << "Input the integer to convert." << endl;
                cout << x << msg;
                break;
            }
            case 8: {
                string sign1, sign2, result;

                cout << "Horoscope Program which examines compatible signs." << endl;
                cout << "Input 2 signs." << endl;
                cin >> sign1 >> sign2;

                if ((sign1 == "Aries" || sign1 == "Leo" || sign1 == "Sagittarius") &&
                    (sign2 == "Aries" || sign2 == "Leo" || sign2 == "Sagittarius")) {
                    result = " are compatible Fire signs.";
                } else if ((sign1 == "Taurus" || sign1 == "Virgo" || sign1 == "Capricorn") &&
                           (sign2 == "Taurus" || sign2 == "Virgo" || sign2 == "Capricorn")) {
                    result = " are compatible Earth signs.";
                } else if ((sign1 == "Gemini" || sign1 == "Libra" || sign1 == "Aquarius") &&
                           (sign2 == "Gemini" || sign2 == "Libra" || sign2 == "Aquarius")) {
                    result = " are compatible Air signs.";
                } else if ((sign1 == "Cancer" || sign1 == "Scorpio" || sign1 == "Pisces") &&
                           (sign2 == "Cancer" || sign2 == "Scorpio" || sign2 == "Pisces")) {
                    result = " are compatible Water signs.";
                } else {
                    result = " are not compatible signs.";
                }

                cout << sign1 << " and " << sign2 << result;
                
                break;
            }
               default:    
                cout << "Exiting the Menu" << endl;
        }
} while (probNum > 0 && probNum <= nMnuItm);
             

    return 0;
}