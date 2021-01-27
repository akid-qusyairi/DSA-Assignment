// pointerDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "List.h"
#include "Booking.h"
#include "Passenger.h"
#include "PriorityQueue.h"
#include "Seat.h"
#include "Tree.h"
#include <iostream>
#include "Flight.h"
#include "Stack.h"
#include "Customer.h"

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
		cout << "[1] Login" << endl;
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
			break;
		default:
			cout << "---------------- User Menu -------------------" << endl;
			cout << "[1] View Flights" << endl;
			cout << "[2] Book a flight" << endl;
			cout << "----------------------------------------------" << endl;
			cout << "Enter your option : ";
			cin >> opt;
			break;
		}
	}
}

void admin(int opt, Tree t, List<Flight>& fList) {
	{
		while (opt != 0) {
			cout << "---------------- Admin Menu ------------------" << endl;
			cout << "[1] View Flight Paths" << endl;
			cout << "[2] Create New Flights" << endl;
			cout << "[0] Exit" << endl;
			cout << "----------------------------------------------" << endl;
			cout << "Enter your option : ";
			cin >> opt;
			switch (opt)
			{
			case 0:

				break;
			case 1: {
				cout << endl << "--------Displaying current flight path--------" << endl;
				t.traverseTree();
				cout << endl;
				int opt1 = -1;
				while (opt1 != 2) {
					cout << "---------------- Add New Paths? --------------" << endl;
					cout << "[1] Yes" << endl;
					cout << "[2] No" << endl;
					cout << "----------------------------------------------" << endl;
					cout << "Enter your option : ";
					cin >> opt1;
					switch (opt1)
					{
					case 1: {
						string originC;
						string destC;
						cout << "----------------------------------------------" << endl;
						cout << "Enter Origin Country: ";
						cin >> originC;
						TreeNode* root = t.getTop();
						TreeNode* Origin = t.search(originC);
						cout << "Enter Destination Country: ";
						cin >> destC;
						if (Origin != NULL) {
							t.insertchild(Origin->leftChild, destC);
							cout << "Added Flight Path [" << originC << " -> " << destC << "]" << endl;
						}
						else {
							t.insertsibling(root, originC);
							cout << "Added Flight Path [" << originC << " -> " << destC << "]" << endl;
						}
						cout << "----------------------------------------------" << endl;
						opt1 = 2;
						break;
					}
					case 2: {
						opt1 = 2;
						break;
					}
					default: {
						cout << "---------------- Add New Paths? --------------" << endl;
						cout << "[1] Yes" << endl;
						cout << "[2] No" << endl;
						cout << "----------------------------------------------" << endl;
						cout << "Enter your option : ";
						cin >> opt1;
						break;
					}
					}
				}
				break;
			}
			case 2: {
				cout <<endl<< "-------Displaying Exisiting Flight Paths------" << endl;
				t.traverseTree();
				cout << endl;
				string originC;
				string destC;
				cout << "----------------------------------------------" << endl;
				cout << "Enter Origin Country: ";
				cin >> originC;
				cout << "Enter Destination Country: ";
				cin >> destC;
				cout << endl;
				TreeNode* Origin = t.search(originC);
				if (Origin != NULL) {
					if (t.searchSibling(Origin->leftChild, destC) != NULL) {
						int F, B, E;
						double Fp, Bp, Ep;
						cout << "Enter Number of First Class Seats: ";
						cin >> F;
						cout << "Enter Price of First Class Seats: ";
						cin >> Fp;
						cout << endl;
						cout << "Enter Number of Business Class Seats: ";
						cin >> B;
						cout << "Enter Price of Business Class Seats: ";
						cin >> Bp;
						cout << endl;
						cout << "Enter Number of Economy Class Seats: ";
						cin >> E;
						cout << "Enter Price of Economy Class Seats: ";
						cin >> Ep;
						List<Seat> seat;
						for (int i = 0; i < F; i++) {
							Seat s = Seat(i + 1, "First", Fp, false);
							seat.add(s);
						}
						int len = seat.getLength();
						for (int i = len; i < len + B; i++) {
							Seat s = Seat(i + 1, "Business", Bp, false);
							seat.add(s);
						}
						len = seat.getLength();
						for (int i = len; i < len + E; i++) {
							Seat s = Seat(i + 1, "Economy", Ep, false);
							seat.add(s);
						}
						List<Booking> bList;
						Flight newFlight = Flight(originC, destC, bList, seat);
						cout << endl << "-----------------------------------------------" << endl;
						cout << "New flight created" << endl;
						cout << "-----------------------------------------------" << endl;
						newFlight.print();
						fList.add(newFlight);
						cout << "-----------------------------------------------" << endl;
					}
					else {
						cout << "No such flight path available" << endl;
					}
				}
				else {
					cout << "No such flight path available" << endl;
				}
				break;
			}
			default:
				cout << "---------------- Admin Menu -------------------" << endl;
				cout << "[1] View Flight Paths" << endl;
				cout << "[2] Create New Flights" << endl;
				cout << "[0] Exit" << endl;
				cout << "----------------------------------------------" << endl;
				cout << "Enter your option : ";
				cin >> opt;
				break;
			}
		}
	}
}

int main()
{
	//testing queue

	Queue q;
	q.enqueue("Ten", 10);
	q.enqueue("One", 1);
	q.enqueue("Highest", 15);
	q.enqueue("Four", 4);
	q.enqueue("Five", 5);
	q.enqueue("Two", 2);
	q.displayItems();
	cout << endl;
	string item;
	q.getTop(item);
	cout << item << endl;

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
