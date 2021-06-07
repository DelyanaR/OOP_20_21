/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Delyana Raykova
* @idnumber 62533
* @task 1
* @compiler VC
*/
#include "Card.hpp"

Card::Card(): name(""), effect(""), rarity(0), type(Type::Default) {
}

Card::Card(std::string new_name, std::string new_effect, unsigned int new_rarity, Type new_type) : 
	name(new_name), effect(new_effect), rarity(new_rarity), type(new_type) {
}

bool Card::operator>(const Card& rhs) {
	if (this->rarity > rhs.rarity) {
		return true;
	}
	return false;
}

bool Card::operator<(const Card& rhs) {
	if (this->rarity < rhs.rarity) {
		return true;
	}
	return false;
}

Type Card::getType()const {
	return this->type;
}

