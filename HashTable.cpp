//HashTable.cpp
#include "HashTable.h"

// default constructor, sets size to 101
HashTable::HashTable()
{
	size = 101;
	table = new ListNode*[size];
	cout << "read hash size " << size;
	printf("\n");
	for(int i = 0; i < size; i++)
	{

		table[i] = NULL;
	}
}

//desctuctor
HashTable::~HashTable()
{
	delete [] table;
}

//returns the size of the hashTable
int HashTable::getSize()
{
	return size;
}

//inserts the passed number into the hash table using the 
//hash function (num mod tableSize)
bool HashTable::insert(int num)
{
	int index;
	bool duplicate = false;
	index = num % size;
	index = abs(index);
	ListNode *p = table[index];
	if(p == NULL)
	{
		table[index] = new ListNode(num, 0);
		cout << "insert " << num;
		printf("\n");
	}
	else
		 duplicate = collision(index, num);

	return duplicate;
}

//uses seperate chaining for collision resolution. 
//stores the values in a ListNode that has a pointer to the next node in the List.
bool HashTable::collision(int index, int num)
{
	bool duplicate = false;
	ListNode *node = table[index];
	ListNode *prevNode;
	while(node != NULL)
	{
		if(node->getNum() == num)
		{
			duplicate = true;
			break;
		}
		prevNode = node;
		node = node->getNextNode();
	}
		
	if(duplicate)
	{
		cout << "error_already_present " << num;
		printf("\n");
		return duplicate;
	}
	else
	{
		node = new ListNode(num, 0);
		node->setPrevNode(prevNode);
		prevNode->setNextNode(node);
		cout << "insert " << num;
		printf("\n");
		return duplicate;
	}
}

//returns the number indexed by the passed integer
ListNode* HashTable::index(int index)
{
	ListNode *p = table[index];
	return table[index];
}

//searches for the passed integer in the hashtable
void HashTable::lookup(int num)
{
	int index = num % size;
	index = abs(index);
	ListNode *p = table[index];
	bool found = false;

	while(p != NULL)
	{
		if(p->getNum() == num)
		{
			found = true;
			break;
		}
		p = p->getNextNode();
	}

	if(found)
	{
		cout << "find " << num ;
		printf("\n");
	}
	else
	{
		cout << "not_find " << num;
		printf("\n");
	}
}

//deletes the passed integer from the hash table if found.
int HashTable::del(int num)
{
	int index = num % size;
	index = abs(index);
	ListNode *p;
	p = table[index];
	ListNode *prevNode, *nextNode;
	bool found = false;
	int heapIndex = -1;

	//makes sure the indexed element in the hash table is not empty
	while(p != NULL)
	{
		if(p->getNum() == num)
		{
			//sets the previous's node's next node to the deleted node's next node
			//sets the next node's previous node to the deleted nodes previous node
			heapIndex = p->getHeapIndex();
			prevNode = p->getPrevNode();
			nextNode = p->getNextNode();
			if(prevNode != NULL)
				prevNode->setNextNode(nextNode);
			if(nextNode != NULL)
				nextNode->setPrevNode(prevNode);
			if(prevNode == NULL)
				table[index] = nextNode;
			delete p;
			found = true;
			break;
		}
		// moves on to the next node in the list
		p = p->getNextNode();
	}

	return heapIndex;
}

// changes the heap index the number is stored in the heap. used when we percolate up and down in the heap.
// this is neseccary to allow delete O(logn) instead of O(n). We can access the number in the heap directly 
// once we delete it from the hash table.
void HashTable::changeHeapIndex(int num, int newHeapIndex)
{
	int index = num % size;
	index = abs(index);
	ListNode *p = table[index];
	bool found = false;

	while(p != NULL)
	{
		if(p->getNum() == num)
		{
			found = true;
			break;
		}
		p = p->getNextNode();
	}

	if(p != NULL)
		p->setHeapIndex(newHeapIndex);
}


