/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on May 20, 2015, 9:50 AM
 *      Purpose: Tic-Tac-Toe
 */

//System Libraries
#include <iostream>//I/O standard
#include <iomanip>//formatting
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void inBoard(char [][3]);
void display(char [][3],short);
bool move(char [][3],short,short);
bool chkWin(char[][3]);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char board[3][3],winner;
    short cho,turns=0;
    bool win=false,check,tie=false;
    //reset the board
    inBoard(board);
    //Prompt the user for inputs
    cout<<"2 player Ti-Tac-Toe:"<<endl;
    cout<<endl;
    display(board,3);
    cout<<endl;
    do{
        do{
            cout<<"Player X it is your turn:"<<endl;
            cin>>cho;
            check=move(board,1,cho);
        }while(check==false||cho<1||cho>9);
        display(board,3);
        turns++;
        if(turns>=9) tie=true;
        win=chkWin(board);
        if(win==true)winner='X';
        if(win==false&&tie==false){
            do{
                cout<<"Player O it is your turn:"<<endl;
                cin>>cho;
                check=move(board,2,cho);
            }while(check==false||cho<1||cho>9);
            display(board,3);
            turns++;
            if(turns>=9) tie=true;
            win=chkWin(board);
            if(win==true) winner='O';
            }
    }while(win==false&&tie==false);
    //Output winner
    cout<<endl;
    if(win==true)cout<<"Congrats to player "<<winner<<"! They win!"<<endl;
    else if(tie==true)cout<<"Tie game"<<endl;
    return 0;
}
//function to reset the board
void inBoard(char a[][3]){
    a[0][0]='1',a[0][1]='2',a[0][2]='3';
    a[1][0]='4',a[1][1]='5',a[1][2]='6';
    a[2][0]='7',a[2][1]='8',a[2][2]='9';
}
//display
void display(char a[][3],short b){
    for (int i=0;i<b;i++){
        for(int i2=0;i2<3;i2++){
            cout<<setw(5)<<a[i][i2];
        }
        cout<<endl;
    }
}
//move
bool move(char a[][3],short p,short c){
    char piece='X';
    if(p==2) piece='O';
    //check for duplicates
    if(((c==1)&&(a[0][0]=='X'))||(c==1)&&(a[0][0]=='O')) return false;
    else if(((c==2)&&(a[0][1]=='X'))||(c==2)&&(a[0][1]=='O')) return false;
    else if(((c==3)&&(a[0][2]=='X'))||(c==3)&&(a[0][2]=='O')) return false;
    else if(((c==4)&&(a[1][0]=='X'))||(c==4)&&(a[1][0]=='O')) return false;
    else if(((c==5)&&(a[1][1]=='X'))||(c==5)&&(a[1][1]=='O')) return false;
    else if(((c==6)&&(a[1][2]=='X'))||(c==6)&&(a[1][2]=='O')) return false;
    else if(((c==7)&&(a[2][0]=='X'))||(c==7)&&(a[2][0]=='O')) return false;
    else if(((c==8)&&(a[2][1]=='X'))||(c==8)&&(a[2][1]=='O')) return false;
    else if(((c==9)&&(a[2][2]=='X'))||(c==9)&&(a[2][2]=='O')) return false;
    //change array
    if(c==1) a[0][0]=piece;
    else if(c==2) a[0][1]=piece;
    else if(c==3) a[0][2]=piece;
    else if(c==4) a[1][0]=piece;
    else if(c==5) a[1][1]=piece;
    else if(c==6) a[1][2]=piece;
    else if(c==7) a[2][0]=piece;
    else if(c==8) a[2][1]=piece;
    else if(c==9) a[2][2]=piece;
    return true;
}
//check win
bool chkWin(char a[][3]){
    //horizontal win
    if((a[0][0]==a[0][1])&&(a[0][0]==a[0][2])) return true;
    if((a[1][0]==a[1][1])&&(a[1][0]==a[1][2])) return true;
    if((a[2][0]==a[2][1])&&(a[2][0]==a[2][2])) return true;
    //vertical win
    if((a[0][0]==a[1][0])&&(a[0][0]==a[2][0])) return true;
    if((a[0][1]==a[1][1])&&(a[0][1]==a[2][1])) return true;
    if((a[0][2]==a[1][2])&&(a[0][2]==a[2][2])) return true;
    //diagonal win
    if((a[0][0]==a[1][1])&&(a[0][0]==a[2][2])) return true;
    if((a[0][2]==a[1][1])&&(a[0][2]==a[2][0])) return true;
    else{
        return false;
    }
}