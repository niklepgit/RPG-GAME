#include "IceSpell.hpp"	

/*constructor*/
IceSpell::IceSpell(string Name,int MinLevel):Spell(Name,MinLevel){}

/*castSpell*/
void IceSpell::castSpell(Monster& monster){
	monster.undoSpellDamageRange = (monster.getMaxDamageRange()-monster.getMinDamageRange());
	if((monster.getMaxDamageRange()-monster.getMinDamageRange())/2 > monster.getMinDamageRange())
		monster.reduceDamageRange((monster.getMaxDamageRange()-monster.getMinDamageRange())/2);
	else
		monster.reduceDamageRange(monster.getMinDamageRange());
}

/*undoSpell*/
void IceSpell::undoSpell(Monster& monster){
	monster.increaseDamageRange(monster.undoSpellDamageRange);
}

/*printTypeOfSpell*/
void IceSpell::printTypeOfSpell(){
	cout << "Type of Spell:IceSpell" << endl;
}