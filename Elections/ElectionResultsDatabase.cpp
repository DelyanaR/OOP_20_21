#include "ElectionResultsDatabase.hpp"

void ElectionResultsDatabase::addResultsFromFile(const char* filename) {
	std::ifstream file;
	file.open(filename, std::ios::in);
	file.seekg(0, std::ios::beg);
	if (file.is_open()) {
		file >> *this;
		file.close();
	}
}

int ElectionResultsDatabase::numberOfSections() const {
	return this->myVect.size();
}

int ElectionResultsDatabase::votesForParty(Party number) const {
	return countVotes(number);
}

Party ElectionResultsDatabase::winningParty() const {
	int allvotes1 = countVotes(Party::PARTY1), allvotes2 = countVotes(Party::PARTY2), allvotes3 = countVotes(Party::PARTY3);
	if (allvotes1 >= allvotes2 && allvotes1 >= allvotes3) {
		return PARTY1;
	}
	else if (allvotes2 >= allvotes1 && allvotes2 >= allvotes3) {
		return PARTY2;
	}
	else {
		return PARTY3;
	}
}

int ElectionResultsDatabase::countVotes(Party number)const {
	int to_return = 0;
	for (int i = 0; i < this->myVect.size(); i++) {
		to_return += this->myVect[i].votesForParty(number);
	}
	return to_return;
}
