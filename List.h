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
		Node(T value){ this->value = value; this->next = NULL;}
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

//due to the usage of templates we have to include the .cpp file here
#include "List.cpp" 
#endif
