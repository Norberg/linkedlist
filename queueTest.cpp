#include <iostream>
#include "QueueArray.h"

using namespace std;

int main()
{
	Queue<int> q;
	for (int i = 0; i < 20; i++)
	{
		q.enqueue(i);
	}
	for (int i = 0; i < 20; i++)
	{
	//	q.enqueue(q.front());
	//	q.dequeue();
	}
//	Queue<int> a;
 //     	a = q;
	while(!q.empty())
	{
		cout << q.front() << endl;
		q.dequeue();
	}
	return 0;
}
