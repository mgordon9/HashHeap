//ListNode.cpp
#include "ListNode.h"

//default ctor
ListNode::ListNode()
{
	num = 0;
	heapIndex = 0;
	nextNode = NULL;
	prevNode = NULL;
}

//2 param ctor
ListNode::ListNode(int newNum, int newHeapIndex)
{
	heapIndex = newHeapIndex;
	num = newNum;
	nextNode = NULL;
	prevNode = NULL;
}

//sets the heap index varible to a new value.
void ListNode::setHeapIndex(int newHeapIndex)
{
	heapIndex = newHeapIndex;
}

//returns a pointer to the next node in the list
ListNode* ListNode::getNextNode()
{
	return nextNode;
}

//returns a pointer to the previous node in the list
ListNode* ListNode::getPrevNode()
{
	return prevNode;
}

//returns the heap index value
int ListNode::getHeapIndex()
{
	return heapIndex;
}

//returns the number stored in this node
int ListNode::getNum()
{
	return num;
}

//sets the next node in the list to the passed pointer
void ListNode::setNextNode(ListNode* newNextNode)
{
	nextNode = newNextNode;
}

//sets the previous node in the list to the passed pointer
void ListNode::setPrevNode(ListNode* newPrevNode)
{
	prevNode = newPrevNode;
}

