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