#include "Sorcerer.hpp"

void Sorcerer::increaseAttributes()
{
	strength += getLevel()*3;
	dexterity += getLevel()*5;
	agility += getLevel()*5;
}