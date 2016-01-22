///*
// * as7.cpp
// *
// *  Created on: Oct 2, 2018
// *      Author: Ella Xue
// */
//
//#include <iostream>
//using namespace std;
//
//void print(int board[][8], int count)
//{
//
//	cout <<"solution: " << count << endl << endl;
//	for ( int i = 0; i < 8; i++)
//	{
//		for( int j = 0; j < 8; j++)
//		{
//			cout<<board[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout<<"------------------cutting-line-----------------"<<endl;
//}
//
//bool testNoConflict(int board[][8])
//{
//	int Q_index[8];
//	//to record Q is placed in which row in each column
//	for(int i = 0; i < 8; i++)
//	{
//		for(int j = 0; j < 8; j++)
//		{
//			if(board[j][i] == 1)
//			{
//				Q_index[i] = j;
//				//found the Q in the current column, move to next column
//				j = 8;
//			}
//		}
//	}
//
//	//test conflicts for columns, up-right diagonal and down-right diagonal
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 1; i + j  < 8; j++)
//		{
//			if ((Q_index[i]==Q_index[i+j]) || (Q_index[i]==Q_index[i+j]+j) || (Q_index[i]==Q_index[i+j]-j))
//			{
//				return false;
//			}
//		}
//	}
//
//	//passed test, return true
//	return true;
//}
//
//int main(void)
//{
//	int board[8][8]={0};
//	int count = 0;
//
//	for(int i0 =0; i0 <8; i0 ++)
//		for(int i1 =0; i1 <8; i1 ++)
//			for(int i2 =0; i2 <8; i2 ++)
//				for(int i3 =0; i3 <8; i3 ++)
//					for(int i4 =0; i4 <8; i4 ++)
//						for(int i5 =0; i5 <8; i5 ++)
//							for(int i6 =0; i6 <8; i6 ++)
//								for(int i7 =0; i7 <8; i7 ++)
//								{
//									// use the indices of the loops to set a configuration in array board
//									board[i0][0] = 1;
//									board[i1][1] = 1;
//									board[i2][2] = 1;
//									board[i3][3] = 1;
//									board[i4][4] = 1;
//									board[i5][5] = 1;
//									board[i6][6] = 1;
//									board[i7][7] = 1;
//
//									// if this configuration is conflict-free, print the count and the board
//									if(testNoConflict(board))
//									{
//										print(board, ++count);
//									}
//
//									// reset the board for the next configuration
//									board[i0][0] = 0;
//									board[i1][1] = 0;
//									board[i2][2] = 0;
//									board[i3][3] = 0;
//									board[i4][4] = 0;
//									board[i5][5] = 0;
//									board[i6][6] = 0;
//									board[i7][7] = 0;
//								}
//	return 0;
//}
