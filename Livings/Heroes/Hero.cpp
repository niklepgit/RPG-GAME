#include "Hero.hpp"

/* Constructor */
Hero::Hero(string Name,int Strength,int Dexterity,int Agility)
		  :Living(Name),strength(Strength),dexterity(Dexterity),
		  agility(Agility),magicPower(100),money(0),experience(0){}