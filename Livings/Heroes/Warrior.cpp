#include "Warrior.hpp"

Warrior::Warrior(string Name,
			 	 int MagicPower,int Strenght,int Dexterity,
			     int Agility,int Money,int Experience)
				 :Living(Name,Level,HealthPower),
				 magicPower(MagicPower)

void Warrior::increaseAttributes()
{
	strength += getLevel()*5;
	dexterity += getLevel()*3;
	agility += getLevel()*5;
}