#include "Warrior.hpp"

/* Constructor */
Warrior::Warrior(string Name)
			    :Hero(Name,15,8,12){}

/* increase attributes */
void Warrior::increaseAttributes(){
	increaseStrength(getLevel()*5); 
	increaseDexterity(getLevel()*3); 
	increaseAgility(getLevel()*5);
}

	
