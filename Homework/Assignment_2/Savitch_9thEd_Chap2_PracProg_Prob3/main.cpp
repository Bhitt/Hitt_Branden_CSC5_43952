/* 
 * File:   main.cpp
 * Author: Branden Hitt 
 * Created on March 17, 2015, 1:50 Pm
 *      Purpose: mph conversion to seconds and minutes
 */
//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float mph, tot, min, sec; //miles per hour, total minutes(with remainder), minutes, seconds
    //Input
    cout<<"This program will convert your mph on the treadmill into minutes and seconds per hour."<<endl;
    cout<<"Please enter in your mph now:"<<endl;
    cin>>mph; //miles per hour
    //Calculate
    tot=(60/mph);//total minutes with remainder
    min=static_cast<int>(60/mph);//minutes without remainder
    sec=(tot-min)*60;//seconds 
    //Output
    cout<<"Your time is "<<min<<" minutes and "<<sec<<" seconds per mile."<<endl;
    //Exit Stage Right
    return 0;
}