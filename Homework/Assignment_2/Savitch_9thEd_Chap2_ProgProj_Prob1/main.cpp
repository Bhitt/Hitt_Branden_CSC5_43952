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
const int GPPCNV = 454;//grams per pound

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int uWght, soda=350, tGram;//user weight, soda in grams, total weight of user in grams
    float lethdos, sSoda;//lethal amount of sweetener, safe amount of soda
    char ans;//answer to yes or no repeat
    const float SWTCNV = 0.001;//sweetener conversion
    //Input
    do{
    cout<<"How much will your end weight be in lbs after you are done dieting?"<<endl;
    cin>>uWght;
    //Calculate
    tGram = uWght*GPPCNV;
    lethdos = tGram/7;
    sSoda = (lethdos/(SWTCNV*soda))-1;
    //Output
    cout<<"You may drink "<< sSoda <<" cans of diet soda without dying"<<endl;
    cout<<"Would you like to run this program again?"<<endl;
    cout<<"Type Y for yes, or N for no. Then hit return"<<endl;
    cin>>ans;
    } while (ans=='Y'||ans=='y');
    cin.get();
    //Exit Stage Right
    return 0;
}