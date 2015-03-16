/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 16, 2015, 8:10 AM
 *      Purpose: Paycheck->Ternary
 */

//System Libraries
#include <iostream>//I/O standard
#include <iomanip>//Formatting
#include <fstream>//I/O File
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    ofstream out;//Output the results in a file
    float hrsWkd;//Hours Worked (hrs)
    float payRate;//Pay Rate ($'s/hr)
    float oRate=1.5f;//Multiplicative factor of payRate
    float oTime=40.0f;//Where overtime begins (hr)
    float payChk;//Gross Pay ($'s)
    //Open the file
    out.open("Payroll.dat");
    //Close the file
    //Prompt the user for inputs
    cout<<"How many hours this week did you work?"<<endl;
    cin>>hrsWkd;
    cout<<"What is your pay rate ($'s/hr)"<<endl;
    cin>>payRate;
    //Calculate the paycheck
    payChk=hrsWkd<oTime?
        payRate*hrsWkd:
        payRate*(hrsWkd+(oRate-1)*(hrsWkd-oTime));
    //Ouput the results to the screen
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Hours worked = "<<hrsWkd<<" (hrs) "<<endl;
    cout<<"Pay Rate = $"<<payRate<<" (hr)"<<endl;
    cout<<"Over time rate = "<<oRate<<endl;
    cout<<"Over time begins at "<<oTime<<" (hrs) "<<endl;
    cout<<"Gross pay = $"<<payChk<<endl;
    //Close the file
     //Ouput the results to the file
    out<<fixed<<setprecision(2)<<showpoint;
    out<<"Hours worked = "<<hrsWkd<<" (hrs) "<<endl;
    out<<"Pay Rate = $"<<payRate<<" /(hr)"<<endl;
    out<<"Over time rate = "<<oRate<<endl;
    out<<"Over time begins at "<<oTime<<" (hrs) "<<endl;
    out<<"Gross pay = $"<<payChk<<endl;
    out.close();
    return 0;
}

