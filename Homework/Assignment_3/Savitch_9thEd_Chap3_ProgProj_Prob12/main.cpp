/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 29, 2015, 7:40 PM
 *      Purpose: A game of 23 vs a computer
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short u1, u2, u3, u4, u5, u6, u7;
    unsigned short stickVal=23, compCho, compWin;
    //Prompt the user for inputs
    cout<<"You are going to play a game of 23 against a computer."<<endl;
    cout<<"There are 23 sticks in a pile."<<endl;
    cout<<"Each player takes turns drawing 1, 2, or 3 sticks until none are left."<<endl;
    cout<<"The player that draws the last stick loses."<<endl;
    cout<<"------------------Turn 1-------------------------"<<endl;
    cout<<"You get to go first. Enter 1, 2 or 3: "<<endl;
    cin>>u1;
    if (u1==1||u1==2||u1==3){
        stickVal-=u1;
        cout<<"There are now "<<stickVal<<" sticks left."<<endl;
        compCho=4-u1;
        stickVal-=compCho;
        cout<<"The computer chose to take "<<compCho<<", leaving "<<stickVal<<" sticks left"<<endl;
        cout<<"------------------Turn 2-------------------------"<<endl;
        cout<<"Enter 1, 2, or 3:"<<endl;
        cin>>u2;
        if (u2==1||u2==2||u2==3){
            stickVal-=u2;
            cout<<"There are now "<<stickVal<<" sticks left."<<endl;
            compCho=4-u2;
            stickVal-=compCho;
            cout<<"The computer chose to take "<<compCho<<", leaving "<<stickVal<<" sticks left"<<endl;
            cout<<"------------------Turn 3-------------------------"<<endl;
            cout<<"Enter 1, 2, or 3:"<<endl;
            cin>>u3;
            if (u3==1||u3==2||u3==3){
                stickVal-=u3;
                cout<<"There are now "<<stickVal<<" sticks left."<<endl;
                compCho=4-u3;
                stickVal-=compCho;
                cout<<"The computer chose to take "<<compCho<<" sticks, leaving "<<stickVal<<" sticks left"<<endl;
                cout<<"------------------Turn 4-------------------------"<<endl;
                cout<<"Enter 1, 2, or 3:"<<endl;
                cin>>u4;
                if (u4==1||u4==2||u4==3){
                  stickVal-=u4;
                  cout<<"There are now "<<stickVal<<" sticks left."<<endl;
                  compCho=4-u4;
                  stickVal-=compCho;
                  cout<<"The computer chose to take "<<compCho<<", leaving "<<stickVal<<" sticks left"<<endl;
                  cout<<"------------------Turn 5-------------------------"<<endl;
                  cout<<"Enter 1, 2, or 3:"<<endl;
                  cin>>u5;
                  if (u5==1||u5==2||u5==3){
                      stickVal-=u5;
                      if (stickVal>4){
                          compCho=4-u5;
                          stickVal-=compCho;
                          cout<<"The computer chose to take "<<compCho<<", leaving "<<stickVal<<" sticks left"<<endl;
                          cout<<"------------------Turn 6-------------------------"<<endl;
                          cout<<"Enter 1, 2, or 3:"<<endl;
                          cin>>u6;
                          if (u6==1||u6==2||u6==3){
                              stickVal-=u6;
                              if (stickVal<4&&stickVal>1){
                                  compWin=stickVal-1;
                                  cout<<"The computer chose to take "<<compWin<<", leaving 1 stick left. You Lose!";
                              }else if (stickVal==0){
                                  cout<<"You took the last stick. You Lose!"<<endl;
                              }else{
                                  cout<<"You left "<<stickVal<<" stick left. The computer loses!"<<endl;
                                  cout<<"CONGRATS YOU WIN"<<endl;
                              }
                          }else{
                              cout<<"You took too many sticks Cheater! You lose!"<<endl;
                          }
                      }else{
                          compWin=stickVal-1;
                          stickVal-=compWin;
                          cout<<"The computer chose to take "<<compWin<<", leaving 1 stick left. You lose!"<<endl;
                      }
                  }else{
                      cout<<"You took too many sticks Cheater! You lose!"<<endl;
                  }
                }else{
                    cout<<"You took too many sticks Cheater! You lose!"<<endl;
                }
            }else{
                cout<<"You took too many sticks Cheater! You lose!"<<endl;
            }
        }else{
            cout<<"You took too many sticks Cheater! You lose!"<<endl;
        }
    }else{
        cout<<"You took too many sticks Cheater! You lose!"<<endl;
    } 
    return 0;
}