/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 25, 2015, 10:10 AM
 *      Purpose: Astrology Program (find user's sign and horoscope)
 */

//System Libraries
#include <iostream>//I/O standard
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void round(int a[]);
void deal1(int &c1,int b[]);
void initilz(int [],int);
//Execution Begins Here!
int main(int argc, char** argv) {
    //set random seed
    srand(static_cast<unsigned int>(time(0)));
    //Initialize array for deck
    const int SIZE=53;
    int test[SIZE]={};
    initilz(test,SIZE);
    //call round
    round(test);
    return 0;
}
//Initialize
void initilz(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=i;
    }
}
//round of poker
void round(int a[]){
    int c1,c2;
    cout<<"this is a round of poker"<<endl;
    //deal card 1
    deal1(c1,a);
    cout<<c1<<endl;
    //deal card 2
    deal1(c2,a);
    cout<<c2<<endl;
}
//deal 1 cards
void deal1(int &c1,int b[]){
    char repeat;
    int card;
    do{
    card=rand()%52+1;
    if(b[card]==0){
       repeat='Y'; 
    }else{
        repeat='N';
    }
    }while(repeat=='Y');
    b[card]=0;
    c1=card;
}