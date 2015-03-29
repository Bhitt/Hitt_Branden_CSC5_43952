
/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 28, 2015, 11:10 PM
 *      Purpose: Will it Sink?
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
    float weight, radius, buoFor, vol, water=62.4, pi=3.141592;
    //Prompt the user for inputs
    cout<<"This program will tell you if a sphere will sink or float in water."<<endl;
    cout<<"What is the weight of your sphere in lbs: "<<endl;
    cin>>weight;//weight of sphere in lbs
    cout<<"What is the radius of your sphere in feet: "<<endl;
    cin>>radius;//radius of sphere in feet
    //Calculate
    vol=((4.0/3)*(pi)*(radius*radius*radius));//volume of sphere formula
    buoFor=vol*water;//buoyancy force formula
    if (buoFor>=weight){//if buoyancy force is >= the weight of the sphere
        cout<<"Your sphere will float!!!"<<endl;//output
    }else{
        cout<<"Your sphere will sink!!!"<<endl;//output
    }
    return 0;
}