#include "sleepingBarber.h"

void ThreadTest::MakingCustomer()
{
	while (true) {
		this_thread::sleep_for((chrono::seconds(3)));
		++Sum;
		thread t1(&ThreadTest::Customer, this, Sum);
		t1.detach();
	}
}