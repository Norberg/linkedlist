#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H
#include <cstdlib>
#include "List.h"

using namespace std;

template <typename T>
class Queue
{
private:
	T* mArray;
	unsigned int mSize;
	unsigned int mCapacity;
	unsigned int mFront;
	unsigned int mEnd;
public:
	Queue();
	Queue(const Queue& queue);
	virtual ~Queue();
	Queue operator=(const Queue& queue);
	void enqueue(T value);
	void dequeue();
       	T front();
	bool empty();	
};

//due to the usage of templates we have to include the .cpp file here
#include "QueueArray.cpp" 
#endif
