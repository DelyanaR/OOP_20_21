#include "SimplePublisher.hpp"

void SimplePublisher::subscribe(Averager* to_add) {
	this->subs.push_back(to_add);
}

void SimplePublisher::subscribe(MovingAverager* to_add) {
	this->subs.push_back(to_add);
}

void SimplePublisher::subscribe(PeriodicSampler* to_add) {
	this->subs.push_back(to_add);
}


void SimplePublisher::signal(Message mes) {
	if (this->subs.size() != 0) {
		for (auto sub : this->subs) {
			sub->signal(mes);
		}
	}
}
