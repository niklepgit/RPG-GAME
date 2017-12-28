#ifndef HERO
#define HERO

#include "../Living.hpp"
#include "../../Spells/Spell.hpp"
#include <list>

class Hero:public Living{
	private:
		int magicPower;
		int strength;
		int dexterity;
		int agility;
		int money;
		int experience;
		
		list<Spell> Spells;
		list<Weapon> Weapons;
		list<Armor> Armors;

	public:
		/*constructor*/
		Hero(int Name,int Level,int HealthPower,
			 int MagicPower,int Strenght,int Dexterity,
			 int Agility,int Money,int Experience);

		/*Accessors*/
		int getMagicPower() const { return magicPower; }
		int getStrength() const { return strength; }
		int getDexterity() const { return dexterity; }
		int getAgility() const { return agility; }
		int getMoney() const { return money; }
		int getExperience() const { return experience; }

		/*Mutators*/
		void reduceMagicPower(int magicPowerToSub) { magicPower -= magicPowerToSub; } 	// change sub to reduce just for mutator's name
		void updateExperience(int experienceGained) { experience += experienceGained; }
		void reduceMoney(int moneyLosted) { money -= moneyLosted; }
		void increaseMoney(int moneyGained) { money += moneyGained; }
		virtual void increaseAttributes()=0;
};

#endif