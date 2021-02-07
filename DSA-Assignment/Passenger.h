#pragma once
// Passenger.h - Definition of Passenger class

#include<string>
#include "Seat.h"
#include<iostream>
//======================================//
//    Done By: Muhamad Akid Qusyairi    //
//         StudentID: S10194941         //
//======================================//
using namespace std;

class Passenger
{
private:
	string name;
	int age;
	int priority;
	Seat seat;
public:
	Passenger() {}

	Passenger(string Name, int Age, int Priority, Seat Seat)
	{
		name = Name;
		age = Age;
		priority = Priority;
		seat = Seat;
	}

	void setName(string n) { name = n; }
	string getName() { return name; }

	void setAge(int a) { age = a; }
	int getAge() { return age; }

	void setPriority(int p) {
		priority = p;
	}
	int getPriority() {
		return priority;
	}
	void setSeat(Seat s) {
		seat = s;
	}
	Seat getSeat() {
		return seat;
	}
	void print() {
		cout << "Name: " << getName() << endl;
		cout << "Age: " << getAge() << endl;
		getSeat().print();
	}
};