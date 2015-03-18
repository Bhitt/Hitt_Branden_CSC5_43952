/* 
 * File:   main.cpp
 * Author: Branden Hitt 
 * Created on March 16, 2015, 2:00 Pm
 *      Purpose: Determine size of total loan and monthly payments
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
    float face, need, inter, dur, month;//face value of loan, amount needed, interest rate, duration, monthly payment
    //Input
    cout<<"This program will determine the size of your loan and monthly payments."<<endl;
    cout<<"Please first enter in the amount you wish to recieve after deducting the interest:"<<endl;
    cin>>need;
    cout<<"Next enter in the percent rate of interest xx %"<<endl;
    cin>>inter;
    cout<<"Last we need the duration of your loan in months:"<<endl;
    cin>>dur;
    //Calculate
    inter*=0.01;
    face=(need/(1-(inter*(dur/12))));//formula to calculate for face value
    month=face/dur;//monthly payment formula
    //Output
    cout<<"Your total loan after adding the interest owed will be $"<<face<<"."<<endl;
    cout<<"The rate you will pay is $"<<month<<" a month for "<<dur<<" months."<<endl;
    //Exit Stage Right
    return 0;
}