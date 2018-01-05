#ifndef WEAPON
#define WEAPON

#include "Item.hpp"

class Weapon:public Item{
	private:
		int damageValue;
		int hands;
		int inUse;
	public:
		/*Constructor*/
		Weapon(string Name,int MinLevel);
		
		/*Others*/
		void printWeapon(void);
		void weaponAttack(void);
};

#endif