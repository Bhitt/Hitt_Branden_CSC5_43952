/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 25, 2015, 10:10 AM
 *      Purpose: Astrology Program (find user's sign and horoscope)
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float sum1=0,sum2=0,exSum1,exSum2;
    float val1=0.1f,val2=0.5f;
    int nXSum=1e7;//10,000,000
    //Calculate the sum
    for (int i=1;i<=nXSum;i++){
        sum1+=val1;
        sum2+=val2;
    }
    //Exact sums are
    exSum1=nXSum*val1;
    exSum2=nXSum*val2;
    //compare the results
    cout<<"Exact Sum 1 = "<<exSum1<<endl;
    cout<<"Summed Sum 1 = "<<sum1<<endl;
    cout<<"Percentage Error = "<<(exSum1-sum1)/exSum1*100<<"%"<<endl;
    cout<<"Exact Sum 2 = "<<exSum2<<endl;
    cout<<"Summed Sum 2 = "<<sum2<<endl;
    cout<<"Percentage Error = "<<(exSum2-sum2)/exSum2*100<<"%"<<endl;
    //Prompt the user for inputs
    
    //Output 
    
    return 0;
}