#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack<int> s;
	s.push(1);
	s.push(2);
	cout << s.top() << endl;
	s.pop();
	s.push(3);
	cout << s.top() << endl;
	Stack<int> a;
       	a= s;
	a.push(9);
	cout << "--" << endl;
	while(!a.empty())
	{
		cout << a.top() << endl;
		a.pop();
	}
	
	return 0;
}
