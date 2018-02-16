#include "FireSpell.hpp"

/*castSpell*/
void FireSpell::castSpell(Monster& monster){
	monster.undoSpellDefense=monster.getDefense();
	if(monster.getDefense()-monster.getDefense()/2 >0)
		monster.reduceDefense(monster.getDefense()-monster.getDefense()/2);
	else
		monster.reduceDefense(monster.getDefense());
}