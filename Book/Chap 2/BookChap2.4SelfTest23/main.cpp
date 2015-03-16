/* 
 * File:   main.cpp
 * Author: Branden Hitt 
 * Created on March 15, 2015, 8:47 Pm
 *      Purpose: write an if/else for passing a test
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
    unsigned int exam, prgDn;
    //Input
    cout<<"Please provide your test score from 1 to 100:"<<endl;
    cin>>exam;
    cout<<"How many of the required 10 programs did you finish?"<<endl;
    cin>>prgDn;
    //Calculate
    if ((exam >= 60) && (prgDn >= 10)){
        cout<< "Passed";
    }
    else 
    {
        cout<<"Failed";
    }
    //Output 
    //Exit Stage Right
    return 0;
}