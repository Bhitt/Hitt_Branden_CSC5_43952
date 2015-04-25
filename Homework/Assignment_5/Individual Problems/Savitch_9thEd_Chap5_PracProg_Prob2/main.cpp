/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 16, 2015, 8:10 PM
 *      Purpose: 
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
short prompt();
float calc(short a);
void output(float a);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    short inch;
    float result;
    char ans;
    cout<<"This program will convert a length of pole from feet/inches to meters/centimeters."<<endl;
    do{
        inch=prompt();
        result=calc(inch);
        output(result);
        cout<<"Would you like to run this program again with different lengths?"<<endl;
        cout<<"Press Y for yes or N for no, then hit enter:"<<endl;
        cin>>ans;
    }while(ans=='Y'||ans=='y');
            
    //Prompt the user for inputs
    
    //Output 
    
    return 0;
}
short prompt(){
    short feet,inches,totInch;
    cout<<"How long is the pole in feet?"<<endl;
    cin>>feet;
    cout<<"What are the remaining inches?"<<endl;
    cin>>inches;
    totInch=inches+(feet*12);
    return totInch;
}
float calc(short a){
    float b,c;
    b=(a/12.0f);
    //cout<<"a/12= "<<b<<endl;
    c=b*0.3048;
    //cout<<"total meters: "<<c<<endl;
    return c;
}
void output(float a){
    short b;
    short c;
    b=a/1;
    c=(a*100)-(b*100);
    cout<<"The equivalent length is "<<b<<" meter(s) and "<<c<<" centimeter(s)"<<endl;
}