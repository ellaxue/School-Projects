/*
 * PrimMST.h
 *
 *  Created on: Nov 29, 2015
 *      Author: Ella
 */

//#ifndef PRIMMST_H_
#define PRIMMST_H_
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <math.h>
using namespace std;

#define MAX_PRINT   10

class graphNode{
    friend class PrimMST;
public:
	graphNode(int nodeID);
	~graphNode();
#ifndef SORT_GRAPH
	void Insert(graphNode *new_node,graphNode *listHead);
	void Delete (graphNode **listHead, graphNode *del_node);
	void printSetNodes(ofstream &output_f2,graphNode *setB_head,graphNode *setA_head,bool A_or_B);
	int getNodeID (void) {return this->nodeID;}
	graphNode* FindAndDelete (graphNode **listHead, int node_id);

private:
	int nodeID;
	graphNode *next;
	graphNode *isEmpty;

};

class edgeNode{
    friend class PrimMST;
public:
	void printEdgeNode(ofstream &output_f,edgeNode *listHead, int max_row);
	void Insert (int nodeI, int nodeJ, int cost, edgeNode **listHead);
	void Delete (edgeNode **listHead, edgeNode *del_node);
	int getCost (void) {return this->edgeCost;}
	int getNi (void) {return this->Ni;}
	int getNj (void) {return this->Nj;}
		edgeNode(int nodeI, int nodeJ, int cost);
		~edgeNode();

private:
    int Ni;//an integer 1 to N
    int Nj;//an integer 1 to N
	int edgeCost;//a positive intEEeger > 0
	edgeNode *next;
};


typedef enum
{
    UNKONWN = 0,
    FROMA = 1,
    FROMB = 2
} NODE_FROM_SET;

class PrimMST{

public:
		PrimMST(int n);
		~PrimMST();
	int PrimsMST(ofstream &output_f1,ofstream &output_f2);//primsMST method
    void stepNodeIDArray(int index) {this->graphNodeIDarray[index]++;}
    void printGraphNodeIDarray (ofstream &output_f1,ofstream &output_f2);
    void printEdgeNode (ofstream &outfile);
    void printMSTofG (ofstream &outfile);
    // set A to true to insert into setA, or false to insert into setB
    void insertNodeToSet (graphNode *new_node, bool A);
    // check if Ni and Nj are from same node, return true if they are from the same (and hence discard)
    void checkNodeIDSets (edgeNode *edge, int *nodeid_fromB, NODE_FROM_SET *NiSet, NODE_FROM_SET *NjSet);
    void insertMSTofG (edgeNode *edge);
    void moveNodeA2B (int node_id);
    void insertEdge (int Ni, int Nj, int edge_cost);
    edgeNode* getNextEdge(int *node_id_fromB, ofstream &output_f2);

private:
	int N;//number of nodes in G
	int totalCost;// Initialized to 0
	int *graphNodeIDarray;//a 1-D array of integer, size N, dynamically allocated
    graphNode *setA, *setB; //the head of a linked list of graphNode
    edgeNode *MSTofG,*edgeList;//the head of a linked list of edgeNode
};

#endif /* PRIMMST_H_ */
