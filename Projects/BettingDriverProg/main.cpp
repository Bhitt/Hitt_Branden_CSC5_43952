/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on May 10, 2015, 11:50 PM
 *      Purpose: bets driver program
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void allBet(short &,short &,short &,short &, short,string ,short);
//Execution Begins Here!
int main(int argc, char** argv) {
    short p1=45,p2=45,p3=45,p4=45;
    short pot=20;
    string name="Branden";
    short button=1;
    allBet(p1,p2,p3,p4,pot,name,button);
    cout<<"p1=$"<<p1<<endl;
    cout<<"p2=$"<<p2<<endl;
    cout<<"p3=$"<<p3<<endl;
    cout<<"p4=$"<<p4<<endl;
    return 0;
}
//*********************************************//
//*              All Bet                      *//
//*********************************************//
void allBet(short &a,short &b,short &c,short &d, short p,string z,short fBet){
    //declare stuff
    string w="Tom",t="Howard",f="Phil",gun,garbage;
    short usrBet,curBet,ttlBets=0;
    char usrFold;
    //find the first person to bet
    if(fBet==5) fBet=1;
    if(fBet==1) gun=z;
    if(fBet==2) gun=w;
    if(fBet==3) gun=t;
    if(fBet==4) gun=f;
    curBet=fBet;
    //Round of betting
    cout<<"Betting starts with "<<gun<<endl;
    cout<<"Press Enter Now"<<endl;
    cin.get();//ignore input
    cin.ignore();
    cout<<"*************************"<<endl;
    do{
    if(curBet==1){
        //call player bet
        //increment current bet
        curBet++;
    }
    if(curBet==2){
        //call comp bet
        compBet();
        //increment current bet
        curBet++;
    }
    if(curBet==3){
        //call comp bet
        compBet();
        //increment current bet
        curBet++;
    }
    if(curBet==4){
        //call comp bet
        compBet();
        //increment current bet
        curBet==1;
    }
    }while(ttlBets<4);
}
//*********************************************//
//*             Computer Bet                  *//
//*********************************************//
short compBet(short &plyTtl,short &curBet,char fold){
    //random betting option
    short choice=rand()%4+1;
    //folding option
    if(choice==4) fold='Y';
    //check total money for all-in
    if(choice==1&&curBet>=plyTtl) return 5;
    if(choice==2&&(curBet+5>=plyTtl)) return 5;
    if(choice==3&&(curBet+10>=plyTtl)) return 5;
    //regular bet
    if(choice==1) return 1;
    if(choice==2) return 2;
    if(choice==3) return 3;
}
//*********************************************//
//*               Player Bet                  *//
//*********************************************//
short playBet(short &plyTtl,short &curBet){
    short choice;
    //prompt the user
    cout<<"Now it is your turn to bet. Please enter in 1 to check/call, 2 "<<
            "to make the Minimum bet, 3 to Max bet, or 4 to Fold."<<endl;
    //folding option
    if(choice==4) return 0;
    //check total money for all-in
    if(choice==1&&curBet>=plyTtl) return 5;
    if(choice==2&&(curBet+5>=plyTtl)) return 5;
    if(choice==3&&(curBet+10>=plyTtl)) return 5;
    //regular bet
    if(choice==1) return 1;
    if(choice==2) return 2;
    if(choice==3) return 3;
}