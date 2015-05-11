/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on May 10, 2015, 11:50 PM
 *      Purpose: bets driver program
 */

//System Libraries
#include <iostream>//I/O standard
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void allBet(short &,short &,short &,short &, short,string ,short);
short comBet1(short &,short &,char);
void comBet2(short, short &,short &);
//Execution Begins Here!
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
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
    short usrBet,curBet=0,ttlBets=0,curGamb;//
    short playBet,ai1Bet,ai2Bet,ai3Bet;//returned bets
    short usrFold,ai1Fold=0,ai2Fold=0,ai3Fold=0;
    //find who is already out
    if(a==0) usrFold=1;
    if(b==0) ai1Fold=1;
    if(c==0) ai2Fold=1;
    if(d==0) ai3Fold=1;
    //find the first person to bet
    if(fBet==5) fBet=1;
    if(fBet==1) gun=z;
    if(fBet==2) gun=w;
    if(fBet==3) gun=t;
    if(fBet==4) gun=f;
    curGamb=fBet;
    //Round of betting
    cout<<"Betting starts with "<<gun<<endl;
    cout<<"Press Enter Now"<<endl;
    cin.get();//ignore input
    cin.ignore();
    cout<<"*************************"<<endl;
    do{
    if(curGamb==1){
        //call player bet
        //increment current bet
        curGamb++;
    }
    if(curGamb==2){
        //call comp bet
        ai1Bet=comBet1(b,curBet,ai1Fold);
        //increment current bet
        curGamb++;
    }
    if(curGamb==3){
        //call comp bet
        ai2Bet=comBet1(c,curBet,ai2Fold);
        //increment current bet
        curGamb++;
    }
    if(curGamb==4){
        //call comp bet
        ai3Bet=comBet1(d,curBet,ai3Fold);
        //increment current bet
        curGamb==1;
    }
    }while(ttlBets<4);
}
//*********************************************//
//*             Computer Bet 1                *//
//*********************************************//
short comBet1(short &plyTtl,short &curBet,short fold){
    if(fold==1) return 6;//for no bets
    //random betting option
    short choice=rand()%4+1;
    //folding option
    if(choice==4) fold=1;
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
//*             Computer Bet 2                *//
//*********************************************//
void comBet2(short betNum,short &curBet,short &aiMoney){
    if(betNum==1) aiMoney-=curBet;
    if(betNum==2) aiMoney-=(curBet+5),curBet+=5;
    if(betNum==3) aiMoney-=(curBet+10),curBet+=10;
    if(betNum==4) aiMoney=aiMoney;//nothing happens
    if(betNum==5) aiMoney-=aiMoney,curBet+=aiMoney;
    if(betNum==6) aiMoney=aiMoney;//nothing happens
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