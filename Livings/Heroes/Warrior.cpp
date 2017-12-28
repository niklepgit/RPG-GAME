#include "Warrior.hpp"

Warrior::Warrior(string Name)
			   :Living(Name){
				   	
}

/* increase attributes */
void Warrior::increaseAttributes(){
	strength += getLevel()*5;
	dexterity += getLevel()*3;
	agility += getLevel()*5;
}

	
