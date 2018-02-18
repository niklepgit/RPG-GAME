#include "FireSpell.hpp"
/*constructor*/
FireSpell::FireSpell(string Name,int MinLevel):Spell(Name,MinLevel){}

/*castSpell*/
void FireSpell::castSpell(Monster& monster){
	monster.undoSpellDefense=monster.getDefense();
	if(monster.getDefense()-monster.getDefense()/2 >0)
		monster.reduceDefense(monster.getDefense()-monster.getDefense()/2);
	else
		monster.reduceDefense(monster.getDefense());
}

/*undoSpell*/
void FireSpell::undoSpell(Monster& monster){
	monster.increaseDefense(monster.undoSpellDefense-monster.getDefense());
}

/*printTypeOfSpell*/
void FireSpell::printTypeOfSpell(){
	cout<<"Type of Spell:FireSpell"<<endl;
}