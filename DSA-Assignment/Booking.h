#pragma once
#include "Passenger.h"
#include "List.h"
class Booking
{
private:
	string name;
	string email;
	List<Passenger> pList;
	double totalPrice;
public:
	Booking() {}

	Booking(string Name, string Email, List<Passenger> P) {
		name = Name;
		email = Email;
		pList = P;
	}

	void setName(string n) { name = n; }
	string getName() { return name; }

	void setEmail(string e) { email = e; }
	string getEmail() { return email; }

	void setList(List<Passenger> p) {
		pList = p;
	}
	List<Passenger> getList() {
		return pList;
	}
	void setPrice(double d) { totalPrice = d; }
	double getPrice() { return totalPrice; }

	void print() {
		cout << "ContactName: " << name << endl;
		cout << "ContactEmail: " << email << endl;
		cout << "Total Price: " << totalPrice << endl;
		cout << "-----Passengers-----" << endl;
		pList.print();
	}
};

