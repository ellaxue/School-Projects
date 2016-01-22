/*
 * Kmean.cpp
 *
 *  Created on: 2015?11?19?
 *      Author: Ella
 */

#include "Kmeans.h"
void KMean::KMeanCluster()
{
	labelChange = false;
	int min_id;
	double min_dis, newDist = 0.0;
	Node *curPoint = list->listHead;

	while(curPoint->next != NULL)
	{
		curPoint = curPoint->next;
		min_dis = 999999;
		for(int ClusterID = 1; ClusterID < K+1; ClusterID++)
		{
			//step 4: 4.1: for each point, p, in the linked list, compute the distance, di(p,ci),
			//from p to the centroids of each Kcentroids[i], i = 1 to K
			newDist =  distance(curPoint,ClusterID);
			if( newDist < min_dis)
			{
				min_id = ClusterID;
				min_dis = newDist;
			}
		}
		if(min_id != curPoint->ClusterLabel)
		{
			labelChange = true;
			cout<<"old label = " <<curPoint->ClusterLabel << " old distance = " <<curPoint->Distance<<endl;
			curPoint->ClusterLabel = min_id;
			cout<<" change current distance "<<curPoint->Distance <<" to "<<min_dis <<"  ";
			cout<<"new label = " << curPoint->ClusterLabel<<" ";
			curPoint->Distance = min_dis;
			cout<<"new distance = " << curPoint->Distance <<endl;
		}
	}
}

void KMean::displayImage(ofstream &output_f)
{
	storeImage();
	cout<<"-------------------------------<<Display Image>> ---------------------------------\r\n";
	output_f<<"-------------------------------<<Display Image>> ---------------------------------\r\n";
	for(int i = 0; i < numRow; i++)
	{
		for(int j = 0; j < numCol; j++)
		{
			if(imageArray[i][j] ==0)
			{
				cout<<" ";
				output_f<<" ";
			}
			else
			{
				cout<<imageArray[i][j];
				output_f<<imageArray[i][j];
			}
		}
		cout<<endl;
		output_f<<"\r\n ";
	}
}

void KMean::storeImage()
{
	cout<<"store image"<<endl;
		Node *head = list->listHead;
		while(head->next != NULL)
		{
			head = head->next;
			imageArray[head->X_coordinate][head->Y_coordinate] = head->ClusterLabel;
		}
}
bool KMean::checkPartition()
{
	int dist = 0;
	int min_dis_required = (numRow + numCol) / (2*K);
	for(int i = 0; i < K; i++)
		for(int j = i+1; j < K; j++)
		{
			dist = distance(i,j);
			if(dist < min_dis_required)
			{
				cout<<dist<<" less than min_dis required "<<min_dis_required << " repartition..."<<endl;
				return true;
			}
		}

	return false;
}
int KMean::distance(int ID1, int ID2)
{
	return sqrt(pow((Kcentroids[ID1].X_coordinate)-(Kcentroids[ID2].X_coordinate),2)+pow((Kcentroids[ID1].Y_coordinate-Kcentroids[ID2].Y_coordinate),2));
}
KMean::KMean(int k, int numRow, int numCol)
{
	this->K = k;
	this->numCol = numCol;
	this->numRow = numRow;
	this->Kcentroids = new xycoord[K];
	this->labelChange = true;
	srand((unsigned)time(0));
	bool check = true;
	while(check)
	{
		for(int i = 0; i < K; i++)
		{
			Kcentroids[i].X_coordinate = (rand()%numRow) + 1;
			Kcentroids[i].Y_coordinate = (rand()%numCol) + 1;
		}
		check = checkPartition();
	}
	//declare a 2d dynamically allocated array and initialize to "0"
	imageArray = new int*[numRow]();
	for(int i = 0; i < numRow; ++i)
	{
		imageArray[i] = new int[numCol]();
	}
}
void KMean::centroid()
{
    int *X_total[2];
    int *Y_total[2];
    
    // dynamically create array
    for(int i = 0; i < 2; ++i)
    {
      X_total[i] = new int[K+1]();
    }
    
    for(int i = 0; i < 2; ++i)
    {
      Y_total[i] = new int[K+1]();
    }
    
	Node *head = list->listHead;
	while(head->next!=NULL)
	{
		head = head->next;
		//row[0]col[k] to store sum of all x/y points in current k group
		//row[1]col[k] to store num of points
		X_total[0][head->ClusterLabel]+= head->X_coordinate;
		X_total[1][head->ClusterLabel]++;
		Y_total[0][head->ClusterLabel]+= head->Y_coordinate;
		Y_total[1][head->ClusterLabel]++;
	}
	for(int i = 1; i < K + 1; i++)
	{
		// sum of x points / num of points = mean
		if(X_total[1][i] > 0)
		{
			Kcentroids[i-1].X_coordinate = X_total[0][i] / X_total[1][i];
			Kcentroids[i-1].Y_coordinate = Y_total[0][i] / Y_total[1][i];
		}
	}
	
	// recycle spaces
    for(int i = 0; i < 2; ++i) 
    {
      delete X_total[i];
    }
    
    for(int i = 0; i < 2; ++i) 
    {
        delete Y_total[i];
    }
}

double KMean::distance(Node *point, int clusterID)
{
	return sqrt(pow(((Kcentroids[clusterID-1].X_coordinate) - point->X_coordinate), 2) + pow((Kcentroids[clusterID-1].Y_coordinate - point->Y_coordinate), 2));
}

bool KMean::isLabelChanged()
{
	return labelChange;
}

void KMean::printXYcoord()
{
	for(int i = 0; i < K; i++)
	{
		cout<<" Kcentroids["<<i+1<<"].X_coordinate "<<Kcentroids[i].X_coordinate<<" Kcentroids["<<i+1<<"].Y_coordinate "<<Kcentroids[i].Y_coordinate<<endl;;
	}
	cout<<"-----------------------------------------------------------------------------------------\r\n";

}
int KMean::getK(){return this->K;}
int KMean::getNumCol(){return this->numCol;}
int KMean::getNumRow(){return this->numRow;}
