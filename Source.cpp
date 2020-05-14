#include<iostream>
#include<string>

#include "List.h"

using namespace std;

int main() {
	List chores;

	chores.listAppendNode("Brush Teeth");
	chores.listAppendNode("Wash Face");
	chores.listAppendNode("Eat Breakfast");
	chores.listAppendNode("Go to school");
	chores.listPrependNode("wakeup");
	chores.listTraverse();
	chores.listInsertAfter("Wash Face", "Make Bed");
	cout << "------------------------" << endl;
	chores.listTraverseReverse();

	char exit;
	cin >> exit;

	return 0;
}