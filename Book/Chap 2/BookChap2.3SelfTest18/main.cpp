/* 
 * File:   main.cpp
 * Author: Branden Hitt 
 * Created on March 15, 2015, 8:23 Pm
 *      Purpose: output whole number and remainder
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
    int num1, num2, ansr, rem;
    //Input
    cout<<"This program takes 2 numbers, divides them, and gives the answer plus the remainder" <<endl;
    cout<<"Please type the first number:"<<endl;
    cin>>num1;
    cout<<"Now type the second number to be divided by:"<<endl;
    cin>>num2;
    //Calculate
    ansr= num1 / num2;
    rem= num1 % num2;
    //Output Big C
    cout<<"The answer to "<< num1 << " divided by "<< num2 << " is " << ansr <<endl;
    cout<<"with a remainder of "<< rem <<endl;
    //Exit Stage Right
    return 0;
}