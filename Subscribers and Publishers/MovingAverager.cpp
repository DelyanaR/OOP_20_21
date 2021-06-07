#include "MovingAverager.hpp"

MovingAverager::MovingAverager(std::string id, size_t windowSize): Subscriber(id), windowSize(windowSize){
}

void MovingAverager::signal(Message mes){
	this->mes.push_back(mes);
}

int MovingAverager::read()const{
	if (this->mes.size() != 0) {
		if (this->mes.size() < this->windowSize) {
			int average = 0;
			for (size_t i = 0; i < this->mes.size(); i++) {
				average += this->mes[i].data;
			}
			return average / this->mes.size();

		}
		else{
			int average = 0;
			for (size_t i = this->mes.size() - this->windowSize; i < this->mes.size(); i++) {
				average += this->mes[i].data;
			}
			return average / this->windowSize;
		}
	}
	else {
		return 0;
	}
}

Subscriber* MovingAverager::clone() {
	return new MovingAverager(*this);
}
