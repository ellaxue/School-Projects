 /*  as16_cross_numbers.cpp
 *	redo cross numbers using recursion
 *  Created on: 2014/11/15
 *      Author: Ella
 *
 *  place 1 - 8 numbers in a cross board, no two consecutive numbers can be placed
 *  in two adjacent blocks. By adjacent means vertically, horizontally, or diagonally.
 *  example:
 *    3 5
 *  7 1 8 2
 *    4 6
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void print_array(int cross[])
{
	cout<<"print"<<endl;
	static int count = 0;
	cout<<"Solution " << ++count << ":" <<endl;
	cout<<" ";

	for (int i = 0; i < 8; i++)
	{
		cout<<" "<< cross[i];
	    if ((i == 1) || (i == 5) || (i==7))
	    {

	    	cout << endl;
	    }

	}
	cout<<"------------------------cutting-line------------------------"<<endl;
}
bool check_ok(int *cross, int i)
{
		int check[8][5] = {{-1,},{0,-1},{0,-1},{0,1,2,-1},{0,1,3,-1},{1,4,-1},{2,3,4,-1},{3,4,5,6,-1}};

		for(int k = 0; k < i; k++)
		{
			if(cross[k]==cross[i])
			{
				return false;
			}
		}
		for(int k = 0;check[i][k] != -1; k++)
		{
			if(abs(cross[i] - cross[check[i][k]]) == 1)
			{
				return false;
			}
		}
		return true;
}
void move(int* cross, int cross_index)
{

	if (cross_index == 8)
	{
		print_array(cross);
		return;
	}
	for (int j = 1; j < 9; j++ )
	{
		cross[cross_index] = j;
		if (check_ok(cross,cross_index))
		{
			move(cross,cross_index+1);
		}
	}

}
int main(void)
{
	int cross[8] = {0};
	move(cross,0);
	return 0;

}//main
