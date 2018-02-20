#ifndef PALADIN
#define PALADIN

#include "Hero.hpp"

class Paladin:public Hero{
	private:

	public:
		/*Constructor*/
		Paladin(string);

		/*Mutators*/
		void increaseAttributes();

};

#endif