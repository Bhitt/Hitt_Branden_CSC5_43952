/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on March 29, 2015, 10:10 AM
 *      Purpose: Solve the Riddler's Riddle
 *              Find a 4 digit number that passes the conditions
 */

//System Libraries
#include <iostream>//I/O standard
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    //Loop for all possible digits
    for(int d1000=0;d1000<=9;d1000++){//loops thousand digit
        for(int d100=0;d100<=9;d100++){//loops hundred digit
            for(int d10=0;d10<=9;d10++){//loops tens digit
                for(int d1=0;d1<=9;d1++){//loops ones digit
                    if((d1000==3*d10) &&//condition 1 (thousand must be 3 times tens)
                        (d1%2==1)   &&//condition 2 (must be odd)
                        (d1000+d100+d10+d1==27) && //condition 3 (sum of digits must be 27)
                           (d1!=d10&&d1!=100&&d1!=d1000&&//condition 4 (digits must be different)
                            d10!=d100&&d10!=1000&&
                            d100!=1000)){
                        cout<<"The Address Number = ";
                        cout<<d1000<<d100<<d10<<d1<<endl;
                    }
                }
        }
    }
    }
    return 0;
}