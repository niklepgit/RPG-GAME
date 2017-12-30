#ifndef POTION
#define POTION

#include "Item.hpp"

class Potion:public Item{
	private:
		int used; //if it has been used then 1 else 0
		string wtIncrease; //what to increase
	public:
		/*Constructor*/
		Potion(string Name,int Value,int MinLevel,string WtIncrease);
		
		//function that increases a valid data member
		//in classes Warrior,Sorcerer and Paladin
		//valid data members:magicPower strength dexterity agility
};

#endif