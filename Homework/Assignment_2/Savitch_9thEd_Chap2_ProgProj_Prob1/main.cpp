/* 
 * File:   main.cpp
 * Author: Branden Hitt 
 * Created on March 15, 2015, 10:19 Pm
 *      Purpose: avoid death by soda pop
 */
//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
const int GPPCNV = 454;
//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int uWght, soda=350, tGram;
    float sSoda;
    //Input
    cout<<"How much do you weigh in lbs?"<<endl;
    cin>>uWght;
    //Calculate
    tGram = uWght*GPPCNV;
    //Output
    cout<<"You may drink "<< sSoda <<" diet soda without dying"<<endl;
    cin.get();
    //Exit Stage Right
    return 0;
}