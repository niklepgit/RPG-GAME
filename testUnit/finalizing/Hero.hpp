#ifndef HERO
#define HERO

#include "Living.hpp"
#include "Inventory.hpp"
#include <list>
#include <cstddef>
using namespace std;

class Hero:public Living{
	private:
		int strength;
		int dexterity;
		int agility;
		int maxAgility;
		int currMagicPower;
		int maxMagicPower;
		
		
		int money;
		int experience;
		int experienceToLevelUp;
	
	public:
		Weapon *Rhand;
		Weapon *Lhand;
		Armor *MyArmor;
		Spell *MySpell;
		Inventory inventory;

	public:
		/*constructor*/
		Hero(string,int,int,int,int);

		/*Accessors*/
		int getCurrMagicPower() const { return currMagicPower; }
		int getMaxMagicPower() const { return maxMagicPower; }
		int getStrength() const { return strength; }
		int getDexterity() const { return dexterity; }
		int getAgility() const { return agility; }
		int getMaxAgility() const { return maxAgility; }
		int getMoney() const { return money; }
		int getExperience() const { return experience; }
		void printHero() const;


		/*Mutators*/
		void levelUp();
		int reduceMagicPower(int magicPowerToSub);
		void increaseExperience(int experienceGained) { experience += experienceGained; }
		void reduceMoney(int moneyLosted);
		void increaseMoney(int moneyGained) { money += moneyGained; }
		void increaseMagicPower(int);
		void increaseStrength(int strengthToIncrease) { strength += strengthToIncrease; }
		void increaseDexterity(int dexterityToIncrease) { dexterity += dexterityToIncrease; }
		void increaseAgility(int agilityToIncrease) { agility += agilityToIncrease; }
		virtual void increaseAttributes(){}

		void regenerateHealthPowerAfterLosing(void);
		void reduceMoneyAfterLosing(void);
		void attackToHero(int DamageValue);
		void weaponEquip(int position);
		void armorEquip(int position);
		void regenerateMagicPowerAfterRound(int round);
		int checkIfLevelUp();

		void findAndUsePotion(int position);
		void spellEquip(int position);
};

#endif