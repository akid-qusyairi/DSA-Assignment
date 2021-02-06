
#include <iostream>
#include "List.h"
#include "Booking.h"
#include "Passenger.h"
#include "PriorityQueue.h"
#include "Seat.h"
#include "Tree.h"
#include "Flight.h"
#include "Stack.h"
#include "Customer.h"

using namespace std;

int logIn(List<Customer> cList) {
	cout << "----------------------- Log In -------------------" << endl;
	string email, password;
	cout << "Enter email: " ;
	cin >> email;
	cout << "Enter password: ";
	cin >> password;
	for (int i=0; i < cList.getLength(); i++) {
		Customer c = cList.get(i);
		if (c.getEmail() == email && c.getPass() == password) {
			return i;
			break;
		}
	}
	return -1;
}
void custMenu(int opt, List<Flight> flightList, int custIndex, List<Customer> cList, List<Passenger> pList) {
	while (opt != 0)
	{
		cout << "---------------- Customer Menu ---------------" << endl;
		cout << "[1] View Booked flights" << endl;
		cout << "[2] Book Flight" << endl;
		cout << "[0] Exit" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Enter your option : ";
		cin >> opt;
		switch (opt)
		{
		case 0:
			break;
		case 1: {
			cout << "---------------- Past Bookings ---------------" << endl;
			Customer c = cList.get(custIndex);
			Stack pastB = c.getStack();
			pastB.displayInOrder();
			break;
		}
		case 2: {
			string sClass;
			int sNo;
			string name;
			int option;
			int passengers;
			int priority;
			int age;
			int highestPrio = 0;
			cout << "----------------- Flight List --------------------" << endl;
			List<Flight> bookingFlights;
			int fOptions = 1;
			for (int i = 0; i < flightList.getLength(); i++) {
				Flight f = flightList.get(i);
				if (f.getStatus() == "Scheduled") {
					cout << "----------------------------------------------" << endl;
					cout << "[Option " << fOptions << "]" << endl;
					f.print();
					bookingFlights.add(f);
					fOptions++;
				}
			}
			cout << "----------------- Book Flight --------------------" << endl;
			cout << "Enter Flight Option : ";
			cin >> option;
			Flight chosen = bookingFlights.get(option - 1);
			cout << "---------------- Flight Chosen -------------------" << endl;
			chosen.print();
			cout << "--------------- Available Seats ------------------" << endl;
			chosen.preview();
			cout << "Enter Number of Passengers : ";
			cin >> passengers;
			cout << "Enter Seat Class (First, Business, Economy) : ";
			cin >> sClass;
			List<Seat> sList = chosen.getSList();
			if (sClass == "First")
			{
				priority = 4;
			}
			else if (sClass == "Business")
			{
				priority = 2;
			}
			else
			{
				priority = 0;
			}
			double totalP = 0;
			for (int x = 0; x<passengers; x++)
			{
				int curr_prior = priority;
				cout << "Enter Name : ";
				cin >> name;
				cout << "Enter Seat No. : ";
				cin >> sNo;
				cout << "Enter Age : ";
				cin >> age;
				if (age < 12 || age > 65)
				{
					curr_prior += 2;
				}
				else
				{
					curr_prior += 1;
				}

				Seat s = sList.get(sNo - 1);
				s.setTaken(true);
				totalP += s.getPrice();
				sList.updateItem(sNo - 1, s);
				Passenger p(name, age, curr_prior, s);
				pList.add(p);
				if (highestPrio < curr_prior)
				{
					highestPrio = curr_prior;
				}
				else
				{
					break;
				}
			}
			cout << "Contact Name: " << cList.get(custIndex).getName() << endl;
			cout << "Contact Email: " << cList.get(custIndex).getEmail() << endl;
			Booking b(chosen.getOrigin(), chosen.getDest(), cList.get(custIndex).getName(), cList.get(custIndex).getEmail(), pList, totalP);
			Queue q = chosen.getQueue();
			q.enqueue(b, highestPrio);
			chosen.setQueue(q);
			flightList.updateItem(option - 1, chosen);
			Customer c = cList.get(custIndex);
			Stack s = c.getStack();
			s.push(b);
			c.setStack(s);
			cList.updateItem(custIndex, c);
		}
		default:
			cout << "---------------- Main Menu -------------------" << endl;
			cout << "[1] View Booked flights" << endl;
			cout << "[2] Book Flight" << endl;
			cout << "[0] Exit" << endl;
			cout << "----------------------------------------------" << endl;
			cout << "Enter your option : ";
			cin >> opt;
		}
	}
}
void guestMenu(int opt, List<Flight> flightList, List<Passenger> pList) {
	string sClass;
	int sNo;
	string name;
	string gName;
	string email;
	int option;
	int passengers;
	int priority;
	int age;
	int highestPrio = 0;
	cout << "----------------- Guest Details --------------------" << endl;
	cout << "Enter Name : ";
	cin >> gName;
	cout << "Enter Email : ";
	cin >> email;
	cout << "----------------- Flight List --------------------" << endl;
	for (int i = 0; i < flightList.getLength(); i++) {
		Flight f = flightList.get(i);
		if (f.getStatus() == "Scheduled") {
			cout << "----------------------------------------------" << endl;
			cout << "[Option " << i+1 << "]" << endl;
			f.print();
		}
	}
	cout << "----------------- Book Flight --------------------" << endl;
	cout << "Enter Flight Option : ";
	cin >> option;
	Flight chosen = flightList.get(option - 1);
	cout << "---------------- Flight Chosen -------------------" << endl;
	chosen.print();
	cout << "--------------- Available Seats ------------------" << endl;
	chosen.preview();
	cout << "Enter Number of Passengers : ";
	cin >> passengers;
	cout << "Enter Seat Class (First, Business, Economy) : ";
	cin >> sClass;
	List<Seat> sList = chosen.getSList();
	if (sClass == "First")
	{
		priority = 4;
	}
	else if (sClass == "Business")
	{
		priority = 2;
	}
	else
	{
		priority = 0;
	}
	double totalP = 0;
	for (int x = 0; x< passengers; x++)
	{
		int curr_prior = priority;
		cout << "enter Name : ";
		cin >> name;
		cout << "Enter Seat No. : ";
		cin >> sNo;
		cout << "Enter Age : ";
		cin >> age;
		if (age < 12 || age > 65)
		{
			curr_prior += 2;
		}
		else
		{
			curr_prior += 1;
		}

		Seat s = sList.get(sNo - 1);
		s.setTaken(true);
		totalP += s.getPrice();
		sList.updateItem(sNo - 1, s);
		Passenger p(name, age, curr_prior, s);
		pList.add(p);
		if (highestPrio < curr_prior)
		{
			highestPrio = curr_prior;
		}
	}
	cout << "Contact Name: " << name << endl;
	cout << "Contact Email: " << email << endl;
	Booking b(chosen.getOrigin(), chosen.getDest(), name, email, pList, totalP);
	Queue q = chosen.getQueue();
	q.enqueue(b, highestPrio);
	chosen.setQueue(q);
	flightList.updateItem(option - 1, chosen);

}
void user(int opt, List<Customer> customerList, List<Flight> flightList, List<Passenger> pList)
{
	while (opt != 0) {
		cout << "---------------- User Menu -------------------" << endl;
		cout << "[1] Login" << endl;
		cout << "[2] Register" << endl;
		cout << "[3] Continue as guest" << endl;
		cout << "[0] Exit" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Enter your option : ";
		cin >> opt;
		switch (opt)
		{
		case 0:
			break;
		case 1: {
			int index = logIn(customerList);
			custMenu(-1, flightList, index, customerList, pList);
			break;
		}
		case 2: {
			string name;
			string email;
			string phoneno;
			string password;
			cout << "---------------- Register ------------------" << endl;
			cout << "Enter Name : ";
			cin >> name;
			cout << "Enter Email : ";
			cin >> email;
			cout << "Enter Phone No. : ";
			cin >> phoneno;
			cout << "Enter Password : ";
			cout << "--------------------------------------------------" << endl;
			cin >> password;
			for (int x = 0; x < customerList.getLength(); x++)
			{
				Customer v = customerList.get(x);
				if (v.getEmail() == email)
				{
					cout << "An account already exist under this email." << endl;
					break;
				}
				else
				{
					Customer c(name, email, phoneno, password);
					customerList.add(c);
					cout << "Account created successfully" << endl;
					custMenu(-1, flightList, customerList.getLength()-1, customerList, pList);
				}
			}
			break;
			
		}
		case 3: {
			guestMenu(-1, flightList, pList);
			break;
		}
		}
	}
}



void admin(int opt, Tree t, List<Flight>& fList) {
	{
		while (opt != 0) {
			cout << "---------------- Admin Menu ------------------" << endl;
			cout << "[1] View Flight Paths" << endl;
			cout << "[2] Delete Flight Paths" << endl;
			cout << "[3] Create New Flights" << endl;
			cout << "[4] Update Flight Status" << endl;
			cout << "[5] View Flight" << endl;
			cout << "[0] Exit" << endl;
			cout << "----------------------------------------------" << endl;
			cout << "Enter your option : ";
			cin >> opt;
			switch (opt)
			{
			case 0:

				break;
			case 1: {
				cout << endl << "--------Displaying current flight path--------" << endl;
				t.traverseTree();
				cout << endl;
				int opt1 = -1;
				while (opt1 != 2) {
					cout << "---------------- Add New Paths? --------------" << endl;
					cout << "[1] Yes" << endl;
					cout << "[2] No" << endl;
					cout << "----------------------------------------------" << endl;
					cout << "Enter your option : ";
					cin >> opt1;
					switch (opt1)
					{
					case 1: {
						string originC;
						string destC;
						cout << "----------------------------------------------" << endl;
						cout << "Enter Origin Country: ";
						cin >> originC;
						TreeNode* root = t.getTop();
						TreeNode* Origin = t.search(originC);
						cout << "Enter Destination Country: ";
						cin >> destC;
						if (Origin != NULL) {
							t.insert(Origin->leftChild, destC);
							cout << "Added Flight Path [" << originC << " -> " << destC << "]" << endl;
						}
						else {
							t.insert(root, originC);
							cout << "Added Flight Path [" << originC << " -> " << destC << "]" << endl;
						}
						cout << "----------------------------------------------" << endl;
						opt1 = 2;
						break;
					}
					case 2: {
						opt1 = 2;
						break;
					}
					default: {
						cout << "---------------- Add New Paths? --------------" << endl;
						cout << "[1] Yes" << endl;
						cout << "[2] No" << endl;
						cout << "----------------------------------------------" << endl;
						cout << "Enter your option : ";
						cin >> opt1;
						break;
					}
					}
				}
				break;
			}
			case 2: {
				cout << endl << "--------Displaying current flight path--------" << endl;
				t.traverseTree();
				cout << endl;
				string originC;
				string destC;
				cout << "----------------------------------------------" << endl;
				cout << "Enter Origin Country: ";
				cin >> originC;
				TreeNode* root = t.getTop();
				TreeNode* Origin = t.search(originC);
				cout << "Enter Destination Country: ";
				cin >> destC;
				cout << "***Deleting this path will delete lead to subsequent paths from the destination to be deleted***" << endl;
				string confirm = "";
				cout << "Are you sure (Y/n): ";
				cin >> confirm;
				if (confirm == "Y") {
					if (Origin != NULL) {
						TreeNode* toDelete = t.searchSibling(Origin->leftChild, destC);
						if (toDelete != NULL) {
							TreeNode* child = t.deleteNode(toDelete);
							Origin->leftChild = child;
						}
						cout << "Deleted Flight Path [" << originC << " -> " << destC << "]" << endl;
					}
				}
				else {
					cout << "Flight path not deleted." << endl;
				}
				break;
			}
			case 3: {
				cout <<endl<< "-------Displaying Exisiting Flight Paths------" << endl;
				t.traverseTree();
				cout << endl;
				string originC;
				string destC;
				cout << "----------------------------------------------" << endl;
				cout << "Enter Origin Country: ";
				cin >> originC;
				cout << "Enter Destination Country: ";
				cin >> destC;
				cout << endl;
				TreeNode* Origin = t.search(originC);
				if (Origin != NULL) {
					if (t.searchSibling(Origin->leftChild, destC) != NULL) {
						int F, B, E;
						double Fp, Bp, Ep;
						cout << "Enter Number of First Class Seats: ";
						cin >> F;
						cout << "Enter Price of First Class Seats: ";
						cin >> Fp;
						cout << endl;
						cout << "Enter Number of Business Class Seats: ";
						cin >> B;
						cout << "Enter Price of Business Class Seats: ";
						cin >> Bp;
						cout << endl;
						cout << "Enter Number of Economy Class Seats: ";
						cin >> E;
						cout << "Enter Price of Economy Class Seats: ";
						cin >> Ep;
						List<Seat> seat;
						for (int i = 0; i < F; i++) {
							Seat s = Seat(i + 1, "First", Fp, false);
							seat.add(s);
						}
						int len = seat.getLength();
						for (int i = len; i < len + B; i++) {
							Seat s = Seat(i + 1, "Business", Bp, false);
							seat.add(s);
						}
						len = seat.getLength();
						for (int i = len; i < len + E; i++) {
							Seat s = Seat(i + 1, "Economy", Ep, false);
							seat.add(s);
						}
						Queue bList;
						Flight newFlight = Flight(originC, destC, bList, seat,"Scheduled");
						cout << endl << "-----------------------------------------------" << endl;
						cout << "New flight created" << endl;
						cout << "-----------------------------------------------" << endl;
						newFlight.print();
						fList.add(newFlight);
						cout << "-----------------------------------------------" << endl;
					}
					else {
						cout << "No such flight path available" << endl;
					}
				}
				else {
					cout << "No such flight path available" << endl;
				}
				break;
			}
			case 4: {
				if (fList.getLength() > 0) {
					cout << endl << "--------Displaying current flights------------" << endl;
					fList.print();
					cout << "----------------------------------------------" << endl;
					int option;
					cout << "Enter your option : ";
					cin >> option;
					if (option <= fList.getLength() && option >= 1) {
						Flight f = fList.get(option - 1);
						cout << endl << "--------Displaying selected flight------------" << endl;
						f.print();
						cout << "----------------------------------------------" << endl;
						string status;
						cout << "Enter flight status : ";
						cin >> status;
						f.setStatus(status);
						fList.updateItem(option - 1, f);
					}
				}
				else
					cout << "No flights made" << endl;
				break;

			}
			case 5: {
				cout << endl << "--------Displaying current flights------------" << endl;
				fList.print();
				cout << "----------------------------------------------" << endl;
				int option;
				cout << "Enter your option : ";
				cin >> option;
				if (option <= fList.getLength() && option >= 1) {
					Flight f = fList.get(option - 1);
					Queue q = f.getQueue();
					q.displayItems();
				}
				break;
			}
			default:
				cout << "---------------- Admin Menu ------------------" << endl;
				cout << "[1] View Flight Paths" << endl;
				cout << "[2] Delete Flight Paths" << endl;
				cout << "[3] Create New Flights" << endl;
				cout << "[4] Update Flight Status" << endl;
				cout << "[0] Exit" << endl;
				cout << "----------------------------------------------" << endl;
				cout << "Enter your option : ";
				cin >> opt;;
				break;
			}
		}
	}
}

int main()
{
	Tree tList;
	tList.insert("Singapore");
	TreeNode* root = tList.getTop();
	tList.insert(root->leftChild, "Japan");
	tList.insert(root->leftChild, "Malaysia");
	TreeNode* tree = tList.search(root, "Japan");
	tList.insert(tree->leftChild, "Thailand");
	TreeNode* temp = tList.search(root, "Thailand");
	tList.insert(root->leftChild, "USA");
	tList.insert(root->leftChild, "Indonesia");
	TreeNode* bottom = tList.search(root, "Indonesia");
	tList.insert(bottom->leftChild, "Vietnam");

	List<Flight> fList;
	List<Customer> cList;
	List<Passenger> pList;
	Customer Jax = Customer("Jax", "test@gmail.com", "password", "9999 9999");
	Customer Akid = Customer("Akid", "test1@gmail.com", "password", "8888 8888");
	Customer A = Customer("A", "test2@gmail.com", "password", "7777 7777");
	Customer B = Customer("B", "test3@gmail.com", "password", "6666 6666");
	cList.add(Jax);
	cList.add(Akid);
	cList.add(A);
	cList.add(B);

    int opt = 1;
	while (opt != 0)
	{
		cout << "---------------- Main Menu -------------------" << endl;
		cout << "[1] User" << endl;
		cout << "[2] Admin" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Enter your option : ";
		cin >> opt;
		switch (opt)
		{
		case 0:
			break;
		case 1:
			user(-1,cList,fList, pList);
			break;
		case 2:
			admin(-1, tList, fList);
		default:
			cout << "---------------- Main Menu -------------------" << endl;
			cout << "[1] User" << endl;
			cout << "[2] Admin" << endl;
			cout << "----------------------------------------------" << endl;
			cout << "Enter your option : ";
			cin >> opt;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
