#include <iostream>
#include <cstdlib>
#include "PriorityQueueHeap.h" 

using namespace std;

int main()
{
	//to be able to do fair benchmarks we better use a constant seed
	srand(42); 
	PriorityQueue<int> pq;
	for (int i = 1; i < 11; i++)
	{
		pq.enqueue(i);
	}
	pq.enqueue(1);
	pq.enqueue(99);
	pq.enqueue(2);
	pq.enqueue(10);
	pq.enqueue(3);
	pq.enqueue(7);
	while(!pq.empty())
	{
		cout << pq.front() << endl;
		pq.dequeue();
	}
	return 0;
}
