#include "Publisher.hpp"

Publisher::~Publisher() {
	this->subs.clear();
}

void Publisher::unsubscribe(Averager* to_remove) {
	for (size_t i = 0; i < this->subs.size(); i++) {
		if (this->subs[i]->id == to_remove->id) {
			this->subs.erase(this->subs.begin() + i);
			return;
		}
	}
}

void Publisher::unsubscribe(MovingAverager* to_remove) {
	for (size_t i = 0; i < this->subs.size(); i++) {
		if (this->subs[i]->id == to_remove->id) {
			this->subs.erase(this->subs.begin() + i);
			return;
		}
	}
}

void Publisher::unsubscribe(PeriodicSampler* to_remove) {
	for (size_t i = 0; i < this->subs.size(); i++) {
		if (this->subs[i]->id == to_remove->id) {
			this->subs.erase(this->subs.begin() + i);
			return;
		}
	}
}

