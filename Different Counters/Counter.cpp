#include "Counter.hpp"

Counter::Counter() : count(0), countStep(1){
}

Counter::Counter(const int& initial): count(initial), countStep(1) {
}

Counter::Counter(const int& initial, const unsigned& step): count(initial), countStep(step) {
}

void Counter::increment() {
	this->count += this->countStep;
}

int Counter::getTotal()const {
	return this->count;
}

unsigned Counter::getStep()const {
	return this->countStep;
}
