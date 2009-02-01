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
}

template <typename T>
Queue<T>::~Queue()
{
	delete [] mArray;
}

template <typename T>
Queue<T> Queue<T>::operator=(const Queue& queue)
{

}

template <typename T>
void Queue<T>::enqueue(T value)
{
	if(mCapacity <= mSize)
	{
		mCapacity += RESIZE;
		T* newArray  = new T[mCapacity];
		for (unsigned int i = 0; i < mSize; i++)
		{
			newArray[i] = mArray[i];	
		}
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
	if(mCapacity > mSize + RESIZE)
	{
		mCapacity -= RESIZE;
		T* newArray = new T[mCapacity];
		if (mEnd > mFront)
		{
			cout << "Shinking Queue, forward" << endl;
			int j = 0;
			for (unsigned int i = mFront; i < mEnd; i++)
			{
				//imFront = (mFront+1) % mCapacity;
				newArray[j] = mArray[i];
				j++;
			}
		}
		else
		{
			cout << "Shinking Queue, bakwards" << endl;
			int j = mSize;
			for (unsigned int i = mEnd; i < mFront; i++)
			{
				newArray[j] = mArray[i];
				j--;
			}
		}

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
