/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Purpose:  Final Problems
 * Created on June 9th, 2015
 */

//System Libraries
#include <iostream>//I/O
#include <ctime>// computer time for srand
#include <cstdlib>//rand
#include <fstream>// I/O to file
#include <vector>//vectors
#include <iomanip>//formatting
#include <string>//string compare
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
short check(short , short ,short &);

int main(int argc, char** argv){
    char ready='s',repeat='s';
    cout<<"BABY WHATS YOUR NUMBA?"<<endl;
    cout<<endl;
    cout<<"I am going to guess a number you pick from"<<endl;
    cout<<"1 to 1000 within ten guesses."<<endl;
    do{
    cout<<"Press enter when you are ready:"<<endl;
    cin.get();
    cin.ignore();
    short tally=0;
    bool win=false;
    short guess=0;
    short hiLow=1;
    short start=0,end=1000;
    do{
        tally++;
        guess=check(start,end,hiLow);
        cout<<"Is this your number: "<<guess<<"?"<<endl;
        cout<<"Enter    0: Correct Guess"<<endl;
        cout<<"         1: Too High:"<<endl;
        cout<<"         2: Too Low:"<<endl;
        cout<<"(Total Guesses: "<<tally<<")"<<endl;
        cin>>hiLow;
        if(hiLow==0)win=true;//win
        if(hiLow==1)end=guess;//too high
        if(hiLow==2)start=guess;//too low
        cout<<"*************************"<<endl;
    }while(tally<10&&win==false);
    if(win==false)cout<<"HOW DID YOU BEAT ME? CHEATER!"<<endl;
    if(win==true)cout<<"YOU LOSE! I WIN!"<<endl;
    cout<<"Total guesses: "<<tally<<endl;
    cout<<"Would you like to play again?"<<endl;
    cout<<"Enter in Y for yes or N for no:"<<endl;
    cin>>repeat;
    }while(repeat=='Y'||repeat=='y');
    return 0;
}
short check(short start, short end,short &hiLow){
    //if(hiLow==1){
    short choice=0,change=0;
    change=(end-start)/2;
    choice=end-change;
    return choice;
    
}
