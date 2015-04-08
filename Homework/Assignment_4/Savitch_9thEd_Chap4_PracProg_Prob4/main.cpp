/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 7, 2015, 4:40 PM
 *      Purpose: Find Inflation Rate
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float inf(float pYrAgo, float pNow);//function to find inflation rate
//Execution Begins Here!
int main(int argc, char** argv) {
    char choice;//for repeat
    do{
    //Declare Variables
        float pYrAgo, pNow;//price a year ago, price now
        //Prompt the user for inputs
        cout<<"This program will gauge the rate of inflation for the past year."<<endl;
        cout<<"First give me the price of a hot dog 1 year ago: (xx.xx)"<<endl;
        cin>>pYrAgo;
        cout<<"Now give me the price of a hot dog today: (xx.xx)"<<endl;
        cin>>pNow;

        inf(pYrAgo, pNow);
        cout<<"Would you like to run this program again?"<<endl;
        cout<<"Type Y for yes or N for no: "<<endl;
        cin>>choice;
    }while(choice=='Y'||choice=='y');
    return 0;
}
float inf(float pYrAgo,float pNow){
    float infRate;
    infRate=((pNow-pYrAgo)/pYrAgo)*100;//formula to get inflation rate
    cout<<"The rate of inflation was: "<<infRate<<"%"<<endl;
}