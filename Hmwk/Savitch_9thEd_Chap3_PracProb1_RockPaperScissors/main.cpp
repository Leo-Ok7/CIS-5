/* 
 * File:   main.cpp
 * Author: Leo Okdemir
 * Created on January 10, 2024, 1:54 PM
 * Purpose: Rock, paper, scissors game.
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
    char player1, player2;
    string msg;
    
    //Initialize or input i.e. set variable values
    cin>>player1>>player2;
    player1-=player1>=97?32:0;
    player2-=player2>=97?32:0;
    msg="Nothing";
    
   
    
    //Map inputs -> outputs
    msg=player1==player2?"Nobody wins.":msg;
    if (player1 == 'R'){
        if(player2 == 'P')  msg="Paper covers rock.";
        else                msg = "Rock breaks scissors.";
    }else if(player1=='P'){
        if(player2=='R')    msg="Paper covers rock.";
        else                msg="Scissors cuts paper.";
    }else if(player1=='S'){
        if(player2=='R')    msg="Rock breaks scissors.";
        else                msg="Scissors cuts paper.";
    }
    
    //Display the outputs
    cout << "Rock Paper Scissors Game" << endl;
    cout << "Input Player 1 and Player 2 Choices" << endl;
    cout << msg;
    //Exit stage right or left!
    return 0;
}