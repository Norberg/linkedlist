#ifndef POSINTLIST_H
#define POSINTLIST_H
#include <cstdlib>

using namespace std;

class PosIntList
{
private :
	class Node
	{
	public:
		int value;
		Node *next;
		Node(int value){ this->value = value; this->next = NULL;}
		~Node() {}
	};
	
	Node *first;
	int nrOfNodes;
public:
	PosIntList();
	PosIntList(const PosIntList& list);
	virtual ~PosIntList();
	PosIntList operator=(const PosIntList& list);
	void insertLast(int value);
	void insertAt(int pos, int value);
	void insertFirst(int value);
	int elementAt(int pos)const;
	int removeFirst();
	int removeLast();
	int removeAt(int pos);
	int size()const;
	bool contains(int value) const;
};

#endif
