// pointerDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "List.h"
#include "Customer.h"
#include "Passenger.h"
#include "PriorityQueue.h"
#include "Seat.h"
#include "Tree.h"
#include <iostream>

using namespace std;
void user(int opt) {


	//Testing prints
	List<Seat> test;
	Seat a = Seat(1, "Business");
	test.add(a);
	test.print();
	List<Customer> cList;
	Customer c = Customer("Jax", 100, "test@gmail.com", "password");
	cList.add(c);
	cList.print();


	while (opt != 0) {
		cout << "---------------- User Menu -------------------" << endl;
		cout << "[1] View Flights" << endl;
		cout << "[2] Book a flight" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Enter your option : ";
		cin >> opt;
		switch (opt)
		{
		case 0:
			break;
		case 1:

		case 2:

		default:
			cout << "---------------- User Menu -------------------" << endl;
			cout << "[1] View Flights" << endl;
			cout << "[2] Book a flight" << endl;
			cout << "----------------------------------------------" << endl;
			cout << "Enter your option : ";
			cin >> opt;
		}
	}
}


int main()
{
	Tree t;
	t.insertsibling("Singapore");
	t.insertsibling("Japan");
	t.insertsibling("Malaysia");
	TreeNode* root = t.getTop();
	TreeNode* tree = t.search(root,"Japan");
	t.insertchild(tree->leftChild, "Thailand");
	TreeNode* temp = t.search(root, "Thailand");
	t.insertchild(root->leftChild, "USA");
	t.insertchild(root->leftChild, "Indonesia");
	TreeNode* bottom = t.search(root, "Indonesia");
	t.insertchild(bottom->leftChild, "Vietnam");
	t.traverseTree();
	cout << endl << endl;

	//testing queue

	Queue q;
	cout << endl;

	List<Passenger> p1;
	List<Passenger> p2;
	List<Seat> seat;
	for (int i = 0; i < 10; i++) {
		Seat s = Seat(i + 1, "First");
		seat.add(s);
		cout << s.getSeatNo()<<" | "<< s.getSeatClass() << endl;
	}
	int len = seat.getLength();
	for (int i = len; i < len + 10; i++) {
		Seat s = Seat(i + 1, "Business");
		cout << s.getSeatNo() << " | " << s.getSeatClass() << endl;
		seat.add(s);
	}

	Passenger a = Passenger();

    int opt = 1;
	while (opt != 0)
	{
		cout << "---------------- Main Menu -------------------" << endl;
		cout << "[1] User" << endl;
		cout << "[2] Admin" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Enter your option : ";
		cin >> opt;
		switch (opt)
		{
		case 0:
			break;
		case 1:
			user(-1);
		case 2:

		default:
			cout << "---------------- Main Menu -------------------" << endl;
			cout << "[1] User" << endl;
			cout << "[2] Admin" << endl;
			cout << "----------------------------------------------" << endl;
			cout << "Enter your option : ";
			cin >> opt;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
