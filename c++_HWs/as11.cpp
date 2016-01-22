/*
 * as11.cpp
 *
 *  Created on: Oct 16, 2014
 *      Author: Ella
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

bool test_no_conflict(int board[],int board_index);
int findSolutions(int size);
void print(int board[], int size);

int main(void)
{
	int size;
	printf("Please input the number of queens.\n");
	scanf("%d",&size);
	int count = 0;

	for (int i = 1; i <= size; i++)
	{
		count = findSolutions(i);
		printf("There are %d %s %d %s\n",count,"solutions to the", i,"queens problems");
	}
	return 0;

}
int findSolutions(int size)
{
	if (size == 1)
		{
			//no need to check
			return 1;
		}

	int *board = new int[size];
	int board_index = 1;
	int count = 0;
	board[0] = 0; //first queen is assigned to the first row of the chess board
	board[board_index] = 0; //assign another queen in the second block

	while(1)
	{
		while(board[board_index] < size)
		{
			if (test_no_conflict(board,board_index))
			{
				board_index++;
				if(board_index == size)
				{
					count++;
				//	print(board,size);
				}
				else
				{
					board[board_index] = 0;
				}
			}//if (test_no_conflict(board,board_index))
			else
			{
				board[board_index]++;
			}//else false
		}//while(board[board_index] < size)

		board_index--;
		if(board_index == -1)
		{
			break;
		}
		board[board_index]++;
	}//while(1)

	delete []board;
	return count;
}

bool test_no_conflict(int board[],int board_index)
{
	for (int i = 0; i < board_index; i ++)
		{
			if (board[board_index] == board[i] || abs(board[i]-board[board_index])== (board_index-i))
				return false;
		}
		return true;
}

//for self checking
void print(int board[], int size)
{
	for (int i = 0; i < size +1; i++)
	{
		for (int j = 0; j < size+1; j++)
		{
			if (board[j] == i)
			{
				printf("Q ");
			}
			else
				printf("- ");
		}
		printf("\n");
	}
	printf("\n");
}
