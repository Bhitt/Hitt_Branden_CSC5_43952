/* 
 * File:   main.cpp
 * Author: Branden Hitt 
 * Created on March 17, 2015, 3:03 Pm
 *      Purpose: water well storage
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
    float gaPerFt=7.48, radFt;//gallons per foot, radius in feet
    float depFt, volCbFt, gal;//depth of well in feet, volume in cubic feet, gallons
    int radInch;//radius of well in inches
    //Input
    cout<<"What is the radius of the well casing in inches?"<<endl;
    cin>>radInch;//users well radius in inches
    cout<<"What is the depth of the well in feet?"<<endl;
    cin>>depFt;//users well depth in feet
    //Calculate
    radFt=radInch/12.0;//converts radius inches to feet
    volCbFt=(3.14159*radFt*radFt*depFt);//computes volume of water pie*r^2*depth
    gal=gaPerFt*volCbFt;//convert from cub feet to gallons
    //Output
    cout<<"Your well contains "<<gal<<" gallons of water!"<<endl;
    //Exit Stage Right
    return 0;
}