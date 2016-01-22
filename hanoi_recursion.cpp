/*
 * hanoi_recursion.cpp
 *
 *  Created on: 2014Äê11ÔÂ14ÈÕ
 *      Author: Ella
 */
#include <iostream>
#include <stdio.h>
using namespace std;
void move(char F, char T, char E, int n)
{
	static int steps;
	if (n == 1)
	{
		steps ++;
		cout<<"n== 1 steps " <<steps<<endl;
		cout<<"transfer "<<n<<" from " << F << " to "<< T <<endl;

		//printf("%s%c%s%c","transfer from "<< F << " to " <<T);
		n++;
		return;
	}
	move (F,E,T,n-1);
	steps ++;
	cout<<"moveF,E,T,) steps " <<steps<<endl;
	cout<<"transfer "<<n<<" from " << F << " to "<< T <<endl;

//	printf("%s%c%s%c","transfer from "<< F << " to " <<T);
	move (E,T,F,n-1);
	cout<<"return" <<endl;
	return;

}
int main(void)
{
	int n = 0;
	char From = 'a' , To ='b', Extra = 'c';
	printf("please input size:");
	scanf("%d", &n);
	move(From, To, Extra,n);
	return 0;
}



