/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on May 18, 2015, 9:30 AM
 *      Purpose: First or Last (2)
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
bool firlst2();
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    bool ans;
    //Prompt the user for inputs
    cout<<"This program takes in a list of entries into an array and finds if"<<endl;
    cout<<"the array starts or ends with a 2."<<endl;
    ans=firlst2();
    if(ans==true){
        cout<<"The array does start or end with a 2"<<endl;
    }else if(ans==false){
        cout<<"The array does not start or end with a 2"<<endl;
    }
    //Output 
    
    return 0;
}
//first last 2
bool firlst2(){
    //declare
    int size,num;
    cout<<"How many integer entries are in the array?"<<endl;
    cin>>size;
    int array[size];
    cout<<"(Keep in mind that the array starts at position (0)"<<endl;
    for(int i=0;i<size;i++){
    cout<<"Please enter in current integer entry for position ("<<i<<")"<<endl;
    cin>>num;
    array[i]=num;
    }
    if(array[0]==2||array[size-1]==2){
        return true;
    }else{
        return false;
    }
}