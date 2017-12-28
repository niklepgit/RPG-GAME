#ifndef WARRIOR
#define WARRIOR

#include "Hero.hpp"

class Warrior:public Hero{
	private:

	public:
		/*constructor*/
		Warrior(string Name);

		/*Mutators*/
		void increaseAttributes();

};

#endif