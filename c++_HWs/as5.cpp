///*
// * as5.cpp
// *
// *  Created on: 2014Äê9ÔÂ20ÈÕ
// *      Author: Ella
// */
//
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>//absolute function
//using namespace std;
//void print(int arr[], int size);
//
//int main(void)
//{
//	int b[8];
//	int c = 0, count = 0;
//
//	//place a queen in the first block (column 0, row 0)
//	b[c] = 0;
//	//go to next column
//	NC: c++;
//
//	//once c hits 8, means all 8 queens have been placed in the right block,
//	//print out the solution
//	if (c == 8)
//	{
//		count++;
//		cout<<"Solution "<< count <<": "<<endl;
//		goto Print;
//
//	}
//	b[c] = -1;
//	NR: b[c]++;
//
//	//no more row to place a queen for the current column, go back one column.
//	if (b[c] == 8)
//	{
//		goto backTrack;
//	}
//
//	//test for all possible conflicts
//	for (int i =0; i < c; i++)
//	{
//		if( b[c] == b[i] || abs(b[i]-b[c])== (c-i))
//		{
//			goto NR;
//		}
//	}
//
//	//done with current column, go to next one
//	goto NC;
//
//	//can't find a solution for current column, go back one column to check other possibility for previous column.
//	backTrack: c--;
//
//	//if column c == -1, means all possibilities have been checked, exit program.
//	if (c == -1) return 0;
//
//	goto NR;
//	Print: print(b, 8);
//
//	//once printed out the solution, go back in columns to find other solutions.
//	goto backTrack;
//}
//
//
//void print(int arr[], int size)
//{
//	//print out values saved in the array
//	for (int i = 0; i < size; i++)
//	{
//		cout<<arr[i]<<" ";
//	}
//	cout<<endl;
//
//	//print out solutions
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size ; j++)
//		{
//			if ( i == arr[j])
//			{
//				cout<< "Q" <<" ";
//			}
//			else
//			cout<< "-" <<" ";
//		}
//
//		cout<<endl;
//	}
//	cout<<"-------------------------cutting-line-------------"<<endl;
//}
//
//
//
