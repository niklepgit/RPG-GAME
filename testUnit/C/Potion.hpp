#ifndef POTION
#define POTION

#include "Item.hpp"

class Potion:public Item{
	private:
		int used; //if it has been used then 1 else 0
		string wtIncrease; //what to increase
		int hmtIncrease; //how much to increase
	public:
		/*Constructor*/
		Potion(string Name,int MinLevel,string WtIncrease);
		//void usePotion(Hero& hero);
		void printPotion(void);
		//function that increases a valid data member
		//in classes Warrior,Sorcerer and Paladin
		//valid data members:magicPower strength dexterity agility
};

#endif