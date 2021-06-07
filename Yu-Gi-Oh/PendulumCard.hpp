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
#include "MonsterCard.hpp"
#include "MagicCard.hpp"

class PendulumCard: public MonsterCard, public MagicCard{
public:
	PendulumCard();
	PendulumCard(std::string new_name, std::string new_effect, unsigned int new_rarity, unsigned int attack, unsigned int defence, int scale, CardType type);
	~PendulumCard()=default;
	std::string getName()const;
	std::string getEffect()const;
	unsigned int getRarity()const;
	void write(std::ostream& out)const override;
	Card* clone()const override;
	PendulumCard& operator=(const PendulumCard& rhs);
	friend std::ostream& operator<<(std::ostream& out, const PendulumCard& card) {
		out << card.name << "|" << card.effect << "|"<< card.rarity<<"|"
			<<card.attack<<"|"<<card.defend<<"|"<<card.scale<<"|";
		if (card.typeCard == CardType::BUFF) {
			out << "BUFF";
		}
		else if (card.typeCard == CardType::SPELL) {
			out << "SPELL";
		}
		else {
			out << "TRAP";
		}
		out << std::endl;
		return out;
	}
	friend std::istream& operator>>(std::istream& in, PendulumCard& card) {
		std::string name, effect, type;
		char skip;
		getline(in, name, '|');
		if(name[0]=='\n')name.erase(0, 1);//erasing the '\n' from the string
		getline(in, effect, '|');
		card.name = name;
		card.effect = effect;
		for (int i = 0; i < 4; i++) {
			int input1 = 0;
			in >> input1>>skip;
			if (i == 0) card.rarity = input1;
			else if (i == 1) card.attack = input1;
			else if (i == 2)card.defend = input1;
			else card.scale = input1;
		}
		in >> type;
		if (type == "BUFF" || type == "buff") card.typeCard = CardType::BUFF;
		else if (type == "SPELL" || type == "spell") card.typeCard = CardType::SPELL;
		else card.typeCard = CardType::TRAP;
		return in;
	}

private:
	int scale=1;//default value
	const int INTERVAL[2]= { 1,13 };
};

