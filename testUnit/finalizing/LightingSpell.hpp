#ifndef LIGHTINGSPELL
#define LIGHTINGSPELL

#include "Spell.hpp"

class LightingSpell:public Spell{
	public:
		/*constructor*/
		LightingSpell(string Name,int MinLevel);

		/*castSpell*/
		void castSpell(Monster& monster);

		/*undoSpell*/
		void undoSpell(Monster& monster);
		
		/*printTypeOfSpell*/
		void printTypeOfSpell();
};

#endif