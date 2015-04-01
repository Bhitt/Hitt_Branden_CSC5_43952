/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 1, 2015, 8:10 AM
 *      Purpose: Busted Keypad, I am hungry, find closest temp for food!
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short tAbove=999, tBelow=0, temp,posSet=0;
    //Prompt the user
    cout<<"Input a temperature from 0 to 999:"<<endl;
    cin>>temp;
    //Exhaust Possible temperature choices
    for(int t100=0;t100<=9;t100++){
        for(int t10=0;t10<=9;t10++){
            for(int t1=0;t1<=9;t1++){
                if(t100==1||t10==1||t1==1)continue;
                if(t100==4||t10==4||t1==4)continue;
                if(t100==7||t10==7||t1==7)continue;
                posSet++;
                unsigned int tLoop=t100*100+t10*10+t1;
                unsigned int tDiffA=tLoop-temp;
                unsigned int tDiffB=temp-tLoop;
                if((tDiffA>=0)&&(tDiffA<(tAbove-temp)))tAbove=tLoop;
                if((tDiffB>=0)&&(tDiffB<(temp-tBelow)))tBelow=tLoop;
            }
        }
    }
    //Output the range of temperature settings
    cout<<"The input temperature = "<<temp<<" degrees"<<endl;
    cout<<"The temp on the high side = "<<tAbove<<" degrees"<<endl;
    cout<<"The temp on the low side = "<<tBelow<<" degrees"<<endl;
    cout<<"There are a total of "<<posSet<<" temperature settings"<<endl;
    //Exit Stage Right
    
    return 0;
}