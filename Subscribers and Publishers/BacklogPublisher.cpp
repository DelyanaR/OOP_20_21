#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Averager* to_add) {
	this->subs.push_back(to_add);
	for (size_t i = 0; i < this->allMes.size(); i++) {
		to_add->signal(this->allMes[i]);
	}

}

void BacklogPublisher::subscribe(MovingAverager* to_add) {
	this->subs.push_back(to_add);
	for (size_t i = 0; i < this->allMes.size(); i++) {
		to_add->signal(this->allMes[i]);
	}
}

void BacklogPublisher::subscribe(PeriodicSampler* to_add) {
	this->subs.push_back(to_add);
	for (size_t i = 0; i < this->allMes.size(); i++) {
		to_add->signal(this->allMes[i]);
	}
}

void BacklogPublisher::signal(Message mes) {
	for (size_t i = 0; i < this->subs.size(); i++) {
		this->subs[i]->signal(mes);
	}
	this->allMes.push_back(mes);
}