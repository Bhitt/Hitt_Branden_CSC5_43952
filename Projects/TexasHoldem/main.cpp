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
void round(short &,short &,short &,short &,string ,short [],short);//starts a new round of poker
void deal2(short &, short &, short [], short);//deal 2 cards
void deal3(short &,short &,short &,short [],short);// deal 3 cards
void deal1(short &,short [],short);//deal 1 card
short dekCrds(short []);//deck used for dealing
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
        round(p1Tot,p2Tot,p3Tot,p4Tot,player1,deck[]);
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
void round(short &a,short &b,short &c,short &d,string z,short deck[],short size){
    char contin='Y';
    short r1=0,r2=0,r3=0;//river card 1,2,3
    cout<<"You:$"<<a<<" | Tom:$"<<b<<" | Howard:$"<<c<<" | Phil:$"<<d<<endl;
    //Deal individual hands
    
    //Round of betting
    if(contin=='Y'){
        cout<<"You:$"<<a<<" | Tom:$"<<b<<" | Howard:$"<<c<<" | Phil:$"<<d<<endl;
        //Deal flop
        deal3(r1,r2,r3,deck[size]);
        cout<<"Table Cards: "<<cardVal(r1)<<" "<<cardVal(r2)<<" "<<cardVal(r3); 
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
//*********************************************//
//*             Deck of Cards                 *//
//*********************************************//
short dekCrds(short deck[]){
    char repeat;
    short card;
    do{
    card=rand()%52+1;
    if(deck[card]==0){
       repeat='Y'; 
    }else{
        repeat='N';
    }
    }while(repeat=='Y');
    deck[card]=0;
    return card;
}
//*********************************************//
//*               Deal 2                      *//
//*********************************************//
void deal2(short &c1,short &c2,short deck[],short size){
    c1=dekCrds(deck[size]);
    c2=dekCrds(deck[size]);
}
//*********************************************//
//*               Deal 3                      *//
//*********************************************//
void deal3(short &c1,short &c2,short &c3,short deck[],short size){
    c1=dekCrds(deck[size]);
    c2=dekCrds(deck[size]);
    c3=dekCrds(deck[size]);
}
//*********************************************//
//*               Deal 1                      *//
//*********************************************//
void deal1(short &c1,short deck[],short size){
    c1=dekCrds(deck[size]);
}
//*********************************************//
//*             Card Values                   *//
//*********************************************//
string cardVal(short v){
    string f;
    //Spades
    if(v==1)f="2 Spds"; 
    if(v==2) f="3 Spds";
    if(v==3) f="4 Spds";
    if(v==4) f="5 Spds";
    if(v==5) f="6 Spds";
    if(v==6) f="7 Spds";
    if(v==7) f="8 Spds";
    if(v==8) f="9 Spds";
    if(v==9) f="10 Spds";
    if(v==10) f="Jack Spds";
    if(v==11) f="Queen Spds";
    if(v==12) f="King Spds";
    if(v==13) f="Ace Spds";
    //Hearts
    if(v==14) f="2 Hrts";
    if(v==15) f="3 Hrts";
    if(v==16) f="4 Hrts";
    if(v==17) f="5 Hrts";
    if(v==18) f="6 Hrts";
    if(v==19) f="7 Hrts";
    if(v==20) f="8 Hrts";
    if(v==21) f="9 Hrts";
    if(v==22) f="10 Hrts";
    if(v==23) f="Jack Hrts";
    if(v==24) f="Queen Hrts";
    if(v==25) f="King Hrts";
    if(v==26) f="Ace Hrts";
    //Clubs
    if(v==27) f="2 Clbs";
    if(v==28) f="3 Clbs";
    if(v==29) f="4 Clbs";
    if(v==30) f="5 Clbs";
    if(v==31) f="6 Clbs";
    if(v==32) f="7 Clbs";
    if(v==33) f="8 Clbs";
    if(v==34) f="9 Clbs";
    if(v==35) f="10 Clbs";
    if(v==36) f="Jack Clbs";
    if(v==37) f="Queen Clbs";
    if(v==38) f="King Clbs";
    if(v==39) f="Ace Clbs";
    //Diamonds
    if(v==40) f="2 Dmds";
    if(v==41) f="3 Dmds";
    if(v==42) f="4 Dmds";
    if(v==43) f="5 Dmds";
    if(v==44) f="6 Dmds";
    if(v==45) f="7 Dmds";
    if(v==46) f="8 Dmds";
    if(v==47) f="9 Dmds";
    if(v==48) f="10 Dmds";
    if(v==49) f="Jack Dmds";
    if(v==50) f="Queen Dmds";
    if(v==51) f="King Dmds";
    if(v==52) f="Ace Dmds";
    return f;
}