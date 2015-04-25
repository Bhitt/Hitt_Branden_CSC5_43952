/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on April 24, 2015, 8:10 PM
 *      Purpose: 
 */

//System Libraries
#include <iostream>//I/O standard
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void shoot(bool &, float );
char strDuel();
//Execution Begins Here!
int main(int argc, char** argv) {
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
    return 0;
}

void shoot(bool &trgtA, float acc){
    float r=(rand()%1000/1000.0);
    if(r<acc){
        trgtA=false;
    }
}
//Return 'a' if aaron wins, 'b' if bob wins, 'c' if charlie wins
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