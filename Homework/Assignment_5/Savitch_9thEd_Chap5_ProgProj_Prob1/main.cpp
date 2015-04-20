
/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 20, 2015, 10:30 AM
 *      Purpose: Compute from 24 hour to 12 hour
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void input(short &,short &);
void calc(short &);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    short hour, min;
    //Prompt the user for inputs
    cout<<"This program will convert a 24-hour notation to 12-hour notation."<<endl;
    input(hour,min);
    //cout<<"after input():"<<hour<<":"<<min<<endl;
    //Calculate 
    calc(hour);
    
    return 0;
}

void input(short &a,short &b){
    short in=1;
    do{
        in=1;
        cout<<"Please enter in the hour portion:"<<endl;
        cin>>a;
        cout<<"Next enter in the minute portion:"<<endl;
        cin>>b;
        if(a>24||a<0||b>60||b<0){
            cout<<"Incorrect input. Please try again."<<endl;
            in=0;
        }
    }while(in==0);
}

void calc(short &a){
   
}