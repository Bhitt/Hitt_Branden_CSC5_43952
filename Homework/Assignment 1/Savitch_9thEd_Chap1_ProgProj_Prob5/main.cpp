/* 
 * File:   main.cpp
 * Author: Branden Hitt 
 * Created on March 4, 2015, 8:23 AM
 *      Purpose: Output letter C devised of input letter
 */
//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char c;//Character to be used to display C
    //Input
    //Prompt for the letter C to be user
    cout<<"What letter would you like to use for Big C?"<<endl;
    cin>>c;
    //Output Big C
    cout<<"   "<<c<<c<<c<<c<<endl;
    cout<<"  "<<c<<"    "<<c<<endl;
    cout<<" "<<c<<"      "<<c<<endl;
    cout<<c<<endl;
    cout<<c<<endl;
    cout<<c<<endl;
    cout<<c<<endl;
    cout<<" "<<c<<"      "<<c<<endl;
    cout<<"  "<<c<<"    "<<c<<endl;
     cout<<"   "<<c<<c<<c<<c<<endl;
    //Exit Stage Right
    return 0;
}
