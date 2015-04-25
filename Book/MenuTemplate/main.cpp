/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Purpose:  Assignment 5
 * Modified on Apr 24th, 2015
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
    char repeat;
    //Display the selection
    do{
    cout<<"Type 1 to solve problem 1"<<endl;
    cout<<"Type 2 to solve problem 2"<<endl;
    cout<<"Type 3 to solve problem 3"<<endl;
    cout<<"Type 4 to solve problem 4"<<endl;
    cout<<"Type 5 to solve problem 5"<<endl;
    cout<<"Type 6 to solve problem 6"<<endl;
    cout<<"Type 7 to solve problem 7"<<endl;
    cout<<"Type 8 to solve problem 8"<<endl;
    cout<<"Type 9 to solve problem 9"<<endl;
    cout<<"Type T to solve problem 10"<<endl;
    //Read the choice
    char choice;
    cin>>choice;
    //Solve a problem that has been chosen.
    switch(choice){
        case '1':{
            cout<<"*****************************"<<endl;
            
            cout<<"*****************************"<<endl;
                break;
            }
        case '2':{
            cout<<"*****************************"<<endl;
            
            cout<<"*****************************"<<endl;
                break;
            }
        case '3':{
            cout<<"*****************************"<<endl;
            
            cout<<"*****************************"<<endl;
                break;
            }
        case '4':{
            cout<<"*****************************"<<endl;
            
            cout<<"*****************************"<<endl;
                break;
            }
        case '5':{
            cout<<"*****************************"<<endl;
            
            cout<<"*****************************"<<endl;
                break;
            }
        case '6':{
            cout<<"*****************************"<<endl;
            
            cout<<"*****************************"<<endl;
                break;
            }
        case '7':{
            cout<<"*****************************"<<endl;
            
            cout<<"*****************************"<<endl;
                break;
            }
        case '8':{
            cout<<"*****************************"<<endl;
            
            cout<<"*****************************"<<endl;
                break;
            }
        case '9':{
            cout<<"*****************************"<<endl;
            
            cout<<"*****************************"<<endl;
                break;
            }
        case 't':
        case 'T':{
            cout<<"*****************************"<<endl;
            
            cout<<"*****************************"<<endl;
                break;
            }
            default:{
                    cout<<"Incorrect Menu Choice"<<endl;
            }      
    };
    cout<<"Would you like to return to the menu? Enter Y for yes or N for no:"<<endl;
    cin>>repeat;
    }while(repeat=='Y'||repeat=='y'); 
    return 0;
}