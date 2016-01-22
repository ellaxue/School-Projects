/*
 * as13.cpp
 *	function pointer
 *  Created on: 10/31/2014
 *      Author: Ella
 */

#include <iostream>
#include <stdio.h>
using namespace std;

typedef double(*FUNC)(double);

double line(double x)
{
	return x;
}

double square(double x)
{
	return x*x;
}

double cube(double x)
{
	return x*x*x;
}
double integrate(FUNC f, double a, double b)
{
	double area = 0.0, dx;
	dx = 0.0001;

	for (double i = a; i <= b; i+=dx)
	{
		area += (f(i) * dx);
	}
	return area;
}
int main(void)
{
	cout<<"The integral of f(x) = x between 1 and 5 is: "<< integrate(line,1,5)<<endl;
	printf("%4.8f", integrate(square,1,5)); //print decimal number to 8 decimal places
	cout<<"The integral of f(x) = x^2 between 1 and 5 is: "<<integrate(square,1,5)<<endl;
	cout<<"The integral of f(x) = x^3 between 1 and 5 is: "<<integrate(cube,1,5)<<endl;
	return 0;
}



