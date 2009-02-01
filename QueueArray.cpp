const unsigned int RESIZE = 10;

template <typename T>
Queue<T>::Queue()
{
	mArray = new T[10];
	mSize = 0;
	mCapacity = 10;
	mFront = 0;
	mEnd = 0;
}

template <typename T>
Queue<T>::Queue(const Queue& queue)
{
	mArray  = new T[queue.mCapacity];
	for (unsigned int i = 0; i < queue.mCapacity; i++)
	{
		mArray[i] = queue.mArray[i];
	}
	mCapacity = queue.mCapacity;
	mFront = queue.mFront;
	mEnd = queue.mEnd;
	mSize = queue.mSize;
}

template <typename T>
Queue<T>::~Queue()
{
	delete [] mArray;
}

template <typename T>
Queue<T> Queue<T>::operator=(const Queue& queue)
{
	delete [] mArray;
	mArray  = new T[queue.mCapacity];
	for (unsigned int i = 0; i < queue.mCapacity; i++)
	{
		mArray[i] = queue.mArray[i];
	}
	mCapacity = queue.mCapacity;
	mFront = queue.mFront;
	mEnd = queue.mEnd;
	mSize = queue.mSize;
	return *this;
	
}

template <typename T>
void Queue<T>::enqueue(T value)
{
	if(mCapacity <= mSize)
	{
		T* newArray  = new T[mCapacity + RESIZE];
		for (unsigned int i = 0; i < mSize; i++)
		{
			newArray[i] = mArray[mFront];
			mFront = (mFront+1) % mCapacity;
		}
		mCapacity += RESIZE;
		mFront = 0;
		mEnd = mSize -1;
		delete [] mArray;
		mArray = newArray;
	}
	if (!mSize)
	{
		mArray[0] = value;
		mEnd = 0;
		mSize++;
	}
	else
	{
		mEnd = (mEnd+1)%mCapacity;
		mArray[mEnd] = value;
		mSize++;
	}
}

template <typename T>
void Queue<T>::dequeue()
{
	if(mCapacity >= mSize + RESIZE)
	{
		T* newArray = new T[mCapacity-RESIZE];
		cout << "Shrinking Queue" << endl;
		for (unsigned int i = 0; i < (mCapacity - RESIZE); i++)
		{
			newArray[i] = mArray[mFront];
			mFront = (mFront+1) % mCapacity;
		}

		mCapacity -= RESIZE;
		mFront = 0;
		mEnd = mSize -1;
		delete [] mArray;
		mArray = newArray;
	}
	
	if (!mSize)
	{
	
	}
	else
	{
		mFront = (mFront+1) % mCapacity;
		mSize--;
	}
}

template <typename T>
T Queue<T>::front()
{
	return mArray[mFront];
}

template <typename T>
bool Queue<T>::empty()
{
	if (mSize == 0)
		return true;
	else
		return false;
}
