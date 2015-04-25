/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 22, 2015, 8:50 AM
 *      Purpose: Change dispenser
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void coins(int,int &, int &);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int userC, num;
    char cho;
    //Prompt the user for inputs
    cout<<"This program will give the correct change back for any value between 1 and 99 cents"<<endl;
    cout<<"(Note: This machine has no nickels or half-dollars)"<<endl;
    do{
        cout<<"Please enter in an amount of change to recieve (1-99 cents):"<<endl;
        cin>>userC;
        //Output
        coins(25,num,userC);
        cout<<num<<" Quarters"<<endl;
        coins(10,num,userC);
        cout<<num<<" Dimes"<<endl;
        coins(1,num,userC);
        cout<<num<<" Pennies"<<endl;
        //Prompt for repeat
        cout<<"Would you like to enter in a new input for change?"<<endl;
        cout<<"Enter in Y for yes or N for n:"<<endl;
        cin>>cho;
    }while(cho=='Y'||cho=='y');
    
    return 0;
}

void coins(int a,int &b, int &c){
    b=0;
    if(a<=c){
        b=c/a;
        c-=(b*a);
    }
}