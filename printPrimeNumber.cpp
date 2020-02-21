#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

#define totalNum 100

int isPrime ( int n );

int main ( void ){
    int i;
    using namespace std;
    cout <<"2 ";
    for ( i = 3; i < totalNum; i+=2){
        if ( isPrime(i)){
            cout << i <<" ";
        }
    }
    system("pause");
    return 0;
}

int isPrime( int n){
    int i;
    int flag = 1;
    for( i = 2; i <= sqrt(n); i++){
        if( n % i == 0){
            flag = 0;
            break;
        }
    }
    return flag;
}