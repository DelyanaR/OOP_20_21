#include "Request.hpp"

int Request::count=0;

Request::Request() {
	this->message = "";
	this->sender = "";
	count++;
	this->ID = count;
}

Request::Request(const std::string& message, const std::string& sender) {
	this->message = message;
	this->sender = sender;
	count++;
	this->ID = count;
}

std::string Request::getMessage()const {
	return this->message;
}

std::string Request::getSender()const {
	return this->sender;
}

int Request::getCount()const {
	return count;
}

int Request::getID()const {
	return this->ID;
}
