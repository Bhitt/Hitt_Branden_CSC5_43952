/* 
 * File:   main.cpp
 * Author: Branden Hitt 
 * Created on March 4, 2015, 8:23 AM
 *      Purpose: Integer sum and product
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
    int num1,num2,sum,prod;
    //Input
    cout<<"Hello. This program can find the sum and product of two integers."<<endl;
    cout<<"Enter in your first integer as xx"<<endl;
    cin>>num1;
    cout<<"Enter in your second integer as xx"<<endl;
    cin>>num2;
    //process
    sum=num1+num2;
    prod=num1*num2;
    //Output
    cout<<"The sum of the two integers is "<<sum<<endl;
    cout<<"The product of the two integers is "<<prod<<endl;
    cout<<"Good-Bye"<<endl;
    //Exit Stage Right
    return 0;
}
