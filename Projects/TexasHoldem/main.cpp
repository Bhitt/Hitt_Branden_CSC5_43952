/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on May 4, 2015, 10:40 AM
 *      Purpose: Code a game of texas hold'em
 */

//System Libraries
#include <iostream>//I/O standard
#include <ctime>//computer time
#include <cstdlib>//for random seed
#include <iomanip>//formatting
#include <string>//strings
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void rules();//instructions on how to play
void rDsplay();//hand ranking display
void totals(short,short,short,short,string);// player totals
void dealBtn(short &,string);//gives dealer button
void iniDeck(short [],short);//initializes and shuffles the deck
void round(short &,short &,short &,short &,string ,short []);//starts a new round of poker
void deal1(short &,short []);//deal 1 card
string cardVal(short);//finds what the card is for output
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    srand(static_cast<unsigned int>(time(0)));
    char info,cPlayrs=2;
    string winner, player1;
    short p1Tot=50,p2Tot=50,p3Tot=50,p4Tot=50;
    short dButton=4;
    const short SIZE=53;
    short deck[SIZE]={};
    iniDeck(deck,SIZE);
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
    cout<<"To your left is Tom Dwan, across from you is Howard Lederer, and to"<<endl;
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
        round(p1Tot,p2Tot,p3Tot,p4Tot,player1,deck);
        //Adjust totals
        cout<<"*************************"<<endl;
        cout<<"This will adjust totals"<<endl;
        //Bust players if needed
        cout<<"*************************"<<endl;
        cout<<"This will bust any players from further action"<<endl;
        //Shuffle and go back to new round if needed  
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
//*             Initialize Deck               *//
//*********************************************//
void iniDeck(short cards[],short n){
    for(int i=0;i<=n;i++){
        cards[i]=i;
    }
    //for(int i=0;i<=52;i++){
    //    cout<<deck[i]<<endl;
    //}
}
//*********************************************//
//*                New round                  *//
//*********************************************//
void round(short &a,short &b,short &c,short &d,string z,short x[]){
    char contin='Y';
    short f1=0,f2=0,f3=0;//flop card 1,2,3
    short t1,r1;//turn and river cards
    cout<<"You:$"<<a<<" | Tom:$"<<b<<" | Howard:$"<<c<<" | Phil:$"<<d<<endl;
    //Deal individual hands
    
    //Round of betting
    if(contin=='Y'){
        cout<<"You:$"<<a<<" | Tom:$"<<b<<" | Howard:$"<<c<<" | Phil:$"<<d<<endl;
        //Deal flop
        deal1(f1,x);
        deal1(f2,x);
        deal1(f3,x);
        cout<<"Table Cards: "<<cardVal(f1)<<"|"<<cardVal(f2)<<"|"<<cardVal(f3)<<endl; 
        //Round of betting
        if(contin=='Y'){
            cout<<"You:$"<<a<<" | Tom:$"<<b<<" | Howard:$"<<c<<" | Phil:$"<<d<<endl;
            //Deal turn
            deal1(t1,x);
            cout<<"Table Cards: "<<cardVal(f1)<<"|"<<cardVal(f2)<<"|"
                    <<cardVal(f3)<<"|"<<cardVal(t1)<<endl;
            //Round of betting
            if(contin=='Y'){
                cout<<"You:$"<<a<<" | Tom:$"<<b<<" | Howard:$"<<c<<" | Phil:$"<<d<<endl;
                //Deal River
                deal1(r1,x);
                cout<<"Table Cards: "<<cardVal(f1)<<"|"<<cardVal(f2)<<"|"
                    <<cardVal(f3)<<"|"<<cardVal(t1)<<"|"<<cardVal(r1)<<endl;
                //Round of betting
            }
        }
    }
    //Unveil winning hand and totals
    //Add pot to winner
}
//*********************************************//
//*               Deal 1                      *//
//*********************************************//
void deal1(short &c1,short y[]){
    char repeat;
    short card;
    do{
    card=rand()%52+1;
    if(y[card]==0){
       repeat='Y'; 
    }else{
        repeat='N';
    }
    }while(repeat=='Y');
    y[card]=0;
    c1=card;
}
//*********************************************//
//*             Card Values                   *//
//*********************************************//
string cardVal(short v){
    string f;
    //Spades
    if(v==1)f="2 Spades"; 
    if(v==2) f="3 Spades";
    if(v==3) f="4 Spades";
    if(v==4) f="5 Spades";
    if(v==5) f="6 Spades";
    if(v==6) f="7 Spades";
    if(v==7) f="8 Spades";
    if(v==8) f="9 Spades";
    if(v==9) f="10 Spades";
    if(v==10) f="Jack Spades";
    if(v==11) f="Queen Spades";
    if(v==12) f="King Spades";
    if(v==13) f="Ace Spades";
    //Hearts
    if(v==14) f="2 Hearts";
    if(v==15) f="3 Hearts";
    if(v==16) f="4 Hearts";
    if(v==17) f="5 Hearts";
    if(v==18) f="6 Hearts";
    if(v==19) f="7 Hearts";
    if(v==20) f="8 Hearts";
    if(v==21) f="9 Hearts";
    if(v==22) f="10 Hearts";
    if(v==23) f="Jack Hearts";
    if(v==24) f="Queen Hearts";
    if(v==25) f="King Hearts";
    if(v==26) f="Ace Hearts";
    //Clubs
    if(v==27) f="2 Clubs";
    if(v==28) f="3 Clubs";
    if(v==29) f="4 Clubs";
    if(v==30) f="5 Clubs";
    if(v==31) f="6 Clubs";
    if(v==32) f="7 Clubs";
    if(v==33) f="8 Clubs";
    if(v==34) f="9 Clubs";
    if(v==35) f="10 Clubs";
    if(v==36) f="Jack Clubs";
    if(v==37) f="Queen Clubs";
    if(v==38) f="King Clubs";
    if(v==39) f="Ace Clubs";
    //Diamonds
    if(v==40) f="2 Diamonds";
    if(v==41) f="3 Diamonds";
    if(v==42) f="4 Diamonds";
    if(v==43) f="5 Diamonds";
    if(v==44) f="6 Diamonds";
    if(v==45) f="7 Diamonds";
    if(v==46) f="8 Diamonds";
    if(v==47) f="9 Diamonds";
    if(v==48) f="10 Diamonds";
    if(v==49) f="Jack Diamonds";
    if(v==50) f="Queen Diamonds";
    if(v==51) f="King Diamonds";
    if(v==52) f="Ace Diamonds";
    return f;
}