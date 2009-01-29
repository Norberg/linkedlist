template <typename T>
Queue<T>::Queue()
{

}

template <typename T>
Queue<T>::Queue(const Queue& queue)
{
	mList = queue.mList;
}

template <typename T>
Queue<T>::~Queue()
{

}

template <typename T>
Queue<T> Queue<T>::operator=(const Queue& queue)
{
	mList = queue.mList;
	return *this;
}

template <typename T>
void Queue<T>::enqueue(T value)
{
	mList.insertLast(value);
}

template <typename T>
void Queue<T>::dequeue()
{
	mList.removeFirst();
}

template <typename T>
T Queue<T>::front()
{
	return mList.elementAt(0);
}

template <typename T>
bool Queue<T>::empty()
{
	if (mList.size() == 0)
		return true;
	else
		return false;
}
