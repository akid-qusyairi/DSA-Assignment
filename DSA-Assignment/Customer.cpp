// Customer.cpp - Implementation of Customer class
#include "Customer.h"

Customer::Customer() {}

Customer::Customer(string n, int a, string e, string p)
{
	name = n;
	age = a;
	email = e;
	password = p;
}

void Customer::setName(string n) { name = n; }
string Customer::getName() { return name; }

void   Customer::setAge(int a) { age = a; }
int Customer::getAge() { return age; }

void Customer::setEmail(string e) { email = e; }
string Customer::getEmail() { return email; }

void Customer::setPassword(string p) { password = p; }
string Customer::getPassword() { return password; }

void Customer::print(){ cout << "Name: " << name << " | Age: " << age << " | Email: " << email << " | Password: " << password  << endl; }