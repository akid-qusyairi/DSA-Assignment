#pragma once
#include <string>
#include<iostream>
//======================================//
//      Done By: Chua Jing Yi, Jax      //
//         StudentID: S10196708         //
//======================================//
using namespace std;
class Seat
{
private:
	int seatNo;
	string seatClass;
	double price;
	bool taken;
public:
	Seat();
	Seat(int SeatNo, string SeatClass,double P,bool t);

	void setSeatNo(int s);
	int getSeatNo();

	void setSeatClass(string s);
	string getSeatClass();

	void setPrice(double d);
	double getPrice();

	void setTaken(bool t);
	bool getTaken();

	void print();
};

