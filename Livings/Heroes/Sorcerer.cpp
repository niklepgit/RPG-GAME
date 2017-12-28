#include "Sorcerer.hpp"

/* Constructor */
Sorcerer::Sorcerer(string Name,int Strength = 8,int Dexterity = 15,int Agility = 12)
				:Hero(Name,Strength,Dexterity,Agility){}

/* increase attributes */
void Sorcerer::increaseAttributes(){
	strength += getLevel()*3;
	dexterity += getLevel()*5;
	agility += getLevel()*5;
}