/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on May 18, 2015, 9:41 AM
 *      Purpose: Count number of (2)
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
short cntNum2();
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    short ans;
    //Prompt the user for inputs
    cout<<"This program takes in a list of entries into an array and finds how"<<endl;
    cout<<"many 2's are in the array."<<endl;
    ans=cntNum2();
    cout<<"The number of 2's in the array is: "<<ans<<endl;
    //Output 
    
    return 0;
}
//first last 2
short cntNum2(){
    //declare
    int size,num;
    short tot=0;
    cout<<"How many integer entries are in the array?"<<endl;
    cin>>size;
    int array[size];
    cout<<"(Keep in mind that the array starts at position (0)"<<endl;
    for(int i=0;i<size;i++){
    cout<<"Please enter in current integer entry for position ("<<i<<")"<<endl;
    cin>>num;
    array[i]=num;
    }
    for(int i=0;i<size;i++){
    if(array[i]==2){
        tot++;
    }
    }
    return tot;
}