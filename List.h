#ifndef LIST_H
#define LIST_H
#include <cstdlib>

using namespace std;

template <typename T>
class List
{
private :
	class Node
	{
	public:
		T value;
		Node *next;
		Node(int value){ this->value = value; this->next = NULL;}
		~Node() {}
	};
	
	Node *first;
	int nrOfNodes;
public:
	List();
	List(const List& list);
	virtual ~List();
	List operator=(const List& list);
	void insertLast(T value);
	void insertAt(int pos, T value);
	void insertFirst(T value);
	T elementAt(int pos)const;
	T removeFirst();
	T removeLast();
	T removeAt(int pos);
	int size()const;
	bool contains(int value) const;
};

#include <iostream>

using namespace std;

template <typename T>
List<T>::List()
{
	first = NULL;
	nrOfNodes = 0;
}

template <typename T>
List<T>::List(const List& list)
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

template <typename T>
List<T> List<T>::operator=(const List& list)
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

template <typename T>
List<T>::~List()
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

template <typename T>
void List<T>::insertFirst(T value)
{
	Node *e = new Node(value);
	e->next = first;
	first = e;
	nrOfNodes++;
}

template <typename T>
void List<T>::insertLast(T value)
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

template <typename T>
void List<T>::insertAt(int pos, T value)
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

template <typename T>
T List<T>::elementAt(int pos)const
{
	Node *walker;
	walker = first;
	for (int i = 0; i < pos; i++)
	{
		walker = walker->next;
	}
	return walker->value;
	
}

template <typename T>
T List<T>::removeFirst()
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

template <typename T>
T List<T>::removeLast()
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

template <typename T>
T List<T>::removeAt(int pos)
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

template <typename T>
int List<T>::size()const
{
	return nrOfNodes;
}
#endif
