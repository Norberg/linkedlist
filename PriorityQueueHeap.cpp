#include <iostream>
const int RESIZE = 100;
	
template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	mHeap = new T[RESIZE];
	mSize = 0;
	mCapacity = RESIZE;
}

template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& queue)
{
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{

}

template <typename T>
PriorityQueue<T> PriorityQueue<T>::operator=(const PriorityQueue& queue)
{
}

template <typename T>
void PriorityQueue<T>::enqueue(T value)
{
	if (mSize == 0)
	{
		mHeap[0] = value;
		mSize++;
		return;
	}
	if (mSize >= mCapacity)
	{
		cout << "resize" << endl;
	}
	mHeap[mSize] = value;
	int i = mSize;
	while(i >= 0)
	{
		if (mHeap[i] > mHeap[(i-1) / 2])
		{
			swap(mHeap[i], mHeap[(i-1) / 2]);
			i = (i -1) / 2;	
		}
		else
		{
			break;
		}		
	}
}

template <typename T>
void PriorityQueue<T>::dequeue()
{
	if (mSize == 0)
	{
		return;
	}
	else if(mSize == 1)
	{
		mSize--;
	}
	mSize--;
	mHeap[0] = mHeap[mSize];
	if (mHeap[1] > mHeap[2])
	{
		swap(mHeap[0], mHeap[1]);		
	}
	else
	{
		swap(mHeap[0], mHeap[2]);		
	}
}

template <typename T>
T PriorityQueue<T>::front()
{
	return mHeap[0];
}

template <typename T>
bool PriorityQueue<T>::empty()
{
	if (mSize == 0)
		return true;
	else
		return false;
}
