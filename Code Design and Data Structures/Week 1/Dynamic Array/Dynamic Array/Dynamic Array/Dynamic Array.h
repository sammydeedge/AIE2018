#pragma once

template<typename T>
class TDynamicArray
{
public:
	TDynamicArray();
	TDynamicArray(const TDynamicArray& other);
	~TDynamicArray();

	TDynamicArray& operator=(const TDynamicArray& other);
	
	void printArray();
	bool isFull();
	void resizeArray(size_t newMaxSize);


	void pushBack(T item);
	void popBack();
	void insertAt(T item, size_t index);
	void removeAt(const size_t index);
	void shrinkToFit();
	void clear();
	

private:
	const int intialSize = 10;

	size_t m_currentSize = 0;
	size_t m_maxSize = 0;
	T* m_contents = 0;
};

template<typename T>
TDynamicArray<T>::TDynamicArray()
{
	m_maxSize = intialSize;
	m_contents = new T[m_maxSize];
}

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

template<typename T>
TDynamicArray<T>& TDynamicArray<T>::operator=(const TDynamicArray<T>& other)
{

	m_currentSize = other.m_currentSize;
	m_maxSize = other.m_maxSize;

	delete[] m_contents;
	m_contents = new T[m_maxSize];
	for (size_t i = 0; i < m_currentSize; ++i)
	{
		m_contents[i] = other.m_contents[i];
	}

	return *this;
}

template<typename T>
TDynamicArray<T>::~TDynamicArray()
{
	delete []m_contents;
}

template<typename T>
void TDynamicArray<T>::printArray()
{
	for (size_t i = 0; i < m_currentSize; ++i)
	{
		std::cout << m_contents[i] << ", ";
	}
	std::cout << std::endl << std::endl;
}

template<typename T>
bool TDynamicArray<T>::isFull()
{
	return (m_currentSize >= m_maxSize);
}

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

template<typename T>
void TDynamicArray<T>::shrinkToFit()
{
	resizeArray(m_currentSize);
}