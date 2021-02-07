#include "Seat.h"
//======================================//
//      Done By: Chua Jing Yi, Jax      //
//         StudentID: S10196708         //
//======================================//
Seat::Seat() {}

Seat::Seat(int SeatNo, string SeatClass,double P,bool t)
{
	seatNo = SeatNo;
	seatClass = SeatClass;
	price = P;
	taken = t;
}

//set seatNo to input
void Seat::setSeatNo(int n) { seatNo = n; }

//returns seatNo
int Seat::getSeatNo() { return seatNo; }

//set seatClass to input
void Seat::setSeatClass(string c) { seatClass = c; }

//returns seatClass
string Seat::getSeatClass() { return seatClass; }

//set price to input
void Seat::setPrice(double d) { price = d; }

//returns price
double Seat::getPrice() { return price; }

//set taken to input
void Seat::setTaken(bool t) { taken = t; }

//returns taken
bool Seat::getTaken() { return taken; }

//prints the seat
void Seat::print() {
	cout << "Seat No.: " << seatNo << endl << "Class: " << seatClass << endl;
	cout << "------------" << endl;
}