/*
 * as4.cpp
 *
 *  Created on: 2014/9/16
 *      Author: Ella Xue
 */


#include <iostream>
using namespace std;
void print(int a[][8], int size);

int main(void){

	int b[8][8] = {0}, r, c = 0; //zero out the entire 2D array
	int count = 0;
	b[0][0] = 1; //start with row 1 column 1
	NC: c++; //Labeled to next column

	//when c reach 8 means all Queens have been placed in the array without conflict,
	//then print the array

	if (c == 8)
	{
		count++;
		cout<<"Solution " << count << ":" <<endl;
		goto Print;
	}


	r = -1;
	NR: r++; //Labeled to next row
	if ( r == 8) goto backTrack;

	//Row check: only check left side of the current row since no value on the right side
	for (int i = 0; i < c; i++)
	{
		if (b[r][i] == 1)
		{
			goto NR;
		}
	}

	// up-left check
	for (int i = 1; (r - i) >= 0 && (c - i) >= 0; i++)
	{
		if (b[r - i][c - i] == 1)
		{
			goto NR;
		}
	}

	// down-left diagram test
	for (int i = 0; (r + i) <= 7 && (c - i) >= 0; i++)
	{
		if (b[r + i][c - i] == 1)
		{
			goto NR;
		}
	}

	b[r][c] = 1; //after eliminating every possible conflict, place a Queen in the current block
	goto NC; //done with the current column, go to next one

	backTrack: c--;
	//when c reaches -1 means all possible solutions have been found, exit the program
	if (c == -1) return 0;


	r = 0;
// to find the "1" in the current column
	while (b[r][c] != 1)
	{
		r++;
	}
	b[r][c] = 0;//erase '1' in the current block,
	goto NR;//to find another possibility, move to next row

	Print: print(b,8);
	goto backTrack; //go back in columns to find other possible solutions
}

void print(int a[][8], int size)
{
	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			cout<<a[r][c]<<"  ";
		}
		cout<<endl;
	}
	cout<<"-----------------------cutting-line-------------------" <<endl;
}

