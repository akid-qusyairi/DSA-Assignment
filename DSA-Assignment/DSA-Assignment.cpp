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
			Login();
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
	//priority queue

	
}


void Login()
{
	int option;
	cout << "---------------- User Menu -------------------" << endl;
	cout << "[1] Create Account" << endl;
	cout << "[2] Existing Account" << endl;
	cin >> option;
	switch (option)
	{
	case 0:
		break;
	case 1:
		string name;
		int age;
		string email;
		string password;
		cout << "---------------- Create Account -------------------" << endl;
		cout << "Enter Name: " << endl;
		cin >> name;
		cout << "Enter Age: " << endl;
		cin >> age;
		cout << "Enter Email: " << endl;
		cin >> email;
		cout << "Enter Password: " << endl;
		cin >> password;
		Customer c(name, age, email, password);

	case 2:

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
