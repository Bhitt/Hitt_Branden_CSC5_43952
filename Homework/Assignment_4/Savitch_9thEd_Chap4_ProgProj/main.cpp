/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 25, 2015, 10:10 AM
 *      Purpose: Compute clothing size
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float hatSize(int w, int h);
float jktSize(int w, int h, int a);
float wstInch(int w,int a);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char cho;
    do{
    int height,weight,age;
    float hat, jacket, waist;
    cout<<"This program will help you find your approximate hat size,"<<endl;
    cout<<"jacket size, and waist line in inches."<<endl;
    //Prompt the user for inputs
    cout<<"Please enter in your age: (in years)"<<endl;
    cin>>age;
    cout<<"Next enter in your weight: (in lbs)"<<endl;
    cin>>weight;
    cout<<"Last, I need your height: (in inches)"<<endl;
    cin>>height;
    //Call Functions
    hat=hatSize(weight,height);
    jacket=jktSize(weight,height,age);
    waist=wstInch(weight,age);
    //Output 
    cout<<"Your hat size should be "<<hat<<" (in inches)."<<endl;
    cout<<"Your jacket size (chest size) should be "<<jacket<<" (in inches)."<<endl;
    cout<<"Your waist size should be "<<waist<<" (in inches)."<<endl;
    cout<<endl;
    cout<<"Would you like to run this program again?"<<endl;
    cout<<"Enter in Y for yes or N for no:"<<endl;
    cin>>cho;
    }while(cho=='y'||cho=='Y');
    return 0;
}
//****************Hat Size Function**********/
float hatSize(int w, int h){
    float result;
    result=(w*1.0/h)*2.9;
    return result;
}
//****************Jacket Size Function*******/
float jktSize(int w, int h, int a){
    float result;
    int taco=0;//if older than 30, for every ten years add .125 inches
    result=(h*w)/288.0;
    if (a>=40){
        taco=((a-30)%100)/10;
        for (taco;taco>0;taco--){
            result+=0.125;
        }
    }
    return result;
}
//****************Waist Size Function*******/
float wstInch(int w, int a){
    float result;
    int taco=0;//if older than 28, for every 2 years add .1 inches
    result=(w/5.7);
    if(a>=30){
        taco=(a-28)/2;
        for(taco;taco>0;taco--){
            result+=0.1;
        }
    }
    return result;
}