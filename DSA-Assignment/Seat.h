#pragma once
#include <string>
#include<iostream>
using namespace std;
class Seat
{
private:
	int seatNo;
	string seatClass;
public:
	Seat();
	Seat(int SeatNo, string SeatClass);

	void setSeatNo(int s);
	int getSeatNo();

	void setSeatClass(string s);
	string getSeatClass();

	void print();
};

