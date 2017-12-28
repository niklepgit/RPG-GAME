#include "Paladin.hpp"

void Paladin::increaseAttributes()
{
	strength += getLevel()*5;
	dexterity += getLevel()*5;
	agility += getLevel()*3;
}