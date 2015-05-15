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
#include <fstream>//file in/out
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void rules();//instructions on how to play
void iniDeck(short [],short);//initializes and shuffles the deck
short round(string ,short []);//starts a new round of poker
void deal1(short &,short []);//deal 1 card
short ranking(short ,short ,short ,short ,short,short &);//gives hand value
string aiRank(short); //finds ranking of computer hand
string cardVal(short);//finds what the card is for output
void hiCard(short &,short &,short &,short &,short &);//sort for high card
short winHand(short,short,short,short,short,short,short,short);//find winning hand
string winner(string,short);//find round winner
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    ofstream fout;//output to file
    fout.open("Results.Dat");
    srand(static_cast<unsigned int>(time(0)));
    char info,repeat;//input for info query, and repeat query
    short p1Rw=0,p2Rw=0,p3Rw=0,p4Rw=0;//total wins for each player
    string winner, player1;//overall winner and player name input
    const short SIZE=53;//size of the deck
    short deck[SIZE]={};//declare array with zeros
    short rWin=0;//current round win
    float perWin,totR=0;//percentage of wins for the player/ totals rounds
    iniDeck(deck,SIZE);//fill array with card values (1-52)
    cout<<"This is a table for Straight Poker."<<endl;
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
    cout<<"Please hit enter to begin"<<endl;
    cin.get();
    cin.ignore();
    cout<<"*************************"<<endl;
    cout<<"Now that you are seated, why don't you meet the other players."<<endl;
    cout<<"To your left is Tom Dwan, across from you is Howard Lederer, and to"<<endl;
    cout<<"your right is Phil Ivey. Good luck players."<<endl;
    cout<<"Please hit enter twice to continue"<<endl;
    cin.get();
    cin.ignore();
    do{
        //Start new round
        rWin=round(player1,deck);
        if(rWin==1) p1Rw++;//player 1 win
        if(rWin==2) p2Rw++;//player 2 win
        if(rWin==3) p3Rw++;//player 3 win
        if(rWin==4) p4Rw++;//player 4 win
        //Shuffle and go back to new round if needed
        iniDeck(deck,SIZE);
        totR++;//increment the total rounds
        cout<<"*************************"<<endl;
        cout<<"Would you like to play another hand?"<<endl;
        cout<<"Enter in Y for yes or N for no:"<<endl;
        cin>>repeat;//prompt for new round
    }while(repeat=='Y'||repeat=='y');
    //Congratulate Overall Winner
    cout<<"*************************"<<endl;
    winner=player1+" ";
    short highRW=p1Rw;
    if(p2Rw>highRW) winner="Tom Dwan ", highRW=p2Rw;
    else if(p2Rw==highRW) winner+="& Tom Dwan ";
    if(p3Rw>highRW) winner="Howard Lederer ", highRW=p3Rw;
    else if(p3Rw==highRW) winner+="& Howard Lederer ";
    if(p4Rw>highRW) winner="Phil Ivey ", highRW=p4Rw;
    else if(p4Rw==highRW) winner+="& Phil Ivey ";
    cout<<"Congrats to "<<winner<<"for being the table's big winner(s)."<<endl;
    cout<<"Out of "<<totR<<" total round(s), "<<winner<<"won "<<highRW<<" round(s) of Poker."<<endl;
    cout<<"Thank you for playing!"<<endl;
    cout<<endl;
    cout<<"(Your results can be found in Results.dat)"<<endl;
    perWin=((p1Rw*1.0f)/totR)*100.0f;
    //output results to a file
    fout<<fixed<<setprecision(2)<<showpoint;
    fout<<"Player name : "<<player1<<endl;
    fout<<"Round Wins  : "<<p1Rw<<endl;
    fout<<"Total Rounds: "<<totR<<endl;
    fout<<"Percent Win : %"<<perWin;
    fout.close();
    //Exit Stage Right!
    return 0;
}
//*********************************************//
//*             Rules Function                *//
//*********************************************//              
void rules(){
    char menu,cho='N';
    bool skip=false;
    cout<<"*************************"<<endl;
    cout<<"How to Play:"<<endl;
    cout<<"Each player is dealt 5 random cards (or a Hand) from a standard 52-card deck."<<endl;
    cout<<"Whoever has the best combination of cards based on rankings will win the round."<<endl;
    cout<<"The more rare the hand, the higher the ranking will be."<<endl;
    cout<<"The worst hand is nothing special with just a High Card, while the best is a Royal Flush."<<endl;
    cout<<"In the event that two players have the same hand, the higher card (pair,flush,etc)"<<endl;
    cout<<"will win."<<endl;
     do{
    cout<<"The Hand Rankings are as followed:"<<endl;
    cout<<"0.High Card | 1.Pair | 2.Two Pair | 3.Three of a Kind | 4.Straight "<<endl;
    cout<<"5.Flush | 6.Full House | 7.Four of a Kind | 8.Straight Flush | 9.Royal Flush"<<endl;
    cout<<"*************************"<<endl;
    cout<<"To view an example/explanation of a specific hand, enter in"<<endl;
    cout<<"the corresponding number. (for example: enter in 4 to view a straight)"<<endl;
    cout<<"Otherwise, enter in S to get started:"<<endl;
    cout<<"*************************"<<endl;
    cin>>menu;
    cout<<"*************************"<<endl;
    switch(menu){
        case'0':{
            cout<<"High Card: This hand has nothing to rely on but a High card."<<endl;
            cout<<"Ex: 3 Diamonds | Jack Clubs | 8 Spades | 4 Hearts | 2 Spades"<<endl;
            break;
        }
        case'1':{
            cout<<"Pair: Two cards of the same rank."<<endl;
            cout<<"Ex: Ace Hearts | Ace Diamonds | 8 Clubs | 4 Spades | 7 Hearts"<<endl;
            break;
        }
        case'2':{
            cout<<"Two Pair: Two different pairs of cards."<<endl;
            cout<<"Ex: 4 Spades | 4 Clubs | 3 Clubs | 3 Diamonds | Queen Clubs"<<endl;
            break;
        }
        case'3':{
            cout<<"Three of a Kind: Three cards of the same rank."<<endl;
            cout<<"Ex: 7 Clubs | 7 Diamonds | 7 Spades | King Clubs | 3 Diamonds"<<endl;
            break;
        }
        case'4':{
            cout<<"Straight: Five cards in a sequence, but not of the same suit."<<endl;
            cout<<"Ex: 5 Hearts | 6 Diamonds | 7 Spades | 8 Diamonds | 9 Clubs"<<endl;
            break;
        }
        case'5':{
            cout<<"Flush: Any five cards of the same suit, but not in a sequence."<<endl;
            cout<<"Ex: 4 Spades | Jack Spades | 8 Spades | 2 Spades | 9 Spades"<<endl;
            break;
        }
        case'6':{
            cout<<"Full House: Three of a Kind and a Pair."<<endl;
            cout<<"Ex: 10 Hearts | 10 Diamonds | 10 Spades | 9 Clubs | 9 Diamonds"<<endl;
            break;
        }
        case'7':{
            cout<<"Four of a Kind: All four cards of the same rank."<<endl;
            cout<<"Ex: Jack Hearts | Jack Spades | Jack Diamonds | Jack Clubs | 7 Hearts"<<endl;
            break;
        }
        case'8':{
            cout<<"Straight Flush: Five cards in a sequence, all in the same suit."<<endl;
            cout<<"Ex: 4 Spades | 5 Spades | 6 Spades | 7 Spades | 8 Spades"<<endl;
            break;
        }
        case'9':{
            cout<<"Royal Flush: 10, J, Q, K, A (all in the same suit)."<<endl;
            cout<<"Ex: 10 Spades | Jack Spades | Queen Spades | King Spades | Ace Spades"<<endl;
            break;
        }
        default:{
            cho=='N';
            skip=true;
            break;
        }    
    }
    if(skip==false){
    cout<<"*************************"<<endl;
    cout<<"Would you like to view another Hand Ranking?"<<endl;
    cout<<"Enter in Y for yes or N for no:"<<endl;
    cin>>cho;
    cout<<"*************************"<<endl;
    }
    }while(cho=='Y'||cho=='y');
}
//*********************************************//
//*             Initialize Deck               *//
//*********************************************//
void iniDeck(short cards[],short n){
    for(int i=0;i<n;i++){
        cards[i]=i;
    }
}
//*********************************************//
//*                New round                  *//
//*********************************************//
short round(string z,short x[]){
    //Declare variables
    short c1=0,c2=0,c3=0,c4=0,c5=0;//player cards
    short usrHand,ai1Hand,ai2Hand,ai3Hand;//hand values
    short ai1c1=0,ai1c2=0,ai1c3=0,ai1c4=0,ai1c5=0;//computer 1 hand
    short ai2c1=0,ai2c2=0,ai2c3=0,ai2c4=0,ai2c5=0;//computer 2 hand
    short ai3c1=0,ai3c2=0,ai3c3=0,ai3c4=0,ai3c5=0;//computer 3 hand
    short hc=0,ai1hc=0,ai2hc=0,ai3hc=0;//high card for tie hands
    short winNum;//player number who has top hand
    string ai1R,ai2R,ai3R,plR; //quick string for hand ranking
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
    //high card and sort
    hiCard(c1,c2,c3,c4,c5);
    hiCard(ai1c1,ai1c2,ai1c3,ai1c4,ai1c5);
    hiCard(ai2c1,ai2c2,ai2c3,ai2c4,ai2c5);
    hiCard(ai3c1,ai3c2,ai3c3,ai3c4,ai3c5);
    //find hand value
    usrHand=ranking(c1,c2,c3,c4,c5,hc);
    ai1Hand=ranking(ai1c1,ai1c2,ai1c3,ai1c4,ai1c5,ai1hc);
    ai2Hand=ranking(ai2c1,ai2c2,ai2c3,ai2c4,ai2c5,ai2hc);
    ai3Hand=ranking(ai3c1,ai3c2,ai3c3,ai3c4,ai3c5,ai3hc);
    //set string for ai hand ranking
    plR=aiRank(usrHand);
    ai1R=aiRank(ai1Hand);
    ai2R=aiRank(ai2Hand);
    ai3R=aiRank(ai3Hand);
    //state hand value
    if(usrHand==1)cout<<"Your hand value is low with just a high card ("<<cardVal(c5)<<")."<<endl;
    if(usrHand==2)cout<<"Your hand value is average with just a pair."<<endl;
    if(usrHand==3)cout<<"You have two pair."<<endl;
    if(usrHand==4)cout<<"You have three of a kind. Not too bad."<<endl;
    if(usrHand==5)cout<<"Congrats! You have a straight."<<endl;
    if(usrHand==6)cout<<"Wow! You have a Flush."<<endl;
    if(usrHand==7)cout<<"What a strong hand. You have a Full House!"<<endl;
    if(usrHand==8)cout<<"Four of a Kind! Quick, don't let them see your excitement."<<endl;
    if(usrHand==9)cout<<"A Straight Flush! You can't be beat!"<<endl;
    //Display player hand
    cout<<"Your Hand: "<<cardVal(c1)<<"|"<<cardVal(c2)<<"|"<<cardVal(c3)<<
                "|"<<cardVal(c4)<<"|"<<cardVal(c5)<<endl;
    cout<<"Please hit enter twice to see everyone's hands:"<<endl;
    cin.get();
    cin.ignore();
    //Unveil all hands
    cout<<"*************************"<<endl;
    cout<<"               All Player Hands     "<<endl;
    cout<<"Your Hand: "<<cardVal(c1)<<"|"<<cardVal(c2)<<"|"<<cardVal(c3)<<
                "|"<<cardVal(c4)<<"|"<<cardVal(c5)<<"  ("<<plR<<")"<<endl;
    cout<<"Tom's Hand: "<<cardVal(ai1c1)<<"|"<<cardVal(ai1c2)<<"|"<<cardVal(ai1c3)<<
                "|"<<cardVal(ai1c4)<<"|"<<cardVal(ai1c5)<<"  ("<<ai1R<<")"<<endl;
    cout<<"Howard's Hand: "<<cardVal(ai2c1)<<"|"<<cardVal(ai2c2)<<"|"<<cardVal(ai2c3)<<
                "|"<<cardVal(ai2c4)<<"|"<<cardVal(ai2c5)<<"  ("<<ai2R<<")"<<endl;
    cout<<"Phil's Hand: "<<cardVal(ai3c1)<<"|"<<cardVal(ai3c2)<<"|"<<cardVal(ai3c3)<<
                "|"<<cardVal(ai3c4)<<"|"<<cardVal(ai3c5)<<"  ("<<ai3R<<")"<<endl;
    //Unveil winning hand
    cout<<"Please hit enter twice to find the winning hand:"<<endl;
    cin.get();
    cin.ignore();
    cout<<"*************************"<<endl;
    winNum=winHand(usrHand,ai1Hand,ai2Hand,ai3Hand,hc,ai1hc,ai2hc,ai3hc);
    string rndWinr=winner(z,winNum);
    cout<<rndWinr<<" has the winning hand. "<<endl;
    cout<<"Please hit enter twice to continue:"<<endl;
    cin.get();
    cin.ignore();
    cout<<"*************************"<<endl;
    return winNum;
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
short ranking(short a,short b,short c,short d,short e, short &hi1){
    //high card hand value= 1
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
    //high card for flush
    if(value==6) hi1=e;
    //pair = 2
    if(a==b||a==c||a==d) value=2,hi1=a;
    if(a==e)value=2,hi1=a;
    if(b==c||b==d) value=2,hi1=b;
    if(c==d) value=2,hi1=c;
    if(c==e) value=2,hi1=c;
    if(d==e) value=2,hi1=e;
    if(b==e) value=2,hi1=e;
    //two pair = 3
    if((b==c&&d==e)||(b==d&&c==e)||(b==e&&c==d)) value=3,hi1=b;
    if((a==c&&d==e)||(a==e&&c==d)||(a==d&&c==e)) value=3,hi1=a;
    if((a==b&&d==e)||(a==e&&b==d)||(a==d&&b==e)) value=3,hi1=a;
    if((a==b&&c==e)||(a==e&&b==c)||(a==c&&b==e)) value=3,hi1=a;
    if((a==b&&c==d)||(a==c&&b==d)||(a==d&&b==c)) value=3,hi1=a;
    //three of a kind = 4
    if((a==d&&a==e)||(a==b&&a==e)||(a==b&&a==c)) value=4,hi1=a;
    if((c==d&&c==e)||(b==d&&b==e)) value=4,hi1=e;
    if((a==c&&a==e)||(a==b&&a==d)) value=4,hi1=a;
    if((b==c&&b==e)||(a==c&&a==d)) value=4,hi1=c;
    if(b==c&&b==d) value=4,hi1=b;
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
    if((e-d==1)&&(d-c==1)&&(c-b==1)&&(b-a==1)) value=5,str='Y',hi1=e;
    if((a==1)&&(b==2)&&(c==3)&&(d==4)&&(e==13)) value=5,str='Y',hi1=e;
    //full house = 7
    if((c==d&&c==e&&a==b)||(a==d&&a==e&&b==c)) value=7,hi1=d;
    if((a==b&&a==e&&c==d)||(a==b&&a==c&&d==e)) value=7,hi1=a;
    if((a==c&&a==e&&b==d)||(a==b&&a==d&&c==e)) value=7,hi1=a;
    if((b==d&&b==e&&a==c)||(b==c&&b==d&&a==e)) value=7,hi1=b;
    if((b==c&&b==e&&a==d)||(a==c&&a==d&&b==e)) value=7,hi1=c;
    //four of a kind = 8
    if((b==c&&d==e&&c==d)||(a==c&&d==e&&c==d)||(a==b&&d==e&&b==d)) value=8,hi1=d;
    if((a==b&&c==e&&b==c)||(a==b&&c==d&&b==c)) value=8,hi1=a;
    //straight flush = 9
    if(flu=='Y'&&str=='Y') value=9;
    return value;
}
//*********************************************//
//*             Computer Hand                 *//
//*********************************************//
string aiRank(short a){
    string state;
    if(a==1)state="High card";
    if(a==2)state="Pair";
    if(a==3)state="Two Pair";
    if(a==4)state="Three of a Kind";
    if(a==5)state="Straight";
    if(a==6)state="Flush";
    if(a==7)state="Full House";
    if(a==8)state="Four of a Kind";
    if(a==9)state="Straight Flush";
    return state;
}
//*********************************************//
//*               High Card/Sort              *//
//*********************************************//
void hiCard(short &a,short &b,short &c,short &d,short &e){
    short tempa=a,tempb=b,tempc=c,tempd=d,tempe=e;
    short temp=0;
    //get rid of suits
    for(tempa;tempa>13;tempa-=13);
    for(tempb;tempb>13;tempb-=13);
    for(tempc;tempc>13;tempc-=13);
    for(tempd;tempd>13;tempd-=13);
    for(tempe;tempe>13;tempe-=13);
    //sort first value
    if(tempa>tempb){
        temp=tempa,tempa=tempb,tempb=temp;
        temp=a,a=b,b=temp;
    }
    if(tempa>tempc){
        temp=tempa,tempa=tempc,tempc=temp;
        temp=a,a=c,c=temp;
    }
    if(tempa>tempd){
        temp=tempa,tempa=tempd,tempd=temp;
        temp=a,a=d,d=temp;
    }
    if(tempa>tempe){
        temp=tempa,tempa=tempe,tempe=temp;
        temp=a,a=e,e=temp;
    }
    //sort second value
    if(tempb>tempc){
        temp=tempb,tempb=tempc,tempc=temp;
        temp=b,b=c,c=temp;
    }
    if(tempb>tempd){
        temp=tempb,tempb=tempd,tempd=temp;
        temp=b,b=d,d=temp;
    }
    if(tempb>tempe){
        temp=tempb,tempb=tempe,tempe=temp;
        temp=b,b=e,e=temp;
    }
    //sort third value
    if(tempc>tempd){
        temp=tempc,tempc=tempd,tempd=temp;
        temp=c,c=d,d=temp;
    }
    if(tempc>tempe){
        temp=tempc,tempc=tempe,tempe=temp;
        temp=c,c=e,e=temp;
    }
    //sort fourth value
    if(tempd>tempe){
        temp=tempd,tempd=tempe,tempe=temp;
        temp=d,d=e,e=temp;
    }
}
//*********************************************//
//*               Winning Hand                *//
//*********************************************//
short winHand(short a,short b,short c,short d,short h1,short h2,short h3,short h4){
    //find top hand value
    short topHand=a,pl1=0,pl2=0,pl3=0,pl4=0,win;
    if(b>topHand) topHand=b;
    if(c>topHand) topHand=c;
    if(d>topHand) topHand=d;
    //find all that have the value of the top hand
    if(a==topHand) pl1=1;
    if(b==topHand) pl2=1;
    if(c==topHand) pl3=1;
    if(d==topHand) pl4=1;
    //compare ties for top hand
    if((pl1==1)&&(pl2==1)){
        if(h1>h2) win=1;
        if(h2>h1) win=2;
    }
    if((pl1==1)&&(pl3==1)){
        if(h1>h3) win=1;
        if(h3>h1) win=3;
    }
    if((pl1==1)&&(pl4==1)){
        if(h1>h4) win=1;
        if(h4>h1) win=4;
    }
    if((pl2==1)&&(pl3==1)){
        if(h2>h3) win=2;
        if(h3>h2) win=3;
    }
    if((pl2==1)&&(pl4==1)){
        if(h2>h4) win=2;
        if(h4>h2) win=4;
    }
    if((pl3==1)&&(pl4==1)){
        if(h3>h4) win=3;
        if(h4>h3) win=4;
    }
    if((pl1==1)&&(pl2==1)&&(pl3==1)){
        if(h1>h2&&h1>h3) win=1;
        if(h2>h1&&h2>h3) win=2;
        if(h3>h1&&h3>h2) win=3;
    }
    if((pl1==1)&&(pl3==1)&&(pl4==1)){
        if(h1>h4&&h1>h3) win=1;
        if(h4>h1&&h4>h3) win=4;
        if(h3>h1&&h3>h4) win=3;
    }
    if((pl1==1)&&(pl2==1)&&(pl4==1)){
        if(h1>h2&&h1>h4) win=1;
        if(h2>h1&&h2>h4) win=2;
        if(h4>h1&&h4>h2) win=4;
    }
    if((pl3==1)&&(pl2==1)&&(pl4==1)){
        if(h3>h2&&h3>h4) win=3;
        if(h2>h3&&h2>h4) win=2;
        if(h4>h3&&h4>h2) win=4;
    }
    if((pl1==1)&&(pl2==1)&&(pl3==1)&&(pl4==1)){
        if(h1>h2&&h1>h3&&h1>h4) win=1;
        if(h2>h1&&h2>h3&&h2>h4) win=2;
        if(h3>h2&&h3>h1&&h3>h4) win=3;
        if(h4>h2&&h4>h3&&h4>h1) win=4;
    }
    if((pl1==1)&&(pl2==0)&&(pl3==0)&&(pl4==0)) win=1;
    if((pl1==0)&&(pl2==1)&&(pl3==0)&&(pl4==0)) win=2;
    if((pl1==0)&&(pl2==0)&&(pl3==1)&&(pl4==0)) win=3;
    if((pl1==0)&&(pl2==0)&&(pl3==0)&&(pl4==1)) win=4;
    //return win
    return win;
}
//*********************************************//
//*            Winning Player                 *//
//*********************************************//
string winner(string you,short a){
    string winner; 
    if(a==1) winner=you;
    if(a==2) winner="Tom";
    if(a==3) winner="Howard";
    if(a==4) winner="Phil";
    if(a<1||a>4) winner="(Tie Game) No one";
    return winner;
}