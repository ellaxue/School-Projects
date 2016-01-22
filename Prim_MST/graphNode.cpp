/*
 * graphNode.cpp
 *
 *  Created on: Nov 29, 2015
 *      Author: Ella
 */

#include "../Prim_MST/PrimMST.h"


graphNode::graphNode(int nodeID)
{
	this->nodeID = nodeID;
	this->next = NULL;
	this->isEmpty = NULL;
}

void graphNode::Insert(graphNode *new_node, graphNode *listHead)
{
	 graphNode *current = listHead;
	 graphNode *nextNode;

	 //adding node in the front of setB
	 nextNode = current->next;
	 current->next = new_node;
	 new_node->next = nextNode;
}
void graphNode::printSetNodes(ofstream &output_f, graphNode * setB_head, graphNode *setA_head,bool A)
{
	graphNode *current;
	if(A)
	{
		current = setA_head;
		output_f<<"******************************\r\n printing current nodes in setA \r\n";
		output_f<<"--------------------------------- \r\n";
	}
	else
	{
		current = setB_head;
		output_f<<"******************************\r\n printing current nodes in setB \r\n";
		output_f<<"--------------------------------- \r\n";
	}

	while(current->next != NULL)
	{
		current = current->next;
		output_f<<current->getNodeID()<<"\r\n";
	}
	cout<<endl;
}
graphNode* graphNode::FindAndDelete (graphNode **listHead, int node_id)
{
    graphNode *current = *listHead;
    graphNode *rt = NULL;
    if (!current)
    {
        return rt;
    }
    
    // head
    if (current->nodeID == node_id)
    {
        rt = current;
        *listHead = (*listHead)->next;
        return rt;
    }
    
    while(current->next)
    {
        if (current->next->nodeID == node_id)
        {
            rt = current->next;
            current->next = current->next->next;
            return rt;
        }
        current = current->next;
    }
    return rt;
}

void graphNode::Delete (graphNode **listHead, graphNode *del_node)
{
    graphNode *current = *listHead;
    
    if (!*listHead || !del_node)
    {
        cout << "Null pointer, return" << endl;
        return;
    }
    
    // most likely this is the code that being coded, since we already remove the head
    if (current == del_node)
    {
        *listHead = del_node->next;
        return;
    }
    
    // but, just for completeness
    while(current)
    {
        // find the node after which is the del_node
        if (current->next == del_node)
        {
            // remove the del_node by short-cut it
            current->next = del_node->next;
            return;
        }
        current = current->next;
    }
}

graphNode::~graphNode(void)
{
	cout<<"deteting node" <<endl;
	this->next = NULL;
	this->isEmpty = NULL;
}
