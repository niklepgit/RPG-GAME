#include "FireSpell.hpp"
/*constructor*/
FireSpell::FireSpell(string Name,int MinLevel):Spell(Name,MinLevel){}

/*castSpell*/
void FireSpell::castSpell(Monster& monster){
	monster.undoSpellDefense = monster.getDefense();	//save current defense to undo the spell
	monster.reduceDefense(monster.getDefense()/2);	//reduce the defense of the monster by almost half
}

/*undoSpell*/
void FireSpell::undoSpell(Monster& monster){
	monster.increaseDefense(monster.undoSpellDefense-monster.getDefense());
}

/*printTypeOfSpell*/
void FireSpell::printTypeOfSpell(){
	cout << "Type of Spell:FireSpell" << endl;
}