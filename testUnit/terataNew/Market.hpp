#ifndef MARKET
#define MARKET

#include <iostream>
#include <list>
#include <string>
#include "LightingSpell.hpp"
#include "FireSpell.hpp"
#include "IceSpell.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
#include "Potion.hpp"
#include "Hero.hpp"

using namespace std;

class Market{
	private:
		list<Spell*> Spells;
		list<Weapon> Weapons;
		list<Armor> Armors;
		list<Potion> Potions;

	public:
		/*Accessors*/
		Spell& getSpells(int index);
		list<Weapon>& getWeapon(int index);
		list<Armor>& getArmors(int index);

		/*Prints*/
		void printSpells(void);
		void printWeapons(void);
		void printArmors(void);
		void printPotions(void);

		/*Others*/
		void addWeapon(string Name,int MinLevel);
		void addArmor(string Name,int MinLevel);
		void addPotion(string Name,int MinLevel,string WtIncrease);
		void addSpell(string Name,int MinLevel);
		void checkMarket(void);
		void menuMarket(Hero**&heroes,int arraySize);
		void printOptionsForMenu(void);
		void printOptionsForSelling(void);
		void Sell(Hero& hero);
		void Buy(Hero&hero);
		Armor buyArmor(int position,int& Money);
		Weapon buyWeapon(int position,int& Money);
		Potion buyPotion(int position,int& Money);
		Spell* buySpell(int position,int& Money);
};

#endif