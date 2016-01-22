/*
 * graphNode.cpp
 *
 *  Created on: Nov 29, 2015
 *      Author: Ella
 */

#include "PrimMST.h"


graphNode::graphNode(int nodeID)
{
	this->nodeID = nodeID;
	this->next = NULL;
	this->isEmpty = NULL;
}

void graphNode::Insert(int nodeId, graphNode *listHead)
{
    while (listHead->next)
    {
        listHead = listHead->next;
    }
    listHead = new graphNode(nodeId);
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
    graphNode *current = this->next;
    graphNode *del = current;

    this->nodeID = 0;
    this->isEmpty = NULL;
    
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
