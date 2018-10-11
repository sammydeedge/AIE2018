#pragma once

template<typename T>
class TDynamicArray
{
public:
	TDynamicArray();			
	TDynamicArray(const TDynamicArray& other);
	~TDynamicArray();

	TDynamicArray& operator=(const TDynamicArray& other);
	
	void printArray();										//Prints all elements of array
	bool isFull();											//Checks if array is full
	void resizeArray(size_t newMaxSize);					//Resize array to chosen size


	void pushBack(T item);									//Adds to end of array
	void popBack();											//Removes from end of array
	void insertAt(T item, size_t index);					//Inserts new data point into array at a given index
	void removeAt(const size_t index);						//Removes data point at a given index
	void shrinkToFit();										//Shrinks array size to fit current number of datapoints
	void clear();											//Deletes all data from array
	

private:
	const int intialSize = 10;

	size_t m_currentSize = 0;
	size_t m_maxSize = 0;
	T* m_contents = 0;
};
<<<<<<< HEAD
//Intialises an array
=======

>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77
template<typename T>
TDynamicArray<T>::TDynamicArray()
{
	m_maxSize = intialSize;
	m_contents = new T[m_maxSize];
}

<<<<<<< HEAD
//Copy constructor
=======
>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77
template<typename T>
TDynamicArray<T>::TDynamicArray(const TDynamicArray& other)
{
	m_currentSize = other.m_currentSize;
	m_maxSize = other.m_maxSize;

	m_contents = new T[m_maxSize];
	for (size_t i = 0; i < m_currentSize; ++i)
	{
		m_contents[i] = other.m_contents[i];
	}

}
<<<<<<< HEAD
//Assignment operator
=======

>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77
template<typename T>
TDynamicArray<T>& TDynamicArray<T>::operator=(const TDynamicArray<T>& other)
{

	m_currentSize = other.m_currentSize;
	m_maxSize = other.m_maxSize;

<<<<<<< HEAD
	delete[] m_contents;														
=======
	delete[] m_contents;
>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77
	m_contents = new T[m_maxSize];
	for (size_t i = 0; i < m_currentSize; ++i)
	{
		m_contents[i] = other.m_contents[i];
	}

	return *this;
}

<<<<<<< HEAD
//Destructor
=======
>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77
template<typename T>
TDynamicArray<T>::~TDynamicArray()
{
	delete []m_contents;
}

<<<<<<< HEAD
//Print Array
template<typename T>
void TDynamicArray<T>::printArray()
{
	for (size_t i = 0; i < m_currentSize; ++i)		//Iterates through list, printing each value
=======
template<typename T>
void TDynamicArray<T>::printArray()
{
	for (size_t i = 0; i < m_currentSize; ++i)
>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77
	{
		std::cout << m_contents[i] << ", ";
	}
	std::cout << std::endl << std::endl;
}

<<<<<<< HEAD
//Checks if the array is full
=======
>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77
template<typename T>
bool TDynamicArray<T>::isFull()
{
	return (m_currentSize >= m_maxSize);
}

<<<<<<< HEAD
//Resizes array to "newMaxSize"
template<typename T>
void TDynamicArray<T>::resizeArray(size_t newMaxSize)
{
	T* newArray = new T[newMaxSize];										//Makes a new array at the new maximum size

		for (size_t i = 0; i < newMaxSize && i < m_currentSize; i++)		//Iterates through original list:
		{
			newArray[i] = m_contents[i];									//Copying data from the old array to the new one
		}

	delete[] m_contents;													//Then the old one is deleted
	m_contents = newArray;													//and sets the new one to point to the old one
	
		m_maxSize = newMaxSize;												//sets the max size variable to match the new size
		if (m_currentSize > m_maxSize)										//if the previous current size is bigger than the new maximum size
		{
			m_currentSize = m_maxSize;										//the current size is set to match the maximum
		}
}

//Adds new data point at end of array
template<typename T>
void TDynamicArray<T>::pushBack(T item)
{
	if (isFull())								//If array is full: 
	{
		resizeArray(m_maxSize+5);				//resize it to have hold 5 more elements
	}
	m_contents[m_currentSize] = item;			//Add new data into new data point
	m_currentSize++;							//and increase the currentSize counter
}

//Removes the last array item
template<typename T>
void TDynamicArray<T>::popBack()
{
	m_contents[m_currentSize] = 0;				//Sets the data in last item to 0
	m_currentSize--;							//Reduces the current size by 1
}

//Inserts new datapoint at given index
template<typename T>
void TDynamicArray<T>::insertAt(T item, const size_t index)
{
	if (isFull())								//If the array is full:
	{
		resizeArray(m_maxSize+5);				//Resize it to have 5 more data points.
	}
	for (size_t i = m_maxSize; i > index; --i)	//Starting at the end of the array, working backwards
	{
		m_contents[i] = m_contents[i - 1];		//The data of each datapoint is moved one further down the list
	}
	m_contents[index] = item;					//The new data is added to the given index
	m_currentSize++;							//and the current size counter is incremented by 1
}

//Removes data point at given index
template<typename T>
void TDynamicArray<T>::removeAt(const size_t index)
{
	for (size_t i = index; i < m_maxSize; ++i)	//Starting at the index location, iterating until the end of the list
	{
		m_contents[i] = m_contents[i+1];		//each datapoint is  replaced by the one before it
	}											//data is preserved, except for the removed data, which is overwritten by the following item
	
	m_currentSize--;							//Current size is decremented by 1
}

//Clears array
template<typename T>
void TDynamicArray<T>::clear()
{
	m_currentSize = 0;							//Current size is set to 0, this means the data remains, but is ignored.
}												//Any functions that add new data, will overwrite previous array

//Resizes array to match the current number of array items.
=======
template<typename T>
void TDynamicArray<T>::resizeArray(size_t newMaxSize)
{
	T* newArray = new T[newMaxSize];

		for (size_t i = 0; i < newMaxSize && i < m_currentSize; i++)
		{
			newArray[i] = m_contents[i];
		}

	delete[] m_contents;
	m_contents = newArray;
	
		m_maxSize = newMaxSize;
		if (m_currentSize > m_maxSize)
		{
			m_currentSize = m_maxSize;
		}
}

template<typename T>
void TDynamicArray<T>::pushBack(T item)
{
	if (isFull())
	{
		resizeArray(m_maxSize+5);
	}
	m_contents[m_currentSize] = item;
	m_currentSize++;
}

template<typename T>
void TDynamicArray<T>::popBack()
{
	m_contents[m_currentSize] = 0;
	m_currentSize--;
}

template<typename T>
void TDynamicArray<T>::insertAt(T item, const size_t index)
{
	if (isFull())
	{
		resizeArray(m_maxSize+5);
	}
	for (size_t i = m_maxSize; i > index; --i)
	{
		m_contents[i] = m_contents[i - 1];
	}
	m_contents[index] = item;
	m_currentSize++;
}

template<typename T>
void TDynamicArray<T>::removeAt(const size_t index)
{
	for (size_t i = index; i < m_maxSize; ++i)
	{
		m_contents[i] = m_contents[i+1];
	}
	
	m_currentSize--;
}

template<typename T>
void TDynamicArray<T>::clear()
{
	m_currentSize = 0;
}

>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77
template<typename T>
void TDynamicArray<T>::shrinkToFit()
{
	resizeArray(m_currentSize);
}