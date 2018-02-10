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
#include "Monster.hpp"
#include "Dragon.hpp"
#include "Spirit.hpp"
#include "Exoskeleton.hpp"

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

int getAverageLevelOfHeroes(Hero**& heroes,int NumberOfHeroes); //forward decleration
void displayStats(Hero**& heroes, Monster**& monsters,int NumberOfHeroes);
int monstersAreDead(Monster**&monsters,int NumberOfHeroes);
int heroesAreDead(Hero**&heroes,int NumberOfHereos);
void attack(Hero& hero,Monster**& monsters,int NumberOfHeroes);
void destroyMonsters(Monster**& monsters,int NumberOfHeroes);
void heroesAfterLosing(Hero**& heroes,int NumberOfHeroes);


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
				for (int i = 0; i < numberOfHeroes; ++i)
					Heroes[i]->printHero();
				cout << "Press enter to continue...";
				getchar();
				break;
			case 'i':
				g->clearScreen();
				cout << "For which hero you want to see inventory?" << endl;
				switch(getchar()){
					case '1':
						Heroes[0]->inventory.checkInventory(*Heroes[0]);
						getchar();
						cout << "Press enter to continue";
						getchar();
						break;
					case '2':
						Heroes[1]->inventory.checkInventory(*Heroes[1]);
						getchar();
						cout << "Press enter to continue";
						getchar();
						break;
					case '3':
						Heroes[2]->inventory.checkInventory(*Heroes[2]);
						getchar();
						cout << "Press enter to continue";
						getchar();
						break;
					default:
						break;
				}
				break;
			case 'b':{
					//g->clearScreen();
					int levelOfMonsters=getAverageLevelOfHeroes(Heroes,numberOfHeroes);
					Monster** Monsters=new Monster*[numberOfHeroes];
					int randomMonster;
					for(int j=0;j<numberOfHeroes;j++){
						randomMonster = rand()%3;
						switch(randomMonster){
							case 0:
								Monsters[j] = new Dragon("Dragon",levelOfMonsters); 
								break;
							case 1:
								Monsters[j] = new Spirit("Spirit",levelOfMonsters);
								break;
							case 2:
								Monsters[j] = new Exoskeleton("Exoskeleton",levelOfMonsters);
								break;
							default:break;
						}
					}
					//call battle function
					int option;
					int i;
					int check; //check if the user used a Potion or casted a Spell in inventory
					int counter=0; //counter for the rounds
					displayStats(Heroes,Monsters,numberOfHeroes);
					do{
						counter++;
						for(i=0;i<numberOfHeroes;i++){
							//print options
							cout<<"For hero "<<i+1<<":"<<endl;
							cout<<"If you want to check the inventory press 1"<<endl;
							cout<<"If you want to start the Attack press 2"<<endl;

							cin>>option;
							switch(option){
								case 1:
									    check=Heroes[i]->inventory.checkInventory(*Heroes[i]); //checkInventory for the current hero
										getchar();
										cout << "Press enter to continue";
										getchar();
										if(check)
											break;
								case 2: cout<<"Attack of Hero "<<i+1;
										attack(*Heroes[i],Monsters,numberOfHeroes); //attack with the current hero
							}
						}
						for(i=0;i<numberOfHeroes;i++){
							int whoToHit=rand()%numberOfHeroes; //generate a random number between 0-2 to choose the hero
							Heroes[whoToHit]->attackToHero(Monsters[i]->generateHit()); //hit the chosen hero 
						}	
						displayStats(Heroes,Monsters,numberOfHeroes);
					}while(monstersAreDead(Monsters,numberOfHeroes) && heroesAreDead(Heroes,numberOfHeroes)); //while all heroes or all monsters die
					getchar();
					getchar();

					if(!heroesAreDead(Heroes,numberOfHeroes)){
						heroesAfterLosing(Heroes,numberOfHeroes);
					}
					if(!monstersAreDead(Monsters,numberOfHeroes)){
						cout<<"The heroes won!!!!"<<endl;
						cout<<"Press enter to continue...!!"<<endl;
						getchar();
					}

					destroyMonsters(Monsters,numberOfHeroes);
					break;
				
				}
			default:
				break;
		} //;
		g->clearScreen();
	} while (keyInput != 'q');	

	/*close files*/
	weapons_txt.close();
	armors_txt.close();
	potions_txt.close();
	spells_txt.close();

	return 0;
}

/*destroyMonsters*/
void destroyMonsters(Monster**& monsters,int NumberOfHeroes){
	for(int i=0;i<NumberOfHeroes;i++){
		delete monsters[i];
		monsters[i]=nullptr;
	}
	delete monsters;
	monsters=nullptr;
}

/*heroesAfterLosing*/
void heroesAfterLosing(Hero**& heroes,int NumberOfHeroes){
	for(int i=0;i<NumberOfHeroes;i++){
		heroes[i]->reduceMoneyAfterLosing();
		if(heroes[i]->getCurrHealthPower()==0)
			heroes[i]->regenerateHealthPowerAfterLosing();
	}
}

/*monstersAreDead*/
int monstersAreDead(Monster**&monsters,int NumberOfHeroes){
	int life=0;
	for(int i=0;i<NumberOfHeroes;i++){ //for every monster
		life += monsters[i]->getCurrHealthPower(); //add the health
	}
	return life; //return 0 if all monsters are dead else != 0
}
/*heroesAreDead*/
int heroesAreDead(Hero**&heroes,int NumberOfHeroes){
	int life=0;
	for(int i=0;i<NumberOfHeroes;i++){ //for every monster
		life += heroes[i]->getCurrHealthPower(); //add the health
	}
	return life; //return 0 if all monsters are dead else != 0
}

/*attack*/
void attack(Hero& hero,Monster**& monsters,int NumberOfHeroes){
	int option;
		cout<<" to Monster: (give a number between 1-"<<NumberOfHeroes<<")"<<endl;
		cin>>option;

		//checking for existing Monster
		while(option<1 && option>NumberOfHeroes){
			cout<<"Wrong input please give a number between 1-"<<NumberOfHeroes<<")"<<endl;	
			cin>>option;
		}
		//checking for alive Monster
		while(monsters[option-1]->getCurrHealthPower()==0){
			cout<<"This monster has no life. Choose another one."<<endl;
			cin>>option;
		}
		
		if(hero.Lhand==hero.Rhand && hero.Rhand!=nullptr)
			monsters[option-1]->attackToMonster(hero.Rhand->getDamageValue()+hero.getStrength()); 
		else if(hero.Lhand==nullptr && hero.Rhand==nullptr)			
			monsters[option-1]->attackToMonster(hero.getStrength());
		else if(hero.Rhand==nullptr)
			monsters[option-1]->attackToMonster(hero.Lhand->getDamageValue()+hero.getStrength());	
		else
			monsters[option-1]->attackToMonster(hero.Rhand->getDamageValue()+hero.getStrength());
		
	}


/*getAverageLevelOfHeroes*/
int getAverageLevelOfHeroes(Hero**& heroes,int NumberOfHeroes){
	int averageLevel=0;
	for(int i=0;i<NumberOfHeroes;i++){
		averageLevel += heroes[i]->getLevel();
	}
	return averageLevel/NumberOfHeroes;
}

//void battle(Hero**& heroes, Monster**& monsters,int NumberOfHeroes){}
void displayStats(Hero**& heroes, Monster**& monsters,int NumberOfHeroes){
	for(int i=0;i<NumberOfHeroes;i++){
		cout << "Name: "<< heroes[i]->getName(); cout<<'\t'<<'\t'<<"Name: "<< monsters[i]->getName(); cout<<endl;
		cout << "Level: "<< heroes[i]->getLevel(); cout<<'\t'<<'\t'<< "Level: "<< monsters[i]->getLevel(); cout<<endl;
			 //<< "Experience: "<< experience << cout<<'\t'<<'\t'<<
		cout << "HP: "<<heroes[i]->getCurrHealthPower(); cout<< "/"<< heroes[i]->getMaxHealthPower(); cout<<'\t'<<'\t'<<"HP: "<< monsters[i]->getCurrHealthPower(); cout<< "/"<<monsters[i]->getMaxHealthPower(); cout<<endl;
		cout << "MP: "<< heroes[i]->getCurrMagicPower(); cout<< "/"<<heroes[i]->getMaxMagicPower(); cout<<'\t'<<'\t'<<"DamageRange: "<< monsters[i]->getMinDamageRange(); cout<< "-"<< monsters[i]->getMaxDamageRange(); cout<<endl;
		cout << "Dexterity: "<<heroes[i]->getDexterity(); cout<<'\t'<<'\t'<<"Probability: "<< monsters[i]->getProbability(); cout<<endl;
		cout << "Agility: "<< heroes[i]->getAgility(); cout<<'\t'<<'\t'<<"Defense: "<<monsters[i]->getDefense(); cout<<endl;
		cout << "Strength: "<< heroes[i]->getStrength(); cout<< endl; // cout<<'\t'<<'\t'<<
		
		if(heroes[i]->MyArmor!=nullptr)
			cout << "Armor: " << heroes[i]->MyArmor->getDamageSave();cout<<endl;
		
		if(heroes[i]->Lhand==heroes[i]->Rhand && heroes[i]->Rhand!=nullptr)
			cout << "Weapon's damage: " << heroes[i]->Rhand->getDamageValue()<<endl<<endl; 
		else if(heroes[i]->Lhand==nullptr && heroes[i]->Rhand==nullptr)
			cout << "Both hands are empty." << endl<<endl;
		else if(heroes[i]->Rhand==nullptr)
			cout << "Left hand->weapon's damage:"<<heroes[i]->Lhand->getDamageValue()<<endl<<endl;
		else
			cout << "Right hand->weapon's damage:"<<heroes[i]->Rhand->getDamageValue()<<endl<<endl;
	}
}
//void endOfBattle(){}