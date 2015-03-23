/* 
 * File:   main.cpp
 * Author: Branden Hitt 
 * Created on March 23, 2015, 10:08 AM
 *      Purpose: 
 */
//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char user1, user2;
    
    //Input
    cout<<"How about a game of Rock, Paper, Scissors?"<<endl;
    cout<<"Player 1, please type in your choice now (R,P,S):"<<endl;
    cin>>user1;
    cout<<"Player 2, please type in your choice now (R,P,S):"<<endl;
    cin>>user2;
    //Calculate
    //Output
    if (user1=user2){
        cout<<"Nobody wins"<<endl;
    }
    else if (user1=='R'&&user2=='P'){
        cout<<"Player 1 picked Rock, Player 2 picked Paper. Paper beats rock."<<endl;
        cout<<"Player 2 wins!"<<endl;
    }
    else if (user1=P&&user2=R){
        cout<<"Player 1 picked Paper, Player 2 picked Rock. Paper beats rock."<<endl;
        cout<<"Player 1 wins!"<<endl;
    }
    else if (user1=R&&user2=S){
        cout<<"Player 1 picked Rock, Player 2 picked Scissors. Rock beats Scissors."<<endl;
        cout<<"Player 1 wins!"<<endl;
    }
    else if (user1=S&&user2=R){
        cout<<"Player 1 picked Scissors, Player 2 picked Rock. Rock beats Scissors."<<endl;
        cout<<"Player 2 wins!"<<endl;
    }
    else if (user1=P&&user2=S){
        cout<<"Player 1 picked Paper, Player 2 picked Scissors. Scissors beat Paper"<<endl;
        cout<<"Player 2 wins!"<<endl;
    }
    else if (user1=S&&user2=P){
        cout<<"Player 1 picked Scissors, Player 2 picked Paper. Scissors beat Paper"<<endl;
        cout<<"Player 1 wins!"<<endl;
    }
    else cout<<"Your choice wasn't Rock, Paper, or Scissors."<<endl;
    //Exit Stage Right
    return 0;
}