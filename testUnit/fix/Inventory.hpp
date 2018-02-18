#ifndef INVENTORY
#define INVENTORY

#include "Spell.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
#include "Potion.hpp"

class Hero; 

#include <list>
using namespace std;

class Inventory{
	public:
		list<Spell*> Spells;
		list<Weapon> Weapons;
		list<Armor> Armors;
		list<Potion> Potions;

	public:
		/*Prints*/
		void printSpells(void);
		void printWeapons(void);
		void printArmors(void);
		void printPotions(void);
		void printOptionsForSeeing(void);

		/*delete*/
		void deleteWeapon(int number,int&Money,Hero&hero);
		void deleteArmor(int number,int&Money);
		void deletePotion(int number,int&Money);
		void deleteSpell(int number,int&Money);

		/*add*/
		void addWeapon(Weapon weapon);
		void addArmor(Armor armor);
		void addPotion(Potion potion);
		void addSpell(Spell* spell);


		/*Others*/
		int checkInventory(Hero& hero,int inBattle);

	
};

#endif