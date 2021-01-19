#pragma once
// Customer.h - Definition of Customer class

#include<string>
#include<iostream>
using namespace std;

class Customer
{
private:
	string name;
	int age; // the i-th minute Customer joins queue.
	string email;
	string password;

public:
	Customer();
	Customer(string n, int a, string e, string p);

	void setName(string n);
	string getName();

	void setAge(int a);
	int getAge();

	void setEmail(string e);
	string getEmail();

	void setPassword(string p);
	string getPassword();

	void print();
};