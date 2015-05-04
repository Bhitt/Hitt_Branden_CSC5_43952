/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 4, 2015, 8:03 AM
 *      Purpose: craps ver 2
 */

//System Libraries
#include <iostream>//I/O standard
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
unsigned char roll(unsigned char,unsigned char);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Initialize the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    const int SIZE=13;
    int win[SIZE]={},lose[SIZE]={},nThrows[SIZE]={};
    int thwGame=0,maxNThw=0,nGames=36000;
    //Loop on the games and take stats
    for(int game=1;game<=nGames;game++){
        int sum=roll(2,6);
        nThrows[sum]++;
        thwGame=1;
        if(sum==2||sum==3||sum==12)lose[sum]++;
        else if(sum==7||sum==11)win[sum]++;
        else{
            //Keep throwing
            bool rollAgn;
            do{
               
               rollAgn=true;
               int sum2=roll(2,6);
               nThrows[sum]++;
               thwGame++;
               if(sum2==sum){
                   win[sum]++;
                   rollAgn=false;
               }else if(sum2==7){
                   lose[sum]++;
                   rollAgn=false;
               }
            }while(rollAgn==true);
            if(thwGame>maxNThw)maxNThw=thwGame;
        }
    }
    //Output wins and losses
    cout<<"Total number of Games  = "<<nGames<<endl;
    cout<<"Sum Win Loss Total  %Win    %Loss  Avg Throw"<<endl;
    for(int sindx=2;sindx<SIZE;sindx++){
        cout<<setw(2)<<sindx;
        cout<<setw(5)<<win[sindx];
        cout<<setw(5)<<lose[sindx];
        cout<<setw(6)<<win[sindx]+lose[sindx];
        cout<<fixed<<setprecision(2)<<showpoint;
        cout<<setw(7)<<100.0f*win[sindx]/(win[sindx]+lose[sindx])<<"%";
        cout<<setw(7)<<100.0f*lose[sindx]/(win[sindx]+lose[sindx])<<"%";
        cout<<setw(7)<<1.0f*nThrows[sindx]/(win[sindx]+lose[sindx])<<endl;
    }
    cout<<"Max throws in any game = "<<maxNThw;
    //Exit Stage Right
    return 0;
}

unsigned char roll(unsigned char nDie,unsigned char sides){
    unsigned char sum=0;
    for(int die=1;die<=nDie;die++){
        sum+=(rand()%sides+1);
    }
        return sum;
}