#pragma once
#include "Counter.hpp"
class LimitedCounter: virtual public Counter{
public:
	LimitedCounter();
	LimitedCounter(const int& max);
	LimitedCounter(const int& max, const int& initial);
	LimitedCounter(const int& max, const int& initial, const unsigned& step);
	void increment(); 
	int getMax()const;
	int getTotal()const;
	unsigned getStep()const;

private:
	int maxV;
};

