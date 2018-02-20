#ifndef SORCERER
#define SORCERER

#include "Hero.hpp"

class Sorcerer:public Hero{
	private:

	public:
		/*Constructor*/
		Sorcerer(string);

		/*Destructor*/
		~Sorcerer();
		
		/*Mutators*/
		void increaseAttributes();

};

#endif