#include <iostream>
#include "PriorityQueue.h" 

using namespace std;

int main()
{
	PriorityQueue<int> pg;
	pg.enqueue(1);
	pg.enqueue(5);
	pg.enqueue(2);
	while(!pg.empty())
	{
		cout << pg.front() << endl;
		pg.dequeue();
	}

	return 0;
}
