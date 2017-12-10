/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 21, 2015, 5:40 PM
 *      Purpose: exponential sequence
 */

//System Libraries
#include <iostream>//I/O standard
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int x, terms;
    float sum=1.0f, exact, error;
    //Prompt the user for inputs
    cout<<"This program will let you input X and the number of terms in a sequence."<<endl;
    cout<<"Please first input X:"<<endl;
    cin>>x;
    cout<<"Next enter in the number of terms:"<<endl;
    cin>>terms;
    //Calculate
    for(int i=terms-1;i>0;--i){
        sum=1+x*sum/i;
    }
    exact=pow(terms, x);
    error=abs(exact-sum)/exact*100;
    //Output
    cout<<"Approximation of e^x = "<<sum<<endl;
    cout<<"Exact value of e^x = "<<exact<<endl;
    cout<<"The percentage error = "<<std::setprecision(4)<<error<<"%"<<endl;
    return 0;
}