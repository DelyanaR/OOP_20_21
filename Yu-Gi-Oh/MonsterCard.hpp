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
#pragma once
#include<iostream>
#include "Card.hpp"

class MonsterCard: virtual public Card{
public:
	MonsterCard();
	MonsterCard(std::string new_name, std::string new_effect, unsigned int new_rarity, const unsigned int attack_points, const unsigned int defend_points);
	std::string getName()const override;
	std::string getEffect()const override;
	unsigned int getRarity()const override;
	const unsigned int  getAttack()const;
	const unsigned int getDefend()const;
	void write(std::ostream& out)const override;
	Card* clone()const override;
	MonsterCard& operator=(const MonsterCard& rhs);
	friend std::ostream& operator<<(std::ostream& out, const MonsterCard& card) {
		out << card.name << "|" << card.effect << "|"<<card.rarity<<"|" << card.attack << "|" << card.defend<<std::endl;//
		return out;
	}
	friend std::istream& operator>>(std::istream& in, MonsterCard& card) {
		std::string name1, effect1;
		char skip;
		getline(in, name1, '|');
		if (name1[0] == '\n') { name1.erase(0, 1); }//erasing the '\n' from the string
		getline(in, effect1, '|');
		card.name = name1;
		card.effect = effect1;
		for (int i = 0; i < 3; i++) {
			int input1 = 0;
			in >> input1;
			if (i == 0) card.rarity = input1;
			else if (i == 1) card.attack = input1;
			else card.defend = input1;
			if (i != 2) in >> skip;
		}
		return in;
	}
protected:
	unsigned int attack;
	unsigned int defend;
};

