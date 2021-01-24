#include "Seat.h"

Seat::Seat() {}

Seat::Seat(int SeatNo, string SeatClass,double P,bool t)
{
	seatNo = SeatNo;
	seatClass = SeatClass;
	price = P;
	taken = t;
}

void Seat::setSeatNo(int n) { seatNo = n; }
int Seat::getSeatNo() { return seatNo; }

void Seat::setSeatClass(string c) { seatClass = c; }
string Seat::getSeatClass() { return seatClass; }

void Seat::setPrice(double d) { price = d; }
double Seat::getPrice() { return price; }

void Seat::setTaken(bool t) { taken = t; }
bool Seat::getTaken() { return taken; }

void Seat::print() {
	cout << "Seat No.: " << seatNo << endl << "Class: " << seatClass << endl;
	cout << "------------" << endl;
}