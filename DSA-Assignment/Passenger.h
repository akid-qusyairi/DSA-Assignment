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
	//constructor
	Passenger() {}

	Passenger(string Name, int Age, int Priority, Seat Seat)
	{
		name = Name;
		age = Age;
		priority = Priority;
		seat = Seat;
	}

	//set name to input, returns name
	void setName(string n) { name = n; }
	string getName() { return name; }

	//set age to input, returns age
	void setAge(int a) { age = a; }
	int getAge() { return age; }

	//set priority to input, returns priority
	void setPriority(int p) {
		priority = p;
	}
	int getPriority() {
		return priority;
	}

	//set seat to input, returns seat
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