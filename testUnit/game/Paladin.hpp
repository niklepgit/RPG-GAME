#ifndef PALADIN
#define PALADIN

#include "Hero.hpp"

class Paladin:public Hero{
	
	public:
		/*Constructor*/
		Paladin(string);

		/*Mutators*/
		void increaseAttributes();

};

#endif