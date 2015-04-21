
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
void calc(short &,char &);
void output(short,short,char);
//Execution Begins Here!
int main(int argc, char** argv) {
    char cho;
    do{
    //Declare Variables
    short hour, min;
    char period='P';
    //Prompt the user for inputs
    cout<<"This program will convert a 24-hour notation to 12-hour notation."<<endl;
    input(hour,min);
    //cout<<"after input():"<<hour<<":"<<min<<endl;
    //Calculate 
    calc(hour,period);
    //cout<<"after calc():"<<hour<<":"<<min<<endl;
    output(hour,min,period);
    cout<<"Would you like to run this program again?"<<endl;
    cout<<"Enter in Y for yes or N for no:"<<endl;
    cin>>cho;
    }while(cho=='Y'||cho=='y');
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
        if(a>24||a<0||b>61||b<0){
            cout<<"Incorrect input. Please try again."<<endl;
            in=0;
        }
    }while(in==0);
}

void calc(short &a, char &b){
    if(a>12){
        a-=12;
    }else if(a==0){
        a=12;
        b='A';
    }else if(a<12||a==24){
        b='A';
    }
}

void output(short a,short b,char c){
    cout<<"***********************"<<endl;
    cout<<"The new time in 12-hour notation is: "<<a<<":"<<b<<" "<<c<<"M"<<endl;
    cout<<"***********************"<<endl;
}