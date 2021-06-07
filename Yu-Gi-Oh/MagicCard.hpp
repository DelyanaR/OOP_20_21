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
#include<fstream>
#include "Card.hpp"

enum class CardType { TRAP, BUFF, SPELL };

class MagicCard: virtual public Card{
public:
	MagicCard();
	MagicCard(std::string new_name, std::string new_effect, unsigned int new_rarity, const CardType new_type);
	std::string getName() const;
	std::string getEffect()const;
	unsigned int getRarity()const;
	CardType getType()const;
	void write(std::ostream& out)const override;
	Card* clone()const override;
	MagicCard& operator=(const MagicCard& rhs);
	friend std::ostream& operator<<(std::ostream& out, const MagicCard& card) {
		out << card.name << "|" << card.effect << "|"<<card.rarity<<"|";
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
	friend std::istream& operator>>(std::istream& in, MagicCard& card) {
		std::string name1, effect1, type1;
		char skip;
		getline(in, name1, '|');
		if(name1[0]=='\n')name1.erase(0, 1);//erasing the '\n' from the string
		getline(in, effect1, '|');
		card.name = name1;
		card.effect = effect1;
		int rar = 0;
		in >> rar>>skip>>type1;
		card.rarity = rar;
		if (type1 == "BUFF" || type1 == "buff") card.typeCard = CardType::BUFF;
		else if (type1 == "SPELL" || type1 == "spell") card.typeCard = CardType::SPELL;
		else card.typeCard = CardType::TRAP;
		return in;
	}
protected:
	CardType typeCard;
};

