/* 
 * File:   main.cpp
 * Author: Branden Hitt 
 * Created on March 15, 2015, 9:21 Pm
 *      Purpose: output the weight of a cereal box in metric tons, and
 *             the amount of boxes needed for 1 metric ton. Also let user repeat
 *              calculations as many times as they want
 */
//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
const float MTON=35273.92; //in ounces
//Function Prototypes
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char ans;
    float uBox, nBox, mBox;
    
    //Calculate
    do {
    cout<<"How much does your box of cereal weigh in ounces?"<<endl;
    cin>>uBox;
    nBox = (MTON/uBox);
    mBox = (uBox/MTON);
    cout<<"Your box of cereal weighs "<< mBox << " in metric tons."<<endl;
    cout<<"You would need "<<nBox<<" boxes to yield 1 metric ton of cereal"<<endl;
    cout<<"Would you like to run this calculation again?"<<endl;
    cout<<"Press Y for yes, or N for no. Then hit return."<<endl;
    cin>>ans;
    }
    while (ans == 'y' || ans == 'Y');
    cout<<"That's All! Good-bye!"<<endl;
    //Exit Stage Right
    return 0;
}