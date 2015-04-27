/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 27, 2015, 8:14 AM
 *      Purpose: find retirement
 */

//System Libraries
#include <iostream>//I/O standard
#include <cmath>//pow function
#include <iomanip>//format
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

float rtirmnt(float,float,int,float);//For-Loop

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float pv=0.0f;//Present Value $'s
    float ir=0.05f;//Interest Rate %/yr
    float fdep=0.15f;//Babylonians say 10%
    float salary=50000;//Salary in $/year
    //Calculate our Savings Required
    float savReq=salary/ir;//Savings Required $'s
    //Output all initial conditions
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Investment Rate from Municipal Bonds = "<<ir*100<<"%"<<endl;
    cout<<"Salary = $"<<salary<<endl;
    cout<<"Yearly Retirement Saved = $"<<salary*fdep<<endl;
    cout<<"Savings Required to Retire = $"<<savReq<<endl;
    cout<<endl<<"Year  Ret  Savings"<<endl;
    float retSav=0.0f;
    //Output our yearly retirement savings
    for(int year=1;retSav<savReq;year++){
        retSav=rtirmnt(pv,ir,year,salary*fdep);
        cout<<setw(4)<<year<<setw(13)<<retSav<<endl;
    }
   //Exit Stage Right
    return 0;
}
//Function for Future Value Calculation
//inputs
//      p->Present Value $'s
//      i->Interest Rate %/Compounding period
//      n->Compounding Period yr's
//      d->Deposit yearly
//outputs
//      fv-> Future Value $'s

float rtirmnt(float p,float i,int n,float d){
    for(int year=1;year<=n;year++){
        p*=(1+i);
        p+=d;
    }
    return p;
}

