#include "Market.hpp"
#include <iostream>
using namespace std;

/*addWeapon*/
void Market::addWeapon(string Name,int MinLevel){
	Weapon weapon(Name,MinLevel);
	Weapons.push_back(weapon);
}

/*addArmor*/
void Market::addArmor(string Name,int MinLevel){
	Armor armor(Name,MinLevel);
	Armors.push_back(armor);
}

/*addPotion*/
void Market::addPotion(string Name,int MinLevel,string WtIncrease){
	Potion potion(Name,MinLevel,WtIncrease);
	Potions.push_back(potion);
}

/*addSpell*/
void Market::addSpell(string Name,int MinLevel){
	Spell spell(Name,MinLevel);
	Spells.push_back(spell);
}

/*printSpells*/
void Market::printSpells(void){
	int i=0;
	list<Spell>::iterator it;
	cout<<"Spells are:"
	for(it=Spells.begin();it!=Spells.end();it++){ //for every spell
		cout<<"<------"<<i++<<"------>"<<endl;
		it->printSpell(); //call the print function for the spell
		cout<<endl; //leave one line empty
	}
}

/*printWeapons*/
void Market::printWeapons(void){
	int i=0;
	list<Weapon>::iterator it;
	cout<<"Weapons are:"
	for(it=Weapons.begin();it!=Weapons.end();it++){ //for every weapon
		cout<<"<------"<<i++<<"------>"<<endl;
		it->printWeapon(); //call the print function for the weapon
		cout<<endl; //leave one line empty
	}
}

/*printArmors*/
void Market::printArmors(void){
	int i=0;
	list<Armor>::iterator it;
	cout<<"Armors are:"
	for(it=Armors.begin();it!=Armors.end();it++){ //for every Armor
		cout<<"<------"<<i++<<"------>"<<endl;
		it->printArmor(); //call the print function for the Armor
		cout<<endl; //leave one line empty
	}
}

/*printPotions*/
void Market::printPotions(void){
	int i=0;
	list<Potion>::iterator it;
	cout<<"Potions are:"
	for(it=Potions.begin();it!=Potions.end();it++){ //for every spell
		cout<<"<------"<<i++<<"------>"<<endl;
		it->printPotion(); //call the print function for the spell
		cout<<endl; //leave one line empty
	}
}

/*checkMarket*/
void Market::checkMarket(void){
	printWeapons();
	printArmors();
	printSpells();
	printPotions();
}

/*menuMarket*/
void Market::menuMarket(Hero**&heroes,int numberOfHeroes){
	char ch,ch1;
	printOptions();

	ch=getchar();
	switch(ch){
		case '1':cout<<"For which Hero you want to buy?"<<endl;
				 for(i=0;i<numberOfHeroes;i++){
				 	cout<<i+1<<":"<<endl;
				 	heroes[i]->printHero();
				 }
				 ch1=getchar();
				 //call buy
				 break;
		case '2':cout<<"For which Hero you want to sell?"<<endl;
				 for(i=0;i<numberOfHeroes;i++){
				 	cout<<i+1<<":"<<endl;
				 	heroes[i]->printHero();
				 }
				 ch1=getchar();
				 break;

		case 'q':return;
				 
	}
}

/*Sell*/
void Market::Sell(Hero& hero)

/*printOptions*/
void Market::printOptions(void){
	cout<<"Options:"<<endl
		<<"1)Buy"<<endl
		<<"2)Sell"<<endl<<endl;
	cout<<"Press 1,2 or q to exit"<<endl;
}
