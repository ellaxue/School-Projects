/*
 * PrimMST.cpp
 *
 *  Created on: Nov 29, 2015
 *      Author: Ella
 */

#include "../Prim_MST/PrimMST.h"

PrimMST::PrimMST(int n)
{
	this->N = n;
	this->totalCost = 0;

	//initialized to 0 with "value-initialize"
	graphNodeIDarray = new int[this->N]();

	edgeList = new edgeNode(-99999,-99999,-99999);
	MSTofG = new edgeNode(-99999,-99999,-99999);
	setA = new graphNode(-99999);
	setB = new graphNode(-99999);
}

PrimMST::~PrimMST(void)
{
	cout<<"Deconstructing nodes and edges" <<endl;
	graphNode *current = this->setA;
	while(current->next != NULL)
	{
		graphNode *next = current->next;
		delete current;
		current = next;
	}
	this->setA = NULL;

	current = this->setB;
	while(current->next != NULL)
	{
		graphNode *next = current->next;
		delete current;
		current = next;
	}
	this->setB = NULL;

	edgeNode *currentE = this->MSTofG;
	while(currentE->next != NULL)
	{
		edgeNode *next = currentE->next;
		delete currentE;
		currentE = next;
	}
	this->MSTofG = NULL;

	currentE = this->edgeList;
	while(currentE->next != NULL)
	{
		edgeNode *next = currentE->next;
		delete currentE;
		currentE = next;
	}
	this->edgeList = NULL;
}

int PrimMST::PrimsMST (ofstream &output_f1,ofstream &output_f2)
{
    graphNode *newGraphNode;
    edgeNode *newEdge;
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
    cout<<"Adding " << newGraphNode->getNodeID() << " to setA\r\n";
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
        cout<<"Adding " << newGraphNode->getNodeID() << " to setB\r\n";
        this->insertNodeToSet(newGraphNode, false);

    }
    // step 10
    while(this->setB)
    {
    	//step 9:print out final nodes in setA and SetB
    	setB->printSetNodes(output_f2,this->setB,this->setA,false);
    	setA->printSetNodes(output_f2,this->setB,this->setA,true);
    	printMSTofG(output_f2);
        // step 7
        newEdge = this->getNextEdge(&node_id_fromB,output_f2);
        // use it if it's valid
        if (!newEdge)
        {
            break;
        }
        
        // step 8
        cout<<"Using " << newEdge->getNi() << " " << newEdge->getNj() << "\n";
        // insert newEdge in the front of MSTofG
        this->insertMSTofG(newEdge);
        // update the total cost
        total_cost += newEdge->getCost();
        this->totalCost += newEdge->getCost();
        cout<< "Run time total cost = " << this->totalCost << "\r\n";;
        // move the node from setB to setA
        cout<<"Moving node " << node_id_fromB << "\r\n";;
        this->moveNodeA2B(node_id_fromB);
    }


    return total_cost;
}
void PrimMST::insertNodeToSet (graphNode *new_node, bool A)
{

	graphNode *listHead;
    // find which set to insert
    if (A){listHead = this->setA;}
    else {listHead = this->setB;}
    
    listHead->Insert(new_node,listHead);
}
void PrimMST::printGraphNodeIDarray (ofstream &output_f1,ofstream &output_f2)
{
    int i;
    output_f2 << "**********************\r\nContents of getNodeIDArray\r\n----------------------" << "\r\n";;
    output_f2 << "Skipping dummy node" << "\r\n";;
    for (i = 1; i < this->N + 1; i++)
    {
        output_f2 << "Node " << i << ": " << this->graphNodeIDarray[i] << "\r\n";;
    }
    output_f2 << "----------------------\r\nEnd of getNodeIDArray\r\n**********************\r\n";

}

edgeNode* PrimMST::getNextEdge(int *node_id_fromB, ofstream &output_f2)
{
    edgeNode *current_edge = this->edgeList->next;

    NODE_FROM_SET NiSet = UNKONWN;
    NODE_FROM_SET NjSet = UNKONWN;
    while(current_edge)
    {
        NiSet = UNKONWN;
        NjSet = UNKONWN;

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
    return NULL;
}

void PrimMST::checkNodeIDSets (edgeNode *edge, int *nodeid_fromB, NODE_FROM_SET *NiSet, NODE_FROM_SET *NjSet)
{
    int Ni = edge->Ni; 
    int Nj = edge->Nj;
    graphNode* current = this->setA;
    while(current)
    {//compare all the nodes in setA with the newEdge to see if they are in the same set
        if (Ni == current->nodeID)
        {
            *NiSet = FROMA;
        }
        if (Nj == current->nodeID)
        {
            *NjSet = FROMA;
        }
        if ((*NiSet != UNKONWN) && (*NjSet != UNKONWN)) 
        {//if both from setA return, find next edge
            return;
        }
        current = current->next;
    }
    
    current = this->setB;
    while(current)
    {//compare all the nodes in setB with the newEdge's node to see if they are in the same set
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
        {//if both from setA return, find next edge
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
    new_node->next = this->MSTofG->next;
    this->MSTofG->next = new_node;
}

void PrimMST::moveNodeA2B (int node_id)
{
    // find the node
    graphNode* node = this->setB->FindAndDelete(&(this->setB), node_id);
    // add the node to set A
    cout<<"inserting node to A" <<node->nodeID<<"\r\n";;
    this->insertNodeToSet(node, true);            
}

void PrimMST::insertEdge (int Ni, int Nj, int edge_cost)
{
    this->edgeList->Insert(Ni, Nj, edge_cost, &(this->edgeList));
}

void PrimMST::printEdgeNode (ofstream &outfile)
{
//    outfile1 << "Skipping dummy node " << this->edgeList->edgeCost << "\r\n";;
    outfile << "Skipping dummy node " << this->edgeList->edgeCost << "\r\n";;
    outfile << "**********************\r\nContents of edgeNode\r\n----------------------" << "\r\n";;
    this->edgeList->printEdgeNode(outfile, this->edgeList, MAX_PRINT);
    outfile << "----------------------\r\nEnd of edgeNode\r\n**********************\r\n";
}

void PrimMST::printMSTofG (ofstream &outfile)
{
	outfile << "**********************\r\nContents of MST of G\r\n----------------------" << "\r\n";;
	outfile <<this->N<<"\r\n";
    this->MSTofG->printEdgeNode(outfile ,this->MSTofG, -1);
    outfile <<"\r\nTotal cost: " << this->totalCost<<"\r\n" ;
    outfile << "----------------------\r\nEnd of MST of G\r\n**********************\r\n";
}
