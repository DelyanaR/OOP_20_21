#include "Averager.hpp"

Averager::Averager(std::string id): Subscriber(id){
}

void Averager::signal(Message mes){
	this->mes.push_back(mes);
}

int Averager::read()const{
	if (this->mes.size() != 0) {
		int average = 0, i = 0;
		for (auto x : this->mes) {
			average += x.data;
			i++;
		}
		return average / i;
	}
	else {
		return 0;
	}
}

Subscriber* Averager::clone(){
	return new Averager(*this);
}
