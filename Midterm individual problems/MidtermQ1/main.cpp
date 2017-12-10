/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 20, 2015, 5:40 PM
 *      Purpose: input lines and display with line numbers
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
    unsigned short choice;
    //Prompt the user for inputs
    cout<<"How many lines would you like to output?: "<<endl;
    cin>>choice;
    //Output 
    for(choice;choice>0;choice--){
        unsigned short a=choice-1;
        //cout<<"a:"<<a<<endl;
        for(a;a>0;a--){
            cout<<" ";
        }
        cout<<choice<<endl;
    }
    return 0;
}