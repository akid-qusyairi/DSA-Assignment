#pragma once
// Passenger.h - Definition of Passenger class

#include<string>
#include "Customer.h"
#include "Seat.h"
#include<iostream>
using namespace std;

class Passenger : public Customer
{
private:
	int priority;
	Seat seat;
public:
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
};