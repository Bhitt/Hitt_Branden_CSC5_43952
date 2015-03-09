/* 
 * File:   main.cpp
 * Author: Branden Hitt 
 * Created on March 4, 2015, 8:23 AM
 *      Purpose: Coin Calculator
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
    unsigned short nQuart,nDime,nNckl,tQuart,tDime,tNckl;
    unsigned short nCents;
    //Input
    //Prompt User for number of quarters,dimes,nickels
    cout<<"This program converts your quarters, dimes, and nickels to total cents."<<endl;
    cout<<"Enter in the number of quarters as xx"<<endl;
    cin>>nQuart;
    tQuart=nQuart*25;
    cout<<"Enter in the number of dimes as xx"<<endl;
    cin>>nDime;
    tDime=nDime*10;
    cout<<"Enter in the numer of nickels as xx"<<endl;
    cin>>nNckl;
    tNckl=nNckl*5;
    nCents=tQuart + tDime + tNckl;
    //Output
    cout<<"The total number of cents is "<<nCents<<endl;
    //Exit Stage Right
    return 0;
}
