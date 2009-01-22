#include <iostream>
#include "PosIntList.h"

using namespace std;

int main()
{
	PosIntList lista;
	lista.insertFirst(10);
	lista.insertLast(20);
	for (int i = 0; i < lista.size(); i++)
	{
		cout << i << " :" << lista.elementAt(i) << endl;
	}
	lista.insertFirst(30);
	for (int i = 0; i < lista.size(); i++)
	{
		cout << i << " :" << lista.elementAt(i) << endl;
	}
	lista.insertAt(1, 55);
	cout << "-----" << endl;
	for (int i = 0; i < lista.size(); i++)
	{
		cout << i << " :" << lista.elementAt(i) << endl;
	}
	cout << "Tog bort: " << lista.removeFirst() << endl;
	cout << "-----" << endl;
	for (int i = 0; i < lista.size(); i++)
	{
		cout << i << " :" << lista.elementAt(i) << endl;
	}
	cout << "Tog bort: " << lista.removeLast() << endl;
	cout << "Tog bort: " << lista.removeLast() << endl;
	cout << "Tog bort: " << lista.removeLast() << endl;
	cout << "Tog bort: " << lista.removeLast() << endl;
	cout << "Tog bort: " << lista.removeLast() << endl;
	cout << "Tog bort: " << lista.removeLast() << endl;
	cout << "-----" << endl;
	for (int i = 0; i < lista.size(); i++)
	{
		cout << i << " :" << lista.elementAt(i) << endl;
	}
	lista.insertFirst(30);
	lista.insertFirst(130);
	lista.insertFirst(330);
	lista.insertFirst(530);
	lista.insertFirst(630);
	lista.insertFirst(730);
	cout << "-----" << endl;
	for (int i = 0; i < lista.size(); i++)
	{
		cout << i << " :" << lista.elementAt(i) << endl;
	}
	cout << "Tog bort: " << lista.removeAt(0) << "pos: 0" << endl;
	cout << "-----" << endl;
	for (int i = 0; i < lista.size(); i++)
	{
		cout << i << " :" << lista.elementAt(i) << endl;
	}
	cout << "Tog bort: " << lista.removeAt(3) << "pos:3" << endl;
	cout << "-----" << endl;
	for (int i = 0; i < lista.size(); i++)
	{
		cout << i << " :" << lista.elementAt(i) << endl;
	}
	return 0;
}
