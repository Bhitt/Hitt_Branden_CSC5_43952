/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 21, 2015, 7:50 PM
 *      Purpose: find time after waiting a certain amount
 */

//System Libraries
#include <iostream>//I/O standard
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short cHour,cMin,hrsW,minsW,finHr,finMin;
    char cho;
    //Prompt the user for inputs
    cout<<"This program will find the time after waiting a given period. (24-hr notation)"<<endl;
    do{
        cout<<"Please first enter in the current hour:"<<endl;
        cin>>cHour;
        cout<<"Next, enter in the minute portion of the current time:"<<endl;
        cin>>cMin;
        cout<<"How many hours would you like to wait:"<<endl;
        cin>>hrsW;
        cout<<"How many minutes would you like to wait:"<<endl;
        cin>>minsW;
        //Calculate
        finMin=cMin+minsW;
        while(finMin>=60){
            finMin-=60;
            cHour+=1;
        }
        finHr=cHour+hrsW;
        while(finHr>24){
            finHr-=24;
        }
        if(finHr<10&&finMin<10){
           cout<<"The time after waiting is 0"<<finHr<<":0"<<finMin<<endl; 
        }else if(finMin<10){
           cout<<"The time after waiting is "<<finHr<<":0"<<finMin<<endl;
        }else if(finHr<10){
           cout<<"The time after waiting is 0"<<finHr<<":"<<finMin<<endl;
        }else{
            cout<<"The time after waiting is"<<finHr<<":"<<finMin<<endl;
        }
        //Prompt for repeat
        cout<<"Would you like to enter in new inputs?"<<endl;
        cout<<"Type Y for yes or N for no:"<<endl;
        cin>>cho;
    }while(cho=='Y'||cho=='y');
    return 0;
}