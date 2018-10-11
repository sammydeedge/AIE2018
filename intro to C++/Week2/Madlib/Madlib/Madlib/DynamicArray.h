#pragma once

class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	int getAmount() const;
	bool isFull() const;

	int randomIndex();
	int removeIndex();

private:
	int m_currentSize = 0;
	int m_maxSize;
	int* m_contents;
};