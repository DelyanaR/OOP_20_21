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
#include "PendulumCard.hpp"

PendulumCard::PendulumCard(): Card("","",0,Type::PendulumCard), MonsterCard(), MagicCard() {
}

PendulumCard::PendulumCard(std::string new_name, std::string new_effect, unsigned int new_rarity, unsigned int attack, unsigned int defence, int scale, CardType type):
	Card(new_name, new_effect, new_rarity, Type::PendulumCard), MonsterCard(new_name, new_effect, new_rarity, attack, defence), MagicCard(new_name, new_effect, new_rarity, type) {
	if (scale >= INTERVAL[0] && scale <= INTERVAL[1]) {//if the given value isn't between 1 and 13, then it will be 1
		this->scale = scale;
	}
}

std::string PendulumCard::getName()const {
	return this->name;
}

std::string PendulumCard::getEffect()const {
	return this->effect;
}

unsigned int PendulumCard::getRarity()const {
	return this->rarity;
}

void PendulumCard::write(std::ostream& out)const {
	out << *this;
}

Card* PendulumCard::clone() const{
	return new PendulumCard(*this);
}

PendulumCard& PendulumCard::operator=(const PendulumCard& rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		this->effect = rhs.effect;
		this->rarity = rhs.rarity;
		this->attack = rhs.attack;
		this->defend = rhs.defend;
		this->scale = rhs.scale;
		this->typeCard = rhs.typeCard;
	}
	return *this;
}