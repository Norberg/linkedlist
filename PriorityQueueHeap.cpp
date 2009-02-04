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
	delete [] mHeap;
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
	mSize++;
	while(i > 0)
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
		return;
	}
	mSize--;
	mHeap[0] = mHeap[mSize];
	unsigned int i = 0;
	while (i < mSize)
	{
		//if left child is bigger then parent and right child
		if (mHeap[i] < mHeap[2*i+1] && mHeap[2*i+1] >= mHeap[2*i+2] && 2*i+1 < mSize)	
		{
			//cerr << "L: size: " << mSize << " child: " << 2*i+1 << endl;
			swap(mHeap[i], mHeap[2*i+1]);
			i = 2*i+1;	
		}
		//if wight child is bigger then parent and left child
		else if (mHeap[i] < mHeap[2*i+2] && mHeap[2*i+1] <= mHeap[2*i+2] && (2*i+2) < mSize)
		{
			//cerr << "R: size: " << mSize << " child: " << 2*i+2 << endl;
			swap(mHeap[i], mHeap[2*i+2]);	
			i = 2*i+2;	
		}
		else
		{
			//finnished
			break;
		}	
	}
}

template <typename T>
T PriorityQueue<T>::front()
{
	/*cerr << "<data>" << endl;
	for (uint i  = 0; i < mSize; i++)
	{
		cerr << i << ": " << mHeap[i] << endl; 
	}
	cerr << "</data>" << endl;*/
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
