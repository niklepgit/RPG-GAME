#include "Warrior.hpp"

Warrior::Warrior(string Name,
			 	 int MagicPower,int Strenght,int Dexterity,
			     int Agility,int Money,int Experience)
				 :Living(Name,Level,HealthPower),
				 magicPower(MagicPower)