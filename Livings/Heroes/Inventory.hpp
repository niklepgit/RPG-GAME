#ifndef INVENTORY
#define INVENTORY

#include "Spell.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
#include "Potion.hpp"
#include <list>
using namespace std;
class Inventory{
	private:
		list<Spell> Spells;
		list<Weapon> Weapons;
		list<Armor> Armors;
		list<Potion> Potions;

	public:
		/*Accessors*/
		Spell& getSpells(int index);
		Weapon& getWeapon(int index);
		Armor& getArmors(int index);

		/*Prints*/
		void printSpells(void);
		void printWeapons(void);
		void printArmors(void);
		void printPotions(void);

		/*delete*/
		void deleteWeapon(int number,int&Money);
		void deleteArmor(int number,int&Money);
		void deletePotion(int number,int&Money);
		void deleteSpell(int number,int&Money);

		/*Others*/
		void checkInventory(void);

		void addWeapon(Weapon weapon);
		void addArmor(Armor armor);
		void addPotion(Potion potion);
		void addSpell(Spell spell);

		/*
		void addWeapon(string Name,int MinLevel);
		void addArmor(string Name,int MinLevel);
		void addPotion(string Name,int MinLevel,string WtIncrease);
		void addSpell(string Name,int MinLevel);
		*/
};

#endif