/*
 * as17_Rec_stableMarrige.cpp
 *
 *  Created on: 2014/11/20
 *      Author: Ella
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

bool check_stability( int *mc,int new_m)
{
	int cur_m;
	int cur_w;
	int m_pref[3][3] = {0, 2, 1, 0, 2, 1, 1, 2, 0};
	int w_pref[3][3] = {2, 1, 0, 0, 1, 2, 2, 0, 1};
	for (int cur_m = 0; cur_m < new_m; cur_m++)
	{
		cur_w = mc[cur_m];
		if (mc[new_m] == cur_w)
		{
			return false;
		}
	}
	for (int cur_m = 0; cur_m < new_m; cur_m++)
	{
		cur_w = mc[cur_m];
		for(int i = 0; i < new_m; i++)
		{
			if (m_pref[cur_m][cur_w] > m_pref[cur_m][mc[new_m]]&&w_pref[mc[new_m]][new_m] > w_pref[mc[new_m]][cur_m])
			{
				return false;
			}

			if(m_pref[new_m][mc[new_m]] > m_pref[new_m][cur_w]&&w_pref[cur_w][cur_m] > w_pref[cur_w][new_m])
			{
				return false;
			}
		}
	}
	//passed test, no instabilities
	return true;
}
void print(int *stable_match)
{
	printf("Men\tWomen\n");
	for (int i = 0 ; i < 3; i++)
	{
	printf("%d\t%d\n",i,stable_match[i]);
	}
	printf("\n");

}

void move(int *q, int i)
{
	if (i == 3)
	{
		print(q);
		return;
	}
	for ( int j = 0; j < 3; j++)
	{
		q[i] = j;
		if(check_stability(q,i))
		{
			move(q, i+1);
		}
	}
}


int main(void)
{
	int stable_match[3] = {0};
	move(stable_match,0);

	return 0;
}






