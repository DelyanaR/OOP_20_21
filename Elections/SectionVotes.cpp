#include "SectionVotes.hpp"

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes): votesParty1(party1Votes), votesParty2(party2Votes), votesParty3(party3Votes){
}

int SectionVotes::votesForParty(Party number) const{
	if (number == Party::PARTY1) {
		return this->votesParty1;
	}
	else if (number == Party::PARTY2) {
		return this->votesParty2;
	}
	else {
		return this->votesParty3;
	}
}

SectionVotes::SectionVotes(): votesParty1(0), votesParty2(0), votesParty3(0) {
}
