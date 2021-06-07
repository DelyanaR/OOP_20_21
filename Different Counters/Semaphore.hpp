#pragma once
#include "LimitedTwowayCounter.hpp"
class Semaphore: public LimitedTwowayCounter{
public:
	Semaphore();
	Semaphore(bool given);
	bool isAvailable();
	void wait();
	void signal();
};

