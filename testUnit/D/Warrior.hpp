#ifndef WARRIOR
#define WARRIOR

#include "Hero.hpp"

class Warrior:public Hero{
	private:

	public:
		/*constructor*/
		Warrior(string);

		/*Mutators*/
		void increaseAttributes();

};

#endif