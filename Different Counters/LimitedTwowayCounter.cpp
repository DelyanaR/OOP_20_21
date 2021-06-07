#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(): minV(0) {
}

LimitedTwowayCounter::LimitedTwowayCounter(const int& min, const int& max): 
	Counter(), LimitedCounter(max), TwowayCounter(), minV(min) {
}

LimitedTwowayCounter::LimitedTwowayCounter(const int& min, const int& max, const int& initial): 
	Counter(initial), LimitedCounter(max, initial),  TwowayCounter(initial), minV(min) {
}

LimitedTwowayCounter::LimitedTwowayCounter(const int& min, const int& max, const int& initial, const unsigned& step): 
	Counter(initial, step), LimitedCounter(max, initial, step), TwowayCounter(initial,step), minV(min) {
}

void LimitedTwowayCounter::increment() {
	LimitedCounter::increment();
} 

void LimitedTwowayCounter::decrement() {
	int check = this->count - this->countStep;
	if(check >=this->minV){
		TwowayCounter::decrement();
	}
}

int LimitedTwowayCounter::getMin()const {
	return this->minV;
}

int LimitedTwowayCounter::getMax()const {
	return LimitedCounter::getMax();
}

int LimitedTwowayCounter::getTotal()const {
	return LimitedCounter::getTotal();
}

unsigned LimitedTwowayCounter::getStep()const {
	return LimitedCounter::getStep();
}

