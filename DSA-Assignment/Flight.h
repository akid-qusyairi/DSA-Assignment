#pragma once
#include "Booking.h"
#include "List.h"
#include <time.h>
#include "Seat.h"
#include "PriorityQueue.h"
class Flight
{
private:
	string origin;
	string dest;
	Queue<Booking> bList;
	List<Seat> sList;
public:
	Flight() {}

	Flight(string O, string D, List<Booking> b, List<Seat> s) {
		origin = O;
		dest = D;
		bList = b;
		sList = s;
	}

	void setOrigin(string O) { origin = O; }
	string getOrigin() { return origin; }

	void setDest(string O) { origin = O; }
	string getDest() { return origin; }

	void preview() {
		cout << "---------------------Seats---------------------" << endl;
		int count = 0;
		for (int i = 0; i < sList.getLength(); i++) {
			Seat s = sList.get(i);
			string taken = "";
			if (s.getTaken() == true) {
				taken = "[X]";
			}
			char sClass;
			if (s.getSeatClass() == "First") {
				sClass = 'F';
			}
			else if (s.getSeatClass() == "Business") {
				sClass = 'B';
			}
			else if (s.getSeatClass() == "Economy") {
				sClass = 'E';
			}

			cout << s.getSeatNo() << sClass << taken << "\t";
			if (count == 5) {
				count = 0;
				cout << endl << "---------------------------------------------" << endl;
			}
			else {
				count++;
			}
		}
		
	}

	void print() {
		cout << "Origin: " << origin << " | Destination: " << dest << endl;
		double Fp, Bp, Ep;
		int size = sList.getLength();
		for (int i = 0; i < sList.getLength(); i++) {
			Seat s = sList.get(i);
			if (s.getTaken() == true) {
				size--;
			}
			if (s.getSeatClass() == "First") {
				Fp = s.getPrice();
			}
			else if (s.getSeatClass() == "Business") {
				Bp = s.getPrice();
			}
			else if (s.getSeatClass() == "Economy") {
				Ep = s.getPrice();
			}
		}
		cout << "First Class: " << Fp << " | Business Class: " << Bp << " | Economy Class: " << Ep << endl;
		cout << "Seats left: " << size << endl;
	}
};

