#pragma once
#include <list>
#include<string>
#include<cassert>

template<typename T>
unsigned int calculateHash(const T& value)
{
	int hash = 0;
	assert(false && "No hash function for theis type");

	return hash;
}

//Creates a unique hash value for the items in the list
static unsigned int calculateHash(const char* data, unsigned int size_t = 0)
{
	int hash = 0;

	for (unsigned int i = 0; i < size_t; ++i)	//for every item in the list
	{
		hash = (hash * 1313) + data[i];			//Assign hash value using this formula
	}

	hash = hash & 0x7FFFFFFF;
	return hash;
}

template<int Size, typename KeyType, typename ValueType>
class hash_map
{
private:
	//Items have a 'key' and a 'value' paired together
	struct pair
	{
		KeyType key;
		ValueType value;
	};	
	//These paired items form into a list
	std::list <pair> m_data[Size];
public:


	pair p;
	
	//Adds pair to list
	void add(KeyType key, ValueType value)
	{
		unsigned int hash = calculateHash(key);		//Gets unique hash value
		hash = hash % Size;							//Changes hash value to fit within list
		p.key = key;								//Assign key & value data
		p.value = value;
		m_data[hash].push_back(p);					//Use push_back to put data point onto list
	}

	//Print out list
	void print()
	{
		for (int i = 0; i < Size; ++i)													//Iterate through list
		{
			for (auto it = m_data[i].begin();it != m_data[i].end();++it)				
			{
				std::cout << "(" << it->key << ", " << it->value << ")" << std::endl;	//Printing it out
			}
			
		}
		std::cout << std::endl << "----------------------------------------------------" << std::endl;
	}

	//Removes items with a target key
	void remove_byKey(KeyType key)
	{
		for (int i = 0; i < Size; ++i)											//Iterates through list
		{
			for (auto it = m_data[i].begin(); it != m_data[i].end(); ++it)
			{
				if (it->key == key)												//If the key matches the search data:
				{
					m_data[i].erase(it);										//Erase the point
					break;														//And end process
				}
			}
			
		}
	}

	//Removes items based on their value
	void remove_byValue(ValueType value)
	{
		for (int i = 0; i < Size; ++i)										//Iterates through list
		{
			for (auto it = m_data[i].begin(); it != m_data[i].end(); ++it)
			{
				if (it->value == value)										//If the value matches the search data:
				{
					m_data[i].erase(it);									//Erase the point
					break;													//And end process
				}
			}
		}
	}

	//Clears out the list
	void clear()
	{
		for (int i = 0; i < Size; ++i)										//Iterate through the list
		{
			for (auto it = m_data[i].begin(); it != m_data[i].end(); ++it)
			{
				if (it->value != 0)											//If value is not 0 (ie there is value data at that location:
				{
					m_data[i].erase(it);									//Erase the point
					break;													//And end process
				}
			}
		}
	}

	//Returns Key that matches with value search data
	KeyType get_KeyfromValue(ValueType value)
	{
		bool foundMatch = false;											
		for (int i = 0; i < Size; ++i)										//Iterates through list
		{
			for (auto it = m_data[i].begin(); it != m_data[i].end(); ++it)
			{
				if (it->value == value)										//If value matches an item:
				{
					return it->key;											//Return the corresponding key
					foundMatch = true;										//match has been found
					break;													//and the process ends
				}
			}
		}
		/*If the list is iterated through and no match is found, return a negative response*/
		if (!foundMatch) { std::cout << "No value match, no key returned" << std::endl; }
	}

	//Returns Value that matches with key search data
	ValueType get_ValuefromKey(KeyType key)
	{
		bool foundMatch = false;
		for (int i = 0; i < Size; ++i)									//Iterates through list
		{
			for (auto it = m_data[i].begin(); it != m_data[i].end(); ++it)
			{
				if (it->key == key)										//If key data matches the search data:
				{
					return it->value;									//Return the corresponding value
					foundMatch = true;									//match has been found
					break;												//End process
				}
			}

		}
		/*If the list is iterated through and no match is found, return a negative response*/
		if (!foundMatch) { std::cout << "No key match, no value returned" << std::endl; }
	}
	
};


template<>
unsigned int calculateHash(const std::string& value)
{
	return calculateHash(value.data(), value.size());
}

template<>
unsigned int calculateHash(const int& value)
{
	return calculateHash(value);
}