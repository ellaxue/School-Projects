/*
 * as8.cpp
 *
 *  Created on: 2014Äê10ÔÂ3ÈÕ
 *      Author: Ella
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void back_track(int &col)
{
	//go back 1 column
	col--;

	// col == -1 means out of board, all possible solutions have been tested, exit program
	if (col == -1)
	{
		exit(1);
	}
}

void print_array(int cross[], int &count)
{
	cout<<"Solution " << count << ":" <<endl;
	cout<<" ";

	//print the first two number in the first line
	for (int i = 0; i < 2; i++)
	{
		cout<<" "<< cross[i];
	}
	cout<<endl;

	//print 3rd - 6th numbers in the second line
	for (int i = 2; i < 6; i ++)
	{
		cout<<cross[i] <<" ";
	}
	cout<<endl;
	cout<<" ";

	//print 7 & 8th numbers in the third line
	for (int i = 6; i < 8; i++)
	{
		cout<<" "<< cross[i];
	}
	cout<<endl;
	cout<<"------------------------cutting-line------------------------"<<endl;
}
bool check_ok(int check[][5], int cross[], int cross_index)
{
	int check_index = 0;

	/*cross_index is the current index in the 1D array(cross)
	* which corresponds to the row index in the 2D array (check).
	* "-1" represents a "sentinel", only need to test the numbers before "-1"
	*/
	for (int col = 0; check[cross_index][col]!= -1; col++)
	{
		//record the adjacent blocks that might have conflict with the
		//current block in the cross array that we want to place a number in
		check_index = check[cross_index][col];

		/*test through each adjacent block that might exists conflict with the value in the current block
		* if the difference between 2 numbers is 1, they are consecutive numbers then the conditions
		* do not satisfy the requirement. return false
		* */
		if (abs(cross[cross_index] - cross[check_index]) == 1)
		{
			return false;
		}
	}

	//test if the number we are trying to place in in the current block is a duplicated number
	//need to test every number on the left side of the current block
	for (int i = 0; i < cross_index;i++)
	{
		if (cross[cross_index] == cross[i])
		{
			return false;
		}
	}

	//passed test, no conflict exists
	return true;
}

int main(void)
{
	int cross[8] = {0};
	int count = 0;
	int cross_index = 0;
	bool from_backTrack = false;
	/*fill out the board with all blocks that we need to check for conflicts
	* every number before "-1", indicates a adjacent block to the current block that we
	* want to place a number in, which are the ones need to be tested
	*/
	int check[8][5] = {{-1,},{0,-1},{0,-1},{0,1,2,-1},{0,1,3,-1},{1,4,-1},{2,3,4,-1},{3,4,5,6,-1}};

	//place the first number in the first index
	cross[0] = 1;

	while (1)
	{
		//if not from the back_track function, start with the second index in the cross array
		//since there is no number have been placed after the first index, no need to test the value in the first index
		if (!from_backTrack)
		{
			cross_index = 1;
			cross[cross_index] = 1;
		}

		//coming back from back_track function,
		//to test for other possibilities by increasing the value in the current block
		else cross[cross_index]++;

		from_backTrack = true;

		//only 1-8 numbers are allowed, can't exceed 8
		while (cross[cross_index] < 9)
		{
			if (check_ok(check, cross, cross_index))
			{
				//passed the conflict test, move to next column, and place 1 in the current block
				cross_index ++;
				cross[cross_index] = 1;

				//out of board, all numbers 1 -8 have been placed in the right blocks, print out solutions.
				if (cross_index == 8)
				{
					print_array(cross, ++count);
					//once done printing, go back_track and find other solutions.
					break;
				}
			}//if (check_ok)

			else
			{
				//if conflict exists,increase the number in the current block by 1 and re-test it
				cross[cross_index]++;

				/*when the number in the cross board reaches 9,
				*it means we have tested out all 1-8 numbers that we can place in the cross board
				*leave the while loop, go back_track to try other possibility in previous columns*/
				if (cross[cross_index] == 9) break;
			}
		}//while (cross[cross_index] < 9)

		//go back in columns to try other possibilities
		back_track(cross_index);

	}//while (true)
}//main



