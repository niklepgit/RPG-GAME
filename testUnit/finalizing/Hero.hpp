#ifndef HERO
#define HERO

#include "Living.hpp"
#include "Inventory.hpp"
#include <list>
#include <cstddef>	// needed for nullptr
using namespace std;

class Hero:public Living{
	private:
		int strength;
		int dexterity;
		int agility;
		int maxStrength;
		int maxDexterity;
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
		Hero(string,int,int,int,int,int,int);

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
		void increaseStrength(int strengthToIncrease);
		void increaseDexterity(int dexterityToIncrease);
		void increaseAgility(int agilityToIncrease);
		virtual void increaseAttributes(){}

		void regenerateHealthPowerAfterLosing();
		void reduceMoneyAfterLosing();
		void attackToHero(int DamageValue);
		int weaponEquip(int position);
		int armorEquip(int position);
		void regenerateMagicPowerAfterRound();
		int checkIfLevelUp();

		int findAndUsePotion(int position);
		int spellEquip(int position);
};

#endif