#include "LightingSpell.hpp"

/*constructor*/
LightingSpell::LightingSpell(string Name,int MinLevel):Spell(Name,MinLevel){}

/*castSpell*/
void LightingSpell::castSpell(Monster& monster){

	monster.undoSpellProbability=monster.getProbability(); //save current probability to undo spell
	monster.reduceProbability(monster.getProbability()/2); //reduce almost half probability of monster
}

/*undoSpell*/
void LightingSpell::undoSpell(Monster& monster){
	monster.increaseProbability(monster.undoSpellProbability-monster.getProbability());
}

/*printTypeOfSpell*/
void LightingSpell::printTypeOfSpell(){
	cout<<"Type of Spell:LightingSpell"<<endl;
}
