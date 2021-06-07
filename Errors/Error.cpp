#include "Error.hpp"

Error::Error(const std::string& message) {
	setMessage(message);
}

std::string Error::get_message() const {
	return this->message;
}

void Error::setMessage(std::string new_message) {
	this->message = new_message;
}