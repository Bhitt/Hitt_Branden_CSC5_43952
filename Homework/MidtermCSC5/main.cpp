/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Purpose:  Mid-term solutions
 
 * Modified on April 20, 2015 5:36PM
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void output(char);
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
                
                break;
            }
            case '4':{
                
                break;
            }
            case '5':{
                
                break;
            }
            case '6':{
                
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