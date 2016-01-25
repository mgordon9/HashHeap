//HashHeap.h
#pragma once

#ifndef _HASHHEAP_H
#define _HASHHEAP_H

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

#include "Heap.h"
#include "HashTable.h"


using namespace std;

//The data structure that implements 
//insert O(logn)
//delete O(logn)
//deleteMin O(logn)
//lookup O(1)
class HashHeap
{
private:
	HashTable hashTable;
	Heap heap;
	vector<string> input;
public:
	HashHeap() : hashTable(), heap() {}
	void run();
	void lookup(int num);
	void insert(int num);
	void deleteMin();
	void del(int num);
	void print();
	void executeCommands(string str);
	void testPrint();
};

#endif