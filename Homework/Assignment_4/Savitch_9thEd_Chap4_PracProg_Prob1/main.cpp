/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 6, 2015, 9:50 AM
 *      Purpose: output # of miles per gallon
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants
const float CONVLTG=0.264179;//liters to gallons
//Function Prototypes
float mpg(int a, int b);//miles per gallon function
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char choice;//to ask if you want to repeat
    unsigned short nLit, nMiles;//number of liters used, number of miles driven
    float result;
    //Prompt the user for inputs
    cout<<"This program will find your miles per gallon from your car."<<endl;
    do{
        cout<<"Please first enter in the number of liters of gasoline consumed:"<<endl;
        cin>>nLit;
        cout<<"Next enter in the amount of miles traveled:"<<endl;
        cin>>nMiles;
        result=mpg(nLit, nMiles);
        cout<<"Your car traveled "<<result<<" miles per gallon"<<endl;
        cout<<"Would you like to run this program again?"<<endl;
        cin>>choice;
    }while(choice=='y'||choice=='Y');
    return 0;
}
float mpg( int a, int b){
    //declare variables for calculation
    float nGal, mPGal;// number of gallons after conversion, miles per gallon
    nGal=a*CONVLTG;//formula to convert user's liters to gallons
    //cout<<"nGal: "<<nGal<<endl;
    mPGal=1.0f*b/nGal;//formula to find miles per gallon
    //cout<<"mPGal: "<<mPGal<<endl;  
}