/*
 * 	as19_kBishops.cpp
 *
 *	The problem:
 *	Write a program that inputs two integers n and k, where n>=k. Your program should calculate
 *	the number of different ways that k bishops could be placed on an nXn chess-board.
 *
 *  Created on: 2014/11/28
 *      Author: Ella
 */


#include <iostream>
#include <stdio.h>
int solution(int size, int num_bishop);
bool check_ok(int bishops[], int current_index, int n);

int main(void)
{
	int n = 0; // n X n chess-board
	int k = 0; // number of bishops

	while (1)
	{
		printf("Please input the size of the chess-board: ");
		scanf("%d",&n);
		if(n == -1)
			return 0;
		printf("number of bishops? ");
		scanf("%d",&k);
		for (int i = 1; i < k+1; i++)
		{
			std::cout<<n<<" "<<i<<" "<<solution(n,i)<<std::endl;
		}
	}
}

int solution(int n, int num_bis)// n*n = board_size, num_bis = number of bishops
{
	int index = 0;
	int *bishops = new int[num_bis+1];
	int num_solution = 0;
	bishops[index] = 0; //place first bishop at position 0 on the board

	while(1)
	{
		while(index<num_bis)
		{
			while(bishops[index] < n*n)
			{
				if (check_ok(bishops, index, n))
					break;
				else
					bishops[index]++;
			}
			if (bishops[index] == n*n)
			{
				index --;
				if (index == -1)
				{
					delete[] bishops;
					return num_solution;
				}
				bishops[index]++;
			}
			else
			{
				int temp = bishops[index];
				index++;
				bishops[index] = temp;
			}
		}
		num_solution++;
		index--;
		if (index == -1)
		{
			delete[] bishops;
			return num_solution;
		}
		bishops[index]++;

	}
}

bool check_ok(int bishops[], int current_index, int n)
{
	for (int i = 0; i < current_index; i++)
	{
		int row1 = bishops[i] / n;
		int col1 = bishops[i] % n;
		int row2 = bishops[current_index] / n;
		int col2 = bishops[current_index] % n;
		if (row1 + col1 == row2+col2)
			return false;
		if (row1 - col1 == row2 - col2)
			return false;
	}

	return true;
}


