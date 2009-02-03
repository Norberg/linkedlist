#include <iostream>
#include <cstdlib>
#include "PriorityQueueHeap.h" 

using namespace std;

int main()
{
	//to be able to do fair benchmarks we better use a constant seed
	srand(42); 
	PriorityQueue<int> pq;
	for (int i = 0; i < 10; i++)
	{
		pq.enqueue(i);
	}
	pq.enqueue(99);
	pq.enqueue(10);
	while(!pq.empty())
	{
		cout << pq.front() << endl;
		pq.dequeue();
	}
	return 0;
}
