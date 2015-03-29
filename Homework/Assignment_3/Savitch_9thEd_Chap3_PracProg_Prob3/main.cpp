/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 25, 2015, 10:10 AM
 *      Purpose: Astrology Program (find user's sign and horoscope)
 */

//System Libraries
#include <iostream>//I/O standard
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
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
    return 0;
}