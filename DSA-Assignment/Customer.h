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
	//constructor
	Customer() {}

	Customer(string n, string e, string p, string pN) {
		name = n;
		email = e;
		password = p;
		phoneNo = pN;
	}
	//set name to input, returns name
	void setName(string n) { name = n; }
	string getName() { return name; }

	//set email to input, returns email
	void setEmail(string e) { email = e; }
	string getEmail() { return email; }

	//set password to input, returns password
	void setPass(string p) { password = p; }
	string getPass() { return password; }

	//set phoneNo to input, returns phoneNo
	void setPhone(string pN) { phoneNo = pN; }
	string getPhone() { return phoneNo; }

	//set bookingList to input, returns bookingList
	void setStack(Stack S) { bookingList = S; }
	Stack getStack() { return bookingList; }
};