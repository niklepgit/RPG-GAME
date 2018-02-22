#include "iofunctions.hpp"
#include <fstream>
#include <cstddef>
#include "Game.hpp"
using namespace std;

int main(void){

	/*variables*/
	int MinLevel;
	string Name,WtIncrease;
	int stop = 0;
	Market *market = new Market();

	fstream weapons_txt;
	fstream armors_txt;
	fstream potions_txt;
	fstream spells_txt;
	
	/*open files*/
	weapons_txt.open("./InputFiles/Weapons.txt",fstream::in); //open weapons_txt for input
	armors_txt.open("./InputFiles/Armors.txt",fstream::in); //open armors_txt for input
	potions_txt.open("./InputFiles/Potions.txt",fstream::in); //open potions_txt for input
	spells_txt.open("./InputFiles/Spells.txt",fstream::in); //open spells_txt for input

	/*READ FILES*/

	while(!weapons_txt.eof()){
		readWeapon(stop,weapons_txt,Name,MinLevel); //read the weapon from file
		market->addWeapon(Name,MinLevel); 			//add it to market
		if(stop)
			break;	
	}

	stop = 0;
	while(!armors_txt.eof()){
		readArmor(stop,armors_txt,Name,MinLevel);
		market->addArmor(Name,MinLevel);
		if(stop)
			break;	
	}

	stop = 0;
	while(!potions_txt.eof()){
		readPotion(stop,potions_txt,Name,MinLevel,WtIncrease);
		market->addPotion(Name,MinLevel,WtIncrease);
		if(stop)
			break;	
	}

	stop = 0;
	while(!spells_txt.eof()){
		readSpell(stop,spells_txt,Name,MinLevel);//it has to change
		market->addSpell(Name,MinLevel);
		if(stop)
			break;
	}

	Game myGame;

	myGame.gameplay(*market);

	/*delete market*/
	delete market;

	/*close files*/
	weapons_txt.close();
	armors_txt.close();
	potions_txt.close();
	spells_txt.close();

	return 0;
}