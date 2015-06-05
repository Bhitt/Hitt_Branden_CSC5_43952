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
bool bet(short &,short &, short &,bool);
void award(short &,short);
short playBet(short &,short &,short &,short &);
short compBet(short &,short &,short &,short &);
bool check(short,short,short);
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
    //call betting round 1
    if(!skip){
        skip=bet(pl1M,pl2M,pot,button);
    }
    //3 community cards are dealt and shown
    //betting round 2
    if(!skip){
        skip=bet(pl1M,pl2M,pot,button);
    }
    //turn is dealt
    //betting round 3
    if(!skip){
        skip=bet(pl1M,pl2M,pot,button);
    }
    //river dealt
    //final betting round
    if(!skip){
        skip=bet(pl1M,pl2M,pot,button);
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
bool bet(short &pM,short &cM, short &pot,bool button){
    //declare variables
    bool stop;
    short tally=0;//tally to make sure both players bet at least once
    short pB=0,cB=0,curBet=0;//player/computer total bet and current bet
    short allFold;
    do{
       if(button==true){
           //call player bet
           allFold=playBet(pM,pB,curBet,pot);
           tally++;
           if(tally>1)stop=check(pB,cB,curBet);
       }
       //call computer bet
       allFold=compBet(cM,cB,curBet,pot);
       tally++;
       if(tally>1)stop=check(pB,cB,curBet);
       if(button==false){
           //call player bet
           allFold=playBet(pM,pB,curBet,pot);
           tally++;
           stop=check(pB,cB,curBet);
       }
       //check for raises
       stop=check(pB,cB,curBet);
    }while(stop==false);
    
    return allFold;
}
//reward pot to winner
void award(short &w,short pot){
    w+=pot;
}
//player bet
short playBet(short &pM,short &pB,short &curBet,short &pot){
    //variables
    short cho;
    //display current bet
    cout<<"The current bet is $"<<curBet<<endl;
    cout<<"pot= $"<<pot<<endl;
    //prompt for bet
    cout<<"Enter in 1-call/check $"<<curBet<<":"<<endl;
    cout<<"         2-raise/bet $5 :"<<endl;
    cout<<"         3-fold         :"<<endl;
    cin>>cho;
    if(cho==1){
        pM-=curBet,pot+=curBet;
    }
    if(cho==2){
        curBet+=5,pM-=curBet,pot+=curBet;
    }
    if(cho==3)return 1;
    if(pM==0) return 2;
    return 0;   
}
//comp bet
short compBet(short &cM,short &cB,short &curBet,short &pot){
    //variables
    short cho;
    cout<<"The current bet is $"<<curBet<<endl;
    cout<<"pot= $"<<pot<<endl;
    cout<<"It is Phil's turn to bet:"<<endl;
    cho=rand()%3+1;
    if(cho==1){
        cM-=curBet,pot+=curBet;
        if(curBet==0) cout<<"Phil checks."<<endl;
        if(curBet>0) cout<<"Phil calls the bet."<<endl;
    }
    if(cho==2){
        curBet+=5,cM-=curBet,pot+=curBet;
        cout<<"Phil raises $5."<<endl;
    }
    if(cho==3){
        cout<<"Phil folds."<<endl;
        return 1;
    }
    if(cM==0){
        cout<<"Phil is All-In"<<endl;
        return 2;
    }
    return 0;
}
//check to see if betting is complete
bool check(short pB,short cB,short curBet){
    if(pB==curBet&&cB==curBet)return true;
    return false;
}