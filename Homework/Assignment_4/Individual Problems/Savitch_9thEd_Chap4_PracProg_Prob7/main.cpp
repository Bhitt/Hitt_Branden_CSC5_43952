/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 7, 2015, 7:10 PM
 *      Purpose: gravitational force
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants
const float G=6.673e-8;//6.673*10^-8
//Function Prototypes
float AttFrce(float m1, float m2, float d);
//Execution Begins Here!
int main(int argc, char** argv) {
    char choice;
    do{
    //Declare Variables
    float m1, m2, d;
    //Prompt the user for inputs
    cout<<"Enter the mass of body 1 (grams):"<<endl;
    cin>>m1;
    cout<<"Enter the mass of body 2 (grams):"<<endl;
    cin>>m2;
    cout<<"Enter the distance between mass 1 and mass 2 (cm):"<<endl;
    cin>>d;
    float force=AttFrce(m1,m2,d);
    cout<<"The attractive force (dynes) is: "<<force<<endl;
    cout<<"Would you like to repeat this program?"<<endl;
    cout<<"Type Y for yes or N for no:"<<endl;
    cin>>choice;
    //Output 
    }while(choice=='y'||choice=='Y');
    return 0;
}

float AttFrce(float m1, float m2, float d){
    return(G*m1*m2/(d*d));
    
}