/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 21, 2015, 5:10 PM
 *      Purpose: determine gross pay
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
    unsigned short hrsWrkd;
    float ratePay, check;
    //Prompt the user for inputs
    cout<<"This program will determine your gross pay."<<endl;
    cout<<"You receive straight-time for the first 40 hours, double time for all"<<endl;
    cout<<"hours worked in excess of 40 hours but less than 50 hours, and triple"<<endl;
    cout<<"time for any hours worked over 50 hours."<<endl;
    cout<<"******************************************"<<endl;
    cout<<"Please enter in your hours worked this week:"<<endl;
    cin>>hrsWrkd;
    cout<<"Next, enter in your rate of pay (per hour):"<<endl;
    cin>>ratePay;
    cout<<"******************************************"<<endl;
    if(hrsWrkd<=40){
        check=hrsWrkd*ratePay;
    }else if(hrsWrkd>40&&hrsWrkd<=50){
        check=40*ratePay+((hrsWrkd-40)*(2*ratePay));
    }else if(hrsWrkd>50){
        check=(40*ratePay)+(10*(2*ratePay))+((hrsWrkd-50)*(3*ratePay));
    }
    //Output 
    cout<<"Your Gross Pay is $"<<check<<endl;
    return 0;
}