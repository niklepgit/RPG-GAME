#ifndef INVENTORY
#define INVENTORY

#include "Spell.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
#include "Potion.hpp"

class Hero;

/*
#include "../../Spells/Spell.hpp"
#include "../../Items/Weapon.hpp"
#include "../../Items/Armor.hpp"
#include "../../Items/Potion.hpp"
*/

#include <list>
using namespace std;
class Inventory{
	public:
		list<Spell> Spells;
		list<Weapon> Weapons;
		list<Armor> Armors;
		list<Potion> Potions;

	public:
		/*Accessors*/
		//Spell& getSpells(int index);
		//Weapon& getWeapon(int index);
		//Armor& getArmors(int index);

		/*Prints*/
		void printSpells(void);
		void printWeapons(void);
		void printArmors(void);
		void printPotions(void);

		/*delete*/
		void deleteWeapon(int number,int&Money,Hero&hero);
		void deleteArmor(int number,int&Money);
		void deletePotion(int number,int&Money);
		void deleteSpell(int number,int&Money);

		/*Others*/
		int checkInventory(Hero& hero,int inBattle);

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