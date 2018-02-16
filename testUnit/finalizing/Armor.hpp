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
		
		/*Mutators*/
		int getDamageSave(void) const { return damageSave; }

		/*Others*/
		void printArmor(void);

};
#endif