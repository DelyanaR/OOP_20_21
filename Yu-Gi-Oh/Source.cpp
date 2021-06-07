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
#include <iostream>
#include "duelist.hpp"
using namespace std;

int main() {
	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 0, 3000, 2500);
	MonsterCard magician("Dark Magician", "The ultimate wizard.", 23, 2500, 2100);

	MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", 123, CardType::SPELL);
	MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 9, CardType::TRAP);

	PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 3, 1200, 600, 8, CardType::BUFF);

	Duelist firstDuelist("Zhehcko Popov");
	firstDuelist.getDeck().setName("Magician Deck");
	firstDuelist.getDeck().addCard(&dragon);
	firstDuelist.getDeck().addCard(&swords);
	firstDuelist.getDeck().addCard(&magician);
	firstDuelist.getDeck().addCard(&cylinder);
	firstDuelist.getDeck().addCard(&timegazer);
	firstDuelist.getDeck().shuffle();

	cout << firstDuelist.getDeck().getNumberofAllCards() << endl;
	cout << firstDuelist.getDeck().getNumberofMagicCards() << endl;
	cout << firstDuelist.getDeck().getNumberofMonsterCards() << endl;
	cout << firstDuelist.getDeck().getNumberofPendulumCards() << endl;

	/*firstDuelist.writeFromFile("ex.txt");*/

	MagicCard box("Mystic Box", "Destroy one monster.", 0, CardType::SPELL);
	firstDuelist.getDeck().changeCard(2, &box);//it won't be able to change the card because the types don't match
	firstDuelist.getDeck().changeCard(4, &box);

	Duelist secondDuelist("Gosho Goshev");
	secondDuelist.getDeck().addCard(&dragon);
	secondDuelist.getDeck().addCard(&swords);
	secondDuelist.getDeck().addCard(&magician);
	secondDuelist.getDeck().addCard(&cylinder);
	secondDuelist.getDeck().addCard(&timegazer);

	firstDuelist.duel(secondDuelist);

	firstDuelist.writeToFile("new.txt");
	secondDuelist.writeToFile("new.txt");

	return 0;
}