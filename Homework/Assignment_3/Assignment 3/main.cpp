/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Purpose:  To Illustrate the code for
 * developing a menu
 * Modified on Mar 30, 2015
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    char ans;
    //General Menu Format
    //Display the selection
    do{
    cout<<"Type 1 to use problem 1: Rock, Paper Scissors"<<endl;
    cout<<"Type 2 to use problem 2: Find Interest Due"<<endl;
    cout<<"Type 3 to use problem 3: Astrology Sign"<<endl;
    cout<<"Type 4 to use problem 4: Prime Numbers 1 to 100"<<endl;
    cout<<"Type 5 to use problem 5: Will it Sink?"<<endl;
    cout<<"Type 6 to use problem 6: Broken Oven Keypad"<<endl;
    cout<<"Type 7 to use problem 7: The Game 23 vs AI"<<endl;
    cout<<"Type 8 to use problem 8: The Riddler's Riddle"<<endl;
    cout<<"Type 9 to use problem 9: Arabic to Roman Numeral"<<endl;
    cout<<"Type T to use problem 10: BlackJack Hand Value"<<endl;
    //Read the choice
    char choice;
    cin>>choice;
    //Solve a problem that has been chosen.
    switch(choice){
            case '1':{//Declare Variables
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
                break;
            }
                break;
            case '2':{
                //Declare Variables
                float intDue, totDue, minPay1, minPay2, minDue, accBal, inter1, inter2, totInt; 
                //Prompt the user for inputs
                cout<<"Please enter in your Account Balance $: "<<endl;
                cin>>accBal;//account balance
                //Calculate
                if (accBal<1000){
                    totInt=0.015*accBal;//interest if under 1000
                }else{//interest if over 1000
                    inter1=0.015*1000;
                    inter2=0.01*(accBal-1000);
                    totInt=inter1+inter2;  
                }
                totDue=totInt+accBal;//total amount due
                if (totDue<=10){
                    minDue=totDue;
                }else{//minimum payment due
                    minPay1=totDue*0.1;//10 percent of amount due
                    minPay2=10;//10 dollars due
                    if (minPay2>minPay1){//if 10 percent of amount due is less than 10 dollars
                        minDue=minPay2;//pay 10 dollars
                    }else{
                        minDue=minPay1;//pay 10 percent of amount due
                    }
                }
                //Output 
                cout<<"Your interest is: $"<<totInt<<endl;
                cout<<"Total Amount Due: $"<<totDue<<endl;
                cout<<"Minimum payment due: $"<<minDue<<endl;
                break;
            }
            case '3':{
                            //Declare Variables
               int bMonth,bDay; // birth month and day
               string cap, aqu, pisc, arie, taur, gem, canc, leo, virgo, libra, scorpio, sag; //horoscopes
               cap="What is dead may never die.";// Capricorn 
               aqu="You will encounter a white walker soon.";// Aquarius
               pisc="All men must die.";// Pisces
               arie="A Lannister always pays his debt.";// Aries
               taur="You will encounter a giant named Hodor";// Taurus
               gem="You will find that John Snow knows nothing";// Gemini
               canc="You will light the biggest fire the North has ever seen";// Cancer
               leo="You will change your name to Wreak";// Leo
               virgo="You will have your face crushed by The Mountain";// Virgo
               libra="All dwarves are bastards in their father's eyes.";// Libra
               scorpio="Don't drink the wine.";// Scorpio
               sag="Winter is Coming.";// Sagittarius

                //Prompt the user for inputs
                cout<<"What month is your Birthday in? For Jan type 1, for Feb type 2, etc."<<endl;
                cin>>bMonth;// user's birthday month
                cout<<"What day of the month is your Birthday (xx)"<<endl;
                cin>>bDay;// user's birthday day
                //Output 
                switch(bMonth){
                    case 1: {// January
                        if(bDay<19){// birthday before 19th
                            cout<<"Your sign is Capricorn and your horoscope is :"<<endl;
                            cout<<cap<<endl;
                        }else if (bDay==19){// birthday on 19th
                            cout<<"Your sign is Capricorn and your horoscope is :"<<endl;
                            cout<<cap<<endl;
                            cout<<"You are on the cusp of being an Aquarius which has the horoscope: "<<endl;
                            cout<<aqu<<endl;
                        }else {// birthday after 19th
                            cout<<"Your sign is Aquarius and your horoscope is :"<<endl;
                            cout<<aqu<<endl;
                        }
                        break;
                    }
                    case 2:{// Febuary
                        if(bDay<18){// birthday before 18th
                            cout<<"Your sign is Aquarius and your horoscope is :"<<endl;
                            cout<<aqu<<endl;
                        }else if (bDay==18){// birthday on 18th
                            cout<<"Your sign is Aquarius and your horoscope is :"<<endl;
                            cout<<aqu<<endl;
                            cout<<"You are on the cusp of being a Pisces which has the horoscope: "<<endl;
                            cout<<pisc<<endl;
                        }else{// birthday after 18th
                            cout<<"Your sign is Pisces and your horoscope is :"<<endl;
                            cout<<pisc<<endl;
                        }
                        break;
                    }
                    case 3: {// March
                        if(bDay<20){// birthday before 20th
                            cout<<"Your sign is Pisces and your horoscope is :"<<endl;
                            cout<<pisc<<endl;
                        }else if (bDay==20){// birthday on 20th
                            cout<<"Your sign is Pisces and your horoscope is :"<<endl;
                            cout<<pisc<<endl;
                            cout<<"You are on the cusp of being an Aries which has the horoscope: "<<endl;
                            cout<<arie<<endl;
                        }else{// birthday after 20th
                            cout<<"Your sign is Aries and your horoscope is :"<<endl;
                            cout<<arie<<endl;
                        }
                        break;
                    }
                    case 4:{// April
                        if(bDay<19){// birthday before 19th
                            cout<<"Your sign is Aries and your horoscope is :"<<endl;
                            cout<<arie<<endl;
                        }else if (bDay==19){// birthday on 19th
                            cout<<"Your sign is Aries and your horoscope is :"<<endl;
                            cout<<arie<<endl;
                            cout<<"You are on the cusp of being a Taurus which has the horoscope: "<<endl;
                            cout<<taur<<endl;
                        }else{// birthday after 19th
                            cout<<"Your sign is Taurus and your horoscope is :"<<endl;
                            cout<<taur<<endl;
                        }
                        break;
                    }
                    case 5:{// May
                        if(bDay<20){// birthday before 20th
                            cout<<"Your sign is Taurus and your horoscope is :"<<endl;
                            cout<<taur<<endl;
                        }else if (bDay==20){// birthday on 20th
                            cout<<"Your sign is Taurus and your horoscope is :"<<endl;
                            cout<<taur<<endl;
                            cout<<"You are on the cusp of being a Gemini which has the horoscope: "<<endl;
                            cout<<gem<<endl;
                        }else{// birthday after 20th
                            cout<<"Your sign is Gemini and your horoscope is :"<<endl;
                            cout<<gem<<endl;
                        }
                        break;
                    }
                     case 6:{// June
                        if(bDay<21){// birthday before 21st
                            cout<<"Your sign is Gemini and your horoscope is :"<<endl;
                            cout<<gem<<endl;
                        }else if (bDay==21){// birthday on 21st
                            cout<<"Your sign is Gemini and your horoscope is :"<<endl;
                            cout<<gem<<endl;
                            cout<<"You are on the cusp of being a Cancer which has the horoscope: "<<endl;
                            cout<<canc<<endl;
                        }else{// birthday after 21st
                            cout<<"Your sign is Cancer and your horoscope is :"<<endl;
                            cout<<canc<<endl;
                        }
                        break;
                    }
                      case 7:{// July
                        if(bDay<22){// birthday before 22nd
                            cout<<"Your sign is Cancer and your horoscope is :"<<endl;
                            cout<<canc<<endl;
                        }else if (bDay==22){// birthday on 22nd
                            cout<<"Your sign is Cancer and your horoscope is :"<<endl;
                            cout<<canc<<endl;
                            cout<<"You are on the cusp of being a Leo which has the horoscope: "<<endl;
                            cout<<leo<<endl;
                        }else{// birthday after 22nd
                            cout<<"Your sign is Leo and your horoscope is :"<<endl;
                            cout<<leo<<endl;
                        }
                        break;
                    }
                       case 8:{// August
                        if(bDay<22){// birthday before 22nd
                            cout<<"Your sign is Leo and your horoscope is :"<<endl;
                            cout<<leo<<endl;
                        }else if (bDay==22){// birthday on 22
                            cout<<"Your sign is Leo and your horoscope is :"<<endl;
                            cout<<leo<<endl;
                            cout<<"You are on the cusp of being a Virgo which has the horoscope: "<<endl;
                            cout<<virgo<<endl;
                        }else{// birthday after 22nd
                            cout<<"Your sign is Virgo and your horoscope is :"<<endl;
                            cout<<virgo<<endl;
                        }
                        break;
                    }
                        case 9:{// September
                        if(bDay<22){// birthday before 22nd
                            cout<<"Your sign is Virgo and your horoscope is :"<<endl;
                            cout<<virgo<<endl;
                        }else if (bDay==22){// birthday on 22nd
                            cout<<"Your sign is Virgo and your horoscope is :"<<endl;
                            cout<<virgo<<endl;
                            cout<<"You are on the cusp of being a Libra which has the horoscope: "<<endl;
                            cout<<libra<<endl;
                        }else{// birthday after 22nd
                            cout<<"Your sign is Libra and your horoscope is :"<<endl;
                            cout<<libra<<endl;
                        }
                        break;
                    }
                        case 10:{// October
                        if(bDay<22){// birthday before 22nd
                            cout<<"Your sign is Libra and your horoscope is :"<<endl;
                            cout<<libra<<endl;
                        }else if (bDay==22){// birthday on 22nd
                            cout<<"Your sign is Libra and your horoscope is :"<<endl;
                            cout<<libra<<endl;
                            cout<<"You are on the cusp of being a Scorpio which has the horoscope: "<<endl;
                            cout<<scorpio<<endl;
                        }else{// birthday after 22nd
                            cout<<"Your sign is Scorpio and your horoscope is :"<<endl;
                            cout<<scorpio<<endl;
                        }
                        break;
                    }
                        case 11:{// November
                        if(bDay<21){// birthday before 21st
                            cout<<"Your sign is Scorpio and your horoscope is :"<<endl;
                            cout<<scorpio<<endl;
                        }else if (bDay==21){// birthday on 21st
                            cout<<"Your sign is Scorpio and your horoscope is :"<<endl;
                            cout<<scorpio<<endl;
                            cout<<"You are on the cusp of being a Sagittarius which has the horoscope: "<<endl;
                            cout<<sag<<endl;
                        }else{// birthday after 21st
                            cout<<"Your sign is Sagittarius and your horoscope is :"<<endl;
                            cout<<sag<<endl;
                        }
                        break;
                    }
                        case 12:{// December
                        if(bDay<21){// birthday before 21st
                            cout<<"Your sign is Sagittarius and your horoscope is :"<<endl;
                            cout<<sag<<endl;
                        }else if (bDay==21){// birthday on 21st
                            cout<<"Your sign is Sagittarius and your horoscope is :"<<endl;
                            cout<<sag<<endl;
                            cout<<"You are on the cusp of being a Capricorn which has the horoscope: "<<endl;
                            cout<<cap<<endl;
                        }else{// birthday after 21st
                            cout<<"Your sign is Capricorn and your horoscope is :"<<endl;
                            cout<<cap<<endl;
                        }
            break;
        }
            default:cout<<"You entered in your birthday incorrectly"<<endl;
    };
            }
               
                break;
            }
            case '4':{
                //Declare Variables
                short p,j,pr;
                //Prompt user
                cout<<"This program finds and outputs the prime numbers from 1 to 100"<<endl;
                //Calculate
                for (p=2;p<=100;p++){
                    for (j=2,pr=1;j<p&&pr==1;){
                        if(p%j==0){
                            pr=0;
                        }
                        else{
                            j++;
                        }

                        }if(pr==1){
                            cout<<p<<" ";
                    }
                    
                }
                cout<<""<<endl;
                break;
            }
            case '5':{
                //Declare Variables
                float weight, radius, buoFor, vol, water=62.4, pi=3.141592;
                //Prompt the user for inputs
                cout<<"This program will tell you if a sphere will sink or float in water."<<endl;
                cout<<"What is the weight of your sphere in lbs: "<<endl;
                cin>>weight;//weight of sphere in lbs
                cout<<"What is the radius of your sphere in feet: "<<endl;
                cin>>radius;//radius of sphere in feet
                //Calculate
                vol=((4.0/3)*(pi)*(radius*radius*radius));//volume of sphere formula
                buoFor=vol*water;//buoyancy force formula
                if (buoFor>=weight){//if buoyancy force is >= the weight of the sphere
                    cout<<"Your sphere will float!!!"<<endl;//output
                }else{
                    cout<<"Your sphere will sink!!!"<<endl;//output
                }
               
                break;
            }
            case '6':{
                //Declare Variables
                int userT, hund, tens, ones;
                //Prompt the user for inputs
                cout<<"The keypad is broken on the oven. This causes the 1, 4, and 7 keys to be unusable."<<endl;
                cout<<"I will find the two closest temperatures above and below the desired temperature if necessary."<<endl;
                cout<<"Please enter in your desired temperature now (0 to 999): "<<endl;
                cin>>userT;//user's temperature
                //Calculate and Output
                hund=userT/100;//finds the hundreds value i.e. 3 for 361
                tens=(userT%100)/10;//finds the tens value i.e. 6 for 361
                ones=userT%10;//finds the ones value i.e. 1 for 361
                if (userT>=0&&userT<=999){//checks for correct input within range
                    if ((hund!=1 && hund!=4 && hund !=7) && (tens!=1 && tens!=4 && tens !=7) && (ones!=1
                            && ones!=4 && ones !=7)){//checks to see if userTemp uses the 1, 4, and 7 keys
                        cout<<"Your Desired Temperature is "<<userT<<endl;
                    }else{//If a 1, 4 , or 7 is used in the desired temp
                        if(hund==1||hund==4||hund==7){//checks first digit
                            hund-1;
                            tens-1;
                            cout<<"The lower temp is "<<hund-1<<"99"<<endl;
                            cout<<"and the higher temp is "<<hund+1<<"00"<<endl;
                        }else if(tens==1||tens==4||tens==7){//checks second digit
                            cout<<"The lower temp is "<<hund<<tens-1<<"9"<<endl;
                            cout<<"and the higher temp is "<<hund<<tens+1<<"0"<<endl;
                        }else if(ones==1||ones==4||ones==7){//checks third digit
                            cout<<"The lower temp is "<<hund<<tens<<ones-1<<endl;
                            cout<<"and the higher temp is "<<hund<<tens<<ones+1<<endl;
                        }else{
                            cout<<"Invalid Entry"<<endl;
                        }
                    }
                }else{//input outside of range
                    cout<<"Invalid Entry"<<endl;
                }
                
                break;
            }case '7':{
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
                                              cout<<"The computer chose to take "<<compWin<<", leaving 1 stick left. You Lose!"<<endl;
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
            
                break;
            }
            case '8':{
                //Declare Variables
                cout<<"This program will find where the Riddler will strike next."<<endl;
                //Loop for all possible digits
                for(int d1000=0;d1000<=9;d1000++){//loops thousand digit
                    for(int d100=0;d100<=9;d100++){//loops hundred digit
                        for(int d10=0;d10<=9;d10++){//loops tens digit
                            for(int d1=0;d1<=9;d1++){//loops ones digit
                                if((d1000==3*d10) &&//condition 1 (thousand must be 3 times tens)
                                    (d1%2==1)   &&//condition 2 (must be odd)
                                    (d1000+d100+d10+d1==27) && //condition 3 (sum of digits must be 27)
                                       (d1!=d10&&d1!=100&&d1!=d1000&&//condition 4 (digits must be different)
                                        d10!=d100&&d10!=1000&&
                                        d100!=1000)){
                                    cout<<"The Address Number = ";
                                    cout<<d1000<<d100<<d10<<d1<<endl;
                                }
                            }
                    }
                }
                }
               
                break;
            }
            case '9':{
                //Declare Variables
                short usrYear, piece, i, hund, tens, ones;
                string romYear;
                //Prompt the user for inputs
                cout<<"This program will convert a year written as an Arabic numeral (ex.1900) to Roman numerals (MCM)."<<endl;
                cout<<"Please enter a year now from 1000 to 3000: "<<endl;
                cin>>usrYear;
                //Calculate
                if (usrYear>3000||usrYear<1000){ //checks for incorrect input
                    cout<<"Invalid Input"<<endl;
                }else{
                    //2534
                    if(usrYear>=1000){//if the year is above 1000 add M for every thousand
                        piece=(usrYear/1000);
                        for(i=0;i<piece;i++){
                            romYear+='M';
                        }  
                    }
                    hund=usrYear%=1000;//get rid of thousands
                    //534
                    if(hund>=100){
                        piece=(hund/100);//find how many hundreds
                        if(piece==9){//if it is 900
                            romYear+="CM";
                        }else if(piece>=5){//if it is 500 or higher
                            romYear+='D';//add D for 500
                            for(i=0;i<piece-5;i++){
                                romYear+='C';//add C for every hundred after
                            }
                        }else if(piece==4){//if it is 400
                            romYear+="CD";//add CD
                        }else if(piece>=1){//if it is 100 or above
                            for(i=0;i<piece;i++){
                                romYear+='C';//add C for every hundred
                            }
                        } 
                    }
                    tens=usrYear%=100;//get rid of thousands and hundreds
                    //34
                    if(tens>=10){
                        piece=(tens/10);//find how many tens
                        if(piece==9){//if it is 90
                            romYear+="XC";// add XC
                        }else if (piece>=5){//if it is 50 or above
                            romYear+='L';//add L 
                            for(i=0;i<piece-5;i++){
                                romYear+='X';//add X for each ten above 50
                            }
                        }else if (piece==4){// if it is 40
                            romYear+="XL";//add XL
                        }else if (piece>=1){//if it is 10 or higher
                            for (i=0;i<piece;i++){
                                romYear+='X';//add X for every ten
                            }
                        }
                    }
                    ones=usrYear%=10;//get rid of thousands, hundreds, and tens
                    //4
                    if(ones>=1){
                        piece=ones;//how many ones
                        if(piece==9){//if it is 9
                            romYear+="IX";//add IX
                        }else if(piece>=5){//if it is 5 or above
                            romYear+="V";//add V
                            for(i=0;i<piece-5;i++){
                                romYear+='I';//add I for every one above 5
                            }
                        }else if (piece==4){//if it is 4
                            romYear+="IV";//add IV
                        }else if (piece>=1){//if it is 1 or above
                            for (i=0;i<piece;i++){
                                romYear+='I';//add I for every one
                            }
                        }
                    }
        //Output results
        cout<<"Your year in Roman numerals is "<<romYear<<endl;
    }
                break;
            }
            case 't':
            case 'T':{
                //Declare Variables
                short numCard,totVal=0,aces=0;
                char card1,card2,card3,card4,card5;
                //Prompt the user for inputs
                cout<<"How many cards do you have: (2,3,4,5)"<<endl;
                cin>>numCard;
                switch (numCard){//checks for amount of cards in hand
                    case 2://2 cards in hand
                        //prompt user for card values
                        cout<<"Please enter the card values.(2-9 or T,J,Q,K,A):"<<endl;
                        cout<<"What is the value of the first card?"<<endl;
                        cin>>card1;
                        cout<<"What is the value of the second card?"<<endl;
                        cin>>card2;
                        //check card 1 for value
                        if (card1=='t' || card1=='T' || card1=='j' || card1=='J' || 
                                card1=='q' || card1=='Q'|| card1=='k' || card1=='K'){
                            totVal+=10;
                        }else if(card1=='a'||card1=='A'){
                            totVal+=11;
                            aces++;
                        }else if(card1=='2'){
                            totVal+=2;
                        }else if(card1=='3'){
                            totVal+=3;
                        }else if(card1=='4'){
                            totVal+=4;
                        }else if(card1=='5'){
                            totVal+=5;
                        }else if(card1=='6'){
                            totVal+=6;
                        }else if(card1=='7'){
                            totVal+=7;
                        }else if(card1=='8'){
                            totVal+=8;
                        }else if(card1=='9'){
                            totVal+=9;
                        }else{
                            cout<<"Invalid input"<<endl;
                        }
                        //check card 2 for value
                        if (card2=='t' || card2=='T' || card2=='j' || card2=='J' || 
                                card2=='q' || card2=='Q'|| card2=='k' || card2=='K'){
                            totVal+=10;
                        }else if(card2=='a'||card2=='A'){
                            totVal+=11;
                            aces++;
                        }else if(card2=='2'){
                            totVal+=2;
                        }else if(card2=='3'){
                            totVal+=3;
                        }else if(card2=='4'){
                            totVal+=4;
                        }else if(card2=='5'){
                            totVal+=5;
                        }else if(card2=='6'){
                            totVal+=6;
                        }else if(card2=='7'){
                            totVal+=7;
                        }else if(card2=='8'){
                            totVal+=8;
                        }else if(card2=='9'){
                            totVal+=9;
                        }else {
                            cout<<"Invalid input"<<endl;
                        }
                        if(totVal<22){//if the total score is less than 22
                            cout<<"Your total score is "<<totVal<<endl;
                        }else{//if the score is 22 or more
                            if(aces>0){//check cards for an ace
                                for(aces;aces>0&&totVal>21;--aces){//until the score is brought down below 22, use an ace to subtract 10
                                    totVal-=10;
                                } 
                                if(totVal<22){
                                    cout<<"Your total score is "<<totVal<<endl;
                                }else if(totVal>21){
                                    cout<<"Busted! Your total was "<<totVal<<endl;
                                }
                            }else{//no aces and over 21 so  bust
                            cout<<"Busted! Your total was "<<totVal<<endl;
                            }
                        }
                        break;
                    case 3://3 cards in hand
                        cout<<"Please enter the card values.(2-9 or T,J,Q,K,A):"<<endl;
                        cout<<"What is the value of the first card?"<<endl;
                        cin>>card1;
                        cout<<"What is the value of the second card?"<<endl;
                        cin>>card2;
                        cout<<"What is the value of the third card?"<<endl;
                        cin>>card3;
                        //check card 1 for value
                        if (card1=='t' || card1=='T' || card1=='j' || card1=='J' || 
                                card1=='q' || card1=='Q'|| card1=='k' || card1=='K'){
                            totVal+=10;
                        }else if(card1=='a'||card1=='A'){
                            totVal+=11;
                            aces++;
                        }else if(card1=='2'){
                            totVal+=2;
                        }else if(card1=='3'){
                            totVal+=3;
                        }else if(card1=='4'){
                            totVal+=4;
                        }else if(card1=='5'){
                            totVal+=5;
                        }else if(card1=='6'){
                            totVal+=6;
                        }else if(card1=='7'){
                            totVal+=7;
                        }else if(card1=='8'){
                            totVal+=8;
                        }else if(card1=='9'){
                            totVal+=9;
                        }else {
                            cout<<"Invalid input"<<endl;
                        }
                        //check card 2 for value
                        if (card2=='t' || card2=='T' || card2=='j' || card2=='J' || 
                                card2=='q' || card2=='Q'|| card2=='k' || card2=='K'){
                            totVal+=10;
                        }else if(card2=='a'||card2=='A'){
                            totVal+=11;
                            aces++;
                        }else if(card2=='2'){
                            totVal+=2;
                        }else if(card2=='3'){
                            totVal+=3;
                        }else if(card2=='4'){
                            totVal+=4;
                        }else if(card2=='5'){
                            totVal+=5;
                        }else if(card2=='6'){
                            totVal+=6;
                        }else if(card2=='7'){
                            totVal+=7;
                        }else if(card2=='8'){
                            totVal+=8;
                        }else if(card2=='9'){
                            totVal+=9;
                        }else {
                            cout<<"Invalid input"<<endl;
                        }
                        //check card 3 for value
                        if (card3=='t' || card3=='T' || card3=='j' || card3=='J' || 
                                card3=='q' || card3=='Q'|| card3=='k' || card3=='K'){
                            totVal+=10;
                        }else if(card3=='a'||card3=='A'){
                            totVal+=11;
                            aces++;
                        }else if(card3=='2'){
                            totVal+=2;
                        }else if(card3=='3'){
                            totVal+=3;
                        }else if(card3=='4'){
                            totVal+=4;
                        }else if(card3=='5'){
                            totVal+=5;
                        }else if(card3=='6'){
                            totVal+=6;
                        }else if(card3=='7'){
                            totVal+=7;
                        }else if(card3=='8'){
                            totVal+=8;
                        }else if(card3=='9'){
                            totVal+=9;
                        }else {
                            cout<<"Invalid input"<<endl;
                        }
                        if(totVal<22){//if the total score is less than 22
                            cout<<"Your total score is "<<totVal<<endl;
                        }else{//if the score is 22 or more
                            if(aces>0){//check cards for an ace
                                for(aces;aces>0&&totVal>21;--aces){//until the score is brought down below 22, use an ace to subtract 10
                                    totVal-=10;
                                } 
                                if(totVal<22){
                                    cout<<"Your total score is "<<totVal<<endl;
                                }else if(totVal>21){
                                    cout<<"Busted! Your total was "<<totVal<<endl;
                                }
                            }else{//no aces and over 21 so  bust
                            cout<<"Busted! Your total was "<<totVal<<endl;
                            }
                        }
                        break;
                    case 4://4 cards in hand
                        cout<<"Please enter the card values.(2-9 or T,J,Q,K,A):"<<endl;
                        cout<<"What is the value of the first card?"<<endl;
                        cin>>card1;
                        cout<<"What is the value of the second card?"<<endl;
                        cin>>card2;
                        cout<<"What is the value of the third card?"<<endl;
                        cin>>card3;
                        cout<<"What is the value of the fourth card?"<<endl;
                        cin>>card4;
                        //check card 1 for value
                        if (card1=='t' || card1=='T' || card1=='j' || card1=='J' || 
                                card1=='q' || card1=='Q'|| card1=='k' || card1=='K'){
                            totVal+=10;
                        }else if(card1=='a'||card1=='A'){
                            totVal+=11;
                            aces++;
                        }else if(card1=='2'){
                            totVal+=2;
                        }else if(card1=='3'){
                            totVal+=3;
                        }else if(card1=='4'){
                            totVal+=4;
                        }else if(card1=='5'){
                            totVal+=5;
                        }else if(card1=='6'){
                            totVal+=6;
                        }else if(card1=='7'){
                            totVal+=7;
                        }else if(card1=='8'){
                            totVal+=8;
                        }else if(card1=='9'){
                            totVal+=9;
                        }else {
                            cout<<"Invalid input"<<endl;
                        }
                        //check card 2 for value
                        if (card2=='t' || card2=='T' || card2=='j' || card2=='J' || 
                                card2=='q' || card2=='Q'|| card2=='k' || card2=='K'){
                            totVal+=10;
                        }else if(card2=='a'||card2=='A'){
                            totVal+=11;
                            aces++;
                        }else if(card2=='2'){
                            totVal+=2;
                        }else if(card2=='3'){
                            totVal+=3;
                        }else if(card2=='4'){
                            totVal+=4;
                        }else if(card2=='5'){
                            totVal+=5;
                        }else if(card2=='6'){
                            totVal+=6;
                        }else if(card2=='7'){
                            totVal+=7;
                        }else if(card2=='8'){
                            totVal+=8;
                        }else if(card2=='9'){
                            totVal+=9;
                        }else {
                            cout<<"Invalid input"<<endl;
                        }
                        //check card 3 for value
                        if (card3=='t' || card3=='T' || card3=='j' || card3=='J' || 
                                card3=='q' || card3=='Q'|| card3=='k' || card3=='K'){
                            totVal+=10;
                        }else if(card3=='a'||card3=='A'){
                            totVal+=11;
                            aces++;
                        }else if(card3=='2'){
                            totVal+=2;
                        }else if(card3=='3'){
                            totVal+=3;
                        }else if(card3=='4'){
                            totVal+=4;
                        }else if(card3=='5'){
                            totVal+=5;
                        }else if(card3=='6'){
                            totVal+=6;
                        }else if(card3=='7'){
                            totVal+=7;
                        }else if(card3=='8'){
                            totVal+=8;
                        }else if(card3=='9'){
                            totVal+=9;
                        }else {
                            cout<<"Invalid input"<<endl;
                        }
                        //check card 4 for value
                        if (card4=='t' || card4=='T' || card4=='j' || card4=='J' || 
                                card4=='q' || card4=='Q'|| card4=='k' || card4=='K'){
                            totVal+=10;
                        }else if(card4=='a'||card4=='A'){
                            totVal+=11;
                            aces++;
                        }else if(card4=='2'){
                            totVal+=2;
                        }else if(card4=='3'){
                            totVal+=3;
                        }else if(card4=='4'){
                            totVal+=4;
                        }else if(card4=='5'){
                            totVal+=5;
                        }else if(card4=='6'){
                            totVal+=6;
                        }else if(card4=='7'){
                            totVal+=7;
                        }else if(card4=='8'){
                            totVal+=8;
                        }else if(card4=='9'){
                            totVal+=9;
                        }else {
                            cout<<"Invalid input"<<endl;
                        }
                        if(totVal<22){//if the total score is less than 22
                            cout<<"Your total score is "<<totVal<<endl;
                        }else{//if the score is 22 or more
                            if(aces>0){//check cards for an ace
                                for(aces;aces>0&&totVal>21;--aces){//until the score is brought down below 22, use an ace to subtract 10
                                    totVal-=10;
                                } 
                                if(totVal<22){
                                    cout<<"Your total score is "<<totVal<<endl;
                                }else if(totVal>21){
                                    cout<<"Busted! Your total was "<<totVal<<endl;
                                }
                            }else{//no aces and over 21 so  bust
                            cout<<"Busted! Your total was "<<totVal<<endl;
                            }
                        }
                        break;
                    case 5://5 cards in hand
                        cout<<"Please enter the card values.(2-9 or T,J,Q,K,A):"<<endl;
                        cout<<"What is the value of the first card?"<<endl;
                        cin>>card1;
                        cout<<"What is the value of the second card?"<<endl;
                        cin>>card2;
                        cout<<"What is the value of the third card?"<<endl;
                        cin>>card3;
                        cout<<"What is the value of the fourth card?"<<endl;
                        cin>>card4;
                        cout<<"What is the value of the fifth card?"<<endl;
                        cin>>card5;
                        //check card 1 for value
                        if (card1=='t' || card1=='T' || card1=='j' || card1=='J' || 
                                card1=='q' || card1=='Q'|| card1=='k' || card1=='K'){
                            totVal+=10;
                        }else if(card1=='a'||card1=='A'){
                            totVal+=11;
                            aces++;
                        }else if(card1=='2'){
                            totVal+=2;
                        }else if(card1=='3'){
                            totVal+=3;
                        }else if(card1=='4'){
                            totVal+=4;
                        }else if(card1=='5'){
                            totVal+=5;
                        }else if(card1=='6'){
                            totVal+=6;
                        }else if(card1=='7'){
                            totVal+=7;
                        }else if(card1=='8'){
                            totVal+=8;
                        }else if(card1=='9'){
                            totVal+=9;
                        }else {
                            cout<<"Invalid input"<<endl;
                        }
                        //check card 2 for value
                        if (card2=='t' || card2=='T' || card2=='j' || card2=='J' || 
                                card2=='q' || card2=='Q'|| card2=='k' || card2=='K'){
                            totVal+=10;
                        }else if(card2=='a'||card2=='A'){
                            totVal+=11;
                            aces++;
                        }else if(card2=='2'){
                            totVal+=2;
                        }else if(card2=='3'){
                            totVal+=3;
                        }else if(card2=='4'){
                            totVal+=4;
                        }else if(card2=='5'){
                            totVal+=5;
                        }else if(card2=='6'){
                            totVal+=6;
                        }else if(card2=='7'){
                            totVal+=7;
                        }else if(card2=='8'){
                            totVal+=8;
                        }else if(card2=='9'){
                            totVal+=9;
                        }else {
                            cout<<"Invalid input"<<endl;
                        }
                        //check card 3 for value
                        if (card3=='t' || card3=='T' || card3=='j' || card3=='J' || 
                                card3=='q' || card3=='Q'|| card3=='k' || card3=='K'){
                            totVal+=10;
                        }else if(card3=='a'||card3=='A'){
                            totVal+=11;
                            aces++;
                        }else if(card3=='2'){
                            totVal+=2;
                        }else if(card3=='3'){
                            totVal+=3;
                        }else if(card3=='4'){
                            totVal+=4;
                        }else if(card3=='5'){
                            totVal+=5;
                        }else if(card3=='6'){
                            totVal+=6;
                        }else if(card3=='7'){
                            totVal+=7;
                        }else if(card3=='8'){
                            totVal+=8;
                        }else if(card3=='9'){
                            totVal+=9;
                        }else {
                            cout<<"Invalid input"<<endl;
                        }
                        //check card 4 for value
                        if (card4=='t' || card4=='T' || card4=='j' || card4=='J' || 
                                card4=='q' || card4=='Q'|| card4=='k' || card4=='K'){
                            totVal+=10;
                        }else if(card4=='a'||card4=='A'){
                            totVal+=11;
                            aces++;
                        }else if(card4=='2'){
                            totVal+=2;
                        }else if(card4=='3'){
                            totVal+=3;
                        }else if(card4=='4'){
                            totVal+=4;
                        }else if(card4=='5'){
                            totVal+=5;
                        }else if(card4=='6'){
                            totVal+=6;
                        }else if(card4=='7'){
                            totVal+=7;
                        }else if(card4=='8'){
                            totVal+=8;
                        }else if(card4=='9'){
                            totVal+=9;
                        }else {
                            cout<<"Invalid input"<<endl;
                        }
                        //check card 5 for value
                        if (card5=='t' || card5=='T' || card5=='j' || card5=='J' || 
                                card5=='q' || card5=='Q'|| card5=='k' || card5=='K'){
                            totVal+=10;
                        }else if(card5=='a'||card5=='A'){
                            totVal+=11;
                            aces++;
                        }else if(card5=='2'){
                            totVal+=2;
                        }else if(card5=='3'){
                            totVal+=3;
                        }else if(card5=='4'){
                            totVal+=4;
                        }else if(card5=='5'){
                            totVal+=5;
                        }else if(card5=='6'){
                            totVal+=6;
                        }else if(card5=='7'){
                            totVal+=7;
                        }else if(card5=='8'){
                            totVal+=8;
                        }else if(card5=='9'){
                            totVal+=9;
                        }else {
                            cout<<"Invalid input"<<endl;
                        }
                        if(totVal<22){//if the total score is less than 22
                            cout<<"Your total score is "<<totVal<<endl;
                        }else{//if the score is 22 or more
                            if(aces>0){//check cards for an ace
                                for(aces;aces>0&&totVal>21;--aces){//until the score is brought down below 22, use an ace to subtract 10
                                    totVal-=10;
                                } 
                                if(totVal<22){
                                    cout<<"Your total score is "<<totVal<<endl;
                                }else if(totVal>21){
                                    cout<<"Busted! Your total was "<<totVal<<endl;
                                }
                            }else{//no aces and over 21 so  bust
                            cout<<"Busted! Your total was "<<totVal<<endl;
                            }
                        }
                        break;
                    default://Invalid input
                        cout<<"Invalid entry"<<endl;
                }
    
                break;
            }
            default:{
                    cout<<"Invalid Menu Choice"<<endl;
            }
    };
    cout<<"Would you like to Return to the Menu? Type Y for yes or N for no:"<<endl;
    cin>>ans;
    }while((ans=='y'||ans=='Y'));
    return 0;
}