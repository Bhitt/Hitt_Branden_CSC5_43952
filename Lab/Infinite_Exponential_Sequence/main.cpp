/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 25, 2015, 8:00 AM
 *      Purpose: Having fun with the exponential
 */

//System Libraries
#include <iostream>//I/O standard
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float ourExp(float x);
double ourExp(double x);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare and initialize variables
    const unsigned int MAX=pow(2,31)-1;
    float xf=1.0f*rand()/MAX*3+1;//float between (1,4)
    double xd=1.0*rand()/MAX*3+1;
    //Call functions and compare
    float expAprx=ourExp(xf);
    float libExp=exp(xf);
    float prcntEr=(libExp-expAprx)/libExp*100;
    cout<<"exp("<<xf<<")="<<libExp<<","<<expAprx
            <<","<<prcntEr<<"%"<<endl;
    //Call functions and compare
    double expAprxd=ourExp(xd);
    double libExpd=exp(xd);
    double prcntErd=(libExpd-expAprxd)/libExpd*100;
    cout<<"exp("<<xd<<")="<<libExpd<<","<<expAprxd
            <<","<<prcntErd<<"%"<<endl;
    //Output 
    
    return 0;
}
float ourExp(float x){
    //Declare Variables
    float term=1,exp=1,tol=x*1.0e-7f;
    for(int nterm=1;term>tol;nterm++){
        term*=x/nterm;
        exp+=term;
    }
    return exp;
}

double ourExp(double x){
    //Declare Variables
    double exp=1;
    for(double tol=x*1.0e-16f,term=1,nterm=1;term>tol;term*=x/nterm,exp+=term,nterm++)
    return exp;
}