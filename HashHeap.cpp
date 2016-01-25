//HashHeap.cpp
#include "HashHeap.h"
#include <sstream>
#include <fstream>


//runs through the input file
void HashHeap::run()
{
    string line;
	int i = 0;
    while (!cin.eof()) 
	{
		getline(cin, line);
		//makes sure it's not the first line or the line isn't emtpty
        if (!line.empty() && i != 0)
			executeCommands(line);
		
		i++;
	}
}

//parses the command from a string and runs the appropriate method
void HashHeap::executeCommands(string str)
{
	int result;
	vector<int> command;

	//finds the index of the comma and seperates it accordingly
	int comma = (int)str.find(",");
	if(comma == -1)
	{
		stringstream convert4(str);
		convert4 >> result;
		if(!convert4.fail())
			command.push_back(result);
	}
	else 
	{
		stringstream convert2(str.substr(0, comma));
		convert2 >> result;

		if(!convert2.fail())
			command.push_back(result);

		stringstream convert3(str.substr(comma + 1));
		convert3 >> result;

		if(!convert3.fail())
			command.push_back(result);
	}
	//runs the command according to the first number in the vector
	if(command[0] == 0)
		insert(command[1]);
	else if(command[0] == 1)
		lookup(command[1]);
	else if(command[0] == 2)
		deleteMin();
	else if(command[0] == 3)
		del(command[1]);
	else if(command[0] == 4)
		print();
}

//runs the lookup method for the hashtable
void HashHeap::lookup(int num)
{
	hashTable.lookup(num);
}

//inserts the number into the hashtable and the heap
void HashHeap::insert(int num)
{
	bool duplicate;
	HashTable *p = &hashTable;
	duplicate = hashTable.insert(num);
	if(!duplicate)
		heap.insert(num, p);
}

//deletes the minimum value in the heap and also deletes it from the hashtable
void HashHeap::deleteMin()
{
	if(heap.getSize() >= 1)
	{
		HashTable *p = &hashTable;
		int num = heap.deleteMin(p);
		hashTable.del(num);
		cout << "deleteMin " << num;
		printf("\n");
	}
	else
	{
		cout << "error_structure_is_empty";
		printf("\n");
	}
}

//deletes the passed number from the hash table and then the heap
void HashHeap::del(int num)
{
	HashTable *p = &hashTable;
	int index = hashTable.del(num);
	if(index >= 0)
	{
		heap.del(index, p);
		cout << "delete " << num;
		printf("\n");
	}
	else
	{
		cout << "error_not_find " << num;
		printf("\n");
	}
}

//prints out the numbers in order by calling deleteMin on the heap until it is empty.
void HashHeap::print()
{
	HashTable *p = &hashTable;
	cout << "print ";
	while(heap.getSize() > 0)
	{
		cout << heap.deleteMin(p);
		if(heap.getSize() > 0)
			cout << ",";
	}
}