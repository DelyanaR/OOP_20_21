#pragma once
#include<fstream>
#include<vector>
#include "SectionVotes.hpp"

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

class ElectionResultsDatabase{

public:

    void addResultsFromFile(const char* filename);

    int numberOfSections() const;

    int votesForParty(Party number) const;

    Party winningParty() const;

    friend std::istream& operator>>(std::istream& in, ElectionResultsDatabase& vote) {
        while (!(in.eof())) {
            int input1 = 0, input2 = 0, input3 = 0;
            in >> input1 >> input2 >> input3;
            SectionVotes to_add(input1, input2, input3);
            vote.myVect.push_back(to_add);
        }
        int lastPos = vote.myVect.size() - 1;
        if (vote.myVect[lastPos].votesForParty(PARTY1)==0 && vote.myVect[lastPos].votesForParty(PARTY2) == 0 && vote.myVect[lastPos].votesForParty(PARTY3) == 0) {
            vote.myVect.pop_back();
        }
        return in;
    }
        
    friend std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& vote) {
        out.seekp(0, std::ios::beg);
            for (int i = 0; i < vote.myVect.size(); i++) {
                out << vote.myVect[i];
            }
            out.seekp(0, std::ios::end);
            return out;
    }

    int countVotes(Party number)const;

private:
    std::vector<SectionVotes>myVect;
};

