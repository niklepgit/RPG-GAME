#include "Weapon.hpp"
#include "Potion.hpp"
#include "Armor.hpp"
#include "Living.hpp"
#include "Hero.hpp"
#include "Paladin.hpp"
#include "Sorcerer.hpp"
#include "Warrior.hpp"
#include "Inventory.hpp"
#include "Market.hpp"
#include "Spell.hpp"
#include "Grid.hpp"

/*
#include "./Items/Weapon.hpp"
#include "./Items/Potion.hpp"
#include "./Items/Armor.hpp"
#include "./Livings/Living.hpp"
#include "./Livings/Heroes/Hero.hpp"
#include "./Livings/Heroes/Paladin.hpp"
#include "./Livings/Heroes/Sorcerer.hpp"
#include "./Livings/Heroes/Warrior.hpp"
#include "./Livings/Heroes/Inventory.hpp"
#include "./Market/Market.hpp"
#include "./Spells/Spell.hpp"
#include "./Grid/Grid.hpp"
*/

#include "iofunctions.hpp"
#include <fstream>
#include <iostream>
using namespace std;

int main(void){

	/*variables*/
	int MinLevel;
	string Name,WtIncrease;
	int stop=0;
	int i;
	Market *market=new Market();
	int numberOfHeroes;
	int typeOfHero;
	string nameOfHero;

	fstream weapons_txt;
	fstream armors_txt;
	fstream potions_txt;
	fstream spells_txt;
	
	/*open files*/
	weapons_txt.open("./InputFiles/Weapons.txt",fstream::in); //open weapons_txt for input
	armors_txt.open("./InputFiles/Armors.txt",fstream::in); //open armors_txt for input
	potions_txt.open("./InputFiles/Potions.txt",fstream::in); //open potions_txt for input
	spells_txt.open("./InputFiles/Spells.txt",fstream::in); //open spells_txt for input

	while(!weapons_txt.eof()){
		readWeapon(stop,weapons_txt,Name,MinLevel);
		market->addWeapon(Name,MinLevel); 
		if(stop)
			break;	
	}

	stop=0;
	while(!armors_txt.eof()){
		readArmor(stop,armors_txt,Name,MinLevel);
		market->addArmor(Name,MinLevel);
		if(stop)
			break;	
	}

	stop=0;
	while(!potions_txt.eof()){
		readPotion(stop,potions_txt,Name,MinLevel,WtIncrease);
		market->addPotion(Name,MinLevel,WtIncrease);
		if(stop)
			break;	
	}

	stop=0;
	while(!spells_txt.eof()){
		readSpell(stop,spells_txt,Name,MinLevel);//it has to change
		market->addSpell(Name,MinLevel);
		if(stop)
			break;
	}

	cout<<"How many heroes you want to have?"<<endl
		<<"give a number between 1-3"<<endl;
	cin>>numberOfHeroes;

/*UI for creation of heroes*/
	Hero**Heroes=new Hero*[numberOfHeroes];
	for(i=0;i<numberOfHeroes;i++){
		cout<<"Give a name for Hero "<<i+1<<" and a number between 1-3 for the type of Hero."<<endl
			<<"1)Warrior, 2)Paladin, 3)Sorcerer"<<endl;
		cin>>nameOfHero;	
		cin>>typeOfHero;
		switch(typeOfHero){
			case 1:Heroes[i]=new Warrior(nameOfHero);
				   break;
			case 2:Heroes[i]=new Paladin(nameOfHero);
				   break;
			case 3:Heroes[i]=new Sorcerer(nameOfHero);
				   break;
			default:cout<<"Wrong value for type of Hero, please give a new one"<<endl;
					i--;
					break;
		}
	}

	Heroes[0]->increaseMoney(100000);

/*Grid*/
Grid* g = new Grid;
	char keyInput;
	do {

		g->displayMap();
		keyInput = g->getmv();
		switch(keyInput){
			case 'm':
				if (!g->nextToMarket())
					break;
				g->clearScreen();
				market->menuMarket(Heroes,numberOfHeroes);
				break;
			case 'p':
				g->clearScreen();
				for (int i = 0; i < numberOfHeroes; ++i){
					Heroes[i]->printHero();
					Heroes[i]->printSkills();
				}
				cout << "Press enter to continue...";
				getchar();
				break;
			case 'i':
				g->clearScreen();
				cout << "For which hero you want to see inventory?" << endl;
				switch(getchar()){
					case '1':
						Heroes[0]->inventory.checkInventory();
						getchar();
						cout << "Press enter to continue";
						getchar();
						break;
					case '2':
						Heroes[1]->inventory.checkInventory();
						getchar();
						cout << "Press enter to continue";
						getchar();
						break;
					case '3':
						Heroes[2]->inventory.checkInventory();
						getchar();
						cout << "Press enter to continue";
						getchar();
						break;
					default:
						break;
				}
				break;
			default:
				break;
		};
		g->clearScreen();
	} while (keyInput != 'q');	

	/*close files*/
	weapons_txt.close();
	armors_txt.close();
	potions_txt.close();
	spells_txt.close();

	return 0;
}