#include "KeyValueDatabase.hpp"

KeyValueDatabase::KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension):
Object(name, location, extension){}

void KeyValueDatabase::add_entry(const std::pair<std::string, int>& entry) {
	for (size_t i = 0; i < this->pairs.size(); i++) {
		if (this->pairs[i].first == entry.first) {
			throw std::invalid_argument("This pair has already been added!");
			break;
		}
	}
	this->pairs.push_back(entry);
}

int KeyValueDatabase::get_value(const std::string& key) const {
	for (size_t i = 0; i < this->pairs.size(); i++) {
		if (this->pairs[i].first == key) {
			return this->pairs[i].second;
		}
	}
	throw std::invalid_argument("The given key is invalid!");
}

Object* KeyValueDatabase::clone()const{
	return new KeyValueDatabase(*this);
}

bool KeyValueDatabase::operator==(const Comparable* rhs)const {
	Comparable* kvd = const_cast<Comparable*>(rhs);
	auto kvd1 = dynamic_cast<KeyValueDatabase*>(kvd);
	if (kvd1) {
		if (this->pairs.size() != kvd1->pairs.size()) {
			return false;
		}
		for (size_t i = 0; i < this->pairs.size(); i++) {
			if (this->pairs[i].first != kvd1->pairs[i].first || this->pairs[i].second!=kvd1->pairs[i].second) {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool KeyValueDatabase::operator!=(const Comparable* rhs)const {
	Comparable* kvd = const_cast<Comparable*>(rhs);
	auto kvd1 = dynamic_cast<KeyValueDatabase*>(kvd);
	if (kvd1) {
		if (this->pairs.size() != kvd1->pairs.size()) {
			return true;
		}
		for (size_t i = 0; i < this->pairs.size(); i++) {
			if (this->pairs[i].first == kvd1->pairs[i].first && this->pairs[i].second == kvd1->pairs[i].second) {
				continue;
			}
			else {
				return true;
			}
		}
		return false;
	}
	return true;
}

std::string KeyValueDatabase::to_string()const {
	std::string hold = this->name + '\n' + this->location + '\n' + this->extension + '\n';
	for (size_t i = 0; i < this->pairs.size(); i++) {
		hold += this->pairs[i].first;
		hold += ":";
		hold += std::to_string(this->pairs[i].second);
		hold += '\n';
	}
	return hold;

}

void KeyValueDatabase::from_string(const std::string& str) {
	this->pairs.clear();
	int i = 0, value=0;
	std::string receive = "str";
	std::istringstream getter(str);
	while (receive != "") {
		if (i == 0) { 
			getline(getter, receive);
			this->name = receive; 
			i++;
		}
		else if (i == 1) {
			getline(getter, receive);
			this->location = receive;
			i++;
		}
		else if (i == 2) {
			getline(getter, receive);
			this->extension = receive;
			i++;
		}
		else {
			getline(getter, receive, ':');
			if (receive == "") {
				break;
			}
			p.first = receive;
			getline(getter, receive);
			p.second = std::stoi(receive);
			this->pairs.push_back(p);
		}
	}
}

std::string KeyValueDatabase::debug_print()const {
	std::string to_print;
	for (size_t i = 0; i < this->pairs.size(); i++) {
		to_print += '{';
		to_print += this->pairs[i].first;
		to_print += ":";
		std::string to_str = std::to_string(this->pairs[i].second);
		to_print += to_str;
		to_print += '}';
		to_print+='\n';
	}
	return to_print;
}
