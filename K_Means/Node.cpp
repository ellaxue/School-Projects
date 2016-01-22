/*
 * node.cpp
 *
 *  Created on: 2015?11?19?
 *      Author: Ella
 */


#include "Kmeans.h"

Node::Node(int x_coord, int y_coord, int clusterLabel)
{
	this->ClusterLabel = clusterLabel;
	this->X_coordinate = x_coord;
	this->Y_coordinate = y_coord;
	this->Distance = 999999;
	this->next = NULL;
}

Node::~Node()
{
	this-> next = NULL;
}

void Node::printNode(ofstream &output_f)
{
	output_f<<this->X_coordinate<<" "<<this->Y_coordinate<<" "<<this->ClusterLabel<<" \r\n";
	//	cout<<" ClusterLabel "<<this->ClusterLabel<<" X_coordinate "<<this->X_coordinate<<
	//	" Y_coordinate "<<this->Y_coordinate<<" Distance " <<this->Distance<<"\r\n";
}
