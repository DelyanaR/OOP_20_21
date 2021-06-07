#pragma once
class Counter{
public:
	Counter();
	Counter(const int& initial);
	Counter(const int& initial, const unsigned& step);
	void increment();
	int getTotal()const;
	unsigned getStep()const;

protected:
	int count;
	unsigned countStep;
};

