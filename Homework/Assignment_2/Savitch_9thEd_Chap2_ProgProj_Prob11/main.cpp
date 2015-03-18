/* 
 * File:   main.cpp
 * Author: Branden Hitt 
 * Created on March 17, 2015, 10:38 Pm
 *      Purpose: velocity of sound
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
    int iniTemp, endTemp;
    //Input
    cout<<"This program will output the velocity of sound throughout a temperature range."<<endl;
    cout<<"First enter in the lower starting temperature in Celsius:"<<endl;
    cin>>iniTemp;
    cout<<"Next enter in the higher ending temperature in Celsius:"<<endl;
    cin>>endTemp;
    //Output
   do {
       float vel1=331.3+0.61*iniTemp;
       cout<<"At "<<iniTemp<<" degrees Celsius the velocity of sound is "<<vel1<<" m/s"<<endl;
       iniTemp+=1;
   } while (endTemp-iniTemp>0 && iniTemp>0);
   {
       float vel1=331.3+0.61*iniTemp;
       cout<<"At "<<iniTemp<<" degrees Celsius the velocity of sound is "<<vel1<<" m/s"<<endl;
       iniTemp+=1;
   }
    //Exit Stage Right
    return 0;
}