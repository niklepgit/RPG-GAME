#ifndef ICESPELL
#define ICESPELL

#include "Spell.hpp"

class IceSpell:public Spell{
	public:
		/*constructor*/
		IceSpell(string Name,int MinLevel);

		/*castSpell*/
		void castSpell(Monster& monster);
		/*undoSpell*/
		void undoSpell(Monster& monster);

		/*printTypeOfSpell*/
		void printTypeOfSpell();
};

#endif