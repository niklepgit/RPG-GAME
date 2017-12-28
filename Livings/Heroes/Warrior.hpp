#ifndef WARRIOR
#define WARRIOR

#include "Hero.hpp"

class Warrior:public Hero{
	private:

	public:
		/*constructor*/
		Warrrior(string Name,
			 	 int MagicPower,int Strenght,int Dexterity,
			     int Agility,int Money,int Experience);

		/*Mutators*/
		void increaseAttributes();

};

#endif