#include <iostream>


bool isLeftMostBitSet(unsigned int value)
{
	int iteratorNo = -1;
	for (char it = 1; it < value; it *= 2)
	{
		iteratorNo++;
	}
	char compare = 1 << iteratorNo;
	if (value & compare)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isRightMostBitSet(unsigned int value)
{
	char compare = 1;
	if (value & compare)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool isBitSetAt(unsigned int value, unsigned char checkBit)
{
	char compare = 1 << checkBit-1;
	if (value & compare)
	{
		return true;
	}
	else
	{
		return false;
	}
}

char printBoolResult(bool result)
{
	if (result) 
	{
		return 'T';
	}
	else
	{
		return 'F';
	}
}
//int getRightmostSetBit(unsigned int value)
//{
//	int iteratorNo = 0;
//	for (char it = 1; it < value; it *= 2)
//	{
//		iteratorNo++;
//	}
//	for (checkBit; checkBit < )
//	char compare = 1 << checkBit;
//	if (value & compare)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}


void main()
{
	int value = 0;
	std::cout << "Enter a value: ";
		std::cin >> value;

		std::cout << "Left bit is set: " << printBoolResult(isLeftMostBitSet(value)) << std::endl;
		std::cout << "Right bit is set: " << printBoolResult(isRightMostBitSet(value)) << std::endl;
		std::cout << "3rd bit is set: " << printBoolResult(isBitSetAt(value,3)) << std::endl;

		system("pause");
}