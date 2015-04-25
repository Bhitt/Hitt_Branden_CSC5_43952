/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 24, 2015, 9:00 PM
 *      Purpose: find the area and perimeter of a triangle
 */

//System Libraries
#include <iostream>//I/O standard
#include <cmath>// sqrt
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void compute(unsigned short, unsigned short, unsigned short, float &, float &);
bool check(unsigned short, unsigned short, unsigned short);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short side1,side2,side3;
    float area, per;
    bool real;
    //Prompt the user for inputs
    cout<<"This program will find the area and perimeter of a given triangle."<<endl;
    do{
        cout<<"First, enter in side 1's length (cm):"<<endl;
        cin>>side1;
        cout<<"Second, enter in side 2's length (cm):"<<endl;
        cin>>side2;
        cout<<"Last, enter in side 3's length (cm):"<<endl;
        cin>>side3;
        real=check(side1,side2,side3);
    }while(real==false);
    //Call functions
    compute(side1,side2,side3,area,per);
    //Output
    cout<<"*************************"<<endl;
    cout<<"The perimeter is "<<per<<" cm"<<endl;
    cout<<"The area is "<<area<<" cm^2"<<endl;
    
    return 0;
}
void compute(unsigned short x, unsigned short y, unsigned short z, float &a, float &p){
    p=x+y+z;
    float s=p/2;
    a=sqrt(s*(s-x)*(s-y)*(s-z));
}

bool check(unsigned short x, unsigned short y, unsigned short z){
    if((x+y>z)&&(x+z>y)&&(z+y>x)){
        return true;
    }else{
        cout<<"These measurements can't make a triangle. Please re-input new side lengths."<<endl;
        cout<<"*************************"<<endl;
        return false;
    }
}