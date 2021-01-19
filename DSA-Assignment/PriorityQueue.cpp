#include "PriorityQueue.h"
using namespace std;
// constructor
Queue::Queue() { frontNode = NULL; backNode = NULL; };

Queue::~Queue() {};

bool Queue::enqueue(ItemType item) {
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;
	if (isEmpty()) {
		frontNode = newNode;
		backNode = newNode;
	}
	else {
		backNode->next = newNode;
		backNode = newNode;
	}
	return true;
};
bool Queue::dequeue() {

	if (frontNode == backNode) {
		frontNode = NULL;
		backNode = NULL;
	}
	else {
		Node* temp = frontNode;
		frontNode = temp->next;
		free(temp);
	}
	return true;
};
bool Queue::dequeue(ItemType& item) {
	if (isEmpty()) {
		cout << "Queue is empty." << endl;
		return true;
	}
	Node* temp = frontNode;
	item = frontNode->item;
	frontNode = frontNode->next;
	free(temp);
	return true;
};
void Queue::getFront(ItemType& item) {
	if (frontNode != NULL) { item = frontNode->item; }
};
bool Queue::isEmpty() {
	bool empty = (frontNode == NULL || backNode == NULL);
	return empty;
};
void Queue::displayItems() {
	ItemType item;
	Queue q;
	while (!isEmpty()) {
		dequeue(item);
		q.enqueue(item);
	}
	while (!q.isEmpty()) {
		q.dequeue(item);
		cout << item << endl;
		enqueue(item);
	}
};