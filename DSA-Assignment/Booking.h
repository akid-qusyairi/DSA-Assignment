#pragma once
#include "Passenger.h"
#include "List.h"
//======================================//
//      Done By: Chua Jing Yi, Jax      //
//         StudentID: S10196708         //
//======================================//
class Booking
{
private:
	string origin;
	string destination;
	string name;
	string email;
	List<Passenger> pList;
	double totalPrice;
public:
	Booking() {}

	Booking(string Origin,string Dest,string Name, string Email, List<Passenger> P,double tP) {
		origin = Origin;
		destination = Dest;
		name = Name;
		email = Email;
		pList = P;
		totalPrice = tP;
	}

	void setName(string n) { name = n; }
	string getName() { return name; }

	void setEmail(string e) { email = e; }
	string getEmail() { return email; }

	void setOrigin(string o) { origin = o; }
	string getOrigin() { return origin; }

	void setDestination(string d) { destination = d; }
	string getDestination() { return destination; }

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

	void preview() {
		cout << "Origin: " << origin << " | Destination: " << destination << " | Total Seats: " << pList.getLength() << " | Total Price: " << totalPrice<< endl;
		cout << "Passengers" <<endl<< "================" << endl;
		for (int i = 0; i < pList.getLength(); i++) {
			Passenger p = pList.get(i);
			p.print();
		}
	}
};

