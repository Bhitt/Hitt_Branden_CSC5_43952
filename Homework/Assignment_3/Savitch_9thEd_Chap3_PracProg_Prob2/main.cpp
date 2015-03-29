/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 28, 2015, 9:00 PM
 *      Purpose: Find interest due
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
    float intDue, totDue, minPay1, minPay2, minDue, accBal, inter1, inter2, totInt; 
    //Prompt the user for inputs
    cout<<"Please enter in your Account Balance $: "<<endl;
    cin>>accBal;//account balance
    //Calculate
    if (accBal<1000){
        totInt=0.015*accBal;//interest if under 1000
    }else{//interest if over 1000
        inter1=0.015*1000;
        inter2=0.01*(accBal-1000);
        totInt=inter1+inter2;  
    }
    totDue=totInt+accBal;//total amount due
    if (totDue<=10){
        minDue=totDue;
    }else{//minimum payment due
        minPay1=totDue*0.1;//10 percent of amount due
        minPay2=10;//10 dollars due
        if (minPay2>minPay1){//if 10 percent of amount due is less than 10 dollars
            minDue=minPay2;//pay 10 dollars
        }else{
            minDue=minPay1;//pay 10 percent of amount due
        }
    }
    //Output 
    cout<<"Your interest is: $"<<totInt<<endl;
    cout<<"Total Amount Due: $"<<totDue<<endl;
    cout<<"Minimum payment due: $"<<minDue<<endl;
    return 0;
}