#ifndef WEAPON
#define WEAPON

#include "Item.hpp"

class Weapon:public Item{
	private:
		int damageValue;
		int hands;
	public:
		/*Constructor*/
		Weapon(string Name,int MinLevel);
		
		/*Accessors*/
		int getHands() const { return hands; }
		int getDamageValue() const { return damageValue; }

		/*Others*/
		void printWeapon(void);
};

#endif