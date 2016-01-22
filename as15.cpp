/*
 * as15.cpp
 *	Towers of Hanoi:
 *	Move n rings from tower 1 to tower 2.
 *	Can't place a larger ring on top of a smaller ring and can only move one ring at a time
 *  Created on: 2014/11/7
 *      Author: Ella
 */

#include <iostream>
#include <vector>
#include <stdio.h>

int main(void)
{
	std::vector<int> t[3];
	unsigned int n, candidate, to, from, move = 0;
	printf("Please enter a number of rings to move:\n");
	scanf("%d",&n);

	//initialize the n towers
	for(int i=n+1;i>=1;i--)
	{
		t[0].push_back(i);
	}
	t[1].push_back(n+1);
	t[2].push_back(n+1);


	if (n % 2 != 0)//odd number rings
	{
		// initialize towers and candidate
		from=0;
		to=1;
		candidate=1;

		//when tower 2(B) has all the rings, done.
		while (t[1].size() < n+1)
		{
			printf("%s %d%s %d %s","Step",++move,": Move ring",candidate,"from tower");
			printf(" %c %s %c%s\n", from+65,"to tower", to+65,".");

			t[to].push_back(t[from].back());
			t[from].pop_back();

			if (t[(to+1)%3].back() < t[(to+2)%3].back())
			{
				from=(to+1)%3;
			}
			else
			{
				from=(to+2)%3;
			}
			if( t[from].back() < t[(from+1)%3].back())
			{
				to=(from+1)%3;
			}
			else
			{
				to=(from+2)%3;
			}
			candidate = t[from].back();
		}
	}

	else//even number rings
	{
		from = 0;
		to = 2;
		candidate = 1;

		while (t[1].size()<n+1)
		{
			printf("%s %d%s %d %s","Step",++move,": Move ring",candidate,"from tower");
			printf(" %c %s %c%s\n", from+65,"to tower", to+65,".");

			t[to].push_back(t[from].back());
			t[from].pop_back();

			if (t[(to+1)%3].back() < t[(to+2)%3].back())
			{
				from = (to+1)%3;
			}
			else
			{
				from = (to+2)%3;
			}
			if (t[(from+2)%3].back() < t[(from)].back() )
			{
				to = (from+1)%3;
			}
			else
			{
				to = (from+2)%3;
			}
			candidate = t[from].back();
		}
	}
	return 0;
}



