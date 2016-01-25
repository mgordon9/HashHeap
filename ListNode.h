//ListNode.h
#pragma once

#ifndef _LISTNODE_H
#define _LISTNODE_H
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

// Used to store the number and heap index in a List 
// format for seperate chaining resolution.
class ListNode
{
private:
	int num;
	int heapIndex;
	ListNode *nextNode;
	ListNode *prevNode;
public:
	ListNode* getNextNode();
	ListNode* getPrevNode();
	ListNode();
	ListNode(int num, int newHeapIndex);
	bool compare(int compareNum);
	int getNum();
	int getHeapIndex();
	void setHeapIndex(int newHeapIndex);
	void setNextNode(ListNode* newNextNode);
	void setPrevNode(ListNode* newPrevNode);
};

#endif