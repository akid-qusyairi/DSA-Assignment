// List.h - - Specification of List ADT (implemented using Pointers)
#pragma once
#include<string>
#include<iostream>
#include  "Seat.h"
using namespace std;
//======================================//
//    Done By: Muhamad Akid Qusyairi    //
//         StudentID: S10194941         //
//======================================//
template <class T>

class List
{
private:
	struct Node
	{
		T item;	// item
		Node* next;	// pointer pointing to next item
	};
	Node* firstNode;	// point to the first item
	int  size;		// number of items in the list

public:
	// constructor
	List() { size = 0; }


	// add an item to the back of the list (append)
	bool add(T item) {
		Node* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;
		if (isEmpty())
			firstNode = newNode;
		else
		{
			Node* tmp = firstNode;
			while (tmp->next != NULL) {
				tmp = tmp->next;
			}
			tmp->next = newNode;
		}
		size++;
		return true;
	}

	// add an item at a specified position in the list (insert)
	bool add(int index, T item){
		if (index <= size && index >= 0)
		{
			Node* newNode = new Node;
			newNode->item = item;
			newNode->next = NULL;
			if (index == 0)
			{
				newNode->next = firstNode;
				firstNode = newNode;
			}
			else
			{
				Node* tmp = firstNode;
				for (int i = 1; i <= index - 1; i++)
				{
					tmp = tmp->next;
				}
				newNode->next = tmp->next;
				tmp->next = newNode;
			}
			size++;
			return true;
		}
		else
			return false;
	}

	// remove an item at a specified position in the list
	void remove(int index) {
		if (index <= size && index >= 0)
		{
			Node* tmp = firstNode;
			if (index == 0)
			{
				firstNode = tmp->next;
			}
			else
			{
				Node* prev = NULL;
				for (int i = 1; i <= index; i++)
				{
					prev = tmp;
					tmp = tmp->next;
				}
				tmp = prev->next;
				prev->next = tmp->next;
			}
			delete tmp;
			tmp = NULL;
			size--;
		}
	}

	// get an item at a specified position of the list (retrieve)
	T get(int index) {
		Node* tmp = firstNode;
		if (index <= size && index >= 0) {
			for (int i = 0; i < index; i++)
			{
				tmp = tmp->next;
			}
			return tmp->item;
		}
	}
	void updateItem(int index, T item) {
		Node* tmp = firstNode;
		if (index <= size && index >= 0) {
			for (int i = 0; i < index; i++)
			{
				tmp = tmp->next;
			}
			tmp->item = item;
		}
	}
	// check if the list is empty
	bool isEmpty() { return size == 0; }

	// check the size of the list
	int getLength() { return size; }

	// display all the items in the list
	void print() {
		Node* tmp = firstNode;
		T item;
		for (int i = 0; i < size; i++) {
			cout << "----------------------------------------------" << endl;
			cout << "[Option " << i + 1 << "]" << endl;
			item = tmp->item;
			item.print();
			tmp = tmp->next;
		}
	}
};