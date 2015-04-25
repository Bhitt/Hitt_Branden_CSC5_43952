/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 19, 2015, 12:20 AM
 *      Purpose: convert lbs/ounces to grams/kilograms using 3 functions
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float prompt();
float calc(float a);
void output(float a);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float lbs;
    float result;
    char ans;
    cout<<"This program will convert the weight of a box from lbs/ounces to kilograms/grams."<<endl;
    do{
    //Prompt the user for inputs  
        lbs=prompt();
    //Calculate
        result=calc(lbs);
    //Output   
        output(result);
        cout<<"Would you like to run this program again with different weights?"<<endl;
        cout<<"Press Y for yes or N for no, then hit enter:"<<endl;
        cin>>ans;
    }while(ans=='Y'||ans=='y');
    return 0;
}
float prompt(){
    short lbs,ounces;
    float totlbs;
    cout<<"What is the weight of the box in lbs (remaining ounces will be next input)?"<<endl;
    cin>>lbs;
    cout<<"What are the remaining ounces?"<<endl;
    cin>>ounces;
    if(lbs<0||ounces<0){
        cout<<"Invalid input"<<endl;
        return 0;
    }
    totlbs=(lbs)+(ounces/16.0f);
    //cout<<"totlbs= "<<totlbs<<endl;
    return totlbs;
}
float calc(float a){
    float b,c;
    b=a/2.2046;
    //cout<<"b/2.2046= "<<b<<endl;
    c=b*1000;
    //cout<<"total grams: "<<c<<endl;
    return c;
}
void output(float a){
    // a = total grams
    float b;
    float c;
    // b = single kilograms
    b=static_cast<int>(a)/1000;
    //c = remaining grams
    c=static_cast<int>(a)%1000;
    cout<<"**********************************************************"<<endl;
    cout<<"* The equivalent weight is "<<b<<" kilogram(s) and "<<c<<" gram(s) *"<<endl;
    cout<<"**********************************************************"<<endl;
}