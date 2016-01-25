//HashTable.h
#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>
#include <stdio.h>

#include "ListNode.h"
using namespace std;

// A hash table that stores pointers to ListNode objects
class HashTable
{
private:
	int size;
	ListNode **table;
public:
	HashTable();
	int getSize();
	~HashTable();
	bool insert(int num);
	bool collision(int index, int num);
	ListNode* index(int i);
	void lookup(int num);
	int del(int num);
	void changeHeapIndex(int num, int newHeapIndex);
};

#endif