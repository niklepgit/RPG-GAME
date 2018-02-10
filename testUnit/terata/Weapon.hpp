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
		
		/*Others*/
		void printWeapon(void);
		int getHands() {return hands;}
		int getDamageValue() { return damageValue; }
		//void weaponAttack(void);
};

#endif