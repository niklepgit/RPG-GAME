#include "Paladin.hpp"

/* Constructor */
Paladin::Paladin(string Name)
				:Hero(Name,15,12,8,124){}

/* increase attributes */
void Paladin::increaseAttributes(){
	increaseStrength(getLevel()*2); 
	increaseDexterity(getLevel()*2); 
	increaseAgility(getLevel()*1);
}