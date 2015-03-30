/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 29, 2015, 10:40 PM
 *      Purpose: Blackjack hand value
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    short numCard,totVal=0;
    char card1,card2,card3,card4;
    //Prompt the user for inputs
    cout<<"How many cards do you have: (2,3,4,5)"<<endl;
    cin>>numCard;
    switch (numCard){//checks for amount of cards in hand
        case 2:
            cout<<"Please enter the card values.(2-9 or T,J,Q,K,A):"<<endl;
            cout<<"What is the value of the first card?"<<endl;
            cin>>card1;
            cout<<"What is the value of the second card?"<<endl;
            cin>>card2;
            if (card1=='t' || card1=='T' || card1=='j' || card1=='J' || 
                    card1=='q' || card1=='Q'|| card1=='k' || card1=='K' || card1=='a'){
                totVal+=2;
            }else {
                totVal+=card1;
            }
            totVal+=card2;
            cout<<"Your total value is "<<totVal<<endl;
            break;
        case 3:
        case 4:
        case 5:
        default:
            cout<<"Invalid entry"<<endl;
    }
    
    return 0;
}