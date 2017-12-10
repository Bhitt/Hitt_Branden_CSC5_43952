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
#include <iomanip>//formatting
#include <string>//string compare
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
void sortC(char **,int ,int);
void swapStr(string &,string &);
void Problem6();
int **filTble(int,int);
void prntTbl(int **,int,int);
int **sumTble(int **,int,int);
void ProblemE();
short icing(char,char);
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
    cout<<"Type E to solve Extra Credit"<<endl;
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
            case 'E':
            case 'e':{
                cout<<"*********************"<<endl;
                ProblemE();
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
    string line1,line2,line3,line4,line5;
    string line6,line7,line8,line9,line10;
    bool swap=false;
    //fill strings
    for(int i=0;i<c;i++){
        line1+=a[0][i];
    }
    for(int i=0;i<c;i++){
        line2+=a[1][i];
    }
    for(int i=0;i<c;i++){
        line3+=a[2][i];
    }
    for(int i=0;i<c;i++){
        line4+=a[3][i];
    }
    for(int i=0;i<c;i++){
        line5+=a[4][i];
    }
    for(int i=0;i<c;i++){
        line6+=a[5][i];
    }
    for(int i=0;i<c;i++){
        line7+=a[6][i];
    }
    for(int i=0;i<c;i++){
        line8+=a[7][i];
    }
    for(int i=0;i<c;i++){
        line9+=a[8][i];
    }
    for(int i=0;i<c;i++){
        line10+=a[9][i];
    }
    //compare strings
    do{
       swap=false;
       if(line1<line2) swap=true,swapStr(line1,line2);
       if(line1<line3) swap=true,swapStr(line1,line3);
       if(line1<line4) swap=true,swapStr(line1,line4);
       if(line1<line5) swap=true,swapStr(line1,line5);
       if(line1<line6) swap=true,swapStr(line1,line6);
       if(line1<line7) swap=true,swapStr(line1,line7);
       if(line1<line8) swap=true,swapStr(line1,line8);
       if(line1<line9) swap=true,swapStr(line1,line9);
       if(line1<line10) swap=true,swapStr(line1,line10);
    }while(swap==true);
    do{
       swap=false;
       if(line2<line3) swap=true,swapStr(line2,line3);
       if(line2<line4) swap=true,swapStr(line2,line4);
       if(line2<line5) swap=true,swapStr(line2,line5);
       if(line2<line6) swap=true,swapStr(line2,line6);
       if(line2<line7) swap=true,swapStr(line2,line7);
       if(line2<line8) swap=true,swapStr(line2,line8);
       if(line2<line9) swap=true,swapStr(line2,line9);
       if(line2<line10) swap=true,swapStr(line2,line10);
    }while(swap==true);
    do{
       swap=false;
       if(line3<line4) swap=true,swapStr(line3,line4);
       if(line3<line5) swap=true,swapStr(line3,line5);
       if(line3<line6) swap=true,swapStr(line3,line6);
       if(line3<line7) swap=true,swapStr(line3,line7);
       if(line3<line8) swap=true,swapStr(line3,line8);
       if(line3<line9) swap=true,swapStr(line3,line9);
       if(line3<line10) swap=true,swapStr(line3,line10);
    }while(swap==true);
    do{
       swap=false;
       if(line4<line5) swap=true,swapStr(line4,line5);
       if(line4<line6) swap=true,swapStr(line4,line6);
       if(line4<line7) swap=true,swapStr(line4,line7);
       if(line4<line8) swap=true,swapStr(line4,line8);
       if(line4<line9) swap=true,swapStr(line4,line9);
       if(line4<line10) swap=true,swapStr(line4,line10);
    }while(swap==true);
    do{
       swap=false;
       if(line5<line6) swap=true,swapStr(line5,line6);
       if(line5<line7) swap=true,swapStr(line5,line7);
       if(line5<line8) swap=true,swapStr(line5,line8);
       if(line5<line9) swap=true,swapStr(line5,line9);
       if(line5<line10) swap=true,swapStr(line5,line10);
    }while(swap==true);
    do{
       swap=false;
       if(line6<line7) swap=true,swapStr(line6,line7);
       if(line6<line8) swap=true,swapStr(line6,line8);
       if(line6<line9) swap=true,swapStr(line6,line9);
       if(line6<line10) swap=true,swapStr(line6,line10);
    }while(swap==true);
    do{
       swap=false;
       if(line7<line8) swap=true,swapStr(line7,line8);
       if(line7<line9) swap=true,swapStr(line7,line9);
       if(line7<line10) swap=true,swapStr(line7,line10);
    }while(swap==true);
    do{
       swap=false;
       if(line8<line9) swap=true,swapStr(line8,line9);
       if(line8<line10) swap=true,swapStr(line8,line10);
    }while(swap==true);
    do{
       swap=false;
       if(line9<line10) swap=true,swapStr(line9,line10);
    }while(swap==true);
    //fill array with new strings
    for(int i=0;i<c;i++){
        a[0][i]=line1[i];
    }
    for(int i=0;i<c;i++){
        a[1][i]=line2[i];
    }
    for(int i=0;i<c;i++){
        a[2][i]=line3[i];
    }
    for(int i=0;i<c;i++){
        a[3][i]=line4[i];
    }
    for(int i=0;i<c;i++){
        a[4][i]=line5[i];
    }
    for(int i=0;i<c;i++){
        a[5][i]=line6[i];
    }
    for(int i=0;i<c;i++){
        a[6][i]=line7[i];
    }
    for(int i=0;i<c;i++){
        a[7][i]=line8[i];
    }
    for(int i=0;i<c;i++){
        a[8][i]=line9[i];
    }
    for(int i=0;i<c;i++){
        a[9][i]=line10[i];
    }
}
void swapStr(string &a,string &b){
    string temp;
    temp=a;
    a=b;
    b=temp;
}
//*************Problem6******************//
void Problem6(){
    //open file
    ofstream fout;
    fout.open("augtable.dat");
    //fill table
    int x=5,y=6,z=7;
    int **table=filTble(x,y);
    //print table
    cout<<"TABLE FROM FILE"<<endl;
    prntTbl(table,x,y);
    //create augtable
    int **augtble=sumTble(table,y,z);
    //print augtable
    cout<<endl;
    cout<<"AUGMENTED TABLE"<<endl;
    prntTbl(augtble,y,z);
    //send results to file
    cout<<"results sent to file (augtable.dat)"<<endl;
    for(int i=0;i<y;i++){
        for(int j=0;j<z;j++){
            fout<<setw(6)<<augtble[i][j];
        }
        fout<<endl;
    }
    //close the file
    fout.close();
}
int **filTble(int r,int c){
    //open file
    ifstream fin;
    fin.open("table.dat");
    //create rows
    int **array=new int*[r];
    //create columns
    for(int i=0;i<r;i++){
        array[i]=new int[c];
    }
    //fill array
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            fin>>array[i][j];
        }
    }
    //close files
    fin.close();
    //return array
    return array;
}
void prntTbl(int **a,int r,int c){
   for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<setw(6)<<a[i][j];
        }
        cout<<endl;
    } 
}
int **sumTble(int **a,int r,int c){
    //create new array
    int **array=new int*[r];
    //loop and create the columns
    for(int i=0;i<r;i++){
        array[i]=new int[c];
    }
    //fill the array
    for(int i=0;i<(r-1);i++){
        for(int j=0;j<(c-1);j++){
            array[i][j]=a[i][j];
        }
    }
    //add zeros for ends
    for(int i=0;i<r-1;i++){
        array[i][c-1]=0;
    }
    for(int i=0;i<c-1;i++){
        array[r-1][i]=0;
    }
    //add the rows
    for(int i=0;i<(r-1);i++){
        for(int j=0;j<(c-1);j++){
            array[i][c-1]+=a[i][j];
        }
    }
    //add the columns
    for(int j=0;j<(c-1);j++){
        for(int i=0;i<(r-1);i++){
            array[r-1][j]+=a[i][j];
        }
    }
    //grand total
    for(int i=0;i<c-1;i++){
        array[r-1][c-1]+=array[r-1][i];
    }
    // I thought you would want this added also, so left in code just in case
    //for(int i=0;i<r-1;i++){
    //    array[r-1][c-1]+=array[i][c-1];
    //}
    
    //return array
    return array;
}
//*************ProblemE******************//
void ProblemE(){
    cout<<"EXTRA CREDIT: New Order (DCBAJIHGFE)"<<endl;
    char l1,l2,l3,l4;//word 1
    char l5,l6,l7,l8;//word 2
    short cake=0;
    bool candle=false;
    cout<<"Please type in the first 4-Letter word:"<<endl;
    cin>>l1>>l2>>l3>>l4;
    cout<<"Now type in the second 4-Letter word:"<<endl;
    cin>>l5>>l6>>l7>>l8;
    //sort
    cake=icing(l1,l5);
    if(cake==1)candle=true;
    if(cake==0){
        cake=icing(l2,l6);
        if(cake==1)candle=true;
        if(cake==0){
            cake=icing(l3,l7);
            if(cake==1)candle=true;
            if(cake==0){
                cake=icing(l4,l8);
                if(cake==1)candle=true;
                if(cake==0){
                    cout<<"Same word twice!"<<endl;
                }
            }
        }
    }
    if(candle==false){
        cout<<"Smallest: "<<l1<<l2<<l3<<l4<<endl;
        cout<<"Largest: "<<l5<<l6<<l7<<l8<<endl;
    }
    if(candle==true){
        cout<<"Smallest: "<<l5<<l6<<l7<<l8<<endl;
        cout<<"Largest: "<<l1<<l2<<l3<<l4<<endl;
    }
}
short icing(char a,char b){
    short val1=0,val2=0;
    //find first letter value
    if(a=='D'||a=='d')val1=10;
    if(a=='C'||a=='c')val1=9;
    if(a=='B'||a=='b')val1=8;
    if(a=='A'||a=='a')val1=7;
    if(a=='J'||a=='j')val1=6;
    if(a=='I'||a=='i')val1=5;
    if(a=='H'||a=='h')val1=4;
    if(a=='G'||a=='g')val1=3;
    if(a=='F'||a=='f')val1=2;
    if(a=='E'||a=='e')val1=1;
    //find second letter value
    if(b=='D'||b=='d')val2=10;
    if(b=='C'||b=='c')val2=9;
    if(b=='B'||b=='b')val2=8;
    if(b=='A'||b=='a')val2=7;
    if(b=='J'||b=='j')val2=6;
    if(b=='I'||b=='i')val2=5;
    if(b=='H'||b=='h')val2=4;
    if(b=='G'||b=='g')val2=3;
    if(b=='F'||b=='f')val2=2;
    if(b=='E'||b=='e')val2=1;
    //return result
    if(val1>val2)return 2;
    if(val2>val1)return 1;
    if(val1==val2)return 0;
}