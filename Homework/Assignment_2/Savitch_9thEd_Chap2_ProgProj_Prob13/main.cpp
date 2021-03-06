/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 9, 2015, 10:23 AM
 *      Purpose: calculate amount of candy bars to maintain weight
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
    unsigned short wtlbs,htin,ageyrs;//weight in lbs, height in inches, age in years
    char mf;//male or female
    unsigned char cBar=230;//candy bar
    float BMRFem,BMRMale,nCBars;//BMR female, BMR male, number of candy bars
    //Prompt the user for input
    cout<<"How many candy bars will it take"<<endl;
    cout<<"to maintain your weight?"<<endl;
    cout<<"All inputs are integers!!!"<<endl;
    cout<<"Input your weight in lbs:"<<endl;
    cin>>wtlbs;
    cout<<"Input your height in inches:"<<endl;
    cin>>htin;
    cout<<"Input your age in yrs:"<<endl;
    cin>>ageyrs;
    cout<<"Are you male or female? Type m for male or f for female:"<<endl;
    cin>>mf;
    //Calculations
    BMRFem=655+4.3*wtlbs+4.7*htin-4.7*ageyrs;//BMR formula
    BMRMale=66+6.3*wtlbs+12.9*htin-6.8*ageyrs;//BMR formula
    //         Ques       if Male        if Female
    nCBars=((mf=='m')?(BMRMale/cBar):(BMRFem/cBar));
    //Output the results
    cout<<"Your weight = "<<wtlbs<<"(lbs)"<<endl;
    cout<<"Your height = "<<htin<<"(inches)"<<endl;
    cout<<"Your age = "<<ageyrs<<"(years)"<<endl;
    cout<<"Your sex = "<<((mf=='m')?"Male":"Female")<<endl;
    cout<<"You can eat "<<nCBars<<" candy bars per/day"<<endl;
    //Exit stage right
    return 0;
}

