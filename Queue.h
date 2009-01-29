#ifndef QUEUE_H
#define QUEUE_H
#include <cstdlib>
#include "List.h"

using namespace std;

template <typename T>
class Queue
{
private:
	List <T>mList;
public:
	Queue();
	Queue(const Queue& list);
	virtual ~Queue();
	Queue operator=(const Queue& list);
	void enqueue(T value);
	void dequeue();
       	T front();
	bool empty();	
};

//due to the usage of templates we have to include the .cpp file here
#include "Queue.cpp" 
#endif
