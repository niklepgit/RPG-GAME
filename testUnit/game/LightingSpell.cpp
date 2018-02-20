#include "LightingSpell.hpp"

/*constructor*/
LightingSpell::LightingSpell(string Name,int MinLevel):Spell(Name,MinLevel){}

/*castSpell*/
void LightingSpell::castSpell(Monster& monster){
	monster.undoSpellProbability=monster.getProbability();

	if(monster.getProbability()-monster.getProbability()/2 > 0)
		monster.reduceProbability(monster.getProbability()-monster.getProbability()/2);
	else
		monster.reduceProbability(monster.getProbability());
}

/*undoSpell*/
void LightingSpell::undoSpell(Monster& monster){
	monster.increaseProbability(monster.undoSpellProbability-monster.getProbability());
}

/*printTypeOfSpell*/
void LightingSpell::printTypeOfSpell(){
	cout<<"Type of Spell:LightingSpell"<<endl;
}
