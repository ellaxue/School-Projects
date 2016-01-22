/*
 * as14_fib_yu.cpp
 *
 *  Created on: 2014Äê11ÔÂ20ÈÕ
 *      Author: Ella
 */

#include<iostream>
#include <stdio.h>
using namespace std;
unsigned long int fib(int n)

{

 static unsigned long int memo[100] = {0,1,1};

 if(n==1 || n==2) return 1;

 if (memo[n]!= 0)
	 {
	 printf("niih\n");
	 return memo[n];
	 }

 return memo[n] = fib(n-1)+fib(n-2);

}
int main(void) {
unsigned long int i = (unsigned long int) -1;
printf("%lu\n", i);

    unsigned long new_n;
    for (int i = 1; i < 70; i++) {
        new_n = fib(i);
        printf("fib(%d) = %lu\n", i, new_n);

    }
    return 0;
}
