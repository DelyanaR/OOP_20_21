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
#include "duelist.hpp"
using namespace std;

Duelist::Duelist() :name("") {
}

Duelist::Duelist(std::string new_name) : name(new_name) {
}

Deck& Duelist::getDeck() {
	return this->deck;
}

bool Duelist::writeToFile(const std::string filename) {
	std::ofstream file;
	file.open(filename, std::ios::trunc);
	if (!file.is_open()) {
		return false;
	}
	else {
		file << this->deck.getName() << "|" << this->deck.getNumberofAllCards() << "|" << this->deck.getNumberofMonsterCards() << "|"
			<< this->deck.getNumberofMagicCards() << "|" << this->deck.getNumberofPendulumCards() << std::endl;
		for (auto x : this->deck.getCards()) {
			file << *x;
		}
		file.close();
		return true;
	}
}

bool Duelist::writeFromFile(const std::string filename) {
	std::ifstream file;
	file.open(filename, std::ios::in);
	if (!file.is_open()) {
		return false;
	}
	else {
		this->deck.clearDeck();
		std::string new_name;
		int all = 0, monst = 0, mag = 0, pend = 0;
		char skip;
		getline(file, new_name, '|');
		this->deck.setName(new_name);
		file >> all >> skip >> monst >> skip >> mag >> skip >> pend;//we get the number of cards of each type
		while (!(file.eof())) {
			int currMonst = 0, currMag = 0, currPend = 0;
			for (; currMonst < monst; currMonst++) {
				MonsterCard to_add;
				file >> to_add;
				this->deck.addCard(&to_add);
			}
			for (; currMag < mag; currMag++) {
				MagicCard to_add;
				file >> to_add;
				this->deck.addCard(&to_add);
			}
			for (; currPend < pend; currPend++) {
				PendulumCard to_add;
				file >> to_add;
				this->deck.addCard(&to_add);
			}
			if (currMonst == monst && currMag == mag && currPend == pend) {
				break;
			}
		}
		file.close();
		return true;
	}
}

CardType Duelist::setType(std::string new_type) {
	if (new_type == "trap" || new_type == "TRAP" || new_type == "Trap") {
		return CardType::TRAP;
	}
	else if (new_type == "buff" || new_type == "BUFF" || new_type == "Buff") {
		return CardType::BUFF;
	}
	else{
		return CardType::SPELL;
	}
	
}

void Duelist::duel(Duelist& opponent) {
	if (this->deck.getNumberofAllCards() == opponent.deck.getNumberofAllCards()) {
		this->deck.shuffle();
		opponent.deck.shuffle();
		int points1 = 0, points2 = 0, i = 0;
		for (auto card : this->deck.getCards()) {
			if (*card > *opponent.deck.getCards()[i]) {
				points1++;
			}
			else if (*card < *opponent.deck.getCards()[i]) {
				points2++;
			}
			i++;
		}
		if (points1 > points2) {
			cout << this->name << " WINNER" << endl;
		}
		else if (points1 < points2) {
			cout << opponent.name << " WINNER" << endl;
		}
		else {
			cout << "TIED" << endl;
		}
	}
	else {
		cout << "This duel is impossible due to different number of cards." << endl;
	}

}