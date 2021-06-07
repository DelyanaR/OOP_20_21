#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(std::string id, size_t period) :Subscriber(id), period(period) {
}

void PeriodicSampler::signal(Message mes) {
	this->mes.push_back(mes);
}

int PeriodicSampler::read()const {
	if (this->mes.size() != 0) {
		for (size_t i = this->mes.size() - 1; i > 0; i--) {
			if (i % this->period == 0) {
				return this->mes[i].data;
			}
		}
		return this->mes[0].data;
	}
	else {
		return 0;
	}
}

Subscriber* PeriodicSampler::clone() {
	return new PeriodicSampler(*this);
}