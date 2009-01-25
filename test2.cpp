#include <iostream>
#include "List.h"
#include <string>

using namespace std;

int main()
{
	List<string> lista;
	lista.insertFirst("a");
	lista.insertLast("b");
	for (int i = 0; i < lista.size(); i++)
	{
		cout << i << " :" << lista.elementAt(i) << endl;
	}
	
	lista.removeFirst();
	lista.removeFirst();
	lista.removeFirst();
	lista.removeFirst();
	lista.removeFirst();
	lista.removeFirst();
	for (int i = 0; i < lista.size(); i++)
	{
		cout << i << " :" << lista.elementAt(i) << endl;
	}
	return 0;
}
