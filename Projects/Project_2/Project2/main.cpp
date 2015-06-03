/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on May 6, 2015, 1:02 PM
 * Notes for next update: work on betting
 *      Purpose: Head's Up Texas Holdem
 */

//System Libraries
#include <iostream>//I/O standard
#include <ctime>//computer time
#include <cstdlib>//for random seed
#include <iomanip>//formatting
#include <string>//for strings
#include <fstream>//file in/out
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void rules();//instructions on how to play
void iniDeck(short [],short);//initializes and shuffles the deck
short round(string ,short []);//starts a new round of poker
void deal1(short &,short []);//deal 1 card
short ranking(short ,short ,short ,short ,short,short &,short &);//gives hand value
string sRank(short); //finds a short string rank of hand
string cardVal(short);//finds what the card is for output
void hiCard(short &,short &,short &,short &,short &);//sort for high card
short bestCom(short,short,short,short,short,short,short);//find best version of your hand
void finCom(short &,short &,short &,short &,short &,short,short,short,short,short,short,short,short);//set hand with best combination
short winHand(short,short,short,short,short,short);//find winning hand between two players
string winner(string,short);//find round winner

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    ofstream fout;//output to file
    fout.open("Results.Dat");//open file
    srand(static_cast<unsigned int>(time(0)));//set random seed
    char info,repeat;//input for info query, and repeat query
    short p1Rw=0,p2Rw=0;//total wins for each player
    string winner, player1;//overall winner and player name input
    const short SIZE=53;//size of the deck
    short deck[SIZE]={};//declare array with zeros
    short rWin=0;//current round win
    float perWin; int totR=0;//percentage of wins for the player/ totals rounds
    iniDeck(deck,SIZE);//fill array with card values (1-52)
    cout<<"This is a table for Heads Up Texas Hold'em."<<endl;
    //Prompt for rules
    cout<<"If you would like instructions on how to play, enter in 'I' now:"<<endl;
    cout<<"otherwise, enter in 'N'"<<endl;
    cin>>info;
    if(info=='I'||info=='i') rules();
    //prompt for name of player
    cout<<"*************************"<<endl;
    cout<<"Please first enter in your name:"<<endl;
    cin.ignore();
    getline(cin,player1);
    cout<<"*************************"<<endl;
    cout<<"Hello, "<<player1<<"! Welcome to the table."<<endl;
    cout<<"Please hit enter to begin"<<endl;
    cin.get();
    cin.ignore();
    cout<<"*************************"<<endl;
    cout<<"Now that you are seated, why don't you meet your opponent."<<endl;
    cout<<"Across from you is poker legend, Phil Hellmuth."<<endl;
    cout<<"Phil is a 13 time World Series of Poker Champion with"<<endl;
    cout<<"$18,282,014 in winnings!"<<endl;
    cout<<"Please hit enter twice to continue"<<endl;
    cin.get();
    cin.ignore();
    do{//do
        //Start new round
        rWin=round(player1,deck);
        if(rWin==1) p1Rw++;//if 1 player 1 win round
        if(rWin==2) p2Rw++;//if 2 player 2 win round
        //Shuffle 
        iniDeck(deck,SIZE);
        totR++;//increment the total rounds
        cout<<"*************************"<<endl;
        cout<<"Would you like to play another hand?"<<endl;
        cout<<"Enter in Y for yes or N for no:"<<endl;
        cin>>repeat;//prompt for new round
    }while(repeat=='Y'||repeat=='y');//while player wants to repeat
    //Congratulate Overall Winner
    cout<<"*************************"<<endl;
    short highRW=p1Rw;
    winner=player1;
    if(p2Rw>highRW) winner="Phil Helmuth ", highRW=p2Rw;
    cout<<"Congrats to "<<winner<<" for being the table's big winner."<<endl;
    cout<<"Out of "<<totR<<" total round(s), "<<winner<<" won "<<highRW<<" round(s) of Poker."<<endl;
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
    //declare variables
    char menu,cho='N';//menu / choice
    bool skip=false;//bool for skip 
    cout<<"*************************"<<endl;
    cout<<"How to Play:"<<endl;//begin explanation of how to play
    cout<<"Step1:"<<endl;
    cout<<"First both players pay an ante (forced $5 bet to join the round)"<<endl;
    cout<<"Each player is dealt 2 cards (hole cards) from a standard 52-card deck."<<endl;
    cout<<"Then each player will have a chance to bet/fold."<<endl;
    cout<<"Note that a player may fold at any time during the game but will lose the pot."<<endl;
    cout<<"*************************"<<endl;
    cout<<"Please hit enter to continue"<<endl;
    cin.get();
    cin.ignore();
    cout<<"*************************"<<endl;
    cout<<"Step 2:"<<endl;
    cout<<"From there, 3 community cards will be dealt to the center called the flop."<<endl;
    cout<<"(Community cards will be used in combination with/without any of your hole cards"<<endl;
    cout<<"to determine your final hand)"<<endl;
    cout<<"Again, there will be a round of betting"<<endl;
    cout<<"*************************"<<endl;
    cout<<"Please hit enter to continue"<<endl;
    cin.get();
    cin.ignore();
    cout<<"*************************"<<endl;
    cout<<"Step 3:"<<endl;
    cout<<"Next, 1 more community card will be dealt called the turn."<<endl;
    cout<<"Another round of betting."<<endl;
    cout<<"*************************"<<endl;
    cout<<"Please hit enter to continue"<<endl;
    cin.get();
    cin.ignore();
    cout<<"*************************"<<endl;
    cout<<"Step 4:"<<endl;
    cout<<"Finally, 1 final community card will be dealt to the center called the river."<<endl;
    cout<<"Now that all 5 community cards are on the table, you can use any combination of them"<<endl;
    cout<<"with/without your hole cards to get the best hand you can."<<endl;
    cout<<"There is one final round of betting."<<endl;
    cout<<"*************************"<<endl;
    cout<<"Please hit enter to continue"<<endl;
    cin.get();
    cin.ignore();
    cout<<"*************************"<<endl;
    cout<<"Whoever has the best combination of cards based on rankings will win the round/pot."<<endl;
    cout<<"The more rare the hand, the higher the ranking will be."<<endl;
    cout<<"The worst hand is nothing special with just a High Card, while the best is a Royal Flush."<<endl;
    cout<<"In the event that two players have the same hand, the higher card (pair,flush,etc)"<<endl;
    cout<<"will win."<<endl;
     do{//do
    cout<<"The Hand Rankings are as followed:"<<endl;//start showing hand rankings
    cout<<"0.High Card | 1.Pair | 2.Two Pair | 3.Three of a Kind | 4.Straight "<<endl;
    cout<<"5.Flush | 6.Full House | 7.Four of a Kind | 8.Straight Flush | 9.Royal Flush"<<endl;
    cout<<"*************************"<<endl;
    cout<<"To view an example/explanation of a specific hand, enter in"<<endl;
    cout<<"the corresponding number. (for example: enter in 4 to view a straight)"<<endl;
    cout<<"Otherwise, enter in S to get started:"<<endl;
    cout<<"*************************"<<endl;
    cin>>menu;//prompt for specific hand ranking display
    cout<<"*************************"<<endl;
    switch(menu){//menu for hand display
        case'0':{//case for hi card
            cout<<"High Card: This hand has nothing to rely on but a High card."<<endl;
            cout<<"Ex: 3 Diamonds | Jack Clubs | 8 Spades | 4 Hearts | 2 Spades"<<endl;
            break;
        }
        case'1':{//case for pair
            cout<<"Pair: Two cards of the same rank."<<endl;
            cout<<"Ex: Ace Hearts | Ace Diamonds | 8 Clubs | 4 Spades | 7 Hearts"<<endl;
            break;
        }
        case'2':{//case for two pair
            cout<<"Two Pair: Two different pairs of cards."<<endl;
            cout<<"Ex: 4 Spades | 4 Clubs | 3 Clubs | 3 Diamonds | Queen Clubs"<<endl;
            break;
        }
        case'3':{//case for three of a kind
            cout<<"Three of a Kind: Three cards of the same rank."<<endl;
            cout<<"Ex: 7 Clubs | 7 Diamonds | 7 Spades | King Clubs | 3 Diamonds"<<endl;
            break;
        }
        case'4':{//case for straight
            cout<<"Straight: Five cards in a sequence, but not of the same suit."<<endl;
            cout<<"Ex: 5 Hearts | 6 Diamonds | 7 Spades | 8 Diamonds | 9 Clubs"<<endl;
            break;
        }
        case'5':{//case for flush
            cout<<"Flush: Any five cards of the same suit, but not in a sequence."<<endl;
            cout<<"Ex: 4 Spades | Jack Spades | 8 Spades | 2 Spades | 9 Spades"<<endl;
            break;
        }
        case'6':{//case for full house
            cout<<"Full House: Three of a Kind and a Pair."<<endl;
            cout<<"Ex: 10 Hearts | 10 Diamonds | 10 Spades | 9 Clubs | 9 Diamonds"<<endl;
            break;
        }
        case'7':{//case for four of a kind
            cout<<"Four of a Kind: All four cards of the same rank."<<endl;
            cout<<"Ex: Jack Hearts | Jack Spades | Jack Diamonds | Jack Clubs | 7 Hearts"<<endl;
            break;
        }
        case'8':{//case for straight flush
            cout<<"Straight Flush: Five cards in a sequence, all in the same suit."<<endl;
            cout<<"Ex: 4 Spades | 5 Spades | 6 Spades | 7 Spades | 8 Spades"<<endl;
            break;
        }
        case'9':{//case for royal flush
            cout<<"Royal Flush: 10, J, Q, K, A (all in the same suit)."<<endl;
            cout<<"Ex: 10 Spades | Jack Spades | Queen Spades | King Spades | Ace Spades"<<endl;
            break;
        }
        default:{//default for skip
            cho=='N';
            skip=true;//set skip to true
            break;
        }    
    }
    if(skip==false){//if skip is false
    cout<<"*************************"<<endl;
    cout<<"Would you like to view another Hand Ranking?"<<endl;
    cout<<"Enter in Y for yes or N for no:"<<endl;
    cin>>cho;//prompt for repeat
    cout<<"*************************"<<endl;
    }
    }while(cho=='Y'||cho=='y');//while player wants to repeat
}
//*********************************************//
//*             Initialize Deck               *//
//*********************************************//
void iniDeck(short cards[],short n){
    for(int i=0;i<n;i++){//increment while still in array
        cards[i]=i;//for position i, set i to i ex: 41 =41
    }
}
//*********************************************//
//*                New round                  *//
//*********************************************//
short round(string z,short x[]){
    //Declare variables
    short c1=0,c2=0;//player hole cards
    short ai1c1=0,ai1c2=0;//computer hole cards
    short com1,com2,com3,com4,com5;//community cards
    short playCom, aiCom;//number for combination of hand
    short pf1=0,pf2=0,pf3=0,pf4=0,pf5=0;//player final hand cards 1-5
    short cf1=0,cf2=0,cf3=0,cf4=0,cf5=0;//computer final hand cards 1-5
    short usrHand,ai1Hand;//hand values
    short hc=0,hc2=0,ai1hc=0,ai1hc2=0;//high card for tie hands
    short winNum;//player number who has top hand
    string plR,ai1R; //quick string for hand ranking
    cout<<"*************************"<<endl;
    //Deal hole cards
    deal1(c1,x);
    deal1(c2,x);
    deal1(ai1c1,x);
    deal1(ai1c2,x);
    //display hole cards
    cout<<"Your Hole Cards: "<<cardVal(c1)<<"|"<<cardVal(c2)<<endl;
    //Deal 3 Community Cards (Flop)
    deal1(com1,x);
    deal1(com2,x);
    deal1(com3,x);
    //Deal 1 Community Card (Turn)
    deal1(com4,x);
    //Deal 1 Community Card (River)
    deal1(com5,x);
    //display community cards
    cout<<"Community Cards: "<<cardVal(com1)<<"|"<<cardVal(com2)<<"|"<<cardVal(com3)<<
                "|"<<cardVal(com4)<<"|"<<cardVal(com5)<<endl;
    //find best combination of cards per player
    playCom=bestCom(com1,com2,com3,com4,com5,c1,c2);
    aiCom=bestCom(com1,com2,com3,com4,com5,ai1c1,ai1c2);
    //set final hand to best combination
    finCom(pf1,pf2,pf3,pf4,pf5,com1,com2,com3,com4,com5,c1,c2,playCom);
    finCom(cf1,cf2,cf3,cf4,cf5,com1,com2,com3,com4,com5,ai1c1,ai1c2,aiCom);
    //high card and sort
    hiCard(pf1,pf2,pf3,pf4,pf5);
    hiCard(cf1,cf2,cf3,cf4,cf5);
    //find hand value of player
    usrHand=ranking(pf1,pf2,pf3,pf4,pf5,hc,hc2);
    //find hand value of computer
    ai1Hand=ranking(cf1,cf2,cf3,cf4,cf5,ai1hc,ai1hc2);
    //set string for short hand ranking
    plR=sRank(usrHand);
    ai1R=sRank(ai1Hand);
    //state player hand value
    if(usrHand==1)cout<<"Your hand value is low with just a high card ("<<cardVal(pf5)<<")."<<endl;
    if(usrHand==2)cout<<"Your hand value is average with just a pair."<<endl;
    if(usrHand==3)cout<<"You have two pair."<<endl;
    if(usrHand==4)cout<<"You have three of a kind. Not too bad."<<endl;
    if(usrHand==5)cout<<"Congrats! You have a straight."<<endl;
    if(usrHand==6)cout<<"Wow! You have a Flush."<<endl;
    if(usrHand==7)cout<<"What a strong hand. You have a Full House!"<<endl;
    if(usrHand==8)cout<<"Four of a Kind! Quick, don't let them see your excitement."<<endl;
    if(usrHand==9)cout<<"A Straight Flush! You can't be beat!"<<endl;
    //Display player hand
    cout<<"Your Hand: "<<cardVal(pf1)<<"|"<<cardVal(pf2)<<"|"<<cardVal(pf3)<<
                "|"<<cardVal(pf4)<<"|"<<cardVal(pf5)<<endl;
    cout<<"Please hit enter twice to start betting:"<<endl;
    cin.get();
    cin.ignore();
    //Unveil all hands
    cout<<"*************************"<<endl;
    cout<<"               All Player Hands     "<<endl;
    cout<<"Your Hand: "<<cardVal(pf1)<<"|"<<cardVal(pf2)<<"|"<<cardVal(pf3)<<
                "|"<<cardVal(pf4)<<"|"<<cardVal(pf5)<<"  ("<<plR<<")"<<endl;
    cout<<"Phil's Hole Cards: "<<cardVal(ai1c1)<<"|"<<cardVal(ai1c2)<<endl;
    cout<<"Phil's Hand: "<<cardVal(cf1)<<"|"<<cardVal(cf2)<<"|"<<cardVal(cf3)<<
                "|"<<cardVal(cf4)<<"|"<<cardVal(cf5)<<"  ("<<ai1R<<")"<<endl;
    cout<<"Please hit enter twice to find the winning hand:"<<endl;
    cin.get();
    cin.ignore();
    cout<<"*************************"<<endl;
    //find winning hand
    winNum=winHand(usrHand,ai1Hand,hc,ai1hc,hc2,ai1hc2);//find winNum
    string rndWinr=winner(z,winNum);//find winner name
    cout<<rndWinr<<" has the winning hand. "<<endl;//state winner
    cout<<"Please hit enter twice to continue:"<<endl;
    cin.get();
    cin.ignore();
    cout<<"*************************"<<endl;
    return winNum;//return winner number
}
//*********************************************//
//*               Deal 1                      *//
//*********************************************//
void deal1(short &c1,short y[]){
    //declare variables
    char repeat;//repeat
    short card;//new card
    do{//do
        card=rand()%52+1;//pick random number
        if(y[card]==0){//if card is 0, then its already picked, so repeat
           repeat='Y'; 
        }else{//else dont repeat
            repeat='N';
        }
    }while(repeat=='Y');//while need new card
    y[card]=0;//set the card you picked to zero in array
    c1=card;//c1 = card
}
//*********************************************//
//*             Card Values                   *//
//*********************************************//
string cardVal(short v){
    string f;//declare string f for card name
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
    return f;//return card name
}
//*********************************************//
//*             Hand Ranking                  *//
//*********************************************//
short ranking(short a,short b,short c,short d,short e, short &hi1, short &hi2){
    //declare variables
    //high card hand value= 1
    short value=1,temp;//temp
    char str='N',flu='N';// straight = n, flush = n
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
    //high card for flush
    if(value==6) hi1=e,hi2=d;
    //high card for high card hand
    if(value==1)hi1=e,hi2=d;
    //pair = 2
    if(a==b||a==c||a==d) value=2,hi1=a,hi2=e;
    if(a==e)value=2,hi1=a,hi2=d;
    if(b==c||b==d) value=2,hi1=b,hi2=e;
    if(c==d) value=2,hi1=c,hi2=e;
    if(c==e) value=2,hi1=c,hi2=d;
    if(d==e) value=2,hi1=e,hi2=c;
    if(b==e) value=2,hi1=e,hi2=d;
    //two pair = 3
    if((b==c&&d==e)||(b==e&&c==d)) value=3,hi1=d,hi2=b;
    if((b==d&&c==e)||(a==c&&b==e)) value=3, hi1=c, hi2=e;
    if((a==e&&c==d)||(a==d&&c==e)) value=3,hi1=c,hi2=a;
    if((a==c&&d==e)||(a==e&&b==d)) value=3, hi1=d, hi2=a;
    if((a==b&&d==e)||(a==d&&b==e)) value=3,hi1=e, hi2=a;
    if((a==b&&c==e)||(a==e&&b==c)) value=3,hi1=c,hi2=a;
    if((a==b&&c==d)||(a==c&&b==d)) value=3,hi1=d,hi2=a;
    if((a==d&&b==c)) value=3, hi1=c,hi2=a;
    //three of a kind = 4
    if((a==d&&a==e)) value=4,hi1=a,hi2=c;
    if((a==b&&a==e)||(a==c&&a==e)) value=4, hi1=a, hi2=d;
    if((a==b&&a==c)||(a==b&&a==d)||(a==c&&a==d)) value=4, hi1=a,hi2=e;
    if((c==d&&c==e)) value=4,hi1=e, hi2=b;
    if((b==d&&b==e)) value=4, hi1=e, hi2=c;
    if((b==c&&b==e)) value=4,hi1=c, hi2=d;
    if(b==c&&b==d) value=4,hi1=b,hi2=e;
    //straight = 5
    if((e-d==1)&&(d-c==1)&&(c-b==1)&&(b-a==1)) value=5,str='Y',hi1=e,hi2=d;
    if((a==1)&&(b==2)&&(c==3)&&(d==4)&&(e==13)) value=5,str='Y',hi1=e,hi2=d;
    //full house = 7
    if((c==d&&c==e&&a==b)||(a==d&&a==e&&b==c)) value=7,hi1=d,hi2=b;
    if((a==b&&a==e&&c==d)||(a==b&&a==c&&d==e)) value=7,hi1=a,hi2=d;
    if((a==c&&a==e&&b==d)||(b==c&&b==e&&a==d)) value=7,hi1=c,hi2=d;
    if((a==b&&a==d&&c==e)||(a==c&&a==d&&b==e)) value=7, hi1=a, hi2=e;
    if((b==d&&b==e&&a==c)||(b==c&&b==d&&a==e)) value=7,hi1=b,hi2=a;
    //four of a kind = 8
    if((b==c&&d==e&&c==d)||(a==c&&d==e&&c==d)||(a==b&&d==e&&b==d)) value=8,hi1=d,hi2=d;
    if((a==b&&c==e&&b==c)||(a==b&&c==d&&b==c)) value=8,hi1=a,hi2=d;
    //straight flush = 9
    if(flu=='Y'&&str=='Y') value=9;// if flush and straight then value =9
    return value;//return hand value
}
//*********************************************//
//*             Short Hand Rank               *//
//*********************************************//
string sRank(short a){
    string state;//declare string for hand type
    if(a==1)state="High card";//if 1 then high card
    if(a==2)state="Pair";//if 2 then pair
    if(a==3)state="Two Pair";//if 3 then two pair
    if(a==4)state="Three of a Kind";// if 4 then 3 of a kind
    if(a==5)state="Straight";//if 5 then straight
    if(a==6)state="Flush";//if 6 then flush
    if(a==7)state="Full House";// 7 then full house
    if(a==8)state="Four of a Kind";//if 8 then four of a kind
    if(a==9)state="Straight Flush";// if 9 then straight flush
    return state;//return string for hand type
}
//*********************************************//
//*               High Card/Sort              *//
//*********************************************//
void hiCard(short &a,short &b,short &c,short &d,short &e){
    short tempa=a,tempb=b,tempc=c,tempd=d,tempe=e;//temp variables for swap
    short temp=0;
    //get rid of suits
    for(tempa;tempa>13;tempa-=13);//take away 13 for values above 13
    for(tempb;tempb>13;tempb-=13);
    for(tempc;tempc>13;tempc-=13);
    for(tempd;tempd>13;tempd-=13);
    for(tempe;tempe>13;tempe-=13);
    //sort first value
    if(tempa>tempb){
        temp=tempa,tempa=tempb,tempb=temp;
        temp=a,a=b,b=temp;//swap if needed
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
    if(tempb>tempc){//swap if needed
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
        temp=c,c=d,d=temp;//swap if needed
    }
    if(tempc>tempe){
        temp=tempc,tempc=tempe,tempe=temp;
        temp=c,c=e,e=temp;
    }
    //sort fourth value
    if(tempd>tempe){
        temp=tempd,tempd=tempe,tempe=temp;
        temp=d,d=e,e=temp;//swap if needed
    }
}
//*********************************************//
//*            Best Combination               *//
//*********************************************//
short bestCom(short a,short b,short c,short d,short e,short h1,short h2){
    //variables
    short high,temp, placeH,placeH2,bestCom=0,curHC=0,curHC2;//high,temporary,placeholder,best combination number,current High Card
    high=ranking(a,b,c,d,e,curHC,curHC2);//5 community cards
    //3 com cards and 2 hole
    temp=ranking(h1,h2,a,b,c,placeH,placeH2);
    if(temp>high) bestCom=1, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=1,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=1,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    temp=ranking(h1,h2,a,c,d,placeH,placeH2);
    if(temp>high) bestCom=2, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=2,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=2,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    temp=ranking(h1,h2,a,d,e,placeH,placeH2);
    if(temp>high) bestCom=3, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=3,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=3,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    temp=ranking(h1,h2,a,b,d,placeH,placeH2);
    if(temp>high) bestCom=4, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=4,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=4,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    temp=ranking(h1,h2,a,b,e,placeH,placeH2);
    if(temp>high) bestCom=5, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=5,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=5,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    temp=ranking(h1,h2,a,c,e,placeH,placeH2);
    if(temp>high) bestCom=6, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=6,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=6,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    temp=ranking(h1,h2,b,c,d,placeH,placeH2);
    if(temp>high) bestCom=7, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=7,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=7,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    temp=ranking(h1,h2,b,c,e,placeH,placeH2);
    if(temp>high) bestCom=8, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=8,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=8,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    temp=ranking(h1,h2,b,d,e,placeH,placeH2);
    if(temp>high) bestCom=9, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=9,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=9,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    temp=ranking(h1,h2,c,d,e,placeH,placeH2);
    if(temp>high) bestCom=10, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=10,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=10,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    //4 com card and first hole card
    temp=ranking(h1,a,b,c,d,placeH,placeH2);
    if(temp>high) bestCom=11, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=11,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=11,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    temp=ranking(h1,a,b,c,e,placeH,placeH2);
    if(temp>high) bestCom=12, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=12,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=12,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    temp=ranking(h1,a,c,d,e,placeH,placeH2);
    if(temp>high) bestCom=13, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=13,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=13,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    temp=ranking(h1,a,b,d,e,placeH,placeH2);
    if(temp>high) bestCom=14, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=14,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=14,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    temp=ranking(h1,b,c,d,e,placeH,placeH2);
    if(temp>high) bestCom=15, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=15,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=15,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    //4 com card and second hole card
    temp=ranking(h2,a,b,c,d,placeH,placeH2);
    if(temp>high) bestCom=16, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=16,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=16,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    temp=ranking(h2,a,b,c,e,placeH,placeH2);
    if(temp>high) bestCom=17, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=17,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=17,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    temp=ranking(h2,a,c,d,e,placeH,placeH2);
    if(temp>high) bestCom=18, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=18,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=18,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    temp=ranking(h2,a,b,d,e,placeH,placeH2);
    if(temp>high) bestCom=19, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=19,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=19,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    temp=ranking(h2,b,c,d,e,placeH,placeH2);
    if(temp>high) bestCom=20, high=temp;
    if(temp==high){
        if(placeH>curHC)bestCom=20,high=temp,curHC=placeH;
        if(placeH==curHC){
            if(placeH2>curHC)bestCom=20,high=temp,curHC=placeH,curHC2=placeH2;
        }
    }
    return bestCom;
}
//*********************************************//
//*               Set Final Hand              *//
//*********************************************//
void finCom(short &c1,short &c2,short &c3, short &c4,short &c5,short a,short b,short c,short d,short e,short h1,short h2,short comb){
    if(comb==0) c1=a,c2=b,c3=c,c4=d,c5=e;
    if(comb==1) c1=h1,c2=h2,c3=a,c4=b,c5=c;
    if(comb==2) c1=h1,c2=h2,c3=a,c4=c,c5=d;
    if(comb==3) c1=h1,c2=h2,c3=a,c4=d,c5=e;
    if(comb==4) c1=h1,c2=h2,c3=a,c4=b,c5=d;
    if(comb==5) c1=h1,c2=h2,c3=a,c4=b,c5=e;
    if(comb==6) c1=h1,c2=h2,c3=a,c4=c,c5=e;
    if(comb==7) c1=h1,c2=h2,c3=b,c4=c,c5=d;
    if(comb==8) c1=h1,c2=h2,c3=b,c4=c,c5=e;
    if(comb==9) c1=h1,c2=h2,c3=b,c4=d,c5=e;
    if(comb==10) c1=h1,c2=h2,c3=c,c4=d,c5=e;
    if(comb==11) c1=h1,c2=a,c3=b,c4=c,c5=d;
    if(comb==12) c1=h1,c2=a,c3=b,c4=c,c5=e;
    if(comb==13) c1=h1,c2=a,c3=c,c4=d,c5=e;
    if(comb==14) c1=h1,c2=a,c3=b,c4=d,c5=e;
    if(comb==15) c1=h1,c2=b,c3=c,c4=d,c5=e;
    if(comb==16) c1=h2,c2=a,c3=b,c4=c,c5=d;
    if(comb==17) c1=h2,c2=a,c3=b,c4=c,c5=e;
    if(comb==18) c1=h2,c2=a,c3=c,c4=d,c5=e;
    if(comb==19) c1=h2,c2=a,c3=b,c4=d,c5=e;
    if(comb==20) c1=h2,c2=b,c3=c,c4=d,c5=e;
}
//*********************************************//
//*               Winning Hand                *//
//*********************************************//
short winHand(short a,short b,short h1,short h2,short sh1, short sh2){
    //find top hand value
    short topHand=a,pl1=0,pl2=0,win;//declare variables for ties
    if(b>topHand) topHand=b;
    //find all that have the same value of the top hand
    if(a==topHand) pl1=1;
    if(b==topHand) pl2=1;
    //compare ties for top hand
    if((pl1==1)&&(pl2==1)){//if two have tie
        if(h1>h2) win=1;//win =1
        if(h2>h1) win=2;//win =2
        if(h1==h2){
            if(sh1>sh2) win=1;
            if(sh2>sh1) win=2;
        }
    }
    //if no tie
    if((pl1==1)&&(pl2==0)) win=1;//win 1
    if((pl1==0)&&(pl2==1)) win=2;//win 2
    //return win
    return win;
}
//*********************************************//
//*            Winning Player                 *//
//*********************************************//
string winner(string you,short a){
    string winner;//declare string variable for winner
    if(a==1) winner=you;//if 1 then winner = user
    if(a==2) winner="Phil";//if 2 then winner = tom
    if(a<1||a>2) winner="(Tie Game) No one";// else tie game
    return winner;//return winner
}
