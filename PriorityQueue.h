#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <cstdlib>
#include "List.h"

using namespace std;

template <typename T>
class PriorityQueue
{
private:
	List <T>mList;
public:
	PriorityQueue();
	PriorityQueue(const PriorityQueue& list);
	virtual ~PriorityQueue();
	PriorityQueue operator=(const PriorityQueue& list);
	void enqueue(T value);
	void dequeue();
       	T front();
	bool empty();	
};

//due to the usage of templates we have to include the .cpp file here
#include "PriorityQueue.cpp" 
#endif
