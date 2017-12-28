#ifndef SORCERER
#define SORCERER

#include "Hero.hpp"

class Sorcerer:public Hero{
	private:

	public:
		/*Constructor*/
		Sorcerer(string,int,int,int);
		/*Mutators*/
		void increaseAttributes();

};

#endif