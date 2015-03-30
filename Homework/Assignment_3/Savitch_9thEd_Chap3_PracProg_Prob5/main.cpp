
/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 28, 2015, 10:50 PM
 *      Purpose: Output the prime numbers from 1 to 100
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
    short p,j,pr;
    //Prompt user
    cout<<"This program finds and outputs the prime numbers from 1 to 100"<<endl;
    //Calculate
    for (p=2;p<=100;p++){
        for (j=2,pr=1;j<p&&pr==1;){
            if(p%j==0){
                pr=0;
            }
            else{
                j++;
            }
            
            }if(pr==1){
                cout<<p<<" ";
        }
    }
    return 0;
}