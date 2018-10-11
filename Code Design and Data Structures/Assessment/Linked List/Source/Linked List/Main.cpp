#include "Linked List Node.h"
#include <iostream>
#include <random>
#include <ctime>

char key = 'r';

char menureturn()
{
	key = 0;
	bool returntoMenu = false;
	while (!returntoMenu)
	{
		std::cout << "Press R to return to top menu" << std::endl;
		std::cin >> key;
		if (key == 'r' || key == 'R')
		{
			returntoMenu = true;
			return key;
		}
		else
		{
			std::cout << "Invalid Entry" << std::endl;
		}

	}
}

char menu()
{
	system("cls");
	bool MadeChoice = false;
	while (!MadeChoice)
	{ 
		std::cout << "Press    I for int linked list demo,\n\t C for char linked list demo,\n\t S for QuickSort Demo\n\t B for Binary Search Demo\n\t Q to quit" << std::endl;
		std::cin >> key;
		if (key == 'I' || key == 'i' || key == 'C' || key == 'c' || key == 'Q' || key == 'q' || key == 's' || key=='S' || key=='b' || key == 'B' )
		{
			MadeChoice = true;
			return key;
		}
		else
		{
			std::cout << "Invalid entry!" << std::endl;
		}
	}

	return '\0';

}

char intlist_Demo()
{
	linkedList<int> list;
	system("cls");

	bool returntoMenu = false;

		std::cout << "Adding the numbers 1-5, using linkedList_pushBack function" << std::endl << std::endl;

		list.pushBack(1);
		list.pushBack(2);
		list.pushBack(3);
		list.pushBack(4);
		list.pushBack(5);
		list.print();

		std::cout << "Count the number of items" << std::endl << std::endl;
		int count = list.count();
		std::cout << count << std::endl <<  "--------------------------------------" << std::endl;
	
	
	
		std::cout << "Remove the first two numbers using linkedList_popFront function" << std::endl << std::endl;

		list.popFront();
		list.popFront();
		list.print();

		std::cout << "--------------------------------------" << std::endl;

		std::cout << "Added 1, 5, 2, 5, 3, 4, 3 & 5 using linkedList_pushFront function" << std::endl << std::endl;

		list.pushFront(1);
		list.pushFront(5);
		list.pushFront(2);
		list.pushFront(5);
		list.pushFront(3);
		list.pushFront(4);
		list.pushFront(3);
		list.pushFront(5);
		list.print();

		std::cout << "--------------------------------------" << std::endl;

		std::cout << "Removed last item using linkedList_popBack function" << std::endl << std::endl;

		list.popBack();
		list.print();
	

		std::cout << "--------------------------------------" << std::endl;

		std::cout << "The first number is: " << list.firstData() << std::endl << "The last number is: " << list.lastData() << std::endl <<std::endl;
		std::cout << "---------------------------------------" << std::endl << std::endl;

		std::cout << "Inserted number 28 at 5th index using linkedList_insertAt function" << std::endl << std::endl;
		list.insertAt(28, 5);
		list.print();
		std::cout << "---------------------------------------" << std::endl << std::endl;

		std::cout << "Removed all fives using the linkedList_remove function" << std::endl << std::endl;
		list.remove(5);
		list.print();

		std::cout << "---------------------------------------" << std::endl << std::endl;

		std::cout << "Removed item at the 4th position using the linkedList_removeAt function" << std::endl << std::endl;
		list.removeAt(4);
		list.print();

		std::cout << "---------------------------------------" << std::endl << std::endl;

		std::cout << "Clear list using linkedList_clear and replace with multiples of 11, using pushBack" << std::endl << std::endl;
		list.clear();
		list.pushBack(11);
		list.pushBack(22);
		list.pushBack(33);
		list.pushBack(44);
		list.pushBack(55);
		list.pushBack(66);
		list.pushBack(77);
		list.print();
	
		std::cout << "---------------------------------------" << std::endl << std::endl;


		std::cout << "The first iteration is: " << list.beginIter() << std::endl << "The last iteration is: " << list.endIter() << std::endl << std::endl;


		std::cout << "---------------------------------------" << std::endl << std::endl;


		return menureturn();
}

char charlist_Demo()
{
	linkedList<char> list;
	system("cls");
	bool returntoMenu = false;

	
		std::cout << "Adding the characters A, B, C, D, E, using linkedList_pushBack function" << std::endl << std::endl;

		list.pushBack('A');
		list.pushBack('B');
		list.pushBack('C');
		list.pushBack('D');
		list.pushBack('E');
		list.print();

		std::cout << "Count the number of items" << std::endl << std::endl;
		int count = list.count();
		std::cout << count << std::endl << "--------------------------------------" << std::endl;



		std::cout << "Remove the first two numbers using linkedList_popFront function" << std::endl << std::endl;

		list.popFront();
		list.popFront();
		list.print();

		std::cout << "--------------------------------------" << std::endl;

		std::cout << "Added A, G, A, T, H & A using linkedList_pushFront function" << std::endl << std::endl;

		list.pushFront('A');
		list.pushFront('G');
		list.pushFront('A');
		list.pushFront('T');
		list.pushFront('H');
		list.pushFront('A');
		list.print();

		std::cout << "--------------------------------------" << std::endl;

		std::cout << "Removed last item using linkedList_popBack function" << std::endl << std::endl;

		list.popBack();
		list.print();


		std::cout << "--------------------------------------" << std::endl;

		std::cout << "The first letter is: " << list.firstData() << std::endl << "The last letter is: " << list.lastData() << std::endl << std::endl;
		std::cout << "---------------------------------------" << std::endl << std::endl;

		std::cout << "Inserted letter V at 5th index using linkedList_insertAt function" << std::endl << std::endl;
		list.insertAt('V', 5);
		list.print();
		std::cout << "---------------------------------------" << std::endl << std::endl;

		std::cout << "Removed all A's using the linkedList_remove function" << std::endl << std::endl;
		list.remove('A');
		list.print();

		std::cout << "---------------------------------------" << std::endl << std::endl;

		std::cout << "Removed item at the 4th place using the linkedList_removeAt function" << std::endl << std::endl;
		list.removeAt(4);
		list.print();

		std::cout << "---------------------------------------" << std::endl << std::endl;

		std::cout << "Clear list using linkedList_clear and the top row symbols, using pushBack" << std::endl << std::endl;
		list.clear();
		list.pushBack('!');
		list.pushBack('@');
		list.pushBack('#');
		list.pushBack('$');
		list.pushBack('%');
		list.pushBack('^');
		list.pushBack('&');
		list.print();

		std::cout << "---------------------------------------" << std::endl << std::endl;


		std::cout << "The first iteration is: " << list.beginIter() << std::endl << "The last iteration is: " << list.endIter() << std::endl << std::endl;

		return menureturn();
}

char quickSort_Demo()
{
	linkedList<int> list;
	system("cls");

	bool returntoMenu = false;

	srand((unsigned int)time(nullptr));
	int random = (rand() % 100) + 1;

	int randomItems = 50;
	std::cout << randomItems <<" random numbers added by pushback" << std::endl;

	for (int i = 0; i < randomItems; i++)
	{
		int random = (rand() % 100) + 1;
		list.pushBack(random);
	}
	list.print();

	

	std::cout << "Sorted with Quicksort" << std::endl;

	list.QuickSort();
	list.print();

	return menureturn();

}

char binarySearch_Demo()
{
	linkedList<int> list;
	system("cls");

	bool returntoMenu = false;

	srand((unsigned int)time(nullptr));
	int random = (rand() % 100) + 1;

	int randomItems = 20;
	std::cout << randomItems << " random numbers added by pushback" << std::endl;

	for (int i = 0; i < randomItems; i++)
	{
		int random = (rand() % 100) + 1;
		list.pushBack(random);
	}


	bool doneSearching = false;
	while (!doneSearching)
	{
		
		list.print();
		int search = 0;
		std::cout << std::endl << "Enter a number to search for in list";
		std::cin >> search;
		list.binarySearch(search);

		char searchAnswer;
		std::cout << "Would you like to search again? Y/N";
		std::cin >> searchAnswer;
		if (searchAnswer == 'n' || searchAnswer == 'N')
		{
			doneSearching = true;
		}
		system("cls");
	}
	
	return menureturn();

}

int main() 
{
	bool demoOver = false;
	while (!demoOver)
	{
		if (key == 'I' || key == 'i')
		{
			key = intlist_Demo();
		}
		else if (key == 'C' || key == 'c')
		{
			key = charlist_Demo();
		}
		else if (key == 'R' || key == 'r')
		{
			key = menu();
		}
		else if (key == 'S' || key == 's')
		{
			key = quickSort_Demo();
		}
		else if (key == 'B' || key == 'b')
		{
			key = binarySearch_Demo();
		}
		else if (key == 'Q' || key == 'q')
		{
			demoOver = true;
		}
	}


}



