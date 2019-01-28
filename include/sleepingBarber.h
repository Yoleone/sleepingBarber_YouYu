#pragma once
#include "std_lib_facilities.h"

class ThreadTest {
public:
    void Barber();
    void MakingCustomer();

    void Customer(int customerID);
	void printWaiting();

    ThreadTest(int seatsNumber);
    ~ThreadTest();

private:
    int Sum = 0;
    int seats;
    int remain;
    std::deque<int> waitingRoom;

    mutex Mutex; // thread lock
};

int enterSeatsNumber();