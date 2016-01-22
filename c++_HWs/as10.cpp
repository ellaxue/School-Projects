/*
 * as10.cpp
 *
 *  Created on: Oct 14, 2014
 *      Author: Ella
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

bool check_stability( int mc[], int new_w, int m_pref[][3], int w_pref[][3],int new_m)
{
	int cur_m;//cur_m == current man / new_m == new man
	int cur_w;//cur_w == current woman/ new_w == new woman
	for (cur_m = 0; cur_m < new_m; cur_m++)
	{
		cur_w = mc[cur_m];
		// if the new woman is the same as the current woman,it means she has been assigned to some other man already
		if (new_w == cur_w)
		{
			return false;
		}
	}
	for (cur_m = 0; cur_m < new_m; cur_m++)
	{
		cur_w = mc[cur_m];
		for(int i = 0; i < new_m; i++)
		{
			// if the current man prefers the new w, and new woman prefers current man, not a stable match
			if (m_pref[cur_m][cur_w] > m_pref[cur_m][new_w]&&w_pref[new_w][new_m] > w_pref[new_w][cur_m])
			{
				return false;
			}

			//if the new man prefers the current woman, and the current woman prefers the new man, not a stable match
			if(m_pref[new_m][new_w] > m_pref[new_m][cur_w]&&w_pref[cur_w][cur_m] > w_pref[cur_w][new_m])
			{
				return false;
			}
		}
	}
	//passed test, no instabilities
	return true;
}
void print(int stable_match[], int size)
{
	printf("Men\tWomen\n");
	for (int i = 0 ; i < size; i++)
	{
	printf("%d\t%d\n",i,stable_match[i]);
	}
	printf("\n");

}

void back_track(int &man_index)
{
	man_index--;
	if ( man_index == -1)
	{
		exit(1);
	}

}
int main(void)
{
	int men_pref[3][3] = {0, 2, 1, 0, 2, 1, 1, 2, 0};
	int women_pref[3][3] = {2, 1, 0, 0, 1, 2, 2, 0, 1};

	int stable_match[3] = {0};
	int man_index = 1;
	while(1)
	{
		while(stable_match[man_index] < 3)
		{
			if(check_stability(stable_match, stable_match[man_index],men_pref,women_pref,man_index))
			{
				//passed test for existing couples, go to next man
				man_index++;
				//propose a new woman
				stable_match[man_index] = 0;

				//man_index == 3, all existing 3 men have been assigned with a woman without instabilities
				if(man_index == 3)
				{
					print(stable_match, 3);
					//go back to previous man, and assign a new woman to him
					back_track(man_index);
					stable_match[man_index]++;
				}
			}

			else
			{
				stable_match[man_index]++;
			}
		}

		//tested all the proposed women, can't find a stable match, go back to previous man
		back_track(man_index);
		//assign a new woman
		stable_match[man_index]++;
	}
}


