#include "Kmeans.h"


void LinkedList::insert(int x, int y,int label)
{
	Node *newNode = new Node(x,y,label);
	Node *head = listHead;

	while(head->next != NULL)
	{
		head = head->next;
	}
	head->next = newNode;
}

//create a dummy node
LinkedList::LinkedList()
{
	Node *newNode = new Node(-9999,-9999,-9999);
	listHead = newNode;
}

//destrutor
LinkedList::~LinkedList(void)
{
	Node *current = listHead;
	while(current->next != NULL)
	{
		Node *next = current->next;
		delete current;
		current = next;
	}
	listHead = NULL;
}
void LinkedList::printList(ofstream &output_f)
{
	Node *head = listHead;
	while(head->next != NULL)
	{
		head = head->next;
		head->printNode(output_f);
	}
}

//delete nodes based on their x,y coordinates
void LinkedList::deletion(int x, int y)
{
	Node* current = listHead;
	Node* del = current;
	Node* previous = current;
	while(current->next != NULL)
	{
		previous = current;
		current = current->next;
		if(current->X_coordinate == x && current->Y_coordinate == y)
		{
			del = current;
			previous->next = current->next;
			current = previous;
			delete del;
			continue;
		}
	}
}

