#include "PriorityQueue.h"
#include <string>
using namespace std;
//======================================//
//    Done By: Muhamad Akid Qusyairi    //
//         StudentID: S10194941         //
//======================================//

// constructor
Queue::Queue() { frontNode = NULL; backNode = NULL; maxPriority = Booking(); };

Queue::~Queue() {};


bool Queue::enqueue(ItemType item,int priority) {
	Node* newNode = new Node;
	newNode->item = item;
	newNode->priority = priority;
	newNode->next = NULL;
	if (isEmpty()) {
		frontNode = newNode;
		backNode = newNode;
		maxPriority = item;
	}
	else {
		if (priority > frontNode->priority) {
			newNode->next = frontNode;
			frontNode = newNode;
			maxPriority = item;
		}
		else {
			Node* tmp = frontNode;
			while (tmp->next != NULL && tmp->next->priority >= priority) {
				tmp = tmp->next;
			}
			newNode->next = tmp->next;
			tmp->next = newNode;
		}
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
bool Queue::dequeue(ItemType& item, int& priority) {
	if (isEmpty()) {
		cout << "Queue is empty." << endl;
		return true;
	}
	Node* temp = frontNode;
	item = frontNode->item;
	priority = frontNode->priority;
	frontNode = frontNode->next;
	free(temp);
	return true;
};
void Queue::getFront(ItemType& item) {
	if (frontNode != NULL) { item = frontNode->item; }
};
void Queue::getTop(ItemType& item) {
	item = maxPriority;
};
bool Queue::isEmpty() {
	bool empty = (frontNode == NULL || backNode == NULL);
	return empty;
};
void Queue::displayItems() {
	ItemType item;
	int priority;
	Queue q;
	while (!isEmpty()) {
		dequeue(item,priority);
		q.enqueue(item, priority);
	}
	int count = 0;
	while (!q.isEmpty()) {
		q.dequeue(item, priority);
		count++;
		cout << "============" << endl;
		cout << "Booking " << count << endl;
		List<Passenger> p = item.getList();
		for (int i = 0; i < p.getLength(); i++) {
			Passenger pass = p.get(i);
			pass.print();
		}
		enqueue(item, priority);
	}
	cout << endl;
};