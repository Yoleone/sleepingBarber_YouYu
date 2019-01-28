#include "sleepingBarber.h"

void ThreadTest::Customer(int customerID)
{
	Mutex.lock(); // lock on
	if (remain <= 0) {
		cout << "Customer " << customerID << " leaving\n";
		this->~ThreadTest();
	}
	else {
		waitingRoom.push_back(customerID);
		--remain;
		printWaiting();
	}
	Mutex.unlock(); // unlock
}

void ThreadTest::printWaiting()
{
	if (waitingRoom[0] != 1) {
		cout << "Waiting room: ";
		for (auto it = waitingRoom.begin(); it != waitingRoom.end(); ++it) {
			cout << *it << ' ';
		}
		cout << endl;
	}
}

int enterSeatsNumber()
{
	cout << "Please enter the number of seats: ";
	int seatsNumber;
	cin >> seatsNumber;
	if (!seatsNumber || seatsNumber <= 0)
		throw("error seats number!");

	cout << "Program starts with " << seatsNumber << " seats: \n";
}