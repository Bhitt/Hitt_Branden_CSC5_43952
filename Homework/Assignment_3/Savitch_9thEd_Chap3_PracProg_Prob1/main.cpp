/* 
 * File:   main.cpp
 * Author: Branden Hitt 
 * Created on March 23, 2015, 10:08 AM
 *      Purpose: Rock Paper Scissors 2 player game
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
    cout<<"Rock beats Scissors. Scissors beat Paper. Paper beats Rock."<<endl;
    cout<<"Player 1, please type in your choice now (R,P,S):"<<endl;
    cin>>user1;
    cout<<"Player 2, please type in your choice now (R,P,S):"<<endl;
    cin>>user2;
    //Calculate
    //Output
    switch (user1){//checks for player 1's choice
        case'r'://if player 1 picks r for rock
        case'R'://if player 1 picks R for rock
            switch (user2){
                case'r'://if player 2 picks r for rock
                case'R'://if player 2 picks R for rock
                    cout<<"Nobody Wins. Tie Game"<<endl;
                    break;
                case'p'://if player 2 picks p for paper
                case'P'://if player 2 picks P for paper
                    cout<<"Player 2 wins! Paper beats Rock"<<endl;
                    break;
                case's'://if player 2 picks s for Scissors
                case'S'://if player 2 picks s for Scissors
                    cout<<"Player 1 wins! Rock beats Scissors"<<endl;
                    break;
                default://if player 2 types an invalid entry
                    cout<<"Invalid Entry for Player 2"<<endl;
            }
            break;
        case'p'://if player 1 picks p for Paper
        case'P'://if player 1 picks P for Paper
            switch(user2){
                case'r'://if player 2 picks r for rock
                case'R'://if player 2 picks R for rock
                    cout<<"Player 1 Wins! Paper beats Rock"<<endl;
                    break;
                case'p'://if player 2 picks p for paper
                case'P'://if player 2 picks P for paper
                    cout<<"Nobody Wins. Tie Game"<<endl;
                    break;
                case's'://if player 2 picks s for Scissors
                case'S'://if player 2 picks S for Scissors
                    cout<<"Player 2 Wins! Scissors beat Paper"<<endl;
                    break;
                default://if player 2 types an invalid entry
                    cout<<"Invalid Entry for Player 2"<<endl;
            }
            break;
        case's'://if player 1 picks s for Scissors
        case'S'://if player 1 picks S for Scissors
            switch(user2){
                case'r'://if player 2 picks r for rock
                case'R'://if player 2 picks R for rock
                    cout<<"Player 2 Wins! Rock beats Scissors"<<endl;
                    break;
                case'p'://if player 2 picks p for paper
                case'P'://if player 2 picks P for paper
                    cout<<"Player 1 Wins!Scissors beat Paper"<<endl;
                    break;
                case's'://if player 2 picks s for Scissors
                case'S'://if player 2 picks S for Scissors
                    cout<<"Nobody Wins. Tie Game"<<endl;
                    break;
                default://if player 2 types an invalid entry
                    cout<<"Invalid Entry for Player 2"<<endl;
            }
            break;
        default://if player 1 types an invalid entry
            cout<<"Invalid Entry for Player 1"<<endl;
    }
    return 0;
}
    