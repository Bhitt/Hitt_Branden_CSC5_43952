/* 
 * File:   main.cpp
 * Author: Branden Hitt 
 * Created on March 16, 2015, 1:19 Pm
 *      Purpose: calculate retroactive salary, new annual salary, and new monthly
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
    const float RETRO = 0.076;
    unsigned int uSal; //user previous salary
    float pDue, nAnu, nMon; // retroactive pay due, new Annual salary, new monthly
    char ans;
    //Input
    do{
    cout<<"Your company has earned a 7.6% retroactive pay increase for the last 6 months!"<<endl;
    cout<<"Please input your annual salary (xxxxxxx): "<<endl;
    cin>>uSal;
    //Calculate
    pDue=((uSal*RETRO)/2);
    nAnu=uSal+(uSal*RETRO);
    nMon=nAnu/12;
    //Output
    cout<<"The pay increase due for the last 6 months is $"<<pDue<<endl;
    cout<<"Your new annual salary will be $"<<nAnu<<" a year."<<endl;
    cout<<"Which means your monthly salary will be $"<<nMon<<endl;
    cout<<"Would you like to run this program again?"<<endl;
    cout<<"Enter Y for yes or N for no. Then hit return."<<endl;
    cin>>ans;
    }while (ans == 'Y'|| ans == 'y');
    cout<<"Thats all! Good day to you."<<endl;
    //Exit Stage Right
    return 0;
}