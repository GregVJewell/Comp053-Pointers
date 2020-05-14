#include<iostream>
#include<string>

#include "List.h"

using namespace std;

List::List() {
	head = NULL;
	curr = NULL;
	temp = NULL;
	tail = NULL;
}
void List::listAppendNode(string addData) {
	nodePtr newNode = new node;
	newNode->next = NULL;
	newNode->previous = NULL;
	newNode->data = addData;

	if (head != NULL) {
		curr = head;
		while (curr->next != NULL) {
			temp = curr;
			curr = curr->next;
		}
		curr->next = newNode;
		temp = curr;
		curr = curr->next;
		curr->previous = temp;
		tail = newNode;
	}
	else {
		head = newNode;
		tail = newNode;
	}
}
void List::listPrependNode(string addData) {
	nodePtr newNode = new node;
	newNode->next = NULL;
	newNode->previous = NULL;
	newNode->data = addData;

	if (head != NULL) {
		curr = head;
		while (curr->previous != NULL) {
			temp = curr;
			curr = curr->previous;
		}
		curr->previous = newNode;
		temp = curr;
		curr = curr->previous;
		curr->next = temp;
		head = newNode;
	}
	else {
		head = newNode;
		tail = newNode;
	}
}
void List::listInsertAfter(string index, string addData) {
	nodePtr newNode = new node;
	newNode->data = addData;
	temp = head;
	curr = head;

	while (curr->next != NULL && curr->data != newNode->data) {
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		cout << "Data was not found!" << endl;
		delete newNode;
	}
	else {
			curr->previous = newNode;
			newNode->next = curr;
			curr = temp;
			newNode->previous = curr;
			curr->next = newNode;
	}
}
void List::listRemoveNode(string delData) {
	nodePtr delPtr = NULL;
	temp = head;
	curr = head;

	while (curr != NULL && curr->data != delData) {
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		cout << "Data was not found!" << endl;
		delete delPtr;
	}
	else {
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		if (delPtr == head) {
			head = head->next;
			temp = NULL;
		}
		delete delPtr;
		cout << delData << " was deleted" << endl;
	}
}
void List::listTraverse() {
	curr = head;

	if (curr == NULL) {
		cout << "The list is empty" << endl;
	}
	else {
		while (curr != NULL) {
			cout << curr->data << endl;
			curr = curr->next;
		}
	}
}
void List::listTraverseReverse() {
	curr = tail;

	if (curr == NULL) {
		cout << "The list is empty" << endl;
	}
	else {
		while (curr != NULL) {
			cout << curr->data << endl;
			curr = curr->previous;
		}
	}
}