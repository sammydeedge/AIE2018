#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
	m_maxSize = 10;
	m_contents = new int[m_maxSize];

}

DynamicArray::~DynamicArray()
{
	delete[] m_contents;
}

bool DynamicArray::isFull() const
{
	return (m_currentSize >= m_maxSize);
}

void DynamicArray::pushBack(int value)
{
	if (isFull())
	{

		resizeArray(++m_maxSize);
	}

	m_contents[m_currentSize] = value;
	m_currentSize++;

}

void DynamicArray::popBack()
{
	if (m_currentSize > 0) 
	{
		--m_currentSize;
	m_contents[m_currentSize] = 0;
	}
	
		
}
void DynamicArray::removeAt(unsigned int index)
{
	for (int i = index; i <= m_currentSize; ++i)
	{
		m_contents[i] = m_contents[i+1];
	}
	--m_currentSize;
	--m_maxSize;
}
int DynamicArray::getAt(unsigned int index)
{
	return m_contents[index];
}

void DynamicArray::resizeArray(unsigned int newMaxAmount)
{
	int* newArray = new int[newMaxAmount];

	for (int i = 0; i < newMaxAmount; i++)
	{
		newArray[i] = m_contents[i];
	}

	delete[] m_contents;
	m_contents = newArray;

	m_maxSize = newMaxAmount;
	if (m_currentSize > m_maxSize)
	{
		m_currentSize = m_maxSize;
	}
}

void DynamicArray::insertAt(unsigned int index, int value)
{
	int newMax = m_currentSize;
	if (isFull()) {
		newMax++;
		resizeArray(newMax);
		
	}
	for (int i = newMax; i > index; i--)
	{
		m_contents[i] = m_contents[i-1];
		}
	m_contents[index] = value;
	++m_currentSize;
}



int DynamicArray::getAmount() const
{
	return m_currentSize;
}

void DynamicArray::resizeArrayToFit()
{
	int max = m_currentSize;
	resizeArray(max);
}