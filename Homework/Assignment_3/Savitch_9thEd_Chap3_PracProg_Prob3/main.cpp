/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 25, 2015, 10:10 AM
 *      Purpose: Astrology Program (find user's sign and horoscope)
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
   int bMonth,bDay;
    
    //Prompt the user for inputs
    cout<<"What month is your Birthday in? For Jan type 1, for Feb type 2, etc."<<endl;
    cin>>bMonth;
    cout<<"What day of the month is your Birthday (xx)"<<endl;
    cin>>bDay;
    //Output 
    switch(bMonth){
        case 1: {
            if(bDay<20){
                cout<<"Your sign is Capricorn and your horoscope is :"<<endl;
                cout<<"What is dead may never die."<<endl;
            }else {
                cout<<"Your sign is Aquarius and your horoscope is :"<<endl;
                cout<<"You will encounter a white walker soon."<<endl;
            }
            break;
        }
        case 2:{
            if(bDay<19){
                cout<<"Your sign is Aquarius and your horoscope is :"<<endl;
                cout<<"You will encounter a white walker soon."<<endl;
            }else{
                cout<<"Your sign is Pisces and your horoscope is :"<<endl;
                cout<<"All men must die."<<endl;
            }
            break;
        }
        case 3: {
            if(bDay<21){
                cout<<"Your sign is Pisces and your horoscope is :"<<endl;
                cout<<"All men must die."<<endl;
            }else{
                cout<<"Your sign is Aries and your horoscope is :"<<endl;
                cout<<"A Lannister always pays his debt."<<endl;
            }
            break;
        }
        case 4:{
            if(bDay<20){
                cout<<"Your sign is Aries and your horoscope is :"<<endl;
                cout<<"A Lannister always pays his debt"<<endl;
            }else{
                cout<<"Your sign is Taurus and your horoscope is :"<<endl;
                cout<<"You will encounter a giant named Hodor"<<endl;
            }
            break;
        }
        case 5:{
            if(bDay<22){
                cout<<"Your sign is Taurus and your horoscope is :"<<endl;
                cout<<"You will encounter a giant named Hodor"<<endl;
            }else{
                cout<<"Your sign is Gemini and your horoscope is :"<<endl;
                cout<<"You will find that John Snow knows nothing"<<endl;
            }
            break;
        }
         case 6:{
            if(bDay<22){
                cout<<"Your sign is Gemini and your horoscope is :"<<endl;
                cout<<"You will find that John Snow knows nothing"<<endl;
            }else{
                cout<<"Your sign is Cancer and your horoscope is :"<<endl;
                cout<<"You will light the biggest fire the North has ever seen"<<endl;
            }
            break;
        }
          case 7:{
            if(bDay<23){
                cout<<"Your sign is Cancer and your horoscope is :"<<endl;
                cout<<"You will light the biggest fire the North has ever seen"<<endl;
            }else{
                cout<<"Your sign is Leo and your horoscope is :"<<endl;
                cout<<"You will change your name to Wreak"<<endl;
            }
            break;
        }
           case 8:{
            if(bDay<23){
                cout<<"Your sign is Leo and your horoscope is :"<<endl;
                cout<<"You will change your name to Wreak"<<endl;
            }else{
                cout<<"Your sign is Virgo and your horoscope is :"<<endl;
                cout<<"You will have your face crushed by The Mountain"<<endl;
            }
            break;
        }
            case 9:{
            if(bDay<23){
                cout<<"Your sign is Virgo and your horoscope is :"<<endl;
                cout<<"You will have your face crushed by The Mountain"<<endl;
            }else{
                cout<<"Your sign is Libra and your horoscope is :"<<endl;
                cout<<"All dwarves are bastards in their father's eyes."<<endl;
            }
            break;
        }
             case 10:{
            if(bDay<23){
                cout<<"Your sign is Libra and your horoscope is :"<<endl;
                cout<<"All dwarves are bastards in their father's eyes."<<endl;
            }else{
                cout<<"Your sign is Scorpio and your horoscope is :"<<endl;
                cout<<"Don't drink the wine."<<endl;
            }
            break;
        }
              case 11:{
            if(bDay<22){
                cout<<"Your sign is Scorpio and your horoscope is :"<<endl;
                cout<<"Don't drink the wine"<<endl;
            }else{
                cout<<"Your sign is Sagittarius and your horoscope is :"<<endl;
                cout<<"Winter is Coming."<<endl;
            }
            break;
        }
               case 12:{
            if(bDay<22){
                cout<<"Your sign is Sagittarius and your horoscope is :"<<endl;
                cout<<"Winter is Coming."<<endl;
            }else{
                cout<<"Your sign is Capricorn and your horoscope is :"<<endl;
                cout<<"What is dead may never die."<<endl;
            }
            break;
        }
            default:cout<<"You entered in your birthday incorrectly"<<endl;
    };
    return 0;
}