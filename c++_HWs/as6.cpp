///*
// * as6.cpp
// *
// *  Created on: 2014/9/24
// *      Author: Ella Xue
// */
//
//#include <iostream>
//#include <cstdlib>
//#include <cmath>
//using namespace std;
//
//bool testNoConflict(int q[], int col)
//{
//	for (int i = 0; i < col; i ++)
//	{
//		if (q[col] == q[i] || abs(q[i]-q[col])== (col-i))
//			return false;
//	}
//	return true;
//}
//
//void backTrack (int &col)
//{
//	col--;
//	if (col == -1)
//	{
//		exit(1);
//	}
//}
//
//void print(int q[])
//{
//	static int count = 0;
//	cout <<"solution: " << ++count << endl << endl;
//	for ( int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			if (i == q[j])
//			{
//				cout<<"Q ";
//			}
//			else
//			{
//				cout<<"- ";
//			}
//		}
//		cout << endl;
//	}
//	cout<<"---------------------cutting-line-----------------"<<endl;
//}
//
//int main(void)
//{
//	int q[8]; q[0] = 0;
//	int c = 1;
//	bool from_backTrack = false;
//
//	while (true)
//	{
//		//if not from the backTrack function, start from the very top
//		if (!from_backTrack)
//		{
//			q[c] = 0;
//		}
//
//		//if back from backTrack, move to next row to see if applicable to place a new queen
//		else
//		{
//			q[c]++;
//		}
//
//		//once leave the while (q[c] < 8) loop,
//		//will trigger the backTrack function, set it back to true
//		from_backTrack = true;
//
//		while (q[c] < 8)
//		{
//			if (testNoConflict(q, c))
//			{
//				//true = no conflict, move to next column
//				c++;
//				//when column = 8, all queens have been placed in the right block
//				if (c == 8)
//				{
//					//print the solution
//					print(q);
//					//exit while loop, execute backTrack
//					break;
//				}
//				else
//				{
//					//moved to the next column, start testing conflicts from the first row
//					q[c] = 0;
//				}
//			}
//			else
//			{
//				//false = conflict exists, try next row
//				q[c]++;
//			}
//		}
//
//		//row = 8 means out of board,then go back in columns and find other possibilities
//		backTrack(c);
//	}
//}
//
//
