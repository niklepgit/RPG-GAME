#include "Warrior.hpp"

/* Constructor */
Warrior::Warrior(string Name,int Strength = 15,int Dexterity = 8,int Agility = 12)
			    :Hero(Name,Strength,Dexterity,Agility){}

/* increase attributes */
void Warrior::increaseAttributes(){
	strength += getLevel()*5;
	dexterity += getLevel()*3;
	agility += getLevel()*5;
}

	
