#pragma once
#include <iostream>
#include <cassert>

//Templated struct, allows any type of data to be inputted into the linked list
template<typename T>
struct linkedListNode
{
	linkedListNode() = default;
	linkedListNode(const linkedListNode& other) = delete;

	T data;
	linkedListNode* nextAddress = nullptr; //Double Linked ie     PREV < - NODE - > NEXT
	linkedListNode* prevAddress = nullptr;
};


template<typename T>
class linkedList
{
public:
	//Prints out the results in list order
	void print()
	{
		{
			linkedListNode<T>* current = m_origin;
			int itemsOnLine = 0;
			while (current != nullptr) //Runs until it reaches the end of the list
			{
				
				std::cout << current->data << ", ";
				current = current->nextAddress;
				itemsOnLine++;										//increments a counter for each item
				
				if (itemsOnLine == 20) { std::cout << std::endl; }	//if the counter reaches 20, it starts on a new line, helps format data
			}
			std::cout << std::endl << "-------------------------------------" << std::endl;
		}
	}
	//Prints out results in reverse list order, useful for testing if prevAddress is working correctly.
	void rev_print()
	{
		{
			linkedListNode<T>* current = m_origin;
			while (current->nextAddress != nullptr)		//Iterates through list until it reaches the end.
			{
				current = current->nextAddress;
			}
			while (current != nullptr)					//Once at end: prints out final number, then moves back one item, repeats 
														//until entire list is printed.
			{
				std::cout << current->data << ", ";
				current = current->prevAddress;
			}
			std::cout << std::endl << "-------------------------------------" << std::endl;
		}
	}

	//Checks if the list is empty
	bool isEmpty()
	{
		if (m_origin == nullptr) //if m_origin (the first item) is absent, then the entire list is empty.
		{
			return true;
		}
		else //otherwise it has at least one element: it is not empty.
		{
			return false;
		}
	}

	//Adds a new node with "newdata" as its data (can be any type), at end of list
	void pushBack(T newdata) 
	{
		linkedListNode<T>* newNode = new linkedListNode<T>;		//Creates a new node
		newNode->data = newdata;								//with newdata
		newNode->nextAddress = nullptr;							//an empty next address (i.e. at the end of the list)

		if (isEmpty())	//If the list is empty, this becomes m_origin (aka the first item)
		{
			m_origin = newNode;
		}
		else													//Otherwise, we need to find wher to put it in the list
		{
			linkedListNode<T>* current = m_origin;				//Start at the first item
			while (current->nextAddress != nullptr)				//and iterate through the list until there are no more items
																//at the next address(ie arriving at the end of the list)
			{
				current = current->nextAddress;
			}
			current->nextAddress = newNode;						//Then connect the node: the original last item's next address is connected to
			newNode->prevAddress = current;						//NewNode, and NewNode's previous address points to the former last node.
		}
	}

	//Removes the last element of the list
	void popBack()
	{
		if (isEmpty()) //If the list is empty, no items can be removed, so response message is called.
		{
			std::cout << "No elements to remove!" << std::endl;
		}
		else										//The function runs properly when 1 or more items are available
		{
			linkedListNode<T>* current = m_origin;			//Start at the first item
			while (current->nextAddress != nullptr)			//Iterate through until we reach an item with no next item (i.e. end of list)
			{
				current = current->nextAddress;
			}
			current->prevAddress->nextAddress = nullptr;	//Go to the second last item, remove the connection to item for deletion
			delete current;									//Delete the node
		}

	}

	//Counts the number of elements in the list
	int count()
	{
		int counter = 0;							//Set counter to zero
		linkedListNode<T>* current = m_origin;		//Start at m_origin (first item)
		while (current != nullptr)					//While there is still elements in the list
		{
			current = current->nextAddress;			//Iterate through the list
			++counter;								//Adding 1 for every item in the list
		}
		return counter;								//Return the count
	}

	//Adds a new node with "newdata" (can be any type), to front of list
	void pushFront(T newdata)
	{
		linkedListNode<T>* newNode = new linkedListNode<T>;	//Make a new node, which is at 
		newNode->data = newdata;							//with "newdata"
												
	linkedListNode<T>* current = m_origin;					//Makes a reference to the original first item,
	m_origin = newNode;										//the newNode becomes the new first item

															//If the list is empty, the newNode is complete														
		if (!isEmpty())										//If not it gets connected up:
		{
			newNode->nextAddress = current;					//newNode's next item is the former first item
			current->prevAddress = newNode;					//and the former first's previous is the newNode
		}
	}

	//Removes the first element
	void popFront()
	{
		if (isEmpty())												//If the list is empty, there are no items to remove, so we just get an alert message
		{
			std::cout << "No elements to remove!" << std::endl;
		}
		else														//Otherwise,
		{
			linkedListNode<T>* newFirst = m_origin->nextAddress;	//Create pointer to the second item

			delete m_origin;										//Remove m_origin node (the first item)
			m_origin = newFirst;									//Set the m_origin (first item) to point to the second item
		}
		
	}

	//Returns the data variable of the first node (can be used with any data type)
	T firstData()
	{
		return m_origin->data;
	}
	//Returns the data variable of the last node (can be used with any data type)
	T lastData()
	{
		linkedListNode<T>* current = m_origin;		//Start with the first item
		while (current->nextAddress != nullptr)		//Iterate through list until there is no nextAddress (ie end of the list)
		{
			current = current->nextAddress;
		}
		return current->data;						//Return the data of the last node
	}

	//Returns the node struct at certain position (in index, ie first = 0, last = number of elements - 1)
	linkedListNode<T>& returnNodeAtIndex(int index)
	{
		linkedListNode<T>* current = m_origin;	//Start with the m_origin node (first item)
		for (int i = 0; i < index; ++i)			//Iterate through until the index number is reached
		{
			current = current->nextAddress;

		}
		return *current;						//Return the node
	}

	//Inserts a node with "newdata" (any data type) at a given index
	void insertAt(T newdata, int index)
	{
		linkedListNode<T>* newNode = new linkedListNode<T>;			//newNode is created
		newNode->data = newdata;									//newNode is assigned newdata

		linkedListNode<T>* current = m_origin;						//Start at m_origin (first) node
		for (int i = 1; i < index; ++i)								//Iterate until index location "current" is reached (node before insertion point)
		{
			current = current->nextAddress;
		}
		linkedListNode<T>* storeAddress = current->nextAddress;		//Stores a node after "current"			current <-> stored
		current->nextAddress = newNode;								//Connects "current" -> newNode		|
		newNode->nextAddress = storeAddress;						//Connects newNode -> "stored"		| -------------------------
		newNode->prevAddress = current;								//Connects "current" <- newNode		|
		storeAddress->prevAddress = newNode;						//Connects newNode <- "stored		|  current <-> new <-> stored

	}

	//Searches for "searchdata", and removes it where found
	void remove(T searchdata)
	{
		linkedListNode<T>* current = m_origin;							//Creates pointers for node being checked,
		linkedListNode<T>* previous = m_origin->prevAddress;			//and the node before it


		while (current != nullptr && current->nextAddress != nullptr)	//Iterate through while there is a current element, and one after it
		{
			if (current->data == searchdata)							//If the current node's data matches the search criteria:
			{
				if (previous == nullptr)								//If there is no previous (i.e. it is the first node)
				{
					popFront();											//Remove the first node, using popFront
					current = m_origin;									//Set "current" to the new first node.
				}
				else													//If this is not the first element
				{
					linkedListNode<T>* endLink = current->nextAddress;	//Store a node "Endlink" for the following node
					previous->nextAddress = endLink;					//Connect the nodes before and after the current
					endLink->prevAddress = previous;					// prev <-> current <-> endLink ==> prev <-> endLink
					delete current;										//delete the target node
					current = endLink;									//set "current" to the endLink
				}


			}
			else														//If the current data doesn't match the search data
			{
				previous = current;										//Increment the nodes one down the list
				current = current->nextAddress;

			}
		}
	}

	//Removes the node at indexed location
	void removeAt(int index)
	{
		{
			linkedListNode<T>* current = m_origin;					//Start at m_origin (first) node
			for (int i = 1; i < index; ++i)							//Iterate until index location "current" is reached (node before insertion point)
			{
				current = current->nextAddress;
			}

			linkedListNode<T>* startLink = current->prevAddress;		//Pointer to node before "current"
			linkedListNode<T>* endLink = current->nextAddress;			//Pointer to node after "current"
			startLink->nextAddress = endLink;							//Connects nodes before and after "current"
			endLink->prevAddress = startLink;							//start <-> current <-> end ==> start <-> end
			delete current;												//Deletes the target node
		}
	}

	//Clears the list
	void clear()
	{
		linkedListNode<T>* current = m_origin;					//Start at m_origin (first) node 
		while (current != nullptr)								//Iterates while current is present in list (iterates through entire list)
		{
			linkedListNode<T>* next = current->nextAddress;		//Gets pointer to second node
			popFront();											//Removes first node 
			current = next;										//Moves current to second node
		}
	}

	//Returns first iterator
	int beginIter()
	{
		return 0;
	}

	//Returns last iterator
	int endIter()
	{
		return count();
	}

	//Swaps locations of two nodes
	void swap(linkedListNode<T>& data1, linkedListNode<T>& data2)
	{
		assert(data2.nextAddress != &data1 && "Wrong order of nodes!");		//Makes sure the nodes are not already in the right order
				

		
		auto firstPrev = data1.prevAddress;									//Stores before and after nodes
		auto firstNext = data1.nextAddress;

		auto secondPrev = data2.prevAddress;
		auto secondNext = data2.nextAddress;
				

		
		if(data1.nextAddress != &data2)										//If data points are next to each other
		{
				data1.prevAddress = secondPrev;								//Sets data2's connections, to connect with data1 node
				data1.nextAddress = secondNext;

				data2.prevAddress = firstPrev;								//and vice versa
				data2.nextAddress = firstNext;

				if (firstPrev) firstPrev->nextAddress = &data2;				//If they aren't null pointers, sets the data1's prev and
				if (firstNext) firstNext->prevAddress = &data2;				//next address to point to data2

				if (secondPrev) secondPrev->nextAddress = &data1;			//and vice versa
				if (secondNext) secondNext->prevAddress = &data1;

		}
		else																//Otherwise if they are consecutive d1, d2 => d2,d1
		{
			data1.prevAddress = &data2;										//data1's prev points to data2
			data1.nextAddress = secondNext;									//data1's next points to data2
			if (data1.prevAddress) data1.prevAddress->nextAddress = &data1;	//if data1 has a prev, point that prev back to data1
			if (secondNext) secondNext->prevAddress = &data1;				//if data2 has a next, point it back to data1

			data2.prevAddress = firstPrev;									//	D1PREV <-> D1 <-> D2 <-> D2NEXT
			data2.nextAddress = &data1;										//_______________________________________________
			if (firstPrev) firstPrev->nextAddress = &data2;					//
			if (data2.nextAddress) data2.nextAddress->prevAddress = &data2;	//	D2NEXT <-> D1 <-> D2 <-> D1PREV

		}

	

		if (m_origin == &data1) { m_origin = &data2; }						//If one of the nodes is the first, swap the m_origin tag
		else if (m_origin == &data2) { m_origin = &data1; }

	}

	//Sorts the list in ascending order
	void QuickSort()
	{
		int pivot = beginIter();				//First iterator
		int upperMarker = endIter() - 1;		//Last iterator
		QSRecursive(pivot, upperMarker);		//Calls QSRecursive using the iterator
	}

	//Recursive function calling Partition with smaller and smaller parameters
	void QSRecursive(int lower, int upper)
	{
		if (lower < upper)						//If the lower value is lower than upper (rather than equal)
		{
			int q = QSPartition(lower, upper);	//Gets a midpoint, based on partition function
			QSRecursive(lower, q - 1);			//Calls the recursive function, making partition with smaller and smaller section of list
			QSRecursive(q, upper);
		}
	}

	int QSPartition(int lower, int upper)
	{	int pivot = returnNodeAtIndex(lower).data;										//Sets pivot, number which nodes are sorted into "higher" and "lower" around
		int lowerMarker = lower + 1;													//Sets the lowerMarker to the second node
		int upperMarker = upper;														//Sets the upperMarker to the last node
		linkedListNode<T>* current = &(returnNodeAtIndex(lowerMarker));					//Sets pointer to "current" the element being compared to pivot
		if (lowerMarker < upperMarker)													//Lower marker should be smaller than uppermarker for most of function
			{
				
				while (upperMarker != lowerMarker)										//while upper and lowerMarkers don't point to same node
				{

					if (current->data > pivot)											//If current data is more than pivot (for ascending list, use < for descending)
					{
						int store_upp = upperMarker;									//Store the iterators for the upper and lower markers
						int store_low = lowerMarker;
						linkedListNode<T>& swapWith = returnNodeAtIndex(upperMarker);	//Store the upper marker node
						swap(*current, swapWith);										//and swap it will current
						upperMarker = store_upp - 1;									//Then reset the markers, upperMarker shifts down one
						lowerMarker = store_low;										//lowermarker stays the same

						current = &(returnNodeAtIndex(lowerMarker));					//Set current to the lower marker

					}
					else																//If not (i.e. data is the same or less than pivot)
					{		
						lowerMarker++;													//Move lowerMarker up one
						linkedListNode<T>* next = current->nextAddress;					//Set a pointer to the next node
						current = next;													//Then set current to the next node
					}
				}
				linkedListNode<T>& pivot = returnNodeAtIndex(lower);					//After running through the nodes, store the pivot node
				linkedListNode<T>& swapwith = returnNodeAtIndex(lowerMarker);			//and the lower/upper marker
				if (pivot.data > swapwith.data) {swap(pivot , swapwith);}				//Swap if pivot is bigger
								/*Generally pivot will be bigger than the swapwith, but may not be the case at end of running the function
								for example if called on two elements, this ensure the pair end up in the correct order*/
				
			}
		else //In the case where upper and lower are the same (i.e. only two elements are called)
		{
			linkedListNode<T>* prevNode = current->prevAddress;							//Store previous node
			if (current->data < prevNode->data)											//if current is smaller than previous
			{
				swap(*prevNode, *current);												//swap elements
			}
		}
		return lowerMarker;								//returns iterator of lower marker, used in Recursive to divide list into smaller pieces
	}

	//Uses binary search to find target data
	void binarySearch(T target)
	{
		
		bool isSorted = true;										//First, check to make sure the list is sorted:
		linkedListNode<T>* current = m_origin;						//Start at the first node
		while (current->nextAddress != nullptr)						//Iterate through the list
		{
			linkedListNode<T>* next = current->nextAddress;			//Get the next node
			if (current->data > next->data)							//and compare the two accordingly (For use with ascending list)
			{
				isSorted = false;									//if any node is out of place, it is not sorted, the while loop ends
				break;												//so the sort check ends
			}
			current = next;											//used to push through the check
		}
			if (!isSorted)											//If not sorted
			{
				QuickSort();										//Do a quick sort,
				binarySearch(target);								//Then restart the binary search
			}
			else													//If sorted, we start the search
			{
				int min = beginIter();								//Store the numbers for the min max iterators
				int max = endIter()-1;
				bool complete = false;
				while (!complete)									//Loop through until a complete criteria is met
				{
						T mindata = returnNodeAtIndex(min).data;	//Get the data from min and max
						T maxdata = returnNodeAtIndex(max).data;
						/*If the target is less than the min or higher than the max, it mustn't be in the list,
						the search returns a negative response*/
					if (target < mindata || target > maxdata)		
						{
							std::cout << target << " has not been found"<<std::endl;
							complete = true;
						}
					/*Since both mindata and maxdata are data point in the list, if it matches the target, the search returns a
					positive result, and checks for additional instances of the target*/
					else if (target == mindata)					
						{
							std::cout << target << " has been found" << std::endl;
							if (binSearch_copycheck(min))			//If we find another instance of the value, print the following response:
							{
								std::cout << "Multiple instance of search item found" << std::endl;
							}
							complete = true;
						}
					else if (target == maxdata)
					{
						std::cout << target << " has been found" << std::endl;
						if (binSearch_copycheck(max))				//If we find another instance of the value, print the following response:
						{
							std::cout << "Multiple instance of search item found" << std::endl;
						}
						complete = true;
					}
						else												//Otherwise we run the search
						{
							int guess = (min + max) / 2;					//Find the midpoint of the min & max iterators
							T guessData = returnNodeAtIndex(guess).data;	//Get the data from the midpoint
							if (guessData > target)							//If the guess is too high:
							{
								max = guess -1;								//Set the new max to point to the next value in the list
							}
							else if (guessData < target)					//If the guess is too low:
							{
								min = guess +1;								//Set the new min to poin to the previous value on the list
							}
							else if (guessData == target)					//If the guess matches, print a positive result
							{
								std::cout << target << " has been found" << std::endl; 
								if (binSearch_copycheck(guess))				//And check for muiltiple instances
								{
									std::cout << "Multiple instance of search item found" << std::endl;
								}
								complete = true;
							}
					}
					
				}

			}

			
		}

	//Checks for additional values matching the target value
	bool binSearch_copycheck(int it)
	{
		linkedListNode<T>* targetNode = &returnNodeAtIndex(it);		//Stores pointer to node, based on iterator value
		T targetdata = targetNode->data;							//Gets data from pointer
		T prevdata = 0;												//Intialiser
		T nextdata = 0;

		if (targetNode->prevAddress != nullptr)					{ prevdata = targetNode->prevAddress->data; }	//gets data from previous node, if it exists
		if (targetNode->nextAddress != nullptr)					{ nextdata = targetNode->nextAddress->data; }	//gets data from next node, if it exists

		/*The binary search only functions using a linkedList, so duplicate values, if they exist, will appear consecutively.
		So in order to locate duplicates, just inspect the neighbour nodes data.*/
		if (targetdata == prevdata || targetdata == nextdata)	{ return true; }								
		else													{ return false; }
	}


	private:
		linkedListNode<T>* m_origin = nullptr;

	
};