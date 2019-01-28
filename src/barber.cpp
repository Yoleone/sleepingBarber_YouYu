#include "sleepingBarber.h"

void ThreadTest::Barber()
{
    while (true) {
        Mutex.lock(); // lock on
        while (remain == seats) {
            Mutex.unlock(); // unlock

            cout << "Baber Sleeping" << endl;
            this_thread::sleep_for((chrono::seconds(5)));

            Mutex.lock(); // lock on
        }

        int customerID = waitingRoom.front();
        waitingRoom.pop_front();
        ++remain;
        remain = min(remain, seats);
        Mutex.unlock(); // unlock

        printf("Barber cutting the hair of customer:%d\n", customerID);
		
		srand(time(0));
        int haircut = rand() %10 + 1;
        this_thread::sleep_for((chrono::seconds(haircut)));
    }
}

//constructor function
ThreadTest::ThreadTest(int seatsNumber)
{
	remain = seatsNumber;
	seats = seatsNumber;
	thread t1(&ThreadTest::Barber, this);
	t1.detach();
	thread t2(&ThreadTest::MakingCustomer, this);
	t2.detach();
}

//destructor
ThreadTest::~ThreadTest()
{
}