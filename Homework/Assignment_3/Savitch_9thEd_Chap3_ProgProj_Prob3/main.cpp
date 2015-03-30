/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 29, 2015, 3:10 PM
 *      Purpose: Convert arabic integer to roman numeral
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
    return 0;
}