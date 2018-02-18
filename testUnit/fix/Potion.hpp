#ifndef POTION
#define POTION

#include "Item.hpp"
class Hero;

class Potion:public Item{
	private:
		int used; //if it has been used then 1 else 0
		string wtIncrease; //what to increase
		int hmtIncrease; //how much to increase

	public:
		/*Constructor*/
		Potion(string Name,int MinLevel,string WtIncrease);
		
		/*usePotion*/
		void usePotion(Hero& hero);

		/*printPotion*/
		void printPotion(void);

};

#endif