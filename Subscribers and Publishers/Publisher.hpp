#pragma once
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include <vector>

class Publisher{
public:
	virtual ~Publisher()=0;

	virtual void subscribe(Averager*) = 0;
	virtual void subscribe(MovingAverager*) = 0;
	virtual void subscribe(PeriodicSampler*) = 0;

	virtual void unsubscribe(Averager*);
	virtual void unsubscribe(MovingAverager*);
	virtual void unsubscribe(PeriodicSampler*);

	virtual void signal(Message mes)=0;

protected:
	std::vector<Subscriber*> subs;
};

