/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 8, 2015, 10:10 AM
 *      Purpose: Find Draft orders for the 4 worst teams
 */

//System Libraries
#include <iostream>//I/O standard
#include <cstdlib>//for random number generator
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
unsigned short draft(int team);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variable
    int team, pick, pick2, pick3, pick4, tPcked=0;
    srand(static_cast<unsigned int>(time(0)));
    //Output
    pick=draft(team);
    tPcked+=1;
    cout<<"The first pick is Team "<<pick<<endl;
    pick2=draft(team);
    cout<<"The second pick is Team "<<pick<<endl;
    pick3=draft(team);
    cout<<"The third pick is Team "<<pick<<endl;
    pick4=draft(team);
    cout<<"The fourth pick is Team "<<pick<<endl;
    return 0;
}
unsigned short draft(int team){
    int repeat=1;
    do{
    int team1=0, team2=0, team3=0, team4=0; 
    int choice=(rand()%40)+1;
    cout<<"choice:"<<choice<<endl;
    if ((choice<21)&&(team1=0)){
        return 1;
    }else if ((choice>=20)&&(choice<31)&&(team2=0)){
        return 2;
    }else if ((choice>=31)&&(choice<37)&&(team3=0)){
        return 3;
    }else if ((choice>=37)&&(choice<41)&&(team4=0)){
        return 4;
    }else{
        repeat=0;
    }
    }while (repeat==0);
}
