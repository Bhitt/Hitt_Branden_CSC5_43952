/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 22, 2015, 9:50 AM
 *      Purpose: Find the day of the week
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void input(short &,short &,short &);
bool isLeap(short);
short centVal(short);
short yrVal(short);
short monVal(short,short);
short dayWeek(short, short, short);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    short uMonth,uDate,uYear,day;
    bool leap;
    //Prompt the user for inputs
    cout<<"This program will tell you the day of the week for a date you input."<<endl;
    input(uMonth,uDate,uYear);
    //Call functions
    day=dayWeek(uYear,uMonth,uDate);
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
    return 0;
}
void input(short &x,short &y,short &z){
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
    twoDig=c-((c/10)*10);
    //cout<<"twoDig = "<<twoDig<<endl;
    end=twoDig/4;
    end+=twoDig;
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
    fin=(d+mVal+yVal+cVal)%7;
    return fin;
}