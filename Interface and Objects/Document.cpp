#include "Document.hpp"

Document::Document(const std::string& name, const std::string& location, const std::string& extension) :
	Object(name, location, extension), pointer(0) {}


void Document::write_line(const std::string& line) {
	this->lines.push_back(line);
}

std::string Document::read_line() {
	if (this->lines.size() == this->pointer) {
		throw std::out_of_range("Reached the end of document!");
		return "";
	}
	return this->lines[pointer++];
}

std::string Document::read_line(const unsigned line) {
	if (this->lines.size() < line || line==0) {
		throw std::out_of_range("Reached the end of document!");
		return "";
	}
	pointer = line;
	return this->lines[line-1];
}

Object* Document::clone()const {
	return new Document(*this);
}

bool Document::operator==(const Comparable* rhs)const {
	Comparable* doc1 = const_cast<Comparable*>(rhs);
	auto doc = dynamic_cast<Document*>(doc1);
	if (doc) {
		if (this->lines.size() != doc->lines.size()) {
			return false;
		}
		for (size_t i = 0; i < this->lines.size(); i++) {
			if (this->lines[i] != doc->lines[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool Document::operator!=(const Comparable* rhs)const {
	Comparable* doc1 = const_cast<Comparable*>(rhs);
	auto doc = dynamic_cast<Document*>(doc1);
	if (doc) {
		return !(this == rhs);
	}
	return false;
}

std::string Document::to_string()const {
	std::string hold = this->name + '\n' + this->location + '\n' + this->extension + '\n';
	for (size_t i = 0; i < this->lines.size(); i++) {
		hold += this->lines[i];
		hold += '\n';
	}
	return hold;

}

void Document::from_string(const std::string& string) {
	int i = 0;
	std::string receive="string";
	std::stringstream getter;
	getter << string;
	while (receive != "") {
		getline(getter, receive);
		if (i == 0) this->name = receive;
		else if (i == 1) this->location = receive;
		else if (i == 2) this->extension = receive;
		else if (i == 3) { 
			this->lines.clear();
			this->lines.push_back(receive); 
			this->pointer = 0;
		}
		else this->lines.push_back(receive);
		i++;
	}
}

std::string Document::debug_print()const {
	std::string to_print;
	int i = 1;
	for (std::string line : this->lines) {
		to_print += "Line ";
		to_print += std::to_string(i++);
		to_print += ':';
		to_print += line+'\n';
	}
	return to_print;
}
