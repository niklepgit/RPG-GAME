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

		/*Others*/
		void checkInventory(void);
};

#endif