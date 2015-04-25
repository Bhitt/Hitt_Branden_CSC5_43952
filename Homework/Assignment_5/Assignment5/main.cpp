/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Purpose:  Assignment 5
 * Modified on Apr 24th, 2015
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
//Problem 1 functions
float calcu(short, short, short, short, float, float);
float avg(short, short, short, short);
float stdDev(short, short, short, short, float);
//Problem 2 functions
short prompt();
float calc(short a);
void output(float a);
//Problem 3 functions
float promp();
float cal(float a);
void out(float a);
//Problem 4 functions
void compute(unsigned short, unsigned short, unsigned short, float &, float &);
bool check(unsigned short, unsigned short, unsigned short);
//Problem 5 functions
void nput(short &,short &);
void alc(short &,char &);
void utput(short,short,char);
//Problem 7 function
void coins(int,int &, int &);
//Problem 8 function
float index(short,short);
//Problem 9 functions
void shoot(bool &, float );
char strDuel();
//Problem 10 functions
void in(short &,short &,short &);
bool isLeap(short);
short centVal(short);
short yrVal(short);
short monVal(short,short);
short dayWeek(short, short, short);
//Execution Begins Here
int main(int argc, char** argv) {
    //General Menu Format
    char repeat;
    //Display the selection
    do{
    cout<<"Type 1 to solve problem 1"<<endl;
    cout<<"Type 2 to solve problem 2"<<endl;
    cout<<"Type 3 to solve problem 3"<<endl;
    cout<<"Type 4 to solve problem 4"<<endl;
    cout<<"Type 5 to solve problem 5"<<endl;
    cout<<"Type 6 to solve problem 6"<<endl;
    cout<<"Type 7 to solve problem 7"<<endl;
    cout<<"Type 8 to solve problem 8"<<endl;
    cout<<"Type 9 to solve problem 9"<<endl;
    cout<<"Type T to solve problem 10"<<endl;
    //Read the choice
    char choice;
    cin>>choice;
    //Solve a problem that has been chosen.
    switch(choice){
        case '1':{
            cout<<"******************"<<endl;
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
                fin=calcu(s1,s2,s3,s4,av,stDev);

                //Output 
                cout<<"The standard deviation is "<<fin<<endl;
                cout<<"Would you like to test again?"<<endl;
                cout<<"Enter in Y for yes or N for no:"<<endl;
                cin>>cho;
                }while(cho=='Y'||cho=='y');
                cout<<"******************"<<endl;
                break;
            }
        case '2':{
            cout<<"******************"<<endl;
                short inch;
                float result;
                char ans;
                cout<<"This program will convert a length of pole from feet/inches to meters/centimeters."<<endl;
                do{
                    inch=prompt();
                    result=calc(inch);
                    output(result);
                    cout<<"Would you like to run this program again with different lengths?"<<endl;
                    cout<<"Press Y for yes or N for no, then hit enter:"<<endl;
                    cin>>ans;
                }while(ans=='Y'||ans=='y');
                cout<<"******************"<<endl;
                break;
            }
        case '3':{
            cout<<"******************"<<endl;
            float lbs;
            float result;
            char ans;
            cout<<"This program will convert the weight of a box from lbs/ounces to kilograms/grams."<<endl;
            do{
            //Prompt the user for inputs  
                lbs=promp();
            //Calculate
                result=cal(lbs);
            //Output   
                out(result);
                cout<<"Would you like to run this program again with different weights?"<<endl;
                cout<<"Press Y for yes or N for no, then hit enter:"<<endl;
                cin>>ans;
            }while(ans=='Y'||ans=='y');
            cout<<"******************"<<endl;  
                break;
            }
        case '4':{
            cout<<"******************"<<endl;
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
            cout<<"******************"<<endl;
                break;
            }
        case '5':{
            cout<<"******************"<<endl;
            char cho;
            do{
            //Declare Variables
            short hour, min;
            char period='P';
            //Prompt the user for inputs
            cout<<"This program will convert a 24-hour notation to 12-hour notation."<<endl;
            nput(hour,min);
            //cout<<"after input():"<<hour<<":"<<min<<endl;
            //Calculate 
            alc(hour,period);
            //cout<<"after calc():"<<hour<<":"<<min<<endl;
            utput(hour,min,period);
            cout<<"Would you like to run this program again?"<<endl;
            cout<<"Enter in Y for yes or N for no:"<<endl;
            cin>>cho;
            }while(cho=='Y'||cho=='y');
            cout<<"******************"<<endl;
                break;
            }
        case '6':{
            cout<<"******************"<<endl;
            unsigned short cHour,cMin,hrsW,minsW,finHr,finMin;
            char cho;
            //Prompt the user for inputs
            cout<<"This program will find the time after waiting a given period. (24-hr notation)"<<endl;
            do{
                cout<<"Please first enter in the current hour:"<<endl;
                cin>>cHour;
                cout<<"Next, enter in the minute portion of the current time:"<<endl;
                cin>>cMin;
                cout<<"How many hours would you like to wait:"<<endl;
                cin>>hrsW;
                cout<<"How many minutes would you like to wait:"<<endl;
                cin>>minsW;
                //Calculate
                finMin=cMin+minsW;
                while(finMin>=60){
                    finMin-=60;
                    cHour+=1;
                }
                finHr=cHour+hrsW;
                while(finHr>24){
                    finHr-=24;
                }
                if(finHr<10&&finMin<10){
                   cout<<"The time after waiting is 0"<<finHr<<":0"<<finMin<<endl; 
                }else if(finMin<10){
                   cout<<"The time after waiting is "<<finHr<<":0"<<finMin<<endl;
                }else if(finHr<10){
                   cout<<"The time after waiting is 0"<<finHr<<":"<<finMin<<endl;
                }else{
                    cout<<"The time after waiting is "<<finHr<<":"<<finMin<<endl;
                }
                //Prompt for repeat
                cout<<"Would you like to enter in new inputs?"<<endl;
                cout<<"Type Y for yes or N for no:"<<endl;
                cin>>cho;
            }while(cho=='Y'||cho=='y');
            cout<<"******************"<<endl;
                break;
            }
        case '7':{
            cout<<"******************"<<endl;
            int userC, num;
            char cho;
            //Prompt the user for inputs
            cout<<"This program will give the correct change back for any value between 1 and 99 cents"<<endl;
            cout<<"(Note: This machine has no nickels or half-dollars)"<<endl;
            do{
                cout<<"Please enter in an amount of change to recieve (1-99 cents):"<<endl;
                cin>>userC;
                //Output
                coins(25,num,userC);
                cout<<num<<" Quarters"<<endl;
                coins(10,num,userC);
                cout<<num<<" Dimes"<<endl;
                coins(1,num,userC);
                cout<<num<<" Pennies"<<endl;
                //Prompt for repeat
                cout<<"Would you like to enter in a new input for change?"<<endl;
                cout<<"Enter in Y for yes or N for n:"<<endl;
                cin>>cho;
            }while(cho=='Y'||cho=='y');
            cout<<"******************"<<endl;
                break;
            }
        case '8':{
            cout<<"******************"<<endl;
            short userT,uWind;
            float result;
            //Prompt the user for inputs
            cout<<"This program will find the windchill index at a given air temperature."<<endl;
            cout<<"Please enter in a temperature (in Celsius)"<<endl;
            cin>>userT;
            cout<<"Next, enter in the wind speed (in m/sec):"<<endl;
            cin>>uWind;
            if(userT<=10){
                result=index(userT,uWind);
                cout<<"The windchill index is "<<result<<" (in degrees Celsius)"<<endl;
            }else{
                cout<<"The temperature is too warm to have a windchill."<<endl;
            }
            cout<<"******************"<<endl;
                break;
            }
        case '9':{
            cout<<"******************"<<endl;
            cout<<"This program simulates duel's between 3 people with different accurracy."<<endl;
            srand((unsigned int) time(0));
        //    for (int i=0;i<10;i++){
        //        bool trgtA = true;
        //        shoot(trgtA,0.5);
        //        cout<<trgtA<<endl;
        //    }
            //Declare Variables
            int aWins=0,bWins=0,cWins=0;
            for(int i=0;i<1000;i++){
                char winner=strDuel();
                switch(winner){
                    case 'a':
                        aWins++;
                        break;
                    case 'b':
                        bWins++;
                        break;
                    case 'c':
                        cWins++;
                        break;
                }
            }
            cout<<"Aaron won "<<(aWins/10.0)<<"% of the time."<<endl;
            cout<<"Bob won "<<(bWins/10.0)<<"% of the time."<<endl;
            cout<<"Charlie won "<<(cWins/10.0)<<"% of the time."<<endl;
            cout<<"******************"<<endl;
                break;
            }
        case 't':
        case 'T':{
            cout<<"******************"<<endl;
            short uMonth,uDate,uYear,day;
            bool leap;
            //Prompt the user for inputs
            cout<<"This program will tell you the day of the week for a date you input."<<endl;
            in(uMonth,uDate,uYear);
            //Call functions
            day=dayWeek(uYear,uMonth,uDate);
            cout<<"*****************************"<<endl;
            //Output
            if(day==0){
                cout<<"The day of the week for that day is Sunday"<<endl;
            }else if(day==1){
                cout<<"The day of the week for that day is Monday"<<endl;
            }else if(day==2){
                cout<<"The day of the week for that day is Tuesday"<<endl;
            }else if(day==3){
                cout<<"The day of the week for that day is Wednesday"<<endl;
            }else if(day==4){
                cout<<"The day of the week for that day is Thursday"<<endl;
            }else if(day==5){
                cout<<"The day of the week for that day is Friday"<<endl;
            }else if(day==6){
                cout<<"The day of the week for that day is Saturday"<<endl;
            }else{
                cout<<"Error in program calculation"<<endl;
            }
            cout<<"******************"<<endl;
                break;
            }
            default:{
                    cout<<"Incorrect Menu Choice"<<endl;
            }      
    };
    cout<<"Would you like to return to the menu? Enter Y for yes or N for no:"<<endl;
    cin>>repeat;
    }while(repeat=='Y'||repeat=='y'); 
    return 0;
}
//Problem 1 functions
float calcu(short a, short b, short c, short d, float x, float y){
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
//Problem 2 functions
short prompt(){
    short feet,inches,totInch;
    cout<<"How long is the pole in feet?"<<endl;
    cin>>feet;
    cout<<"What are the remaining inches?"<<endl;
    cin>>inches;
    totInch=inches+(feet*12);
    return totInch;
}
float calc(short a){
    float b,c;
    b=(a/12.0f);
    //cout<<"a/12= "<<b<<endl;
    c=b*0.3048;
    //cout<<"total meters: "<<c<<endl;
    return c;
}
void output(float a){
    short b;
    short c;
    b=a/1;
    c=(a*100)-(b*100);
    cout<<"The equivalent length is "<<b<<" meter(s) and "<<c<<" centimeter(s)"<<endl;
}
//Problem 3 functions
float promp(){
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
float cal(float a){
    float b,c;
    b=a/2.2046;
    //cout<<"b/2.2046= "<<b<<endl;
    c=b*1000;
    //cout<<"total grams: "<<c<<endl;
    return c;
}
void out(float a){
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
//Problem 4 functions
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
//Problem 5 functions
void nput(short &a,short &b){
    short in=1;
    do{
        in=1;
        cout<<"Please enter in the hour portion:"<<endl;
        cin>>a;
        cout<<"Next enter in the minute portion:"<<endl;
        cin>>b;
        if(a>24||a<0||b>61||b<0){
            cout<<"Incorrect input. Please try again."<<endl;
            in=0;
        }
    }while(in==0);
}

void alc(short &a, char &b){
    if(a>12){
        a-=12;
    }else if(a==0){
        a=12;
        b='A';
    }else if(a<12||a==24){
        b='A';
    }
}

void utput(short a,short b,char c){
    cout<<"***********************"<<endl;
    cout<<"The new time in 12-hour notation is: "<<a<<":"<<b<<" "<<c<<"M"<<endl;
    cout<<"***********************"<<endl;
}
//Problem 7 function
void coins(int a,int &b, int &c){
    b=0;
    if(a<=c){
        b=c/a;
        c-=(b*a);
    }
}
//Problem 8 function
float index(short t,short v){
    float w;
    w=13.12+0.6215*t-11.37*(pow(v,0.16))+0.3965*t*(pow(v,0.016));
    return w;
}
//Problem 9 functions
void shoot(bool &trgtA, float acc){
    float r=(rand()%1000/1000.0);
    if(r<acc){
        trgtA=false;
    }
}
char strDuel(){
    bool aaron=true, bob=true,charlie=true;
    bool fShot=true;
    while((aaron&&bob)||(aaron&&charlie)||(bob&&charlie)){
        //First is aaron's turn
        if(aaron){
            if(fShot){
                fShot=false;
            }else{
                if(charlie){
                shoot(charlie, 0.3333);
            }else if(bob){
                shoot(bob, 0.3333);
            }
            }
            
        }
        //It's bob's turn
        if(bob){
            if(charlie){
                shoot(charlie, 0.5);
            }else if(aaron){
                shoot(aaron, 0.5);
            }
        }
        //It's charlie's turn
        if(charlie){
            if(bob){
                shoot(bob, 1.0);
            }else if(aaron){
                shoot(aaron, 1.0);
            }
        }
    }
    if(aaron){
        return 'a';
    }else if(bob){
        return 'b';
    }else{
        return 'c';
    }
}
//Problem 10 functions
void in(short &x,short &y,short &z){
    cout<<"First enter in the month: (1 for Jan, 2 for Feb....etc"<<endl;
    cin>>x;
    cout<<"Next, enter in the date: (12 for 12th, 15 for 15th...etc"<<endl;
    cin>>y;
    cout<<"Last, enter in the year:"<<endl;
    cin>>z;
}

bool isLeap(short a){
    if(a%400==0){
        return 0;
    }else if(a%4==0&&a%100!=0){
        return 0;
    }else{
        return 1;
    }
}

short centVal(short b){
    short result;
    result=b/100;
    result%=4;
    result=3-result;
    result*=2;
    return result;
}

short yrVal(short c){
    short twoDig,end;
    twoDig=c-((c/100)*100);
    //cout<<"twoDig = "<<twoDig<<endl;
    end=twoDig/4;
    //cout<<"end without add = "<<end<<endl;
    end+=twoDig;
    //cout<<"end with two dig = "<<end<<endl;
    return end;
}

short monVal(short d, short e){
    if(d==1){
        bool leap=isLeap(e);
        if(leap==0){
            return 6;
        }else{
            return 0;
        }
    }else if(d==2){
        bool leap=isLeap(e);
        if(leap==0){
            return 2;
        }else{
            return 3;
        }
    }else if(d==3){
        return 3;
    }else if(d==4){
        return 6;
    }else if(d==5){
        return 1;
    }else if(d==6){
        return 4;
    }else if(d==7){
        return 6;
    }else if(d==8){
        return 2;
    }else if(d==9){
        return 5;
    }else if(d==10){
        return 0;
    }else if(d==11){
        return 3;
    }else if(d==12){
        return 5;
    }
}

short dayWeek(short y,short m, short d){
    short fin,mVal,yVal,cVal;
    mVal=monVal(m,y);
    yVal=yrVal(y);
    cVal=centVal(y);
    //cout<<"D:"<<d<<"mval:"<<mVal<<"yval:"<<yVal<<"cval:"<<cVal<<endl;
    fin=(d+mVal+yVal+cVal)%7;
    return fin;
}