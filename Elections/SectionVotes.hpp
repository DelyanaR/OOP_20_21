#include<iostream>
#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

enum Party
{
    PARTY1 = 0,
    PARTY2 = 1,
    PARTY3 = 2,
};

class SectionVotes{
public:

    SectionVotes(int party1Votes, int party2Votes, int party3Votes);

    int votesForParty(Party) const;

    SectionVotes();

    friend std::istream& operator>>(std::istream& in, SectionVotes& vote) {
        for (int i = 0; i < 3; i++) {
            int input1=0;
            in >> input1;
            if (i==0) vote.votesParty1 = input1;
            else if (i == 1) vote.votesParty2 = input1;
            else vote.votesParty3 = input1;
        }
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const SectionVotes& vote) {
        out<< vote.votesParty1 << " " << vote.votesParty2 << " " << vote.votesParty3 << std::endl;
        return out;
    }


private:
    int votesParty1;
    int votesParty2;
    int votesParty3;
};


