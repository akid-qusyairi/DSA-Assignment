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
	//constructor
	Booking() {}

	Booking(string Origin,string Dest,string Name, string Email, List<Passenger> P,double tP) {
		origin = Origin;
		destination = Dest;
		name = Name;
		email = Email;
		pList = P;
		totalPrice = tP;
	}

	//set name to input, returns name
	void setName(string n) { name = n; }
	string getName() { return name; }

	//set email to input, returns email
	void setEmail(string e) { email = e; }
	string getEmail() { return email; }

	//set origin to input, returns origin
	void setOrigin(string o) { origin = o; }
	string getOrigin() { return origin; }

	//set destination to input, returns destination
	void setDestination(string d) { destination = d; }
	string getDestination() { return destination; }

	//set pList to input, returns pList
	void setList(List<Passenger> p) {
		pList = p;
	}
	List<Passenger> getList() {
		return pList;
	}

	//set totalPrice to input, returns totalPrice
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

