#include "Sorcerer.hpp"

/* Constructor */
Sorcerer::Sorcerer(string Name)
				:Hero(Name,8,15,12,200,250,250){}

/* increase attributes */
void Sorcerer::increaseAttributes(){
	increaseStrength(getLevel()*1); 
	increaseDexterity(getLevel()*2); 
	increaseAgility(getLevel()*2);
}