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
#include "deck.hpp"
using namespace std;

Deck::Deck() : name("") {
}

Deck::~Deck() {
	for (auto card : this->cards) {
		delete card;
	}
	clearDeck();
}

Deck::Deck(const Deck& rhs) {
	unsigned i = 0;
	for (auto card : rhs.cards) {
		this->cards[i] = card;
		i++;
	}
}

Deck& Deck::operator=(const Deck& rhs) {
	if (this != &rhs) {
		for (auto card : this->cards) {
			delete card;
		}
		clearDeck();
		unsigned i = 0;
		for (auto card : rhs.cards) {
			this->cards[i] = card;
			i++;
		}
	}
	return *this;
}

void Deck::setName(std::string new_name) {
	this->name = new_name;
}

const unsigned int Deck::getNumberofMonsterCards()const {
	unsigned int number = 0;
	for (auto card : cards) {
		if (card->getType()==Type::MonsterCard) {
			number++;
		}
	}
	return number;
}

const unsigned int Deck::getNumberofMagicCards()const {
	unsigned int number = 0;
	for (auto card : cards) {
		if (card->getType() == Type::MagicCard) {
			number++;
		}
	}
	return number;
}

const unsigned int Deck::getNumberofPendulumCards()const {
	unsigned int number = 0;
	for (auto card : cards) {
		if (card->getType() == Type::PendulumCard) {
			number++;
		}
	}
	return number;
}

const unsigned int Deck::getNumberofAllCards()const {
	return this->cards.size();
}

void Deck::addCard(Card* card) {
	this->cards.push_back(card->clone());
}

void Deck::changeCard(unsigned int index, Card* card) {
	if (card->getType() == this->cards[index]->getType()) {
		this->cards[index] = card->clone();
	}
}

std::vector<Card*> Deck::getCards()const {
	return this->cards;
}

const std::string Deck::getName() const {
	return this->name;
}

void Deck::clearDeck() {
	this->name.clear();
	this->cards.clear();
}

void Deck::shuffle() {
	std::vector<Card*>::iterator pos = this->cards.begin();
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(pos, pos + this->getNumberofAllCards(), std::default_random_engine(seed));
}