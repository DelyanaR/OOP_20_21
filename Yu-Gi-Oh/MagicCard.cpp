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

#include "MagicCard.hpp"
using namespace std;

MagicCard::MagicCard():Card("","",0, Type::MagicCard), typeCard(CardType::BUFF) {
}

MagicCard::MagicCard(std::string new_name, std::string new_effect, unsigned int new_rarity, const CardType new_type):
	Card(new_name, new_effect, new_rarity, Type::MagicCard), typeCard(new_type) {
}

std::string MagicCard::getName()const {
	return this->name;
}
std::string MagicCard::getEffect()const {
	return this->effect;
}

unsigned int MagicCard::getRarity()const {
	return this->rarity;
}

CardType MagicCard::getType() const{
	return this->typeCard;
}

void MagicCard::write(std::ostream& out) const{
	out << *this;
}

Card* MagicCard::clone() const{
	return new MagicCard(*this);
}

MagicCard& MagicCard::operator=(const MagicCard& rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		this->effect = rhs.effect;
		this->rarity = rhs.rarity;
		this->typeCard = rhs.typeCard;
	}
	return *this;
}
