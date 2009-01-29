template <typename T>
Stack<T>::Stack()
{

}

template <typename T>
Stack<T>::Stack(const Stack& stack)
{
	mList = stack.mList;
}

template <typename T>
Stack<T>::~Stack()
{

}

template <typename T>
Stack<T> Stack<T>::operator=(const Stack& stack)
{
	mList = stack.mList;
}

template <typename T>
void Stack<T>::push(T value)
{
	mList.insertFirst(value);
}

template <typename T>
void Stack<T>::pop()
{
	mList.removeFirst();
}

template <typename T>
T Stack<T>::top()
{
	return mList.elementAt(0);
}

template <typename T>
bool Stack<T>::empty()
{
	if (mList.size() == 0)
		return true;
	else
		return false;
}
