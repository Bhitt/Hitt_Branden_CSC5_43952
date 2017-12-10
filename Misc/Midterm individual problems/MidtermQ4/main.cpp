/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 25, 2015, 10:10 AM
 *      Purpose: Astrology Program (find user's sign and horoscope)
 */

//System Libraries
#include <iostream>//I/O standard
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float packA(unsigned short);
float packB(unsigned short);
float packC(unsigned short);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char curPack;
    unsigned short hrsWtch;
    float a,b,c;
    //Prompt the user for inputs
    cout<<"This program will calculate your monthly cable bill, and find the package"<<endl;
    cout<<"that is best for you."<<endl;
    cout<<"The packages are as follows:"<<endl;
    cout<<"a) $19.95 per month, 5 hours access. Additional hours are $0.75 up to 20 hours"<<endl;
    cout<<"    then $1 for all additional hours."<<endl;
    cout<<"b) $24.95 per month, 15 hour access. Additional hours are $0.75 up to 25 hours"<<endl;
    cout<<"    then $0.50 for each hour above this limit."<<endl;
    cout<<"c) $29.75 per month unlimited access."<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"What is your current package: (a,b,c)"<<endl;
    cin>>curPack;
    cout<<"How many hours of tv did you watch this month:"<<endl;
    cin>>hrsWtch;
    cout<<"*****************************"<<endl;
    a=packA(hrsWtch);
    b=packB(hrsWtch);
    c=packC(hrsWtch);
    //Output 
    if(curPack=='A'||curPack=='a'){
        cout<<"Your current bill is $"<<a<<endl;
        if(b<a&&b<c){
            cout<<"You should switch to package B next month."<<endl;
            cout<<"You would only have to pay $"<<b<<endl;
        }else if(c<a&&c<b){
            cout<<"You should switch to package C next month."<<endl;
            cout<<"You would only have to pay $"<<c<<endl;
        } 
    }else if(curPack=='B'||curPack=='b'){
        cout<<"Your current bill is $"<<b<<endl;
        if(a<b&&a<c){
            cout<<"You should switch to package A next month."<<endl;
            cout<<"You would only have to pay $"<<a<<endl;
        }else if(c<a&&c<b){
            cout<<"You should switch to package C next month."<<endl;
            cout<<"You would only have to pay $"<<c<<endl;
        }
    }else if(curPack=='C'||curPack=='c'){
        cout<<"Your current bill is $"<<c<<endl;
        if(b<a&&b<c){
            cout<<"You should switch to package B next month."<<endl;
            cout<<"You would only have to pay $"<<b<<endl;
        }else if(a<c&&a<b){
            cout<<"You should switch to package A next month."<<endl;
            cout<<"You would only have to pay $"<<a<<endl;
        }
    }else{
        cout<<"Incorrect package input"<<endl;
    }
    
    
    return 0;
}
//Cable Package A
float packA(unsigned short x){
    float end;
    if(x<=5){
        end=19.95;
    }else if(x<=20&&x>5){
        end=(19.95)+((x-5)*0.75);
    }else if(x>20){
        end=(19.95)+(15*0.75)+((x-20)*1);
    }else{
        //do nothing
    }
    return end;
}
//Cable Package B
float packB(unsigned short y){
    float end;
    if(y<=15){
        end=24.95;
    }else if(y<=25&&y>15){
        end=(24.95)+((y-15)*0.75);
    }else if(y>25){
        end=(19.95)+(15*0.75)+((y-25)*0.50);
    }else{
        //do nothing
    }
    return end;
}
//Cable Package C
float packC(unsigned short z){
    return 29.75;
}