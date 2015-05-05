/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on May 4, 2015, 10:40 AM
 *      Purpose: Code a game of texas hold'em
 */

//System Libraries
#include <iostream>//I/O standard
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void rules();//instructions on how to play
void rDsplay();//hand ranking display
void totals(short,short,short,short,string);// player totals
void dealBtn(short &,string);//gives dealer button
void round(short &,short &,short &,short &,string);//starts a new round of poker
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char info,cPlayrs=2;
    string winner, player1;
    short p1Tot=50,p2Tot=50,p3Tot=50,p4Tot=50;
    short dButton=4;
    cout<<"This is a table for $5/10 limit Texas Hold'em."<<endl;
    //Prompt for rules
    cout<<"If you would like instructions on how to play, then enter in 'I' now:"<<endl;
    cout<<"otherwise, enter in 'N'"<<endl;
    cin>>info;
    if(info=='I'||info=='i') rules();
    //Buy-in
    cout<<"*************************"<<endl;
    cout<<"Please first enter in your name:"<<endl;
    cin>>player1;
    cout<<"*************************"<<endl;
    cout<<"Hello, "<<player1<<"! Welcome to the table."<<endl;
    cout<<"The Buy-In for this table is $50"<<endl;
    cout<<"Please hit enter to buy your chips and begin"<<endl;
    cin.get();
    cin.ignore();
    cout<<"*************************"<<endl;
    cout<<"Welcome to the table. Meet the other players."<<endl;
    cout<<"To your left is Tom Dwan. Across from you is Howard Lederer. And to"<<endl;
    cout<<"your right is Phil Ivey. Good luck players."<<endl;
    do{
        //Give player totals
        cout<<"*************************"<<endl;
        totals(p1Tot,p2Tot,p3Tot,p4Tot,player1);
        //State dealer button location
        cout<<"*************************"<<endl;
        dealBtn(dButton,player1);
        //Start new round
        cout<<"*************************"<<endl;
        round(p1Tot,p2Tot,p3Tot,p4Tot,player1);
        //Adjust totals
        cout<<"*************************"<<endl;
        cout<<"This will adjust totals"<<endl;
        //Bust players if needed
        cout<<"*************************"<<endl;
        cout<<"This will bust any players from further action"<<endl;
        //Go back to new round if needed  
        cout<<"*************************"<<endl;
        cout<<"This will start a new round if needed."<<endl;
        cPlayrs--;//this is for testing purposes
    }while(cPlayrs>1);
    //Congratulate Winner
    cout<<"*************************"<<endl;
    cout<<"Congrats to "<<winner<<" for being the table's big winner."<<endl;
    cout<<"The grand total of winnings is $200"<<endl;
    cout<<"Thanks for playing"<<endl;
    //Exit Stage Right!
    return 0;
}
//*********************************************//
//*             Rules Function                *//
//*********************************************//              
void rules(){
    cout<<"This will be where the rules are displayed"<<endl;
}
//*********************************************//
//*         Hand Rankings Display             *//
//*********************************************//
void rDsplay(){
    cout<<"This is where the hand rankings will be displayed for the player"<<endl;
}
//*********************************************//
//*              Player Totals                *//
//*********************************************//
void totals(short a,short b,short c,short d, string plyr1){
    if(a<=0){
        cout<<plyr1<<" is busted with $0"<<endl;
    }else{
        cout<<plyr1<<" has $"<<a<<endl;
    }
    if(b<=0){
        cout<<"Tom Dwan is busted with $0"<<endl;
    }else{
        cout<<"Tom Dwan has $"<<b<<endl;
    }
    if(c<=0){
        cout<<"Howard is busted with $0"<<endl;
    }else{
        cout<<"Howard Lederer has $"<<c<<endl;
    }
    if(d<=0){
        cout<<"Phil Ivey is busted with $0"<<endl;
    }else{
        cout<<"Phil Ivey has $"<<d<<endl;  
    }
}
//*********************************************//
//*              Dealer Button                *//
//*********************************************//
void dealBtn(short &a, string b){
    //Shift button to the left
    if(a>=4) a=1;
    else a++;
    //Output the new dealer
    if(a==1) cout<<b<<" has the dealer button"<<endl;
    if(a==2) cout<<"Tom Dwan has the dealer button"<<endl;
    if(a==3) cout<<"Howard Lederer has the dealer button"<<endl;
    if(a==4) cout<<"Phil Ivey has the dealer button"<<endl;
}
//*********************************************//
//*                New round                  *//
//*********************************************//
void round(short &a,short &b,short &c,short &d,string z){
    char contin='Y';
    cout<<"You:$"<<a<<" | Tom:$"<<b<<" | Howard:$"<<c<<" | Phil:$"<<d<<endl;
    //Deal individual hands
    //Round of betting
    if(contin=='Y'){
        cout<<"You:$"<<a<<" | Tom:$"<<b<<" | Howard:$"<<c<<" | Phil:$"<<d<<endl;
        //Deal flop
        //Round of betting
        if(contin=='Y'){
            cout<<"You:$"<<a<<" | Tom:$"<<b<<" | Howard:$"<<c<<" | Phil:$"<<d<<endl;
            //Deal turn
            //Round of betting
            if(contin=='Y'){
                cout<<"You:$"<<a<<" | Tom:$"<<b<<" | Howard:$"<<c<<" | Phil:$"<<d<<endl;
                //Deal River
                //Round of betting
            }
        }
    }
    //Unveil winning hand and totals
    //Add pot to winner
}