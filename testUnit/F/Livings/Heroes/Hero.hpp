#ifndef HERO
#define HERO

#include "../Living.hpp"
#include "Inventory.hpp"
#include <list>

class Hero:public Living{
	private:
		int currMagicPower;
		int maxMagicPower;
		int strength;
		int dexterity;
		int agility;
		int money;
		int experience;
	public:
		Inventory inventory;

	public:
		/*constructor*/
		Hero(string,int,int,int);

		/*Accessors*/
		int getMagicPower() const { return currMagicPower; }
		int getStrength() const { return strength; }
		int getDexterity() const { return dexterity; }
		int getAgility() const { return agility; }
		int getMoney() const { return money; }
		int getExperience() const { return experience; }
		void printHero() const;
		void printSkills() const;

		/*Mutators*/
		void levelUp();
		void reduceMagicPower(int magicPowerToSub) { currMagicPower -= magicPowerToSub; }
		void updateExperience(int experienceGained) { experience += experienceGained; }
		void reduceMoney(int moneyLosted) { money -= moneyLosted; }
		void increaseMoney(int moneyGained) { money += moneyGained; }
		void increaseMagicPower(int);
		void increaseStrength(int strengthToIncrease) { strength += strengthToIncrease; }
		void increaseDexterity(int dexterityToIncrease) { dexterity += dexterityToIncrease; }
		void increaseAgility(int agilityToIncrease) { agility += agilityToIncrease; }
		virtual void increaseAttributes(){}
};

#endif