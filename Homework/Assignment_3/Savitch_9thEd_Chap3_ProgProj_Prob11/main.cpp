/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 29, 2015, 6:40 PM
 *      Purpose: Oven keypad is broken, give closest temp to users input
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
    return 0;
}