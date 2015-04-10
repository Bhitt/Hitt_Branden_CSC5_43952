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
    int a, pick, pick2=0, pick3, pick4, tPcked=0;
    srand(static_cast<unsigned int>(time(0)));
    //Output
    cout<<"**********************************************************"<<endl;
    cout<<"This program will find draft picks for the lowest ranking teams."<<endl;
    cout<<"Balls with numbers on them will be taken from an urn to determine pick order."<<endl;
    cout<<"Team 1 will have 20 balls (1-20) in the urn for coming in last."<<endl;
    cout<<"Team 2 will have 10 balls (21-30) in the urn for coming in second to last."<<endl;
    cout<<"Team 3 will have 6 balls  (31-36) in the urn for coming in third-to last."<<endl;
    cout<<"Team 4 will have 4 balls  (37-40) in the urn for coming in fourth-to-last."<<endl;
    cout<<"**********************************************************"<<endl;
    pick=draft(a);
    tPcked+=1;
    cout<<"The First pick is Team "<<pick<<endl;
    cout<<"**********************************************************"<<endl;
    do{
        pick2=draft(a);
    }while(pick2==pick);
    cout<<"The Second pick is Team "<<pick2<<endl;
    cout<<"**********************************************************"<<endl;
    do{
        pick3=draft(a);
    }while(pick3==pick||pick3==pick2);
    cout<<"The Third pick is Team "<<pick3<<endl;
    cout<<"**********************************************************"<<endl;
    do{
        pick4=draft(a);
    }while(pick4==pick||pick4==pick2||pick4==pick3);
    cout<<"The Fourth pick is Team "<<pick4<<endl;
    return 0;
}
unsigned short draft(int a){
    int choice=(rand()%40)+1;
    cout<<"The Ball picked from the Urn is Ball:"<<choice<<endl;
    if (choice<21){
        return 1;
    }else if ((choice>=20)&&(choice<31)){
        return 2;
    }else if ((choice>=31)&&(choice<37)){
        return 3;
    }else {
        return 4;
    }
}
