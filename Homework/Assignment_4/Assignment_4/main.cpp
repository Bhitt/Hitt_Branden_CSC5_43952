/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Purpose:  To Illustrate the code for
 * developing a menu
 * Modified on April 9, 2015
 */

//System Libraries
#include <iostream>// I/O
#include <iomanip>// Format
#include <string>// using strings
#include <string.h>//for string compare
#include <cstdlib>//for random number generator
using namespace std;

//User Libraries

//Global Constants
const float CONVLTG=0.264179;//liters to gallons
const float G=6.673e-8;//6.673*10^-8 for gravity
//Function Prototypes
float mpg(int a, int b);//miles per gallon function
float price(int pStkNum, int pStkDen, int nShares, int pStk);//stock function
float inf(float pYrAgo, float pNow);//function to find inflation rate
float AttFrce(float m1, float m2, float d);//Attractive force
float hatSize(int w, int h);//hat size
float jktSize(int w, int h, int a);//jacket size
float wstInch(int w,int a);//waist in inches
string lyric(unsigned short num1, unsigned short num2);//ninety nine bottles
bool cntDgt(int number, int digit);//checks the specific digits
bool yCnt147(int number);//checks if the number has 1,4,7
unsigned short draft(int team);// drafting function
//Execution Begins Here
int main(int argc, char** argv) {
    char ans;
    //General Menu Format
    //Display the selection
    do{
    cout<<"Type 1 to use problem 1: Miles Per Gallon"<<endl;
    cout<<"Type 2 to use problem 2: Stock Value"<<endl;
    cout<<"Type 3 to use problem 3: Inflation Rate"<<endl;
    cout<<"Type 4 to use problem 4: Gravitational Force"<<endl;
    cout<<"Type 5 to use problem 5: Clothing Size"<<endl;
    cout<<"Type 6 to use problem 6: 99 Bottles of Beer"<<endl;
    cout<<"Type 7 to use problem 7: Fried Twinkie Dispenser"<<endl;
    cout<<"Type 8 to use problem 8: Oven Keypad with Bool Function"<<endl;
    cout<<"Type 9 to use problem 9: Draft Orders"<<endl;
    cout<<"Type T to use problem 10: "<<endl;
    //Read the choice
    char choice;
    cin>>choice;
    //Solve a problem that has been chosen.
    switch(choice){
            case '1':{
                //Execution Begins Here!
                    char choice;//to ask if you want to repeat
                    unsigned short nLit, nMiles;//number of liters used, number of miles driven
                    float result;
                    //Prompt the user for inputs
                    cout<<"This program will find your miles per gallon from your car."<<endl;
                    do{
                        cout<<"Please first enter in the number of liters of gasoline consumed:"<<endl;
                        cin>>nLit;
                        cout<<"Next enter in the amount of miles traveled:"<<endl;
                        cin>>nMiles;
                        result=mpg(nLit, nMiles);
                        cout<<"Your car traveled "<<result<<" miles per gallon"<<endl;
                        cout<<"Would you like to run this program again?"<<endl;
                        cin>>choice;
                    }while(choice=='y'||choice=='Y');
                break;
            }
            case '2':{
                unsigned short nShares, pStk, pStkNum, pStkDen;
                float stkPr;
                char choice;
                //Loop on answer
                do{
                    //Prompt the user for inputs
                    cout<<"What is the number of shares of stock owned: "<<endl;
                    cin>>nShares;
                    cout<<"What is the whole dollar portion of the price of the stock: "<<endl;
                    cin>>pStk;
                    cout<<"For the fractional portion, input first the numerator: "<<endl;
                    cin>>pStkNum;
                    cout<<"Next for the fractional portion, input the denominator: "<<endl;
                    cin>>pStkDen;
                    stkPr=price(pStkNum,pStkDen,nShares,pStk);
                    //Output
                    cout<<"Would you like to run this again? Y for Yes. No for No."<<endl;
                    cin>>choice;
                }while(choice=='Y'||choice=='y');
                break;
            }
            case '3':{
                char choice;//for repeat
                do{
                //Declare Variables
                    float pYrAgo, pNow;//price a year ago, price now
                    //Prompt the user for inputs
                    cout<<"This program will gauge the rate of inflation for the past year."<<endl;
                    cout<<"First give me the price of a hot dog 1 year ago: (xx.xx)"<<endl;
                    cin>>pYrAgo;
                    cout<<"Now give me the price of a hot dog today: (xx.xx)"<<endl;
                    cin>>pNow;

                    inf(pYrAgo, pNow);
                    cout<<"Would you like to run this program again?"<<endl;
                    cout<<"Type Y for yes or N for no: "<<endl;
                    cin>>choice;
                }while(choice=='Y'||choice=='y');       
                break;
            }
            case '4':{
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
                break;
            }
            case '5':{
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
                break;
            }
            case '6':{
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
                break;
            }
            case '7':{
                //Declare Variables
                const int SIZE=80;
                char input[SIZE];
                unsigned short totChng=0, pTwnke=350;
                char nQrts, nDimes, nNikels;
                //Prompt the user for inputs
                cout<<fixed<<setprecision(2)<<showpoint;
                cout<<"This is a Fried Twinkie Vending Machine"<<endl;
                cout<<"Fried Twinkies cost $3.50"<<endl;
                cout<<"Input your change as "<<endl;
                cout<<"Dollar, Quarter, Dime, Nickel"<<endl;
                cout<<"One at a time:"<<endl;
                do{
                    cout<<"Input coins/change"<<endl;
                    cin>>input;
                    if(strcmp(input,"Dollar")==0){
                        totChng+=100;//Add a Dollar
                    }else if (strcmp(input, "Quarter")==0){
                        totChng+=25;//Add a Quarter
                    }else if (strcmp(input, "Dime")==0){
                        totChng+=10;//Add a Dime
                    }else if (strcmp(input, "Nickel")==0){
                        totChng+=5;//Add a Nickel
                    }else {
                        cout<<"No Slugs Allowed"<<endl;//Invalid input
                    }
                    //Output 
                    cout<<"Total Change = $"<<totChng/100.0f<<endl;
                    cout<<endl;
                }while(totChng<pTwnke);
                //Give Twinkie
                cout<<endl<<"Here is your Fried Twinkie"<<endl;
                //Calculate the change
                totChng-=pTwnke;
                cout<<"Your change is = $"<<totChng/100.0f<<endl;
                //How many Quarters
                nQrts=totChng/25;
                if(nQrts>0)cout<<static_cast<int>(nQrts)<<" Quarters Change"<<endl;
                //How many Dime
                totChng-=nQrts*25;
                nDimes=totChng/10;
                if(nDimes>0)cout<<static_cast<int>(nDimes)<<" Dimes Change"<<endl;
                //How many Nickels
                totChng-=nDimes*10;
                nNikels=totChng/5;
                if(nNikels>0)cout<<static_cast<int>(nNikels)<<" Nickels Change"<<endl;
                //Exit Stage Right
                break;
            }
            case '8':{
                int temp;
                bool cnt147;
                cout<<"Enter the desired temperature."<<endl;
                cin>>temp;//user's desired temp

                int lowTemp=temp;
                cnt147=yCnt147(lowTemp);
                while(cnt147){
                    lowTemp--;
                    cnt147=yCnt147(lowTemp);
                }
                int hiTemp=temp;
                cnt147=yCnt147(hiTemp);
                while(cnt147){
                    hiTemp++;
                    cnt147=yCnt147(hiTemp);
                }
                cout<<"The next closest lower temperature is "<<lowTemp<<endl;
                cout<<"The next closest higher temperature is "<<hiTemp<<endl;
                break;
            }
            case '9':{
                //Declare Variable
                int a, pick, pick2=0, pick3, pick4, tPcked=0;
                srand(static_cast<unsigned int>(time(0)));
                //Output
                cout<<"**********************************************************"<<endl;
                cout<<"This program will find draft picks for the lowest ranking teams."<<endl;
                cout<<"Balls with numbers on them will be taken from an urn to determine pick order."<<endl;
                cout<<"Team 1 will have 20 balls (1-20) in the urn for coming in last."<<endl;
                cout<<"Team 2 will have 10 balls (21-30) in the urn for coming in second to last."<<endl;
                cout<<"Team 3 will have 6 balls  (31-36) in the urn for coming in third-to last."<<endl;
                cout<<"Team 4 will have 4 balls  (37-40) in the urn for coming in fourth-to-last."<<endl;
                cout<<"**********************************************************"<<endl;
                pick=draft(a);
                tPcked+=1;
                cout<<"The First pick is Team "<<pick<<endl;
                cout<<"**********************************************************"<<endl;
                do{
                    pick2=draft(a);
                }while(pick2==pick);
                cout<<"The Second pick is Team "<<pick2<<endl;
                cout<<"**********************************************************"<<endl;
                do{
                    pick3=draft(a);
                }while(pick3==pick||pick3==pick2);
                cout<<"The Third pick is Team "<<pick3<<endl;
                cout<<"**********************************************************"<<endl;
                do{
                    pick4=draft(a);
                }while(pick4==pick||pick4==pick2||pick4==pick3);
                cout<<"The Fourth pick is Team "<<pick4<<endl;
                break;
            }
            case 't':
            case 'T':{
                
                break;
            }
            default:{
                    cout<<"Invalid Menu Choice"<<endl;
            }
    };
    cout<<"Would you like to Return to the Menu? Type Y for yes or N for no:"<<endl;
    cin>>ans;
    }while((ans=='y'||ans=='Y'));
    return 0;
}
float mpg( int a, int b){
                    //declare variables for calculation
                    float nGal, mPGal;// number of gallons after conversion, miles per gallon
                    nGal=a*CONVLTG;//formula to convert user's liters to gallons
                    //cout<<"nGal: "<<nGal<<endl;
                    mPGal=1.0f*b/nGal;//formula to find miles per gallon
                    //cout<<"mPGal: "<<mPGal<<endl;  
 }
float price(int pStkNum, int pStkDen, int nShares, int pStk){
    //Declare
    float pStkFlt, totStkP;
    //Single Share Price
        pStkFlt=pStk+(1.0f*pStkNum/pStkDen);
        cout<<"The price of one stock is: $"<<pStkFlt<<endl;
        //Total Holdings
        totStkP=nShares*pStkFlt; 
        cout<<"Your total holdings of stock is: $"<<totStkP<<endl;
}
float inf(float pYrAgo,float pNow){
    float infRate;
    infRate=((pNow-pYrAgo)/pYrAgo)*100;//formula to get inflation rate
    cout<<"The rate of inflation was: "<<infRate<<"%"<<endl;
}
float AttFrce(float m1, float m2, float d){
    return(G*m1*m2/(d*d));
    
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
//*****************************************************
bool cntDgt(int number, int digit){
    int ones, tens, hund;
    bool cntDgt;
    
    ones=number%10;
    tens=(number/10)%10;
    hund=(number/100);
    if ((ones==digit)||(tens==digit)||hund==digit){
        cntDgt=true;
    }else{
        cntDgt=false;
    }
    return cntDgt;
}
//***************************************************
bool yCnt147(int number){
    if((cntDgt(number,1))||(cntDgt(number,4))||(cntDgt(number,7))){
        return true;
    }else{
        return false;
    }
}
//***************************************************
unsigned short draft(int a){
    int choice=(rand()%40)+1;
    cout<<"The Ball picked from the Urn is Ball:"<<choice<<endl;
    if (choice<21){
        return 1;
    }else if ((choice>=20)&&(choice<31)){
        return 2;
    }else if ((choice>=31)&&(choice<37)){
        return 3;
    }else {
        return 4;
    }
}