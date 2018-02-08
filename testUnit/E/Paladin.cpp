#include "Paladin.hpp"

/* Constructor */
Paladin::Paladin(string Name)
				:Hero(Name,15,12,8){}

/* increase attributes */
void Paladin::increaseAttributes(){
	increaseStrength(getLevel()*5); 
	increaseDexterity(getLevel()*5); 
	increaseAgility(getLevel()*3);
}