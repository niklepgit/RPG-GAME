#ifndef WARRIOR
#define WARRIOR

#include "Hero.hpp"

class Warrior:public Hero{
	
	public:
		/*constructor*/
		Warrior(string);

		/*Destructor*/
		~Warrior();
		
		/*Mutators*/
		void increaseAttributes();

};

#endif