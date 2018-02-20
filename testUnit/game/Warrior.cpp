#include "Warrior.hpp"

/* Constructor */
Warrior::Warrior(string Name)
			    :Hero(Name,15,8,12,250,200,250){}

/* increase attributes */
void Warrior::increaseAttributes(){
	increaseStrength(getLevel()*2); 
	increaseDexterity(getLevel()*1); 
	increaseAgility(getLevel()*2);
}

	
