#ifndef PRIORITYQUEUEHEAP_H
#define PRIORITYQUEUEHEAP_H
#include <cstdlib>

using namespace std;

template <typename T>
class PriorityQueue
{
private:
	T * mHeap;
	unsigned int mSize;
	unsigned int mCapacity;
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
#include "PriorityQueueHeap.cpp" 
#endif
