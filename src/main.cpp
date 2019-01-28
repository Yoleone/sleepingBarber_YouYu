#include "sleepingBarber.h"

int main() {

	int number = enterSeatsNumber();
	ThreadTest sleepingBarber(number);

	while (true) {}
	return 0;
}


