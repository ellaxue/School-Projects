/*
 * as14.cpp
 *
 *  Created on: 2014Äê10ÔÂ31ÈÕ
 *      Author: Ella
 */
#include<iostream>
#include <stdio.h>
using namespace std;
unsigned long previous_n[2];
int last_n = 0;
int count = 0;
unsigned long fib(int n) {
    if ((n == 1) || (n == 2)) {
        return 1;
    } else if (n <= last_n) {
        // always return the previous one calculated value
        return previous_n[n+1-last_n];
    }
    // new # = sum of # (n-1) and # (n-2)
    return fib(n - 1) + fib(n - 2);
}
;

int main(void) {
unsigned long int i = (unsigned long int) -1;
printf("%lu\n", i);

    unsigned long new_n;
    for (int i = 1; i < 70; i++) {
        new_n = fib(i);
        printf("fib(%d) = %lu\n", i, new_n);

        // updated the where we have the recent value
        last_n++;
        cout<<last_n<<endl;
        // update the array to track the last two values
        previous_n[0] = previous_n[1];
        previous_n[1] = new_n;
    }
    return 0;
}




