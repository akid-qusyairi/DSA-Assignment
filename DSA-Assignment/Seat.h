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
	//Constructor
	Seat();
	Seat(int SeatNo, string SeatClass,double P,bool t);

	//set seatNo to input, returns seatNo
	void setSeatNo(int s);
	int getSeatNo();

	//set seatClass to input, returns seatClass
	void setSeatClass(string s);
	string getSeatClass();

	//set price to input, returns price
	void setPrice(double d);
	double getPrice();

	//set taken to input, returns taken
	void setTaken(bool t);
	bool getTaken();

	//Display seat details
	void print();
};

