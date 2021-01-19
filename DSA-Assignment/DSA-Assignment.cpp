// pointerDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "List.h"
#include "Customer.h"
#include "Passenger.h"
#include "PriorityQueue.h"
#include "Seat.h"
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
