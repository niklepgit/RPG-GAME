#ifndef ICESPELL
#define ICESPELL

#include "Spell.hpp"

class IceSpell:public Spell{
	public:
		/*constructor*/
		IceSpell(string Name,int MinLevel):Spell(Name,MinLevel){}

		/*castSpell*/
		void castSpell(Monster& monster){
			monster.undoSpellDamageRange=(monster.getMaxDamageRange()-monster.getMinDamageRange());
			if((monster.getMaxDamageRange()-monster.getMinDamageRange())/2 > monster.getMinDamageRange())
				monster.reduceDamageRange((monster.getMaxDamageRange()-monster.getMinDamageRange())/2);
			else
				monster.reduceDamageRange(monster.getMinDamageRange());
		}

		/*undoSpell*/
		void undoSpell(Monster& monster){
			monster.increaseDamageRange(monster.undoSpellDamageRange);
		}

		/*printTypeOfSpell*/
		void printTypeOfSpell(){
			cout<<"Type of Spell:IceSpell"<<endl;
		}
};

#endif