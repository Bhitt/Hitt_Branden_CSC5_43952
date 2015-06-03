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
bool anteUp(short &, short &, short &);
bool indAnte(short &,short &);
void worth(short,short,short,short,short);
bool bet(short &,short &, short &);
void award(short &,short);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    short pl1M=50,pl2M=50;//player money
    short pot=0,button=1;//pot total and dealer button
    bool skip=false;//skip if there is all in 
    //display totals
    worth(pl1M,pl2M,pl3M,pl4M,pot);
    //call antes
    skip=anteUp(pl1M,pl2M,pot);
    //display totals
    worth(pl1M,pl2M,pl3M,pl4M,pot);
    //2 cards are dealt
    //hand is shown to player
    //call betting round
    if(!skip){
    
    }
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
bool bet(short &pM,short &cM, short &pot){
    
}
//reward pot to winner
void award(short &w,short pot){
    w+=pot;
}