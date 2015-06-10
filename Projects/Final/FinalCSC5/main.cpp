/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Purpose:  Final Problems
 * Created on June 9th, 2015
 */

//System Libraries
#include <iostream>//I/O
#include <ctime>// computer time for srand
#include <cstdlib>//rand
#include <fstream>// I/O to file
#include <vector>//vectors
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void Problem1();

void Problem2();
bool check(short,short);
void Problem3();
void fillVec(vector<int> &,int,bool);
void prntVec(vector<int> &,int,int);
void filOdEv(int **,vector<int> &,vector<int> &,int);
void prntOE(int **,int,int);
void Problem4();
void retrand(short int [],int [],short,short);
void Problem5();
char **filCA(int,int);
void prntAry(char **,int,int);
void sortC(char **a,int r,int c);
void Problem6();
//Execution Begins Here
int main(int argc, char** argv) {
    //General Menu Format
    srand(static_cast<unsigned int>(time(0)));//set random seed
    char repeat;
    //Display the selection
    do{
    cout<<"Type 1 to solve problem 1"<<endl;
    cout<<"Type 2 to solve problem 2"<<endl;
    cout<<"Type 3 to solve problem 3"<<endl;
    cout<<"Type 4 to solve problem 4"<<endl;
    cout<<"Type 5 to solve problem 5"<<endl;
    cout<<"Type 6 to solve problem 6"<<endl;
    cout<<"Type anything else to quit with no solutions."<<endl;
    //Read the choice
    char choice;
    cin>>choice;
    //Solve a problem that has been chosen.
    switch(choice){
            case '1':{
                cout<<"*********************"<<endl;
                Problem1();
                cout<<"*********************"<<endl;
                break;
            }
            case '2':{
                cout<<"*********************"<<endl;
                Problem2();
                cout<<"*********************"<<endl;
                break;
            }
            case '3':{
                cout<<"*********************"<<endl;
                Problem3();
                cout<<"*********************"<<endl;
                break;
            }
            case '4':{
                cout<<"*********************"<<endl;
                Problem4();
                cout<<"*********************"<<endl;
                break;
            }
            case '5':{
                cout<<"*********************"<<endl;
                Problem5();
                cout<<"*********************"<<endl;
                break;
            }
            case '6':{
                cout<<"*********************"<<endl;
                Problem6();
                cout<<"*********************"<<endl;
                break;
            }
            default:{
                    cout<<"Exit"<<endl;
            }
    };
    cout<<"Would you like to pick a different problem to run?"<<endl;
    cout<<"Enter in Y or N"<<endl;
    cin>>repeat;
    }while(repeat=='Y'||repeat=='y');
    return 0;
}
//*************Problem1******************//
void Problem1(){
    unsigned short num;
    cout<<"UNSIGNED TO SIGNED REVERSAL"<<endl;
    cout<<"Please enter in a number between 0 and 65,000"<<endl;
    cout<<"I will attempt to reverse it:"<<endl;
    cin>>num;
    short out = 0;
    while (num != 0){
        out *= 10;
        out += num % 10;
        num /= 10;
    }
    if(out<0)cout<<"No conversion possible"<<endl;
    else cout<<out<<endl;
}
//*************Problem2******************//
void Problem2(){
    char repeat;
    do{
    //variables
    bool win=false;
    short guess,myNum,tally=0;
    //randomly pick myNum
    myNum=rand()%1000+1;
    cout<<"GUESS THE NUMBER"<<endl;
    cout<<"I have a number between 1 and 1000."<<endl;
    cout<<"Can you guess my number? You will be"<<endl;
    cout<<"given a maximum of 10 guesses."<<endl;
    cout<<endl;
    do{
    if(tally!=0)cout<<"Guesses made: "<<tally<<endl;
    if(tally==0)cout<<"Please type your first guess:"<<endl;
    else cout<<"Please guess again:"<<endl;
    cin>>guess;
    tally++;
    win=check(myNum,guess);
    cout<<"*********************"<<endl;
    }while(tally<10&&win==false);
    if(win==true)cout<<"Congratulations, You guess the number! ("<<myNum<<")"<<endl;
    if(win==false){
        cout<<"Too many tries. You Lose :("<<endl;
        cout<<"The number was: "<<myNum<<endl;
    }
    cout<<"Would you like to play again with a new number?"<<endl;
    cout<<"Enter Y or N:"<<endl;
    cin>>repeat;
    }while(repeat=='Y'||repeat=='y');
}
bool check(short myNum,short guess){
    if(myNum>guess){
        cout<<"Too Low. Try Again"<<endl;
        return false;
    }else if(myNum<guess){
        cout<<"Too High. Try Again"<<endl;
        return false;
    }else{
        return true;
    }
}
//*************Problem3******************//
void Problem3(){
    cout<<"VECTORS"<<endl;
    //prompt the user for the size of the vectors
    int vecSize,cols;
    bool even=true;
    cout<<"What size would you like the vectors to be?:"<<endl;
    cin>>vecSize;
    cout<<"How many columns would you like displayed?:"<<endl;
    cin>>cols;
    cout<<"*********************"<<endl;
    //create the vectors
    vector<int> evens(vecSize);
    vector<int> odds(vecSize);
    //fill the vectors
    fillVec(evens,vecSize,even);
    even=false;
    fillVec(odds,vecSize,even);
    //print the vectors
    cout<<"Even Vector"<<endl;
    prntVec(evens,vecSize,cols);
    cout<<endl;
    cout<<"Odd Vector"<<endl;
    prntVec(odds,vecSize,cols);
    cout<<endl;
    //create 2d array
    int oddEven[2][vecSize];
    //fill 2d array
    for(int i=0;i<vecSize;i++){
        oddEven[0][i]=evens[i];
        oddEven[1][i]=odds[i];
    }
    //print 2d array
    cout<<"2 Dim Array"<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<vecSize;j++){
            cout<<oddEven[i][j]<<" ";
        }
        cout<<endl;
    }
}
void fillVec(vector<int> &a,int n,bool even){
    if(even){
    for(int i=0;i<n;i++){
        do{
        a[i]=rand()%90+10;
        }while(a[i]%2!=0);
    }
    }else{
        for(int i=0;i<n;i++){
        do{
        a[i]=rand()%90+10;
        }while(a[i]%2==0);
    }
    }
    
}
void prntVec(vector<int> &a,int n,int perLine){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
}
//*************Problem4******************//
void Problem4(){
    //setup
    const int n=5,ntimes=10000;
    int freq[n]={0};
    short int rndseq[]={9,51,78,101,121};
    //call routine
    retrand(rndseq,freq,n,ntimes);
    //results
    for(int i=0;i<n;i++){
        cout<<rndseq[i]<<" occurred "<<freq[i]<<" times"<<endl;
    }
}
void retrand(short int rnd[],int freq[],short n,short ntimes){
    int pick;
    for(int i=0;i<ntimes;i++){
        pick=rand()%n;
        freq[pick]++;
    }
}
//*************Problem5******************//
void Problem5(){
    //problem
    cout<<"ALL KINDS OF SORTING"<<endl;
    //create the array
    int rows=10, cols=15;
    char **cIndex=filCA(rows,cols);
    //print the array
    prntAry(cIndex,rows,cols);
    cout<<endl;
    //sort the array
    sortC(cIndex,rows,cols);
    //print the sorted array
    prntAry(cIndex,rows,cols);
    //exit stage right
}
char **filCA(int rows,int cols){
    //file I/O
    ifstream fin;
    fin.open("input.dat");
    //create the number of rows
    char **array=new char*[rows];
    //create columns
    for(int i=0;i<rows;i++){
        array[i]=new char[cols];
    }
    //fill the array
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            fin>>array[i][j];
        }
    }
    //close the file
    fin.close();
    //return the array
    return array;
}
void prntAry(char **a,int r,int c){
for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
void sortC(char **a,int r,int c){
    
}
//*************Problem6******************//
void Problem6(){
    
}