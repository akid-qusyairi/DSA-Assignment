#include "Stack.h"
//======================================//
//      Done By: Chua Jing Yi, Jax      //
//         StudentID: S10196708         //
//======================================//
Stack::Stack() { topNode = NULL; }

Stack::~Stack()
{
	while (topNode != NULL)
	{
		pop();
	}
}


bool Stack::isEmpty() { return topNode == NULL; }

bool Stack::push(ItemType& item) {
	StackNode* newNode = new StackNode;
	newNode->item = item;
	newNode->next = topNode;
	if (!isEmpty()) {
		newNode->next = topNode;
	}
	topNode = newNode;
	return true;
}
bool Stack::pop() {
	if (!isEmpty()) {
		StackNode* tmp = topNode;
		if (topNode->next != NULL)
			topNode = topNode->next;
		else
			topNode = NULL;
		tmp = NULL;
		delete tmp;
	}
	return true;
}

bool Stack::pop(ItemType& item) {
	bool success = !isEmpty();
	if (success) {
		StackNode* tmp = topNode;
		topNode = topNode->next;
		item = tmp->item;
		tmp->next = NULL;
		delete tmp;
		tmp = NULL;
	}
	return true;
}

void Stack::getTop(ItemType& item) {
	if (!isEmpty()) { item = topNode->item; }
}

void Stack::displayInOrder() {
	ItemType item;
	Stack s;
	if (!isEmpty()) {
		while (!isEmpty()) {
			pop(item);
			s.push(item);
			item.preview();
		}
		while (!s.isEmpty()) {
			s.pop(item);
			push(item);
		}
	}
}

void Stack::displayInOrderOfInsertion() {
	ItemType item;
	Stack s;
	if (!isEmpty()) {
		while (!isEmpty()) {
			pop(item);
			s.push(item);
		}
		while (!s.isEmpty()) {
			s.getTop(item);
			item.preview();
			push(item);
			s.pop();
		}
	}
}

