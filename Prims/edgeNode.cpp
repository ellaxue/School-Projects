/*
 * edgeNode.cpp
 *
 *  Created on: Nov 29, 2015
 *      Author: Ella
 */

#include "PrimMST.h"

edgeNode::edgeNode(int nodeI, int nodeJ, int cost)
{
	this->Ni = nodeI;
	this->Nj = nodeJ;
	this->edgeCost = cost;
	this->next = NULL;
}

edgeNode::~edgeNode()
{
    edgeNode *current = this->next;
    edgeNode *del = current;

    this->Ni = -9999;
    this->Nj = -9999;
    this->edgeCost = -9999;
    this->next = NULL;
    
    // check for reminding node
    while(next)
    {
        // save pointer to next node
        current = current->next;
        // delete the current node
        delete del;
        // update current node to next
        del = current;
    }
}

void edgeNode::Insert(int nodeI, int nodeJ, int cost, edgeNode **NodeHead)
{
	// initialize and store data into the new node
	edgeNode *newNode = new edgeNode(nodeI,nodeJ,cost);

    // current node 
	edgeNode *current = *NodeHead;
    // previous node, to where the new node should attach
	edgeNode *prev = NULL;

    // if NULL head?
    if (!*NodeHead)
    {
        *NodeHead = newNode;
        return;
    }
    
    // if the new node is bigger then the current node
    while(current != NULL && cost >= current->edgeCost)
    {
        // save this node, since it might be the last node to attach the new node
        prev = current;
        // update the current node to check the next one
        current = current->next;
    }
    
    // check if insert to the head
    if (!prev)
    {
        // attach the original list to the new node
        newNode->next = *NodeHead;
        // update the head to the new node as it's the 1st node now
        *NodeHead = newNode;
    }
    else
    {
        // attach the new node to previous node
        newNode->next = current;
        prev->next = newNode;
    }
	
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
    cout << "**********************\nContents of edgeNode\n----------------------" << endl;
    output_f << "**********************\nContents of edgeNode\n----------------------" << endl;
    
    // now print max_row nodes, not including the dummy node
	while(listHead != NULL)
	{
	    cout << "The cost from " << listHead->Ni << " to " << listHead->Nj << " is " << listHead->edgeCost << endl; 
	    output_f << "The cost from " << listHead->Ni << " to " << listHead->Nj << " is " << listHead->edgeCost << endl;
		listHead = listHead->next;
		count--;
		if ((max_row > 0) && (count <= 0))
		{
		    cout << "Only printing " << max_row << " entries, others are skipped" << endl;
		    break;
		}
	}
	
    cout << "----------------------\nEnd of edgeNode\n**********************" << endl << endl;
    output_f << "----------------------\nEnd of edgeNode\n**********************\n" << endl << endl;
}

