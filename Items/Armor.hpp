#ifndef ARMOR
#define ARMOR

#include "Item.hpp"

class Armor:public Item{
	private:
		int damageSave;
		int inUse;
	public:
		//should somehow use healthPower from class living
		/*Others*/
		void printArmor(void);
};
#endif