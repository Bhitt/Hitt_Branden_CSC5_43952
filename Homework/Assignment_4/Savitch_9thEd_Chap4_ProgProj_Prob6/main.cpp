/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 8, 2015, 8:00 AM
 *      Purpose: to gain weight, become a public health hazard, and design
 *      the interface for a fried twinkie machine
 */

//System Libraries
#include <iostream>//I/O standard
#include <string.h>//for string compare
#include <iomanip>//format
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=80;
    char input[SIZE];
    unsigned short totChng=0, pTwnke=350;
    char nQrts, nDimes, nNikels;
    //Prompt the user for inputs
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"This is a Fried Twinkie Vending Machine"<<endl;
    cout<<"Fried Twinkies cost $3.50"<<endl;
    cout<<"Input your change as "<<endl;
    cout<<"Dollar, Quarter, Dime, Nickel"<<endl;
    cout<<"One at a time:"<<endl;
    do{
        cout<<"Input coins/change"<<endl;
        cin>>input;
        if(strcmp(input,"Dollar")==0){
            totChng+=100;//Add a Dollar
        }else if (strcmp(input, "Quarter")==0){
            totChng+=25;//Add a Quarter
        }else if (strcmp(input, "Dime")==0){
            totChng+=10;//Add a Dime
        }else if (strcmp(input, "Nickel")==0){
            totChng+=5;//Add a Nickel
        }else {
            cout<<"No Slugs Allowed"<<endl;//Invalid input
        }
        //Output 
        cout<<"Total Change = $"<<totChng/100.0f<<endl;
        cout<<endl;
    }while(totChng<pTwnke);
    //Give Twinkie
    cout<<endl<<"Here is your Fried Twinkie"<<endl;
    //Calculate the change
    totChng-=pTwnke;
    cout<<"Your change is = $"<<totChng/100.0f<<endl;
    //How many Quarters
    nQrts=totChng/25;
    if(nQrts>0)cout<<static_cast<int>(nQrts)<<" Quarters Change"<<endl;
    //How many Dime
    totChng-=nQrts*25;
    nDimes=totChng/10;
    if(nDimes>0)cout<<static_cast<int>(nDimes)<<" Dimes Change"<<endl;
    //How many Nickels
    totChng-=nDimes*10;
    nNikels=totChng/5;
    if(nNikels>0)cout<<static_cast<int>(nNikels)<<" Nickels Change"<<endl;
    //Exit Stage Right
    return 0;
}