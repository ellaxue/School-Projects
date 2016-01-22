/*
 * edgeNode.cpp
 *
 *  Created on: Nov 29, 2015
 *      Author: Ella
 */

#include "../Prim_MST/PrimMST.h"

edgeNode::edgeNode(int nodeI, int nodeJ, int cost)
{
	this->Ni = nodeI;
	this->Nj = nodeJ;
	this->edgeCost = cost;
	this->next = NULL;
}

edgeNode::~edgeNode()
{
	cout<<"deleting edge"<<endl;
    this->next = NULL;
}
void edgeNode::Insert(int nodeI, int nodeJ, int cost, edgeNode **listHead)
{
	edgeNode *newNode = new edgeNode(nodeI,nodeJ,cost);
	edgeNode *head = *listHead;

	//find a right position for the new input data (in ascending order based on edge cost)
	while(head->next != NULL && newNode->edgeCost > head-> next->edgeCost)
	{
		head = head->next;
	}

	//insert the new data
	newNode->next = head->next;
	head->next = newNode;

}

void edgeNode::Delete (edgeNode **listHead, edgeNode *del_node)
{
    edgeNode *current = *listHead;
    
    if (!*listHead || !del_node)
    {
        return;
    }
    
    // deleting the head
    if (current == del_node)
    {
        *listHead = del_node->next;
    }
    
    while(current)
    {
        // find the node after which is the del_node
        if (current->next == del_node)
        {
            // remove the del_node by short-cut it
            current->next = del_node->next; 
        }
        current = current->next;
    }
}

void edgeNode::printEdgeNode(ofstream &output_f, edgeNode *listHead, int max_row)
{
	int count = max_row;

    // now print max_row nodes, not including the dummy node
	while(listHead->next != NULL)
	{
		listHead = listHead->next;
	    output_f << listHead->Ni << " " << listHead->Nj << " " << listHead->edgeCost << "\r\n";;
		count--;
		if ((max_row > 0) && (count <= 0))
		{
		    output_f<<"Only printing " << max_row << " entries, others are skipped\r\n";
		    break;
		}
	}

}

