/*
 * PrimMST.cpp
 *
 *  Created on: Nov 29, 2015
 *      Author: Ella
 */

#include "PrimMST.h"

PrimMST::PrimMST(int n)
{
	this->N = n;
	this->totalCost = 0;

	//initialized to 0 with "value-initialize"
	graphNodeIDarray = new int[this->N]();

	edgeList = new edgeNode(-99999,-99999,-99999);
	MSTofG = NULL;
	setA = NULL;
	setB = NULL;
}

PrimMST::~PrimMST(void)
{
    // leave it empty for now
}

int PrimMST::PrimsMST (void)
{
    graphNode *newGraphNode;
    edgeNode *newEdge;
    graphNode *currentGraphNode;
    int N, Ni, Nj,cost;
    int k = 0;
    int node_id_value = 0;
    int total_cost = 0;
    int node_id_fromB;
    
    // step 4, add 1st none zero graphNodelIDArray to setA
    do
    {
        k++;
        node_id_value = this->graphNodeIDarray[k];
    } while (node_id_value == 0);
    
    newGraphNode = new graphNode(k);
    cout << "Adding " << newGraphNode->getNodeID() << " to setA" << endl;
    this->insertNodeToSet(newGraphNode, true);
    // done with this node
    k++;
    
    // step 5 & 6, read all the rest of none zero node to setB
    for (; k <= this->N; k++)
    {
        node_id_value = this->graphNodeIDarray[k];
        if (node_id_value == 0)
        {
            continue;
        }
        newGraphNode = new graphNode(k);
        cout << "Adding " << newGraphNode->getNodeID() << " to setB" << endl;
        this->insertNodeToSet(newGraphNode, false);
    }

    // step 10
    while(this->setB)
    {
        // step 7
        newEdge = this->getNextEdge(&node_id_fromB);
        // use it if it's valid
        if (!newEdge)
        {
            break;
        }
        
        // step 8
        cout << "Using " << newEdge->getNi() << " " << newEdge->getNj() << endl;
        // insert newEdge in the front of MSTofG
        this->insertMSTofG(newEdge);
        // update the total cost
        total_cost += newEdge->getCost();
        cout << "Run time total cost = " << total_cost << endl;
        // move the node from setB to setA
        cout << "Moving node " << node_id_fromB << endl;
        this->moveNodeA2B(node_id_fromB);
    }
    
    return total_cost;
}

void PrimMST::printGraphNodeIDarray (ofstream &output_f)
{
    int i;
    cout << "**********************\nContents of getNodeIDArray\n----------------------" << endl;
    output_f << "**********************\nContents of getNodeIDArray\n----------------------" << endl;
    cout << "Skipping dummy node" << endl;
    output_f << "Skipping dummy node" << endl;
    for (i = 1; i < this->N; i++)
    {
        cout << "Node " << i << ": " << this->graphNodeIDarray[i] << endl;
        output_f << "Node " << i << ": " << this->graphNodeIDarray[i] << endl;
    }
    cout << "----------------------\nEnd of getNodeIDArray\n**********************" << endl << endl;
    output_f << "----------------------\nEnd of getNodeIDArray\n**********************" << endl << endl;
}

void PrimMST::insertNodeToSet (graphNode *new_node, bool A)
{
    graphNode *current;
    new_node->next = NULL;
    
    // find which set to insert
    if (A)
    {
        // check for empty
        if (!this->setA)
        {
            this->setA = new_node;
            return;
        }
        current = this->setA;
    }
    else
    {
        // check for empty
        if (!this->setB)
        {
            this->setB = new_node;
            return;
        }
        current = this->setB;
    }
    
    // add to the tail
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
}

edgeNode* PrimMST::getNextEdge(int *node_id_fromB)
{
    edgeNode *previous_edge = this->edgeList;
    edgeNode *current_edge = this->edgeList->next;
    NODE_FROM_SET NiSet = UNKONWN;
    NODE_FROM_SET NjSet = UNKONWN;
    int counter = 0;
    while(current_edge)
    {
        NiSet = UNKONWN;
        NjSet = UNKONWN;
        counter++;
        if (counter > 20)
            break;
        // check if they are from the same set
        checkNodeIDSets(current_edge, node_id_fromB, &NiSet, &NjSet);
        
        // if both nodes are already in setA, 
        // we could just remove this edge since it's no use for us anymore
        // we should also delete invalid nodes, if there's any 
        if (((NiSet == FROMA) && (NjSet == FROMA))
                || (NiSet == UNKONWN) || (NjSet == UNKONWN))
        {
            // delete this edge
            this->edgeList->Delete(&(this->edgeList), current_edge);
        }
        // if both nodes are from setB, we just skip this edge for now 
        else if ((NiSet == FROMB) && (NjSet == FROMB))
        {
            // do nothing
        }
        else
        {
            // if not the same set, pick this edge
            // remove from the list since it's already picked
            this->edgeList->Delete(&(this->edgeList), current_edge);
            // return this edge
            return current_edge;
        }
        // otherwise, find the next one
        current_edge = current_edge->next;
    }
    cout << "Find nothing" << endl;
    return NULL;
}

void PrimMST::checkNodeIDSets (edgeNode *edge, int *nodeid_fromB, NODE_FROM_SET *NiSet, NODE_FROM_SET *NjSet)
{
    int Ni = edge->Ni; 
    int Nj = edge->Nj;
    graphNode* current = this->setA;
    while(current)
    {
        if (Ni == current->nodeID)
        {
            *NiSet = FROMA;
        }
        if (Nj == current->nodeID)
        {
            *NjSet = FROMA;
        }
        if ((*NiSet != UNKONWN) && (*NjSet != UNKONWN)) 
        {
            return;
        }
        current = current->next;
    }
    
    current = this->setB;
    while(current)
    {
        if (Ni == current->nodeID)
        {
            *nodeid_fromB = Ni;
            *NiSet = FROMB;
        }
        if (Nj == current->nodeID)
        {
            *nodeid_fromB = Nj;
            *NjSet = FROMB;
        }
        if ((*NiSet != UNKONWN) && (*NjSet != UNKONWN)) 
        {
            return;
        }
        current = current->next;
    }
}

void PrimMST::insertMSTofG (edgeNode *new_node)
{
    // same we already removed the node from edgeList,
    // modifying its next pointer will not affect edgeList
    
    // save current MSTofG
    new_node->next = this->MSTofG;
    this->MSTofG = new_node;
}

void PrimMST::moveNodeA2B (int node_id)
{
    // find the node
    graphNode* node = this->setB->FindAndDelete(&(this->setB), node_id);
    // add the node to set A
    this->insertNodeToSet(node, true);            
}

void PrimMST::insertEdge (int Ni, int Nj, int edge_cost)
{
    this->edgeList->Insert(Ni, Nj, edge_cost, &(this->edgeList));
}

void PrimMST::printEdgeNode (ofstream &outfile)
{
    cout << "Skipping dummy node " << this->edgeList->edgeCost << endl;
    outfile << "Skipping dummy node " << this->edgeList->edgeCost << endl;
    this->edgeList->printEdgeNode(outfile, this->edgeList->next, MAX_PRINT);
}

void PrimMST::printMSTofG (ofstream &outfile)
{
    this->MSTofG->printEdgeNode(outfile, this->MSTofG, -1);
}