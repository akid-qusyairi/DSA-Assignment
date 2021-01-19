// Queue.h - Specification of Queue ADT (Pointer-based)
#pragma once
#include<string>
#include<iostream>
#include "Passenger.h"

typedef string ItemType;
struct Node
{
	ItemType item;	// item
	int priority;
	Node* next;	// pointer pointing to next item
};
class Queue
{
private:

	ItemType maxPriority;
	Node* frontNode;	// point to the first item
	Node* backNode;	// point to the first item


public:
	// constructor
	Queue();

	~Queue();

	// enqueue (add) item at the back of queue
	bool enqueue(ItemType item,int priority);

	// dequeue (remove) item from front of queue
	bool dequeue();

	// dequeue (remove) and retrieve item from front of queue
	bool dequeue(ItemType& item, int& priority);

	// retrieve (get) item from front of queue
	void getFront(ItemType& item);

	// check if the queue is empty
	bool isEmpty();

	void getTop(ItemType& item);
	// display items in queue from front to back
	void displayItems();
};
