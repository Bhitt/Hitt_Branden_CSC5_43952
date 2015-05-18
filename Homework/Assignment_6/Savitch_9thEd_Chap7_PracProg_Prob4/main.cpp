/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on May 18, 2015, 10:00 AM
 *      Purpose: contact list/phone number array
 */

//System Libraries
#include <iostream>//I/O standard
#include <string>//for strings
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
string lookupN(string,string [],string [],short);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    string names[]={"Michael Myers","Ash Williams","Jack Torrance","Freddy Krueger"};
    string phneNum[]={"333-8000","333-2323","333-6150","339-7970"};
    string tgtName,tgtPhne;
    char c;
    do{
        cout<<"Enter a name to find the corresponding phone number."<<endl;
        getline(cin, tgtName);
        tgtPhne=lookupN(tgtName,names,phneNum,4);
        if(tgtPhne.length()>0){
            cout<<"The number is:"<<tgtPhne<<endl;
        }else{
            cout<<"Name not found"<<endl;
        }
        cout<<"Look up another name? (y/n)"<<endl;
        cin>>c;
        cin.ignore();
    }while(c=='Y'||c=='y');
    //exit stage right
    return 0;
}
//look up name function
string lookupN(string a,string b[],string c[],short d){
    for(int i=0;i<d;i++){
        if(a==b[i]){
            return c[i];
        }
    }
    string error="";
    return error;
}