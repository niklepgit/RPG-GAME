#include <iostream>

int main(void){

	/*variables*/
	int MinLevel;
	string Name,WtIncrease;
	int stop=0;

	fstream weapons_txt;
	fstream armors_txt;
	fstream potions_txt;
	fstream spells_txt;

	/*open files*/
	weapons_txt.open("...",fstream::in); //open weapons_txt for input
	armors_txt.open("...",fstream::in); //open armors_txt for input
	potions_txt.open("...",fstream::in); //open potions_txt for input
	spells_txt.open("...",fstream::in); //open spells_txt for input

	while(!weapons_txt.eof()){
		readWeapon(stop,weapons_txt,Name,MinLevel);
		if(stop)
			break;
		market1.addWeapon(Name,MinLevel); //example
	}

	stop=0;
	while(!armors_txt.eof()){
		readArmor(stop,armors_txt,Name,MinLevel);
		if(stop)
			break;
	}

	stop=0;
	while(!potions_txt.eof()){
		readPotion(stop,potions_txt,Name,MinLevel,WtIncrease);
		if(stop)
			break;
	}

	stop=0;
	while(!spells_txt.eof()){
		readSpell(stop,potions_txt,Name,MinLevel,WtIncrease);//it has to change
		if(stop)
			break;
	}

	/*close files*/
	weapons_txt.close();
	armors_txt.close();
	potions_txt.close();
	spells_txt.close();

	return 0;
}