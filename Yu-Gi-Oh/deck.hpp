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
#include<vector>
#include <algorithm>
#include<typeinfo>
#include <random>
#include <chrono> 
#include "PendulumCard.hpp"

class Deck{
public:
	Deck();
	~Deck();
	Deck(const Deck& rhs);
	Deck& operator=(const Deck& rhs);
	void setName(std::string new_name);
	const unsigned int getNumberofMonsterCards()const;
	const unsigned int getNumberofMagicCards()const;
	const unsigned int getNumberofPendulumCards()const;
	const unsigned int getNumberofAllCards()const;
	void addCard(Card* card);
	void changeCard(unsigned int index, Card* card);
	std::vector<Card*> getCards()const;
	const std::string getName()const;
	void clearDeck();
	void shuffle();

private:
	std::string name;
	std::vector<Card*> cards;
};

