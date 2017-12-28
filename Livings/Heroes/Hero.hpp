#ifndef HERO
#define HERO

#include "../Living.hpp"

class Hero:public Living{
	private:
		int magicPower;
		int strength;
		int dexterity;
		int agility;
		int money;
		int experience;

	public:
		/*constructor*/
		Hero(int Name,int Level,int HealthPower,
			 int MagicPower,int Strenght,int Dexterity
			 ,int Agility,int Money,int Experience);

};

#endif