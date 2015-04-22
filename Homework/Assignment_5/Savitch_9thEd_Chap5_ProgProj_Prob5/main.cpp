/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 22, 2015, 9:10 AM
 *      Purpose: Windchill Program
 */

//System Libraries
#include <iostream>//I/O standard
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float index(short,short);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    short userT,uWind;
    float result;
    //Prompt the user for inputs
    cout<<"This program will find the windchill index at a given air temperature."<<endl;
    cout<<"Please enter in a temperature (in Celsius)"<<endl;
    cin>>userT;
    cout<<"Next, enter in the wind speed (in m/sec):"<<endl;
    cin>>uWind;
    if(userT<=10){
        result=index(userT,uWind);
        cout<<"The windchill index is "<<result<<" (in degrees Celsius)"<<endl;
    }else{
        cout<<"The temperature is too warm to have a windchill."<<endl;
    }
    //Output 
    
    return 0;
}
//windchill index function
float index(short t,short v){
    float w;
    w=13.12+0.6215*t-11.37*(pow(v,0.16))+0.3965*t*(pow(v,0.016));
    return w;
}