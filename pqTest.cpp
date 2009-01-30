#include <iostream>
#include <cstdlib>
#include "PriorityQueue.h" 

using namespace std;

int main()
{
	//to be able to do fair benchmarks we better use a constant seed
	srand(42); 
	PriorityQueue<int> pg;
	for (int i = 0; i < 3000; i++)
	{
		pg.enqueue(rand());
	}
	/*	
	while(!pg.empty())
	{
		cout << pg.front() << endl;
		pg.dequeue();
	}
	*/
	return 0;
}
