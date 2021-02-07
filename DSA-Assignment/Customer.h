#pragma once
#include <string>
#include <iostream>
#include "Stack.h"
using namespace std;
//======================================//
//      Done By: Chua Jing Yi, Jax      //
//         StudentID: S10196708         //
//======================================//
class Customer
{
private:
	string name;
	string email;
	string password;
	string phoneNo;
	Stack bookingList;
public:
	Customer() {}

	Customer(string n, string e, string p, string pN) {
		name = n;
		email = e;
		password = p;
		phoneNo = pN;
	}
	void setName(string n) { name = n; }
	string getName() { return name; }

	void setEmail(string e) { email = e; }
	string getEmail() { return email; }

	void setPass(string p) { password = p; }
	string getPass() { return password; }

	void setPhone(string pN) { phoneNo = pN; }
	string getPhone() { return phoneNo; }

	void setStack(Stack S) { bookingList = S; }
	Stack getStack() { return bookingList; }
};