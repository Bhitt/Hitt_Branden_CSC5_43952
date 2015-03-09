/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 2, 2015, 9:03 AM
 *      Purpose: Free Fall problem from Savitch
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
const float G=3.2174e1f;// Acceleration in ft/sec^2 on earth
const float CNVFTMT=3.058e-1f;// Conversion from feet to meters

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    float time,dstnce;
    //Prompt for time
    cout<<"Free Fall Problem"<<endl;
    cout<<"Input the time to drop x.xx (seconds)"<<endl;
    cin>>time;
    //Calculate the distance
    //dstnce=1/2*G*time*time;//DOES NOT WORK
    //dstnce=static_cast<float>(1)/2*G*time*time;
    //dstnce=1.0f/2*G*time*time;
    //dstnce=1/2.of*G*time*time;
    //dstnce=G*1/2*time*time;
    //dstnce=0.5f*G*time*time;
    dstnce=5e-1f*G*time*time;
    //Output the results
    cout<<"Distance fallen ="<<dstnce<<"(feet)"<<endl;
    cout<<"Distance fallen ="<<dstnce*CNVFTMT<<"(meters)"<<endl;
    //Exit Stage Right!
    return 0;
}

