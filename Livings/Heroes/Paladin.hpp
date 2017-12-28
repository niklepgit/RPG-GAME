#ifndef PALADIN
#define PALADIN

#include "Hero.hpp"

class Paladin:public Hero{
	private:

	public:
		/*Constructor*/
		Paladin(string,int,int,int);

		/*Mutators*/
		void increaseAttributes();

};

#endif