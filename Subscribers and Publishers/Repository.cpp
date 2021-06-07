#include "Repository.hpp"

Repository& Repository::operator=(const Repository& rhs) {
	if (this != &rhs) {
		this->subscribers.clear();
		for (size_t i = 0; i < rhs.subscribers.size(); i++) {
			this->subscribers.push_back(rhs.subscribers[i]->clone());
		}
	}
	return *this;
}

Repository::Repository(const Repository& rhs) {
	for (size_t i = 0; i < rhs.subscribers.size(); i++) {
		this->subscribers.push_back(rhs.subscribers[i]->clone());
	}
}

void Repository::add(Subscriber* to_add) {
	this->subscribers.push_back(to_add->clone());
}

Subscriber* Repository::get(std::string id) {
	for (size_t i = 0; i < this->subscribers.size(); i++) {
		if (this->subscribers[i]->id == id) {
			return this->subscribers[i];
		}
	}
	return nullptr;
}