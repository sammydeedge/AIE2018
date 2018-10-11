#include "DynamicArray.h"

int main()
{

	{
		DynamicArray arr; //pirate array
		for (int i = 0; i < 15; ++i)
		{
			arr.pushBack(i);
		}
		arr.popBack();
		arr.insertAt(5, 28);
		arr.insertAt(10, 7);
		arr.getAt(11);
		arr.removeAt(13);
		arr.resizeArrayToFit();
	}

	return 0;
}

