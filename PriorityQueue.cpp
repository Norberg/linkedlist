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
	else if (mList.elementAt(0) <= value)
	{

		mList.insertFirst(value);
		return;
	}
	int lower = 0, upper = mList.size(), middle = upper /2;
	while(1)
	{
		if(middle == lower)
		{
			mList.insertAt(middle+1, value);
			return;
		}
		if (mList.elementAt(middle) < value)
		{
			upper = middle;
			middle = lower + (upper - lower)/2;
		}
		else if(mList.elementAt(middle) > value)
		{
			lower = middle;
			middle = lower + (upper - lower)/2;
		}
	}
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
