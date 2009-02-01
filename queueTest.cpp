#include <iostream>
#include "QueueArray.h"

using namespace std;

int main()
{
	Queue<int> q;
	for (int i = 0; i < 30; i++)
	{
		q.enqueue(i);
	}
	for (int i = 0; i < 30; i++)
	{
		q.enqueue(q.front());
		q.dequeue();
	}
	Queue<int> a = q;
	while(!a.empty())
	{
		cout << a.front() << endl;
		a.dequeue();
	}
	return 0;
}
