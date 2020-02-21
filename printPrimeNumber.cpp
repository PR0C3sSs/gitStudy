#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

#define totalNum 100

int isPrime ( int n );

int main ( void ){
    int i;
    using namespace std;
    for ( i = 1; i < totalNum; i++){
        if ( isPrime(i)){
            cout << i <<" ";
        }
    }
    system("pause");
    return 0;
}

int isPrime( int n ){
    int i;
    int flag = 1;
    if ( n == 1 || n % 2 == 0) flag = 0;
    for( i = 3; i <= sqrt(n); i+=2){
        if( n % i == 0){
            flag = 0;
            break;
        }
    }
    if ( n == 2 ) flag = 1;
    return flag;
}