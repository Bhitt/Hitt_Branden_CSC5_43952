/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Purpose:  Mid-term solutions
 
 * Modified on April 20, 2015 5:36PM
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void output(char);
float packA(unsigned short);
float packB(unsigned short);
float packC(unsigned short);
//Execution Begins Here
int main(int argc, char** argv) {
    //General Menu Format
    //Display the selection
    char ans;
    do{
    cout<<"Type 1 to solve problem 1"<<endl;
    cout<<"Type 2 to solve problem 2"<<endl;
    cout<<"Type 3 to solve problem 3"<<endl;
    cout<<"Type 3 to solve problem 4"<<endl;
    cout<<"Type 3 to solve problem 5"<<endl;
    cout<<"Type 3 to solve problem 6"<<endl;
    //Read the choice
    char choice;
    cin>>choice;
    //Solve a problem that has been chosen.
    switch(choice){
            case '1':{
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
                break;
            }
            case '2':{
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
                break;
            }
            case '3':{
                //Declare Variables
                unsigned short pin, bal, dCharg, cred, balCred;
                float endBal;
                char over;
                //Prompt the user for inputs
                cout<<"This program will help you check your debit card balance."<<endl;
                cout<<"First enter in your Pin Number (4 alpha-numeric characters):"<<endl;
                cin>>pin;
                cout<<"Next, I need the initial balance on the card:"<<endl;
                cin>>bal;
                cout<<"Next, type in the total of all debits charged during this month: "<<endl;
                cin>>dCharg;
                cout<<"Last, I need the total of all added credits to the card:"<<endl;
                cin>>cred;
                cout<<"**********************************"<<endl;
                //Output 
                balCred=bal+cred;
                //cout<<"balCred:"<<balCred;
                if(balCred>=dCharg){
                    endBal=balCred-dCharg;
                }else if(balCred<dCharg){
                    endBal=dCharg-balCred;
                    over='Y';

                }
                if(over=='Y'){
                    cout<<"Your new balance is: -$"<<endBal<<endl;
                    endBal+=27.75f;
                    cout<<"Since your account was overdrawn, a $27.75 fee has been added to your balance."<<endl;
                    cout<<"Your new balance, after the added fee, is: -$"<<endBal<<endl;
                    cout<<"In order to allow further charges to occur, this card would have to be zeroed"<<endl;
                    cout<<"out and a new credit balance applied."<<endl;
                }else{
                    cout<<"Your new balance is $"<<endBal<<endl;
                }
                break;
            }
            case '4':{
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


                break;
            }
            case '5':{
                 //Declare Variables
                unsigned short hrsWrkd;
                float ratePay, check;
                //Prompt the user for inputs
                cout<<"This program will determine your gross pay."<<endl;
                cout<<"You receive straight-time for the first 40 hours, double time for all"<<endl;
                cout<<"hours worked in excess of 40 hours but less than 50 hours, and triple"<<endl;
                cout<<"time for any hours worked over 50 hours."<<endl;
                cout<<"******************************************"<<endl;
                cout<<"Please enter in your hours worked this week:"<<endl;
                cin>>hrsWrkd;
                cout<<"Next, enter in your rate of pay (per hour):"<<endl;
                cin>>ratePay;
                cout<<"******************************************"<<endl;
                if(hrsWrkd<=40){
                    check=hrsWrkd*ratePay;
                }else if(hrsWrkd>40&&hrsWrkd<=50){
                    check=40*ratePay+((hrsWrkd-40)*(2*ratePay));
                }else if(hrsWrkd>50){
                    check=(40*ratePay)+(10*(2*ratePay))+((hrsWrkd-50)*(3*ratePay));
                }
                //Output 
                cout<<"Your Gross Pay is $"<<check<<endl;
                break;
            }
            case '6':{
                //Declare Variables
                int x, terms;
                float sum=1.0f, exact, error;
                float e=exp(1.0);
                //Prompt the user for inputs
                cout<<"This program will let you input X and the number of terms in a sequence."<<endl;
                cout<<"Please first input X:"<<endl;
                cin>>x;
                cout<<"Next enter in the number of terms:"<<endl;
                cin>>terms;
                //Calculate
                for(int i=terms-1;i>0;--i){
                    sum=1+x*sum/i;
                }
                exact=pow(e,x);
                error=(abs(exact-sum))/exact*100;
                //Output
                cout<<"Approximation of e^x = "<<sum<<endl;
                cout<<"Exact value of e^x = "<<exact<<endl;
                cout<<"The percentage error = "<<error<<"%"<<endl;
                break;
            }
            default:{
                    cout<<"Invalid menu selection choice"<<endl;
            }
    };
    cout<<"Would you like to return to the menu?"<<endl;
    cout<<"Type Y for yes or N for no:"<<endl;
    cin>>ans;
    }while(ans=='Y'||ans=='y');
    return 0;
}

//Output function for problem 2
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