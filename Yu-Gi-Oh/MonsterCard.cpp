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

#include "MonsterCard.hpp"
using namespace std;

MonsterCard::MonsterCard(): Card("","",0,Type::MonsterCard), attack(0), defend(0) {
}

MonsterCard::MonsterCard(std::string new_name, std::string new_effect, unsigned int new_rarity, const unsigned int attack_points, const unsigned int defend_points):
	Card(new_name, new_effect, new_rarity, Type::MonsterCard), attack(attack_points), defend(defend_points){
	
}

std::string MonsterCard::getName()const {
	return this->name;
}

std::string MonsterCard::getEffect() const{
	return this->effect;
}

unsigned int MonsterCard::getRarity() const {
	return this->rarity;
}

const unsigned int MonsterCard::getAttack()const {
	return this->attack;
}

const unsigned int MonsterCard::getDefend()const {
	return this->defend;
}

void MonsterCard::write(std::ostream& out) const{
	out << *this;
}

Card* MonsterCard::clone() const{
	return new MonsterCard(*this);
}


MonsterCard& MonsterCard::operator=(const MonsterCard& rhs){
	if (this != &rhs) {
		this->name = rhs.name;
		this->effect = rhs.effect;
		this->rarity = rhs.rarity;
		this->attack = rhs.attack;
		this->defend = rhs.defend;
	}
	return *this;
}
