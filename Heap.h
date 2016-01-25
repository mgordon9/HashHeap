//heap.h
#ifndef _HEAP_H
#define _HEAP_H
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include "HashTable.h"
#include <stdio.h>
using namespace std;

// a heap data structure stored in a vector using array representaion.
class Heap
{
private:
	std::vector<int> heap;
	void percolateUp(int index, HashTable*);
	void percolateDown(int index, HashTable*);
public:
	Heap();
	std::vector<int> getHeap();
	int deleteMin(HashTable*);
	int del(int index, HashTable*);
	void insert(int num, HashTable*);
	int index(int i);
	int getSize();
};
#endif