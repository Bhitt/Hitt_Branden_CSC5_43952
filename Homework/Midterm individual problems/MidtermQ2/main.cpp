/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 20, 2015, 6:00 PM
 *      Purpose: read in a 4-digit number, output in format
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void output(char);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char a,b,c,d;
    //Prompt the user for inputs
    cout<<"Please type in your 4-digit number now: "<<endl;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    //Output 
    output(a);
    output(b);
    output(c);
    output(d);
    return 0;
}
//Output function
void output(char a){
    unsigned short b=10;
    if(a=='9'){
        b=9;
    }else if(a=='8'){
        b=8;
    }else if(a=='7'){
        b=7;
    }else if(a=='6'){
        b=6;
    }else if(a=='5'){
        b=5;
    }else if(a=='4'){
        b=4;
    }else if(a=='3'){
        b=3;
    }else if(a=='2'){
        b=2;
    }else if(a=='1'){
        b=1;
    }
    if(b<=9){
        cout<<a<<" ";
        for(b;b>0;b--){
            cout<<"*";
        }
        cout<<endl;
    }else{
        cout<<a<<" ";
        cout<<"?"<<endl;
    }
}