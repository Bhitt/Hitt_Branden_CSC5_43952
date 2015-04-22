/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 16, 2015, 7:10 PM
 *      Purpose: write a function that finds the average and standard deviation
 *              of 4 scores
 */

//System Libraries
#include<iostream>
#include<cmath>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float calc(short, short, short, short, float, float);
float avg(short, short, short, short);
float stdDev(short, short, short, short, float);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char cho;
    do{
    short s1,s2,s3,s4;
    float av,stDev,fin;
    //Prompt the user for inputs
    cout<<"This program finds the standard deviation of four scores"<<endl;
    cout<<"Please input score 1:"<<endl;
    cin>>s1;
    cout<<"Please input score 2:"<<endl;
    cin>>s2;
    cout<<"Please input score 3:"<<endl;
    cin>>s3;
    cout<<"Please input score 4:"<<endl;
    cin>>s4;
    //Call functions
    fin=calc(s1,s2,s3,s4,av,stDev);
    
    //Output 
    cout<<"The standard deviation is "<<fin<<endl;
    cout<<"Would you like to test again?"<<endl;
    cout<<"Enter in Y for yes or N for no:"<<endl;
    cin>>cho;
    }while(cho=='Y'||cho=='y');
    return 0;
}
float calc(short a, short b, short c, short d, float x, float y){
    x=avg(a,b,c,d);
    y=stdDev(a,b,c,d,x);
    return y;
}
float avg(short a, short b, short c, short d){
    float avg;
    avg=(a+b+c+d)/4;
    return avg;
}
float stdDev(short a, short b, short c, short d, float avg){
    float end;
    end=sqrt(((pow((a-avg),2))+pow((b-avg),2)+pow((c-avg),2)+pow((d-avg),2))/4);
    return end;
}