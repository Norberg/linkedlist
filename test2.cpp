#include <iostream>
#include "List.h"
#include <string>

using namespace std;

int main()
{
	List<int> lista;
	for (int j = 0; j < 100; j++)
	{
		for (int i = 0; i < 10000; i++)
			lista.insertLast(1);
		cout << j+1 << "%" << endl;
	}
	return 0;
}
