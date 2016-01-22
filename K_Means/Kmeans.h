/*
 * Kmeans.h
 *
 *  Created on: 2015?11?19?
 *      Author: Ella
 */

#ifndef KMEANS_H_
#define KMEANS_H_
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <math.h>
//#include <random>
using namespace std;

class Node
{
public:
	Node(int x_coord, int y_coord, int clusterLabel);
	~Node();
	void printNode(ofstream &output_f);
private:
	int X_coordinate;
	int Y_coordinate;
	int	ClusterLabel;
	double Distance;
	Node* next;
	friend class LinkedList;
	friend class KMean;
};

class LinkedList
{
public:
	void insert(int x,int y,int label);
	void deletion(int x, int y);
	void printList(ofstream &output_f);
	LinkedList();
	~LinkedList();

private:
	Node* listHead;
	friend class KMean;
};

class KMean
{
public:
	struct xycoord
	{
		int X_coordinate;
		int Y_coordinate;
	};
	void KMeanCluster();
	void centroid();
	void displayImage(ofstream &output_f);
	void storeImage();
	void printXYcoord();
	int getK();
	int getNumRow();
	int getNumCol();
	int distance(int ID1, int ID2);
	double distance(Node *point, int clusterID);
	bool isLabelChanged();
	bool checkPartition();
	KMean(int k, int numRow, int numCol);
	LinkedList *list;

private:
	int K, numRow, numCol;
	int **imageArray;
	bool labelChange;
	xycoord *Kcentroids;
	friend class LinkedList;
};

#endif /* KMEANS_H_ */

