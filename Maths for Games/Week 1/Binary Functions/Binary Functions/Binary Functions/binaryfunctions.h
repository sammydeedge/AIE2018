#pragma once

class binaryValue
{
public:
	binaryValue();
	binaryValue(char value);

	bool isLeftMostBitSet();
	bool isRightMostBitSet();
	bool isBitSet();



private:
	char m_value;
};