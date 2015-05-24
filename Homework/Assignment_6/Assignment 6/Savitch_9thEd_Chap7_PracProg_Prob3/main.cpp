/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on May 18, 2015, 9:50 AM
 *      Purpose: Swap first and last entry of array
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void swap();
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    bool ans;
    //Prompt the user for inputs
    cout<<"This program takes in a list of entries into an array and then swaps"<<endl;
    cout<<"the first entry with the last."<<endl;
    swap();
    //Output 
    
    return 0;
}
//first last 2
void swap(){
    //declare
    int size,num,temp;
    cout<<"How many integer entries are in the array?"<<endl;
    cin>>size;
    int array[size];
    cout<<"(Keep in mind that the array starts at position (0)"<<endl;
    for(int i=0;i<size;i++){
    cout<<"Please enter in current integer entry for position ("<<i<<")"<<endl;
    cin>>num;
    array[i]=num;
    }
    cout<<"Before the swap:"<<endl;
    cout<<"The first value in the array is: "<<array[0]<<endl;
    cout<<"The last value in the array is: "<<array[size-1]<<endl;
    temp=array[0];
    array[0]=array[size-1];
    array[size-1]=temp;
    cout<<"After the swap:"<<endl;
    cout<<"The first value in the array is now: "<<array[0]<<endl;
    cout<<"The last value in the array is now: "<<array[size-1]<<endl;
}