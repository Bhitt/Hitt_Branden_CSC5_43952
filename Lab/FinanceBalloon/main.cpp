/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 27, 2015, 9:04 AM
 *      Purpose: purchase a car, home, etc.
 */

//System Libraries
#include <iostream>//I/O standard
#include <cmath>//pow function
#include <iomanip>//format
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float blnPmnt(float, float,int,float);

//Execution Begins Here!
int main(int argc, char** argv){
    //Declare Variables
    float purPrce=1e4f;//Purchase price 10k
    float dwnPymt=1e-1f;//down payment % of purchase price
    float intRate=3.29e-2;//Interest rate per year
    int nMnths=60;//Number of months
    float mnPmnt=1.6543e2f;//Monthly Payment
    //Calculate the amount to finance
    float finance=purPrce*(1-dwnPymt);
    //Output all the initial conditions
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Purchase Price    = $"<<purPrce<<endl;
    cout<<"Down Payment      = $"<<purPrce*dwnPymt<<endl;
    cout<<"Interest Rate     =  "<<intRate*100<<"%"<<endl;
    cout<<"Months to Finance =  "<<nMnths<<endl;
    cout<<"Amount Financed   = $"<<finance<<endl;
    //Balloon Payment and Monthly Payment
    cout<<"Monthly Payment   = $"<<mnPmnt<<endl;
    cout<<"Balloon Payment   = $"<<blnPmnt(finance,intRate/12,nMnths,mnPmnt)<<endl;
    //Exit Stage Right
    return 0;
}

//Balloon Payment Function
//Input
//  f->Finance Amount $'s
//  i->Interest Rate  /month
//  n->Number of months
//  p->Monthly Payment
//Output
//  bln->Balloon Payment $'s
float blnPmnt(float f, float i,int n,float p){
    for(int month=1;month<n;month++){
        f*=(1+i);//Increase due to the interest rate
        f-=p;    //Decrease due to payment
    }
    return f;//Balloon Payment
}