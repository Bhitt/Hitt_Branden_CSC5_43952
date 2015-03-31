/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 29, 2015, 10:40 PM
 *      Purpose: Blackjack hand value
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
    
    return 0;
}