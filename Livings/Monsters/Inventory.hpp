#ifndef INVENTORY
#define INVENTORY

#include "Spell.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"

class Inventory{
	private:
		list<Spell> Spells;
		list<Weapon> Weapons;
		list<Armor> Armors;
	public:
		/*Accessors*/
		Spell& getSpells(int index);
		Weapon& getWeapon(int index);
		Armors& get Armors(int index);

		/*Prints*/
		void printSpells(void);
		void printWeapons(void);
		void printArmors(void);
};

#endif