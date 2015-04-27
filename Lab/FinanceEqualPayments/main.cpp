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
float blnPmnt(float, float,int,float);//For-Loop
float eqlPmnt(float,float,int);//For-Loop
float eqlPmnt1(float,float,int);//Equation
//Execution Begins Here!
int main(int argc, char** argv){
    //Declare Variables
    float purPrce=1e4f;//Purchase price 10k
    float dwnPymt=1e-1f;//down payment % of purchase price
    float intRate=3.29e-2;//Interest rate per year
    int nMnths=60;//Number of months
    //Calculate the amount to finance
    float finance=purPrce*(1-dwnPymt);
    //Output all the initial conditions
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Purchase Price    = $"<<purPrce<<endl;
    cout<<"Down Payment      = $"<<purPrce*dwnPymt<<endl;
    cout<<"Interest Rate     =  "<<intRate*100<<"%"<<endl;
    cout<<"Months to Finance =  "<<nMnths<<endl;
    cout<<"Amount Financed   = $"<<finance<<endl;
    //Calculate the Monthly Payment without interest
    
    //Balloon Payment and Monthly Payment
    cout<<fixed<<setprecision(4)<<showpoint;
    cout<<"Monthly Payment   = $"<<eqlPmnt(finance,intRate/12,nMnths)<<endl;
    cout<<"Monthly Payment   = $"<<eqlPmnt1(finance,intRate/12,nMnths)<<endl;
    //cout<<"Balloon Payment   = $"<<bln<<endl;
    
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

float eqlPmnt(float f, float i,int n){
    float mnPmnt=f/n;//Payment without interest
    //Calculate the Balloon Payment tending to Zero
    float bln=0,incrmnt=0;
    float penny=0.01f;//Value of a Penny
    float halfPny=0.005f;//Value of a half penny
    do{
        mnPmnt+=incrmnt;
        mnPmnt=static_cast<int>((mnPmnt+halfPny)*100)/100.0f;//Exact pennies
        bln=blnPmnt(f,i,n,mnPmnt);
        incrmnt=bln/n;
    }while(incrmnt>penny||incrmnt<-penny);
    return mnPmnt;
}

float eqlPmnt1(float f,float i,int n){
    float temp=pow((1+i),n);
    return i*temp*f/(temp-1);
}