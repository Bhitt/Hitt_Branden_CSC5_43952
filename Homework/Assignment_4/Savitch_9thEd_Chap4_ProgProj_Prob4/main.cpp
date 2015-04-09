/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 9, 2015, 1:30 PM
 *      Purpose: Ninety-Nine Bottles of Beer
 */

//System Libraries
#include <iostream>//I/O standard
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
string lyric(unsigned short num1, unsigned short num2);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short tens, ones, input;
    string engNum, first;
    //Prompt the user for inputs
    cout<<"Could you please tell me how many bottles of beer are on the wall? (0-99)"<<endl;
    cin>>input;
    //Find digits for first case
    tens=(input%100)/10;
    //cout<<"tens = "<<tens<<endl; <- for testing purposes
    ones=(input%10);
    //cout<<"ones = "<<ones<<endl; <- for testing purposes
    //Output first case
    first=lyric(tens,ones);
    cout<<first<<" bottles of beer on the wall,"<<endl;
    cout<<first<<" bottles of beer,"<<endl;
    cout<<"Take one down, pass it around"<<endl;
    input--;
    //call function for output
    do{
    //Find the tens and ones digits
        tens=(input%100)/10;
        //cout<<"tens = "<<tens<<endl; <- for testing purposes
        ones=(input%10);
        //cout<<"ones = "<<ones<<endl; <- for testing purposes
        engNum=lyric(tens,ones);//function to find number in english
        input--;
        cout<<engNum<<" bottles of beer on the wall."<<endl;
        cout<<"..."<<endl;
        cout<<engNum<<" bottles of beer on the wall,"<<endl;
        cout<<engNum<<" bottles of beer,"<<endl;
        cout<<"Take one down, pass it around"<<endl; 
    }while(input>1);
    cout<<"One bottle of beer on the wall,"<<endl;
    cout<<"..."<<endl;
    cout<<"One bottle of beer on the wall,"<<endl;
    cout<<"One bottle of beer,"<<endl;
    cout<<"Take one down, pass it around"<<endl;
    cout<<"Zero bottles of beer on the Wall!"<<endl;
    cout<<".................................."<<endl;
    cout<<"Press Enter to Exit, You Drunk:"<<endl;
    cin.ignore();
    cin.get();
    return 0;
}
string lyric(unsigned short num1, unsigned short num2){
    string full;
    if(num1==9){
        full="Ninety";
        }else if (num1==8){
            full="Eighty";
        }else if (num1==7){
            full="Seventy";
        }else if (num1==6){
            full="Sixty";
        }else if (num1==5){
            full="Fifty";
        }else if (num1==4){
            full="Forty";
        }else if (num1==3){
            full="Thirty";
        }else if (num1==2){
            full="Twenty";
        }else if (num1==1&&num2==9){
            full="Nineteen";
        }else if (num1==1&&num2==8){
            full="Eighteen";
        }else if (num1==1&&num2==7){
            full="Seventeen";
        }else if (num1==1&&num2==6){
            full="Sixteen";
        }else if (num1==1&&num2==5){
            full="Fifteen";
        }else if (num1==1&&num2==4){
            full="Fourteen";
        }else if (num1==1&&num2==3){
            full="Thirteen";
        }else if (num1==1&&num2==2){
            full="Twelve";
        }else if (num1==1&&num2==1){
            full="Eleven";
        }else if (num1==1&&num2==0){
            full="Ten";
        }else{
            //do nothing
        }
    if(num1>1&&num2!=0){
        full+="-";
    }
    if(num2==0){
        //do nothing
        }else if (num2==9&&num1!=1){
            full+="Nine";
        }else if (num2==8&&num1!=1){
            full+="Eight";
        }else if (num2==7&&num1!=1){
            full+="Seven";
        }else if (num2==6&&num1!=1){
            full+="Six";
        }else if (num2==5&&num1!=1){
            full+="Five";
        }else if (num2==4&&num1!=1){
            full+="Four";
        }else if (num2==3&&num1!=1){
            full+="Three";
        }else if (num2==2&&num1!=1){
            full+="Two";
        }else if ((num2==1)&&(num1!=1)&&(num1!=0)){
            full+="One";
        }else{
            //do nothing
        }
    return full;
}