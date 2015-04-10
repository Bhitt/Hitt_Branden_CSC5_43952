/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 8, 2015, 9:40 AM
 *      Purpose: Oven keypad is broken, give closest temp to users input
 *      Also include bool function
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
bool cntDgt(int number, int digit);//checks the specific digits
bool yCnt147(int number);//checks if the number has 1,4,7
//Execution Begins Here!
int main(int argc, char** argv) {
    int temp;
    bool cnt147;
    cout<<"Enter the desired temperature."<<endl;
    cin>>temp;//user's desired temp
    
    int lowTemp=temp;
    cnt147=yCnt147(lowTemp);
    while(cnt147){
        lowTemp--;
        cnt147=yCnt147(lowTemp);
    }
    int hiTemp=temp;
    cnt147=yCnt147(hiTemp);
    while(cnt147){
        hiTemp++;
        cnt147=yCnt147(hiTemp);
    }
    cout<<"The next closest lower temperature is "<<lowTemp<<endl;
    cout<<"The next closest higher temperature is "<<hiTemp<<endl;
    return 0;
}    

bool cntDgt(int number, int digit){
    int ones, tens, hund;
    bool cntDgt;
    
    ones=number%10;
    tens=(number/10)%10;
    hund=(number/100);
    if ((ones==digit)||(tens==digit)||hund==digit){
        cntDgt=true;
    }else{
        cntDgt=false;
    }
    return cntDgt;
}
bool yCnt147(int number){
    if((cntDgt(number,1))||(cntDgt(number,4))||(cntDgt(number,7))){
        return true;
    }else{
        return false;
    }
}