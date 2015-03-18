/* 
 * File:   main.cpp
 * Author: Branden Hitt 
 * Created on March 16, 2015, 3:46 Pm
 *      Purpose: Mad Lib
 */
//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    string insNam, name, food, numb, adj, color, animal;
    
    //Input
    cout<<"Time to play a game of Mad Lib"<<endl;
    cout<<"First we need some variables from you"<<endl;
    cout<<"Enter in the last name of your class instructor:"<<endl;
    cin>>insNam;
    cout<<"Enter in a name:"<<endl;
    cin>>name;
    cout<<"Enter in your favorite food:"<<endl;
    cin>>food;
    cout<<"Enter in a number between 100 and 200:"<<endl;
    cin>>numb;
    cout<<"Enter in an adjective:"<<endl;
    cin>>adj;
    cout<<"Enter in a color:"<<endl;
    cin>>color;
    cout<<"And last we need an animal:"<<endl;
    cin>>animal;
    //Calculate
   
    //Output
    cout<<"Dear Instructor "<<insNam<<","<<endl;
    cout<<endl;
    cout<<"I am sorry that I am unable to turn in my homework at this time. First,"<<endl;
    cout<<"I ate a rotten "<<food<<", which made me turn "<<color<<" and extremely ill. I"<<endl;
    cout<<"came down with a fever of "<<numb<<". Next, my "<<adj<<" pet "<<endl;
    cout<<animal<<" must have smelled the remains of the "<<food<<" on my homework, "<<endl;
    cout<<"because he ate it. I am currently rewriting my homework and hope you"<<endl;
    cout<<"will accept it."<<endl;
    cout<<endl;
    cout<<"Sincerely, "<<endl;
    cout<<name<<endl;
    
    //Exit Stage Right
    return 0;
}