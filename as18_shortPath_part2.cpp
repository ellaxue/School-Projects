/*
 * as18_shortPath_part2.cpp
 *
 *  Created on: 2014/11/22
 *      Author: Ella
 */

#include <iostream>
#include <stdio.h>

const int row = 5;
const int col = 6;
int Path[row][col-1];
int min(int left, int up, int down, int c, int r);
int cost(int exit_costs[], int &exit);

int main(void)
{
    int ex[row];
    int exit = 0; //shortest path's exit (row number)
    int min_cost = cost(ex,exit);

    //print out the costs for each exit
    printf("\n");
    for ( int i = 0; i< row; i++)
    {
    	printf("path exit #%d has cost of %d\n",i,ex[i]);
    }
    printf("\nThe shortest path is of cost %d \n\n", min_cost);

    //save the path to a 1D array
    int min_row = exit;
	int min_path[col];
	min_path[col-1] = min_row;
	for (int i = col-1; i>0; i--)
	{
		min_row = Path[min_row][i-1];
		min_path[i-1] = min_row;
	}

	//print out the path the robot traveled through
	printf("the path is: ");
	for (int i = 0; i < col; i++)
	{
		printf("%d ", min_path[i]);
	}
	printf("\n");

    return 0;
}

//return the minimum cost from three directions
int min(int left, int up, int down, int c, int r)
{
	int min = left; //set left to be temp min cost
	Path[r][c-1]  = r;
	if (min > up)
	{
		Path[r][c-1]  = (r+(row-1))%row; //record the path coming from to current block
		min = up; //change min if up direction cost less
	}
	if (min > down)
	{
		Path[r][c-1] = (r+1)%row;
		min = down; //change min if down direction cost less
	}
	return min;
}

//calculate the minimum cost for each exit
int cost(int exit_costs[], int &exit)
{
    int left, up, down;
    static int PathMemo[row][col]= {{3},{6},{5},{8},{3}};
	int weight[row][col] = {{3,4,1,2,8,6},
						    {6,1,8,2,7,4},
						    {5,9,3,9,9,5},
						    {8,4,1,3,2,6},
						    {3,7,2,8,6,4}};

	for(int c = 1; c < col; c++)
	{
		for(int r = 0; r < row; r++ )
		{
			left = weight[r][c] + PathMemo[r][c-1];
			up   = weight[r][c] + PathMemo[(r+(row-1))%row][c-1];
			down = weight[r][c] + PathMemo[(r+1)%row][c-1];

			//record the mim cost among all the costs coming from each direction to this block
			PathMemo[r][c] = min(left, up, down, c, r);
		}
	}

	exit_costs[0] = PathMemo[0][col-1]; //record the first row exit cost
	int min_cost  = exit_costs[0]; //set it to be the temp minimum cost
	for(int i = 1; i < row; i++)
	{
		exit_costs[i] = PathMemo[i][col-1]; //record the cost for other exits
		if(min_cost > exit_costs[i])
		{
			min_cost = exit_costs[i]; //choose the minimum as the shortest path
			exit = i; //record the exit row
		}
	}

	return min_cost;
}
