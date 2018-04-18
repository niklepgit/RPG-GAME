#ifndef SORCERER
#define SORCERER

#include "Hero.hpp"

class Sorcerer:public Hero{
	
	public:
		/*Constructor*/
		Sorcerer(string);
		
		/*Mutators*/
		void increaseAttributes();

};

#endif