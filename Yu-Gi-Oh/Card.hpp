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
#include <string>

enum class Type{Default, MonsterCard, MagicCard, PendulumCard};

class Card {
public:
	Card();
	Card(std::string new_name, std::string new_effect, unsigned int new_rarity, Type new_type);
	virtual ~Card()=default;
	bool operator>(const Card& rhs);
	bool operator<(const Card& rhs);
	virtual std::string getName()const=0;
	virtual std::string getEffect()const=0;
	virtual unsigned int getRarity()const=0;
	Type getType()const;
	virtual void write(std::ostream& out)const=0;
	virtual Card* clone()const = 0;
	friend std::ostream& operator<<(std::ostream& out, const Card& card) {
		card.write(out);
		return out;
	}
protected:
	std::string name;
	std::string effect;
	unsigned int rarity;
	Type type;
};
