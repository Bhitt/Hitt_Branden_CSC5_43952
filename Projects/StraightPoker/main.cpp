/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on May 6, 2015, 1:02 PM
 *      Purpose: Code a game of straight poker
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
void deal1(short &,short []);//deal 1 card
short ranking(short,short,short,short,short);//gives hand value
string cardVal(short);//finds what the card is for output
void allBet(short &,short &,short &,short &,string,short,short);//function to start betting
short compBet(short,short);//betting function for computer players
short playBet(short ,short );//betting function for player
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    srand(static_cast<unsigned int>(time(0)));
    char info,cPlayrs=2;
    string winner, player1;
    short p1Tot=50,p2Tot=50,p3Tot=50,p4Tot=50;
    short dButton=rand()%4+1;
    const short SIZE=53;
    short deck[SIZE]={};
    iniDeck(deck,SIZE);
    cout<<"This is a table for $5/10 limit Straight Poker."<<endl;
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
        round(p1Tot,p2Tot,p3Tot,p4Tot,player1,deck,dButton);
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
}
//*********************************************//
//*                New round                  *//
//*********************************************//
void round(short &a,short &b,short &c,short &d,string z,short x[],short button){
    //Declare variables
    short c1=0,c2=0,c3=0,c4=0,c5=0;//player cards
    short usrHand,ai1Hand,ai2Hand,ai3Hand;//hand values
    short ai1c1=0,ai1c2=0,ai1c3=0,ai1c4=0,ai1c5=0;//computer 1 hand
    short ai2c1=0,ai2c2=0,ai2c3=0,ai2c4=0,ai2c5=0;//computer 2 hand
    short ai3c1=0,ai3c2=0,ai3c3=0,ai3c4=0,ai3c5=0;//computer 3 hand
    short frstBet=button+1;
    short pot=0;
    //ante up
    cout<<"-$5 from everyone for the ante:"<<endl;
    a-=5,b-=5,c-=5,d-=5;
    pot+=20;
    cout<<"You:$"<<a<<" | Tom:$"<<b<<" | Howard:$"<<c<<" | Phil:$"<<d<<endl;
    cout<<"Pot: "<<pot<<endl;
    cout<<"*************************"<<endl;
    //Deal individual hands
    deal1(c1,x);
    deal1(c2,x);
    deal1(c3,x);
    deal1(c4,x);
    deal1(c5,x);
    deal1(ai1c1,x);
    deal1(ai1c2,x);
    deal1(ai1c3,x);
    deal1(ai1c4,x);
    deal1(ai1c5,x);
    deal1(ai2c1,x);
    deal1(ai2c2,x);
    deal1(ai2c3,x);
    deal1(ai2c4,x);
    deal1(ai2c5,x);
    deal1(ai3c1,x);
    deal1(ai3c2,x);
    deal1(ai3c3,x);
    deal1(ai3c4,x);
    deal1(ai3c5,x);
    //find hand value
    usrHand=ranking(c1,c2,c3,c4,c5);
    ai1Hand=ranking(ai1c1,ai1c2,ai1c3,ai1c4,ai1c5);
    ai2Hand=ranking(ai2c1,ai2c2,ai2c3,ai2c4,ai2c5);
    ai3Hand=ranking(ai3c1,ai3c2,ai3c3,ai3c4,ai3c5);
    if(usrHand==1)cout<<"Your hand value is low with just a high card."<<endl;
    if(usrHand==2)cout<<"Your hand value is low with just a pair."<<endl;
    if(usrHand==3)cout<<"Your have two pair."<<endl;
    if(usrHand==4)cout<<"Your have three of a kind. Not too bad."<<endl;
    if(usrHand==5)cout<<"Congrats! You have a straight."<<endl;
    if(usrHand==6)cout<<"Wow! You have a Flush."<<endl;
    if(usrHand==7)cout<<"What a strong hand. You have a Full House!"<<endl;
    if(usrHand==8)cout<<"Four of a Kind! Quick, don't let them see your excitement."<<endl;
    if(usrHand==9)cout<<"A Straight Flush! You can't be beat!"<<endl;
    //Display player hand
    cout<<"Your Hand: "<<cardVal(c1)<<"|"<<cardVal(c2)<<"|"<<cardVal(c3)<<
                "|"<<cardVal(c4)<<"|"<<cardVal(c5)<<endl;
    //allBet();
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
//*********************************************//
//*             Hand Ranking                  *//
//*********************************************//
short ranking(short a,short b,short c,short d,short e){
    //high card = 1
    short value=1,temp;
    char str='N',flu='N';
    //flush = 6
    if((a>=1&&a<=13)&&(b>=1&&b<=13)&&(c>=1&&c<=13)&&(d>=1&&d<=13)&&(e>=1&&e<=13)) value=6,flu='Y'; //spades
    if((a>=14&&a<=26)&&(b>=14&&b<=26)&&(c>=14&&c<=26)&&(d>=14&&d<=26)&&(e>=14&&e<=26)) value=6,flu='Y'; //hearts
    if((a>=27&&a<=39)&&(b>=27&&b<=39)&&(c>=27&&c<=39)&&(d>=27&&d<=39)&&(e>=27&&e<=39)) value=6,flu='Y'; //clubs
    if((a>=40&&a<=52)&&(b>=40&&b<=52)&&(c>=40&&c<=52)&&(d>=40&&d<=52)&&(e>=40&&e<=52)) value=6,flu='Y'; //diamonds
    //get rid of suits
    for(a;a>13;a-=13);
    for(b;b>13;b-=13);
    for(c;c>13;c-=13);
    for(d;d>13;d-=13);
    for(e;e>13;e-=13);
    //pair = 2
    if(a==b||a==c||a==d||a==e) value=2;
    if(b==c||b==d||b==e) value=2;
    if(c==d||c==e) value=2;
    if(d==e) value=2;
    //two pair = 3
    if((b==c&&d==e)||(b==d&&c==e)||(b==e&&c==d)) value=3;
    if((a==c&&d==e)||(a==e&&c==d)||(a==d&&c==e)) value=3;
    if((a==b&&d==e)||(a==e&&b==d)||(a==d&&b==e)) value=3;
    if((a==b&&c==e)||(a==e&&b==c)||(a==c&&b==e)) value=3;
    if((a==b&&c==d)||(a==c&&b==d)||(a==d&&b==c)) value=3;
    //three of a kind = 4
    if((c==d&&c==e)||(a==d&&a==e)||(a==b&&a==e)||(a==b&&a==c)) value=4;
    if((b==d&&b==e)||(a==c&&a==e)||(a==b&&a==d)) value=4;
    if((b==c&&b==e)||(a==c&&a==d)) value=4;
    if(b==c&&b==d) value=4;
    //sort for straight
        //sort first value
        if(a>b) temp=a,a=b,b=temp;
        if(a>c) temp=a,a=c,c=temp;
        if(a>d) temp=a,a=d,d=temp;
        if(a>e) temp=a,a=e,e=temp;
        //sort second value
        if(b>c) temp=b,b=c,c=temp;
        if(b>d) temp=b,b=d,d=temp;
        if(b>e) temp=b,b=e,e=temp;
        //sort third value
        if(c>d) temp=c,c=d,d=temp;
        if(c>e) temp=c,c=e,e=temp;
        //sort fourth value
        if(d>e) temp=d,d=e,e=temp;
    //straight = 5
    if((e-d==1)&&(d-c==1)&&(c-b==1)&&(b-a==1)) value=5,str='Y';
    //full house = 7
    if((c==d&&c==e&&a==b)||(a==d&&a==e&&b==c)||(a==b&&a==e&&c==d)||(a==b&&a==c&&d==e)) value=7;
    if((b==d&&b==e&&a==c)||(a==c&&a==e&&b==d)||(a==b&&a==d&&c==e)) value=7;
    if((b==c&&b==e&&a==d)||(a==c&&a==d&&b==e)) value=7;
    if(b==c&&b==d&&a==e) value=7;
    //four of a kind = 8
    if((b==c&&d==e&&c==d)||(a==c&&d==e&&c==d)||(a==b&&d==e&&b==d)) value=8;
    if((a==b&&c==e&&b==c)||(a==b&&c==d&&b==c)) value=8;
    //straight flush = 9
    if(flu=='Y'&&str=='Y') value=9;
    return value;
}
//*********************************************//
//*               All Bet                     *//
//*********************************************//
void allBet(short &a,short &b,short &c,short &d,string z,short fBet,short pot){
    //declare stuff
    string w="Tom",t="Howard",f="Phil",gun,garbage;
    short usrBet,curBet=0;
    char usrFold;
    //find the first person to bet
    if(fBet==5) fBet=1;
    if(fBet==1) gun=z;
    if(fBet==2) gun=w;
    if(fBet==3) gun=t;
    if(fBet==4) gun=f;
    //Round of betting
    cout<<"Betting starts with "<<gun<<endl;
    cout<<"Press Enter Now"<<endl;
    cin>>garbage;//ignore input
    cout<<"*************************"<<endl;
    if(fBet==1){
        //call player bet
    }
    fBet++;
    if(fBet==5) ;
    
    cout<<"Now it is your turn to bet. Please enter in 1 to check/call, 2 "<<
            "to make the Minimum bet, 3 to Max bet, or 4 to Fold."<<endl;
    cin>>usrBet;
    if(usrBet==4) usrFold='Y';
    else a-=curBet;
    if(usrBet==2) a-=5,pot+=5;
    if(usrBet==3) a-=10,pot+=10;
}
//*********************************************//
//*             Computer Bet                  *//
//*********************************************//
short compBet(short a,short b){
    //random betting option
    short choice=rand()%4+1;
    //folding option
    if(choice==4) return 0;
    //check total money for all-in
    if(choice==1&&b>=a) return 5;
    if(choice==2&&(b+5>=a)) return 5;
    if(choice==3&&(b+10>=a)) return 5;
    //regular bet
    if(choice==1) return 1;
    if(choice==2) return 2;
    if(choice==3) return 3;
}
//*********************************************//
//*               Player Bet                  *//
//*********************************************//
short playBet(short a,short b){
    //random betting option
    short choice=rand()%4+1;
    //folding option
    if(choice==4) return 0;
    //check total money for all-in
    if(choice==1&&b>=a) return 5;
    if(choice==2&&(b+5>=a)) return 5;
    if(choice==3&&(b+10>=a)) return 5;
    //regular bet
    if(choice==1) return 1;
    if(choice==2) return 2;
    if(choice==3) return 3;
}