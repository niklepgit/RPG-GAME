#include "Market.hpp"
#include <iostream>
using namespace std;

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
