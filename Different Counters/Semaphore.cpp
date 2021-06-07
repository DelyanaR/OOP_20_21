#include "Semaphore.hpp"

Semaphore::Semaphore(): Counter(0,1), LimitedTwowayCounter(0, 1, 0, 1) {
}

Semaphore::Semaphore(bool given) {
	if (given == true) {
		this->count = 1;
	}
	else {
		this->count = 0;
	}
}

bool Semaphore::isAvailable() {
	if (this->count > 0) {
		return true;
	}
	return false;
}

void Semaphore::wait() {
	decrement();
}

void Semaphore::signal() {
	increment();
}