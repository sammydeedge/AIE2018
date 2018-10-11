#include "Dynamic Array.h"
#include <iostream>

struct Foo
{
	int a;
	float b;
};

int main()
{
	const size_t array_size = 25;
	TDynamicArray<int> m_intArray;
	m_intArray.resizeArray(array_size);

	std::cout << "Numbers added to array using pushback" << std::endl;
	m_intArray.pushBack(5);
	m_intArray.pushBack(7);
	m_intArray.pushBack(24);
	m_intArray.pushBack(3);
	m_intArray.pushBack(8);
	m_intArray.printArray();
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "2 Popbacks" << std::endl;
	m_intArray.popBack();
	m_intArray.popBack();
	m_intArray.printArray();
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "5 Numbers added by Pushback" << std::endl;
	m_intArray.pushBack(17);
	m_intArray.pushBack(6);
	m_intArray.pushBack(11);
	m_intArray.pushBack(365);
	m_intArray.pushBack(111);
	m_intArray.printArray();
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "5 inserted at 5th index, 7 inserted at 7th index" << std::endl;
	m_intArray.insertAt(5,5);
	m_intArray.insertAt(7, 7);
	m_intArray.printArray();
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Remove at 0th index" << std::endl;
	m_intArray.removeAt(0);
	m_intArray.printArray();
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Remove at 3rd index" << std::endl;
	m_intArray.removeAt(3);
	m_intArray.printArray();
	std::cout << "-------------------------------------" << std::endl;

	std::cin.get();
}