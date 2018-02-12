#ifndef ARMOR
#define ARMOR

#include "Item.hpp"

class Armor:public Item{
	private:
		int damageSave;
		int inUse;
	public:
		/*Constructor*/
		Armor(string Name,int MinLevel);
		
		//should somehow use healthPower from class living
		/*Others*/
		void printArmor(void);
		int getDamageSave(void) {return damageSave;}
};
#endif