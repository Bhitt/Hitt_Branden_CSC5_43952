/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on May 27, 2015, 9:40 AM
 *      Purpose:betting driver
 */

//System Libraries
#include <iostream>//I/O standard
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
bool anteUp(short &, short &, short &);
bool indAnte(short &,short &);
void worth(short,short,short);
bool bet(short &,short &, short &);
void award(short &,short);
bool playBet(short &,short &,short &);
bool compBet(short &,short &,short &);
bool check(short,short,short,short,short);
//Execution Begins Here!
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));//set random seed
    //Declare Variables
    short pl1M=50,pl2M=50;//player money
    short pot=0;//pot total 
    bool skip=false;//skip if there is all in 
    bool button=false;
    //display totals
    worth(pl1M,pl2M,pot);
    //call antes
    skip=anteUp(pl1M,pl2M,pot);
    //display totals
    worth(pl1M,pl2M,pot);
    //2 cards are dealt
    //hand is shown to player
    //call betting round
    if(!skip){
    
    }
    //find winner
    //award pot to winner
    award(pl1M,pot);
    //switch button
    if(button==false) button=true;
    else if(button==true) button=false;
    //display totals
    return 0;
}
//display money totals
void worth(short a,short b,short p){
    cout<<"p1=$"<<a<<" p2=$"<<b<<"pot=$"<<p<<endl;
}
//ante up
bool anteUp(short &a, short &b,short &pot){
    //variables
    bool allIn=false,skip=false;
    //call indAnte
    allIn=indAnte(a,pot);//player 1 ante
    if(allIn==true) skip=true;
    allIn=indAnte(b,pot);//player 2 ante
    if(allIn==true) skip=true;
    //find if skip is needed
    return skip;
}
//individual ante
bool indAnte(short &a, short &p){
    bool allIn, fold=false;
    if(a==0) fold=true;
    if(a>0) a-=5, p+=5;
    if(a==0&&fold==false) allIn=true;
    return allIn;
}
//betting
bool bet(short &pB,short &cB, short &pot, bool button){
    bool check,allIn=false;
    short tally=0;
    short pB=0,cB=0,curBet=0;
    do{
       if(button==true){
           //call player bet
           allIn=playBet();
           tally++;
           if(tally>1)check=check();
       }
       //call computer bet
       allIn=compBet();
       tally++;
       if(tally>1)check=check();
       if(button==false){
           //call player bet
           allIn=playBet();
           tally++;
           check=check();
       }
       //check for raises
       check=check();
    }while(check=false);
    
    return allIn;
}
//reward pot to winner
void award(short &w,short pot){
    w+=pot;
}
//player bet
bool playBet(short &pM,short &curBet,short &pot){
    //variables
    short cho;
    //display current bet
    cout<<"The current bet is $"<<curBet;
    //prompt for bet
    cout<<"Enter in 1-call/check  :"<<endl;
    cout<<"         2-raise/bet $5:"<<endl;
    cout<<"         3-fold        :"<<endl;
    cin>>cho;
    if(cho==1)pM-=curBet,pot+=curBet;
    if(cho==2)curBet+=5, pM-=curBet, pot+=curBet;
    if(cho==3)return true;
    return false;   
}
//comp bet
bool compBet(short &cM,short &curBet,short &pot){
    //variables
    short cho;
    cout<<"It is Phil's turn to bet:"<<endl;
    cho=rand()%3+1;
    if(cho==1){
        cM-=curBet,pot+=curBet;
        if(curBet==0) cout<<"Phil checks."<<endl;
        if(curBet>0) cout<<"Phil calls the bet."<<endl;
    }
    if(cho==2){
        curBet+=5, cM-=curBet, pot+=curBet;
        cout<<"Phil raises $5."<<endl;
    }
    if(cho==3){
        cout<<"Phil folds."<<endl;
        return true;
    }
    if(cM==0) cout<<"Phil is All-In"<<endl;
    return false;
}
//check to see if betting is complete
bool check(short pB,short cB,short pM,short cM,short curBet){
    if(pB==cB)return true;
    if(pM==0)
    return false;
}