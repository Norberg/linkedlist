#include "PosIntList.h"
#include <iostream>

using namespace std;

void modify(PosIntList );
int main()
{
	PosIntList *list1;
	list1=new PosIntList();
	
	//Test 1, funktioner
	//Ska ge utskriften:
	//Test 1
	//10
	/*	
	list1->insertFirst(10);
		
	cout<<"Test 1"<<endl;
	for (int i=0; i<list1->size(); i++)
	{
		cout<<list1->elementAt(i)<<"  ";
	}
	cout<<endl;
*/
	//Test 2, funktioner
	/*Ska ge utskriften:
	Test 2
	70 60 20 50 10 30
	*/
	/*
	list1->insertFirst(10);
	list1->insertFirst(20);
	list1->insertLast(30);
	list1->insertAt(1,50);
	list1->insertFirst(60);
	list1->insertFirst(70);

	cout<<"Test 2"<<endl;
	for (int i=0; i<list1->size(); i++)
	{
		cout<<list1->elementAt(i)<<"  ";
	}
	cout<<endl;
	*/
	//Test 3, funktioner
	/*Ska ge utskriften:
	Test 3
	60 20 10
	*/
	list1->insertFirst(10);
	list1->insertFirst(20);
	list1->insertLast(30);
	list1->insertAt(1,50);
	list1->insertFirst(60);
	list1->insertFirst(70);
	
	for (int i=0; i<list1->size(); i++)
	{
		cout<<list1->elementAt(i)<<"  ";
	}
	list1->removeFirst();
	list1->removeLast();
	list1->removeAt(2);
	cout<<"Test 3"<<endl;
	for (int i=0; i<list1->size(); i++)
	{
		cout<<list1->elementAt(i)<<"  ";
	}
	cout<<endl;
	//Test 4, tilldelningsoperator
	/*Ska ge utskriften:
	Test 4
	20 10 30

	PosIntList list3;
	list3.insertFirst(10);
	list3.insertFirst(20);
	list3.insertLast(30);
	
	PosIntList list4;
	list4=list3;
	cout<<"Test 4"<<endl;
	for (int i=0; i<list4.size(); i++)
	{
		cout<<list4.elementAt(i)<<"  ";
	}
	cout<<endl;*/

	//Test 5, removeLast()
	/*Ska ge utskriften:
	Test 5
*/
	/*
	list1->insertFirst(10);
	list1->removeLast();
	cout<<"Test 5"<<endl;
	for (int i=0; i<list1->size(); i++)
	{
		cout<<list1->elementAt(i)<<"  ";
	}
	cout<<endl;
	*/
	//Test 6, copy-konstruktor
	/*Ska ge utskriften:
	Test 6
	70 60 20 50 10 30
	70 60 50 30
	70 60 20 50 10 30
	
	PosIntList list5;
	list5.insertFirst(10);
	list5.insertFirst(20);
	list5.insertLast(30);
	list5.insertAt(1,50);
	list5.insertFirst(60);
	list5.insertFirst(70);
	cout<<"Test 6"<<endl;
	for (int i=0; i<list5.size(); i++)
	{
		cout<<list5.elementAt(i)<<"  ";
	}
	cout<<endl;
	modify(list5);
	for (int i=0; i<list5.size(); i++)
	{
		cout<<list5.elementAt(i)<<"  ";
	}
	cout<<endl;*/
	return 0;
}
void modify(PosIntList list6)
{
	list6.removeAt(2);
	list6.removeAt(3);
	for (int i=0; i<list6.size(); i++)
	{
		cout<<list6.elementAt(i)<<"  ";
	}
	cout<<endl;
}
