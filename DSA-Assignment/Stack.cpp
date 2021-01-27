#include "Stack.h"

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
		topNode = topNode->next;
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
	if (!isEmpty()) {
		while (!isEmpty()) {
			getTop(item);
			item.preview();
			pop();
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

