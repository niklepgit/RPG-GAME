#ifndef LIGHTINGSPELL
#define LIGHTINGSPELL

#include "Spell.hpp"

class LightingSpell:public Spell{
	public:
		/*constructor*/
		LightingSpell(string Name,int MinLevel):Spell(Name,MinLevel){}

		/*castSpell*/
		void castSpell(Monster& monster){
			monster.undoSpellProbability=monster.getProbability();
			if(monster.getProbability()-monster.getProbability()/2 >0)
				monster.reduceProbability(monster.getProbability()-monster.getProbability()/2);
			else
				monster.reduceProbability(monster.getProbability());
		}

		/*undoSpell*/
		void undoSpell(Monster& monster){
			monster.increaseProbability(monster.undoSpellProbability-monster.getProbability());
		}

		
		/*printTypeOfSpell*/
		void printTypeOfSpell(){
			cout<<"Type of Spell:LightingSpell"<<endl;
		}
};

#endif