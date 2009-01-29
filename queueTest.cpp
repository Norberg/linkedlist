#include <iostream>
#include "Queue.h"
#include "List.h"

using namespace std;

int main()
{
	Queue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	Queue<int> a;
       	a = q;
	while(!a.empty())
	{
		cout << a.front() << endl;
		a.dequeue();
	}
	return 0;
}
