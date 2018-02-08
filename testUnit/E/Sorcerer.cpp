#include "Sorcerer.hpp"

/* Constructor */
Sorcerer::Sorcerer(string Name)
				:Hero(Name,8,15,12){}

/* increase attributes */
void Sorcerer::increaseAttributes(){
	increaseStrength(getLevel()*3); 
	increaseDexterity(getLevel()*5); 
	increaseAgility(getLevel()*5);
}