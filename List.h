#pragma once
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>

using namespace std;

class List {
private:
	typedef struct node {
		string data;
		node* next;
		node* previous;

	}*nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;
	nodePtr tail;

public:
	List();
	void listAppendNode(string addData);
	void listPrependNode(string addData);
	void listInsertAfter(string index, string addData);
	void listRemoveNode(string delData);
	void listTraverse();
	void listTraverseReverse();
};


#endif // !List_H