/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 9, 2015, 9:10 PM
 *      Purpose: Overloaded Function
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float max(float a, float b);
float max(float a, float b, float c);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float x,y,z,end;
    //Prompt the user for inputs
    cout<<"Please enter in a number:"<<endl;
    cin>>x;
    cout<<"Please enter in another number:"<<endl;
    cin>>y;
    cout<<"Please enter in a third number:"<<endl;
    cin>>z;
    end=max(x,y,z);
    //Output 
    cout<<"The largest number was "<<end<<endl;
    return 0;
}
float max(float a, float b){
    float temp=a;
    if (b>a){
        temp=b;
    }
    return temp;
}
float max(float a, float b, float c){
    float temp=a;
    if (b>a){
        temp=b;
    }
    if(c>a){
        temp=c;
    }
    return temp;
}