#include "iofunctions.cpp"
#include <iostream>

using namespace std;

/*read_weapon*/
void readWeapon(int& stop,fstream& weapons_txt,string& Name,int& MinLevel){

	weapons_txt>>Name;
	weapons_txt>>MinLevel;

	if(weapons_txt.eof())
		stop=1;
}

/*read_armor*/
void readArmor(int& stop,fstream& armors_txt,string& Name,int& MinLevel){

	armors_txt>>Name;
	armors_txt>>MinLevel;

	if(armors_txt.eof())
		stop=1;
}

/*read_potion*/
void readPotion(int& stop,fstream& potions_txt,string& Name,int& MinLevel,string& WtIncrease){

	potions_txt>>Name;
	potions_txt>>MinLevel;
	potions_txt>>WtIncrease;

	if(potions_txt.eof())
		stop=1;
}

/*read_spells*/
void readSpell(int& stop,fstream& spells_txt,string& Name,int& MinLevel){

	spells_txt>>Name;
	spells_txt>>MinLevel;

	if(spells_txt.eof())
		stop=1;
}

