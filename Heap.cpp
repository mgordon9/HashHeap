//Heap.cpp
#include "Heap.h"

//default ctor
Heap::Heap()
{
	heap = vector<int>();
}

//returns the vector tat stores the heap
vector<int> Heap::getHeap()
{
	return heap;
}

//inserts the passed integer into the heap and percolates up as neseccary.
void Heap::insert(int num, HashTable* ht)
{
	heap.push_back(num);
	int index = heap.size() - 1;
	ht->changeHeapIndex(heap[index], index);
	percolateUp(index, ht);
}

// basic percolate up procedure
void Heap::percolateUp(int index, HashTable* ht)
{
	if(index != 0  && heap[(index - 1) / 2] > heap[index])
	{
		int temp = heap[index];
		heap[index] = heap[(index - 1) / 2];
		heap[(index - 1) / 2] = temp;

		ht->changeHeapIndex(heap[(index - 1) / 2], (index - 1) / 2);
		ht->changeHeapIndex(heap[index], index);

		percolateUp((index - 1) / 2, ht);
	}
}

//deletes the minimum value (at index 0) and re adjusts the heap to keep it still a heap.
int Heap::deleteMin(HashTable* ht)
{
	return del(0, ht);
}

//deletes a the number expressed by the passed index and percolates the heap accordingly.
int Heap::del(int index, HashTable* ht)
{
	int deletedValue = 0;
	if(index >= 0)
	{
		deletedValue = heap[index];
		int temp = heap[heap.size() - 1];
		heap[index] = temp;
		heap.pop_back();
		if(heap.size() > 0)
		{
			if(index < (int)heap.size())
			{
				//changes the index stored in the hashtable to the new index that the number is now, in the heap.
				ht->changeHeapIndex(heap[index], index);
				percolateUp(index, ht);
				percolateDown(index, ht);
			}
		}
	}

	return deletedValue;
}

// basic percolate down procedure.
void Heap::percolateDown(int index, HashTable* ht)
{
	if(index * 2 + 1 <= (int)heap.size() - 1)
	{
		int child1, child2, smallerChild, smallerChildIndex;
		child1 = heap[index * 2 + 1];
		if(index * 2 + 2 <= (int)heap.size() - 1)
		{
			child2 = heap[index * 2 + 2];

			if(child1 < child2)
			{
				smallerChild = child1;
				smallerChildIndex = index * 2 + 1;
			}
			else
			{
				smallerChild = child2;
				smallerChildIndex = index * 2 + 2;
			}
		}
		else
		{
			smallerChild = child1;
			smallerChildIndex = index * 2 + 1;
		}

		if(heap[index] > smallerChild)
		{
			int temp = heap[index];
			heap[index] = heap[smallerChildIndex];
			heap[smallerChildIndex] = temp;

			ht->changeHeapIndex(heap[index], index);
			ht->changeHeapIndex(heap[smallerChildIndex], smallerChildIndex);

			percolateDown(smallerChildIndex, ht);
		}
	}
}


int Heap::index(int i)
{
	return heap[i];
}

int Heap::getSize()
{
	return heap.size();
}
