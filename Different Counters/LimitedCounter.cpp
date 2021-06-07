#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter(): Counter(), maxV(0) {
}

LimitedCounter::LimitedCounter(const int& max): Counter(), maxV(max) {
}

LimitedCounter::LimitedCounter(const int& max, const int& initial): Counter(initial), maxV(max) {
}

LimitedCounter::LimitedCounter(const int& max, const int& initial, const unsigned& step): Counter(initial, step), maxV(max) {
}

void LimitedCounter::increment() {
	int check = this->count + this->countStep;
	if (check <= this->maxV) {
		this->count += this->countStep;
	}
}

int LimitedCounter::getMax()const {
	return this->maxV;
}

int LimitedCounter::getTotal()const {
	return Counter::getTotal();
}

unsigned LimitedCounter::getStep()const {
	return Counter::getStep();
}
