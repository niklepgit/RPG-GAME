#ifndef FIRESPELL
#define FIRESPELL

#include "Spell.hpp"

class FireSpell:public Spell{
	public:
		/*constructor*/
		FireSpell(string Name,int MinLevel):Spell(Name,MinLevel){}

		/*castSpell*/
		void castSpell(Monster& monster){
			monster.undoSpellDefense=monster.getDefense();
			if(monster.getDefense()-monster.getDefense()/2 >0)
				monster.reduceDefense(monster.getDefense()-monster.getDefense()/2);
			else
				monster.reduceDefense(monster.getDefense());
		}

		/*undoSpell*/
		void undoSpell(Monster& monster){
			monster.increaseDefense(monster.undoSpellDefense-monster.getDefense());
		}

		
		/*printTypeOfSpell*/
		void printTypeOfSpell(){
			cout<<"Type of Spell:FireSpell"<<endl;
		}
};

#endif