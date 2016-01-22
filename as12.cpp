/*
 * as12.cpp
 *
 *  Created on: 2014Äê10ÔÂ30ÈÕ
 *      Author: Ella
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;



bool testNoConflict(int q[], int col)
{
	for (int i = 0; i < col; i ++)
	{
		if (q[col] == q[i] || abs(q[i]-q[col])== (col-i))
			return false;
	}
	return true;
}

void backTrack (int &col)
{
	col--;
	if (col == -1)
	{
		exit(1);
	}
}
void print(int q[])
{
	static int count = 0;
	cout <<"solution: " << ++count << endl << endl;
	for ( int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i == q[j])
			{
				cout<<"Q ";
			}
			else
			{
				cout<<"- ";
			}
		}
		cout << endl;
	}
	cout<<"---------------------cutting-line-----------------"<<endl;
}

int main(void)
{

	int i,j,k,l;
	 typedef char box[5][7];
	 box bb,wb,wq, bq,*board[8][8];
	 int q[8]; q[0] = 0;
	 int c = 1;
	 int count = 0;
	 q[c] = 0;


	 //fill in black box and white box
	 for (i = 0; i < 5; i++ )
	 {
		 for (j = 0; j < 7; j++)
		 {
			 bb[i][j] = char(219);
			 wb[i][j] = ' ';
		 }
	 }

	 //fill in white queen and black queen
	 for (i = 0; i < 5; i++)
	 {
		 for (j = 0; j < 7; j++)
		 {
			 if ((i!=0 && i!=4 && j%2==1) || ((j==2 || j == 4) && (i==2 || i==3)))
			 {
				 bq[i][j] = ' ';
				 wq[i][j] = char(219);
			 }
			 else
			 {
				 bq[i][j] = char(219);
				 wq[i][j] = ' ';
			 }
		 }
	 }

	 //fill the board with black box and white box
	 for (i = 0; i < 8; i++)
	 {
		 for (j = 0; j < 8; j++)
		 {
			 if ((i + j) % 2 ==0)
				 board[i][j] = &wb;
			 else
				 board[i][j] = &bb;
		 }
	}


	 while (true)
	{

		while (q[c] < 8)
		{
			if (testNoConflict(q, c))
			{
				//true = no conflict, move to next column
				c++;

				//when column = 8, all queens have been placed in the right block, ready to print
				if (c == 8)
				{
					 count++;
					 // print the board via the pointers in array board
					 // first print upper border
					 cout<<"solution" <<count<<endl;
					 cout<<" ";
					 for(i=0;i<7*8;i++)
					 {
						 cout<<'_';
					 }
					 cout<<endl;

					 //place queens in the chess board with corresponding color
					 for (k = 0; k < 8; k++)
					 {
						 if ((q[k]+k) % 2 ==0)
						 {
							 board[q[k]][k] = &wq;
						 }
						 else
						 {
							 board[q[k]][k] = &bq;
						 }
					 }

					 // now print the board
					 for(i=0;i<8;i++)
					 {
						 for(k=0;k<5;k++)
						 {
							 cout<<" "<<char(179); //print left border
							 for(j=0;j<8;j++)
							 {
								 for(l=0;l<7;l++)
								 {
									 cout<<(*board[i][j])[k][l];
								 }
							 }
								 cout<<char(179)<<endl; // at end of line print bar and then newline
						 }
					}

					 //before exiting print lower border
					 cout<<" ";
					 for(i=0;i<58;i++)
					 cout<<char(196);
					 cout<<endl;


					// reset the chess board for next print
					 for (k = 0; k < 8; k++)
					 {
						 if ((q[k]+k) % 2 ==0)
						 {
							 board[q[k]][k] = &wb;
						 }
						 else
						 {
							 board[q[k]][k]  = &bb;
						 }
					 }
					//exit while loop, execute backTrack
					break;
				}
				else
				{
					//moved to the next column, start testing conflicts from the first row
					q[c] = 0;
				}
			}
			else
			{
				//false = conflict exists, try next row
				q[c]++;
			}
		}//while (q[c] < 8)

		backTrack(c);
		q[c]++;
	}//while(true)

}





