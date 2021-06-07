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
#include<fstream>
#include <istream>
#include"deck.hpp"

class Duelist{
public:
	Duelist();
	Duelist(std::string new_name);
	Deck& getDeck();
	bool writeToFile(const std::string filename);
	bool writeFromFile(const std::string filename);
	void duel(Duelist& opponent);
private:
	std::string name;
	Deck deck;
	CardType setType(std::string new_type);
};

