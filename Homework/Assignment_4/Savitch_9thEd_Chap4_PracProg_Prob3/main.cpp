/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 6, 2015, 9:40 AM
 *      Purpose: compute holding into stock
 */

//System Libraries
#include <iostream>//I/O standard
#include <iomanip>//formatting
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short nShares, pStk, pStkNum, pStkDen;
    float pStkFlt, totStkP;
    char choice;
    //Loop on answer
    do{
        //Prompt the user for inputs
        cout<<"What is the number of shares of stock owned: "<<endl;
        cin>>nShares;
        cout<<"What is the whole dollar portion of the price of the stock: "<<endl;
        cin>>pStk;
        cout<<"For the fractional portion, input first the numerator: "<<endl;
        cin>>pStkNum;
        cout<<"Next for the fractional portion, input the denominator: "<<endl;
        cin>>pStkDen;
        //Output
        //Single Share Price
        pStkFlt=pStk+(1.0f*pStkNum/pStkDen);
        cout<<"pStkFlt: "<<pStkFlt<<endl;
        //Total Holdings
        totStkP=nShares*pStkFlt;
        cout<<"totStkP: "<<totStkP<<endl;
    }while(choice=='Y'||choice=='y');
    //Exit Stage Right
    return 0;
}