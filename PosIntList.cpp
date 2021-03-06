#include <iostream>
#include "PosIntList.h"

using namespace std;

PosIntList::PosIntList()
{
	first = NULL;
	nrOfNodes = 0;
}

PosIntList::PosIntList(const PosIntList& list)
{
	if (list.nrOfNodes == 0)
	{
		first = NULL;
		nrOfNodes = 0;
		return;
	}

	Node *walker;
	Node *copy1;
	Node *copy2;
	walker = list.first;
	copy1 = new Node(walker->value);
	first = copy1;
	for (int i = 1; i < list.nrOfNodes; i++)
	{
		walker = walker->next;
		copy2 = new Node(walker->value);
		copy1->next = copy2;
		copy1 = copy2;
	}
	nrOfNodes = list.nrOfNodes;	
}

PosIntList PosIntList::operator=(const PosIntList& list)
{
	if (list.nrOfNodes == 0)
	{
		nrOfNodes = 0;
		return *this;
	}

	Node *walker;
	Node *copy1;
	Node *copy2;
	walker = list.first;
	copy1 = new Node(walker->value);
	first = copy1;
	for (int i = 1; i < list.nrOfNodes; i++)
	{
		walker = walker->next;
		copy2 = new Node(walker->value);
		copy1->next = copy2;
		copy1 = copy2;
	}
	nrOfNodes = list.nrOfNodes;
	return *this;
}

PosIntList::~PosIntList()
{
	Node *tmp;
	Node* walker;
	walker = first;
	for(int i = 0; i < nrOfNodes; i++)
	{
		 tmp = walker;
		 walker = walker->next;
		 delete tmp;
	}
}
void PosIntList::insertFirst(int value)
{
	Node *e = new Node(value);
	e->next = first;
	first = e;
	nrOfNodes++;
}

void PosIntList::insertLast(int value)
{
	Node *e = new Node(value);
	Node *walker;
	walker = first;
	for (int i = 1; i < nrOfNodes; i++)
	{
		walker = walker->next;
	}
	walker->next = e;
	nrOfNodes++;
}

void PosIntList::insertAt(int pos, int value)
{
	Node *e = new Node(value);
	Node *walker;
	Node *tmp;
	walker = first;
	for (int i = 1; i < pos; i++)
	{
		walker = walker->next;
	}
	tmp = walker->next;
	walker->next = e;
	e->next = tmp;
	nrOfNodes++;
	
}

int PosIntList::elementAt(int pos)const
{
	Node *walker;
	walker = first;
	for (int i = 0; i < pos; i++)
	{
		walker = walker->next;
	}
	return walker->value;
	
}

int PosIntList::removeFirst()
{
	if (nrOfNodes == 0)
	{
		cerr << "No element to remove!" << endl;
		return -1;	
	}
	Node *remove = first;
	int val = first->value;
	first = first->next;
	delete remove;
	nrOfNodes--;
	return val;
}

int PosIntList::removeLast()
{
	if (nrOfNodes == 1)
		return removeFirst();	
	if (nrOfNodes == 0)
	{
		cerr << "No element to remove!" << endl;
		return -1;	
	}
	
	Node *walker = first;
	for (int i = 2; i < nrOfNodes; i++)
	{
		walker = walker->next;
	}
	nrOfNodes--;
	int val = walker->next->value;
	delete walker->next;
	walker->next = NULL;
	return val;
}

int PosIntList::removeAt(int pos)
{
	if (pos >= nrOfNodes)
	{
		cerr << "Element dont exist!" << endl;
		return -1;
	}
	//First element
	else if (pos == 0)
	{
		return removeFirst();
	}
	//Last element
	else if (pos+1 == nrOfNodes)
	{
		return removeLast();
	}
	
	Node *walker = first;
	for (int i = 1; i < pos; i++)
	{
		walker = walker->next;
	}
	nrOfNodes--;
	int val = walker->next->value;
	Node* remove = walker->next;
	walker->next = walker->next->next;
	delete remove;
	return val;
}

int PosIntList::size()const
{
	return nrOfNodes;
}
