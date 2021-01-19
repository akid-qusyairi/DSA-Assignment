#include "Seat.h"

Seat::Seat() {}

Seat::Seat(int SeatNo, string SeatClass)
{
	seatNo = SeatNo;
	seatClass = SeatClass;
}

void Seat::setSeatNo(int n) { seatNo = n; }
int Seat::getSeatNo() { return seatNo; }

void Seat::setSeatClass(string c) { seatClass = c; }
string Seat::getSeatClass() { return seatClass; }

void Seat::print() {
	cout << "Seat No.: " << seatNo << " | Class: " << seatClass << endl;
}