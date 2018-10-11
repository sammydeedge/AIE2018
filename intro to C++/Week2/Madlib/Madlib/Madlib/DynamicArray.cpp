#include"DynamicArray.h"

DynamicArray::DynamicArray()
{
	m_maxSize = 10;
	m_contents = new int[m_maxSize];
}

DynamicArray::~DynamicArray()
{
	delete[] m_contents;
}

void DynamicArray::resizeArrayToFit()
{
	int* newArray
}