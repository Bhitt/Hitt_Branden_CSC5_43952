/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 25, 2015, 10:10 AM
 *      Purpose: Astrology Program (find user's sign and horoscope)
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
    unsigned short pin, bal, dCharg, cred, balCred;
    float endBal;
    char over;
    //Prompt the user for inputs
    cout<<"This will help you check if your debit card has exceeded the amount on the card"<<endl;
    cout<<"First enter in your Pin Number (4 alpha-numeric characters):"<<endl;
    cin>>pin;
    cout<<"Next, I need the initial balance on the card:"<<endl;
    cin>>bal;
    cout<<"Next, type in the total of all debits charged during this month: "<<endl;
    cin>>dCharg;
    cout<<"Last, I need the total of all added credits to the card:"<<endl;
    cin>>cred;
    cout<<"**********************************"<<endl;
    //Output 
    balCred=bal+cred;
    //cout<<"balCred:"<<balCred;
    if(balCred>=dCharg){
        endBal=balCred-dCharg;
    }else if(balCred<dCharg){
        endBal=dCharg-balCred;
        over='Y';
        
    }
    if(over=='Y'){
        cout<<"Your new balance is: -$"<<endBal<<endl;
        endBal+=27.75f;
        cout<<"Since your account was overdrawn, a $27.75 fee has been added to your balance."<<endl;
        cout<<"Your new balance, after the added fee, is: -$"<<endBal<<endl;
        cout<<"In order to allow further charges to occur, this card would have to be zeroed"<<endl;
        cout<<"out and a new credit balance applied."<<endl;
    }else{
        cout<<"Your new balance is $"<<endBal<<endl;
    }
    return 0;
}