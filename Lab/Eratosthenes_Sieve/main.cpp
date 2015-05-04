/* 
 * File:   main.cpp
 * Author: Branden Hitt
 * Created on May 4, 2015, 9:40 AM
 *      Purpose: Find prime numbers using eratosthenes sieve
 */

//System Libraries
#include <iostream>//I/O standard
#include <cmath>// sqrt
#include <iomanip>//formatting
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes
void sieve(bool [],int);
void prntPrm(const bool [],int,int);
void initial(bool [],int);
//Execution Begins Here!
int main(int argc, char** argv) { 
    //Declare Variables
    const int SIZE=10001;
    bool prime[SIZE];
    //Initialize the array
    initial(prime,SIZE);
    //Perform the sieve
    sieve(prime,SIZE);
    //Print the Sieve
    prntPrm(prime,SIZE,10);
    //Exit stage right
    return 0;
}

void prntPrm(const bool primes[],int n,int perLine){
    //Print out only the prime numbers
    int nPrimes=0;
    for(int i=0;i<n;i++){
        if(primes[i]){
            cout<<setw(5)<<i;
            if(nPrimes%perLine==(perLine-1))cout<<endl;
            nPrimes++;
        }
    }
    cout<<endl<<"Total number of primes "
            <<"between 0 and "<<n-1<<" = "<<nPrimes<<endl;
}

void sieve(bool primes[],int n){
    //Outer loop to process the sieve
    for(int i=2;i<sqrt(n);i++){
        if(primes[i]){
            //Inner loop of sieve
            for(int j=2*i;j<n;j+=i){
                primes[j]=false;
            }
        }
    }
    
}

void initial(bool primes[],int n){
    for(int i=0;i<n;i++){
        primes[i]=true;
    }
    primes[0]=false;
    primes[1]=false;
}