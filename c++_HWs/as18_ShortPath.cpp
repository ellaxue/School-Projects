/*
 * as18_ShortPath.cpp
 *
 *  Created on: 2014/11/20
 *      Author: Ella
 *
 *  Problem: FIND THE SHORTEST PATH
 *  Input:
 *  {3,4,1,2,8,6}
 *  {6,1,8,2,7,4}
 *  {5,9,3,9,9,5}
 *  {8,4,1,3,2,6}
 *  {3,7,2,1,2,3}
 *
 *  Output: Shortest Path has length 11.
 *  Path in rows:         0 1 0 4 3 4
 *  costs for each block: 3 1 1 1 2 3 = 11
 */

#include <iostream>
#include <stdio.h>
const int row = 5;
const int col = 6;
int Path[row][col];

int cost(int r, int c) //r is the row , c is the column
{
    int left, up, down;
	int weight[row][col] = {{3,4,1,2,8,6},
						    {6,1,8,2,7,4},
						    {5,9,3,9,9,5},
						    {8,4,1,3,2,6},
						    {3,7,2,8,6,3}};

	static int PathMemo[row][col]= {{3},{6},{5},{8},{3}};

//	    //test data
//	    int weight[row][col] = {{501,2,1003,4},
//	                            {105,106,507,108},
//	                            {209,610,211,212},
//	                            {313,314,915,316}};
//
//	    static int PathMemo[row][col]= {};

    //base case
    if (c == 0)
    {
        return weight[r][0];
    }
    else if (PathMemo[r][c] != 0)
    {
        return PathMemo[r][c];
    }

    //recursive call
    left = cost(r,c-1) + weight[r][c]; //  same row. 1 column to the left
    up   = cost((r+(row-1))%row,c-1) + weight[r][c]; // 1 row up, 1 column to the left
    down = cost((r+1)%row,c-1) + weight[r][c]; // 1 row down, 1 column to the left

    int min = left;
    Path[r][c] = r;
    if (min > up)
    {
        Path[r][c]  = (r+(row-1))%row;
        min = up;
    }
    if (min > down)
    {
        Path[r][c] = (r+1)%row;
        min = down;
    }
    return PathMemo[r][c] = min;
}

int main(void)
{
    int ex[row];
    int min;
    int exit = 0; //shortest path's exit (row number)

    //to record the costs for each path
    //how much it costs to travel from the first column to the last column.
    for(int i = 0; i < row; i++)
    {
        ex[i] = cost(i, col-1);
    }

    min = ex[0];
    //choose the smallest value as the shortest path
    for(int i = 0; i < row; i++)
    {
        if (min > ex[i])
        {
            min = ex[i];
            exit = i;
        }
    }

    //print out the costs for each path
    for(int i = 0; i < row; i++)
    {
        printf("cost from exit #%d= %d \n", i, ex[i]);
    }


    //print out the length of the path
    printf("%s %d\n", "the shortest path is of length", min);



    int min_row = exit;
    int min_path[col];
    min_path[col-1] = min_row;

    //save the path to a 1D array
    for (int i = col-1; i>0; i--)
    {
        min_row = Path[min_row][i];
        min_path[i-1] = min_row;
    }
    printf("the path is: ");

    for (int i = 0; i < col; i++)
    {
    	printf("%d ", min_path[i]);
    }
    printf("\n");

    return 0;
}



