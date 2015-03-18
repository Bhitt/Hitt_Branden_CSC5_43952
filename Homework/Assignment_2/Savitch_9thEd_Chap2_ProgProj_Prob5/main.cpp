/* 
 * File:   main.cpp
 * Author: Branden Hitt 
 * Created on March 16, 2015, 2:00 Pm
 *      Purpose: maximum room capacity
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
    unsigned short maxCap, nAtt, addAtt, extras;//max room capacity, number of attendees, additional guests allowed, extra guests over limit
    //Input
    cout<<"I am here to help you find if you have too many friends."<<endl;
    cout<<"What is the maximum room capacity of your destination?:"<<endl;
    cin>>maxCap; //max capacity
    cout<<"What is the amount of attendees?:"<<endl;
    cin>>nAtt; //number of attendees
    //Output
    if (nAtt<=maxCap){
         addAtt = maxCap-nAtt; //additional attendees allowed
         cout<<"This meeting is legal to hold!"<<endl;
         cout<<"Furthermore, you could fit up to "<<addAtt<<" more friends into the party!"<<endl;
    } else {
        extras= nAtt-maxCap; //extra attendees not allowed
        cout<<"This meeting is totally illegal and dangerous in case of an inferno!"<<endl;
        cout<<"You should be ashamed of yourself. Lose at least "<<extras<<" of  your attendees"<<endl;
        cout<<"or suffer the consequences!"<<endl;
    }
    //Exit Stage Right
    return 0;
}