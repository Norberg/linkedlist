template <typename T>
PriorityQueue<T>::PriorityQueue()
{

}

template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& queue)
{
	mList = queue.mList;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{

}

template <typename T>
PriorityQueue<T> PriorityQueue<T>::operator=(const PriorityQueue& queue)
{
	mList = queue.mList;
	return *this;
}

template <typename T>
void PriorityQueue<T>::enqueue(T value)
{
	if (!mList.size())
	{
		mList.insertFirst(value);
		return;
	}
	for (int i = 0; i < mList.size(); i++)
	{
		if (mList.elementAt(i) < value)
		{
			mList.insertAt(i, value);
		       	return;	
		}	
	}
	//value is smallest
	mList.insertLast(value);
}

template <typename T>
void PriorityQueue<T>::dequeue()
{
	mList.removeFirst();
}

template <typename T>
T PriorityQueue<T>::front()
{
	return mList.elementAt(0);
}

template <typename T>
bool PriorityQueue<T>::empty()
{
	if (mList.size() == 0)
		return true;
	else
		return false;
}
