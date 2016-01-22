/*
 * short_path_xueba.cpp
 *
 *  Created on: 2014Äê11ÔÂ22ÈÕ
 *      Author: Ella
 */
//CHANGLIN LI
#include<iostream>
using namespace std;
const int rows = 5;
const int cols = 6;
int minvalue(int a,int b,int c,int d, int e){
	int min=a;
	if(b<min&&b>=0)min=b;
	if(c<min&&c>=0)min=c;
	if(d<min&&d>=0)min=d;
	if(e<min&&e>=0)min=e;
	return min;
}
int cost(int i, int j,int memo_cost[rows][cols]){ // i is the row, j is the column
int weight[rows][cols]={
							{3,4,1,2,8,6},
							{6,1,8,2,7,4},
							{5,9,3,9,9,5},
							{8,4,1,3,2,6},
							{3,7,2,8,6,4}
						};
//base case
if(j==0){
	memo_cost[i][0]=weight[i][0];
	return weight[i][0];
}
// recursive call
int left,up,down;
if		(memo_cost[i][j-1]!=0)			left=memo_cost[i][j-1];
else 	{
			left =cost(i,j-1,memo_cost);
			memo_cost[i][j-1]=left;
		}
if		(memo_cost[(i+4)%5][j-1]!=0)	up =memo_cost[(i+4)%5][j-1];
else 	{
			up =cost((i+4)%5,j-1,memo_cost);
			memo_cost[(i+4)%5][j-1]=up;
		}
if		(memo_cost[(i+1)%5][j-1]!=0)	down =memo_cost[(i+1)%5][j-1];
else 	{
			down =cost((i+1)%5,j-1,memo_cost);
			memo_cost[(i+1)%5][j-1]=down;
		}
// find the value of the shortest path through cell (i,j)
int min =minvalue(left,up,down,-1,-1);
	min=weight[i][j]+min;
	return min;
}
int main(){
	int ex[rows];
	int row_out;
	int memo_cost[rows][cols]={0};
	// get the shortest path out of each cell on the right
	for( int i=0; i<rows; i++){
		ex[i]=cost(i,cols-1,memo_cost);
	}
	// now find the smallest of them
	int min=minvalue(ex[0],ex[1],ex[2],ex[3],ex[4]);
	for (int i=0;i<rows;i++){
		if(ex[i]==min){
			row_out=i;
			break;
		}
	}
	//print memo_cost
	/*for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++)
		cout<<memo_cost[i][j]<<" ";
	cout<<endl;
	}*/
	int route[cols]={-1};
	route[cols-1]=row_out;
	int r=row_out;
	for(int c=cols-2;c>=0;c--){
		int min=minvalue(memo_cost[(r+4)%5][c],memo_cost[r][c],memo_cost[(r+1)%5][c],-1,-1);
		if(memo_cost[(r+4)%5][c]==min){
			route[c]=(r+4)%5;
			r=route[c];
		}
		else{
			if(memo_cost[r][c]==min){
				route[c]=r;
				r=route[c];
			}
			else {
				route[c]=(r+1)%5;
				r=route[c];
			}
		}
	}
	for(int i=0;i<cols;i++)
		cout<<"route "<<i<<" is: "<<route[i]<<" row."<<endl;
	cout<<"the shortest path is of length "<<min<<endl;
	return 0;
}



