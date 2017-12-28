#include "Paladin.hpp"

/* Constructor */
Paladin::Paladin(string Name,int Strength = 15,int Dexterity = 12,int Agility = 8)
				:Hero(Name,Strength,Dexterity,Agility){}

/* increase attributes */
void Paladin::increaseAttributes(){
	strength += getLevel()*5;
	dexterity += getLevel()*5;
	agility += getLevel()*3;
}