/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on May 27, 2015, 9:40 AM
 *      Purpose:betting driver
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
bool anteUp(short &, short &, short &, short &, short &);
bool indAnte(short &,short &);
void worth(short,short,short,short,short);
void allBet(short &, short &, short &, short &, short &,short);
void award(short &,short);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    short pl1M=50,pl2M=50,pl3M=50,pl4M=50;//player money
    short pot=0,button=1;//pot total and dealer button
    //bool skip=false;//skip if there is all in at ante
    //display totals
    worth(pl1M,pl2M,pl3M,pl4M,pot);
    //call antes
    //skip=anteUp(pl1M,pl2M,pl3M,pl4M,pot);
    //display totals
    worth(pl1M,pl2M,pl3M,pl4M,pot);
    //cards are dealt
    //hand is shown to player
    //call betting round
    //if(!skip){
    allBet(pl1M,pl2M,pl3M,pl4M,pot,button);
    //}
    //find winner
    //award pot to winner
    award(pl1M,pot);
    //display totals
    return 0;
}
//display money totals
void worth(short a,short b,short c,short d,short p){
    cout<<"p1=$"<<a<<" p2=$"<<b<<" p3=$"<<c<<" p4=$"<<d<<endl;
    cout<<"pot=$"<<p<<endl;
}
//ante up
bool anteUp(short &a, short &b, short &c, short &d, short &pot){
    //variables
    bool allIn=false,skip=false;
    //call indAnte
    allIn=indAnte(a,pot);//player 1 ante
    if(allIn==true) skip=true;
    allIn=indAnte(b,pot);//player 2 ante
    if(allIn==true) skip=true;
    allIn=indAnte(c,pot);//player 3 ante
    if(allIn==true) skip=true;
    allIn=indAnte(d,pot);//player 4 ante
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
//all bet
void allBet(short &p1,short &p2,short &p3,short &p4,short &p5,short dButton){
    //declare variables
    short plFold=0,ai1Fold=0,ai2Fold=0,ai3Fold=0;
    short gun;
    //check for busted players
    if(p1==0) plFold=1;
    if(p2==0) ai1Fold=1;
    if(p3==0) ai2Fold=1;
    if(p4==0) ai3Fold=1;
    //find who goes first
    gun=dButton;
    
}
//reward pot to winner
void award(short &w,short pot){
    w+=pot;
}