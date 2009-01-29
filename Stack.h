#ifndef STACK_H
#define STACK_H
#include <cstdlib>
#include "List.h"

using namespace std;

template <typename T>
class Stack
{
private:
	List <T>mList;
public:
	Stack();
	Stack(const Stack& list);
	virtual ~Stack();
	Stack operator=(const Stack& list);
	void push(T value);
	void pop();
       	T top();
	bool empty();	
};

//due to the usage of templates we have to include the .cpp file here
#include "Stack.cpp" 
#endif
