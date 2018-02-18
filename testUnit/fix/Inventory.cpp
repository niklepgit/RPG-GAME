#include "Inventory.hpp"
#include "Hero.hpp"
#include <iostream>
using namespace std;

/*deleteArmor*/
void Inventory::deleteArmor(int number,int&Money){ 
	list<Armor>::iterator it;
	int counter=1;
	for(it=Armors.begin();it!=Armors.end();it++){ //for every armor
		if(counter==number){					  //if you find the armor that the user put
			Money=it->getValue();				//get the money
			it=Armors.erase(it);				//delete the armor from list
			it--;								//it's necessary because erase returns it++
			break;
		}
		counter++;
	}
}

/*deleteSpell*/
void Inventory::deleteSpell(int number,int&Money){  //same as armor
	list<Spell*>::iterator it;
	int counter=1;
	for(it=Spells.begin();it!=Spells.end();it++){
		if(counter==number){
			Money=(*it)->getValue();
			it=Spells.erase(it);
			it--;
			break;
		}
		counter++;
	}
}

/*deleteWeapon*/
void Inventory::deleteWeapon(int number,int&Money,Hero& hero){
	list<Weapon>::iterator it;
	int counter=1;
	for(it=Weapons.begin();it!=Weapons.end();it++){ //for every weapon on the list
		if(counter==number){						//if you find the weapon that the user gave
			if(hero.Lhand==&(*it))					//if the hero has the weapon on his left hand
				hero.Lhand=nullptr;					//make left hand point to nullptr
			if(hero.Rhand==&(*it))					//if the hero has the weapon on his right hand
				hero.Rhand=nullptr;					//make right hand point to nullptr
			Money=it->getValue();					//get the money from the weapon
			it=Weapons.erase(it);					//erase the weapon
			it--;									
			break;
		}
		counter++;
	}
}

/*deletePotion*/
void Inventory::deletePotion(int number,int&Money){	//same as armor
	list<Potion>::iterator it;
	int counter=1;
	for(it=Potions.begin();it!=Potions.end();it++){
		if(counter==number){
			Money=it->getValue();
			it=Potions.erase(it);
			it--;
			break;
		}
		counter++;
	}
}

/*printSpells*/
void Inventory::printSpells(void){
	int i=0;
	list<Spell*>::iterator it;
	cout<<"Spells are:"<<endl;
	for(it=Spells.begin();it!=Spells.end();it++){ //for every spell
		cout<<"<------"<<++i<<"------>"<<endl;
		(*it)->printSpell(); //call the print function for the spell
		cout<<endl; //leave one line empty
	}
}

/*printWeapons*/
void Inventory::printWeapons(void){
	int i=0;
	list<Weapon>::iterator it;
	cout<<"Weapons are:"<<endl;
	for(it=Weapons.begin();it!=Weapons.end();it++){ //for every weapon
		cout<<"<------"<<++i<<"------>"<<endl;
		it->printWeapon(); //call the print function for the weapon
		cout<<endl; //leave one line empty
	}
}

/*printArmors*/
void Inventory::printArmors(void){
	int i=0;
	list<Armor>::iterator it;
	cout<<"Armors are:"<<endl;
	for(it=Armors.begin();it!=Armors.end();it++){ //for every Armor
		cout<<"<------"<<++i<<"------>"<<endl;
		it->printArmor(); //call the print function for the Armor
		cout<<endl; //leave one line empty
	}
}

/*printPotions*/
void Inventory::printPotions(void){
	int i=0;
	list<Potion>::iterator it;
	cout<<"Potions are:"<<endl;
	for(it=Potions.begin();it!=Potions.end();it++){ //for every spell
		cout<<"<------"<<++i<<"------>"<<endl;
		it->printPotion(); //call the print function for the spell
		cout<<endl; //leave one line empty
	}
}

/*checkInventory*/
int Inventory::checkInventory(Hero&hero,int inBattle){
	int ch,ch1;
	printOptionsForSeeing();
	cin>>ch;
	switch(ch){
		case 1:printWeapons();															//if you want to see weapons print the weapons
			   cout<<"If you  want to equip give weapon's number else 0 to exit."<<endl;
			   cin>>ch1;																//take input from user
			   if(ch1==0)																//if he wants to exit then break
			    break;																	//break from switch statement
			   hero.weaponEquip(ch1);													//else equip the weapon
			   break;																	//break from switch statement
		case 2:printArmors();															//if you want to see armors print the armors
			   cout<<"If you  want to equip give armor's number else 0 to exit."<<endl;
			   cin>>ch1;																//take input from user
			   if(ch1==0)																//if he wants to exit then break
			   	break;																	//break from switch statement	
			   hero.armorEquip(ch1);
			   break;																	//break from switch statement
		case 3:printPotions();															//if you want to see potions print the potions
			   cout<<"If you want to use a Potion give it's number else 0 to exit."<<endl;
			   cin>>ch1;																//take input from user
			   if(ch1==0)																//if he wants to exit then break
			   	break;																	//break from switch statement
			   hero.findAndUsePotion(ch1); //find and use Potion
			   return 1;																//returns 1 which means that the hero used a potion
		case 4:printSpells();															//if you want to see spells print the spells
			   if(inBattle){															//if the hero is in a battle then
				   cout<<"If you want to cast a Spell give it's number else 0 to exit."<<endl; //ask if he want to cast a spell
				   cin>>ch1;															//take input from user
				   if(ch1==0)															//if he wants to exit then break
				   		break;															//break from switch statement
				   //cast spell
				   if(hero.MySpell==nullptr)											//if the hero doesn't have a spell
				   	hero.spellEquip(ch1);												//equip the spell
				   else																	//else
				   	cout<<"You can't use a spell right now."<<endl;						//print message
				}
	    	   break;																	//break from switch statement
	    default:																		//if the user put an other string or number
	    		if(cin.fail()){															//if the fail bit is 1 else if the user put a string
					cin.clear(); 														// reset failbit
			   		cin.ignore(100, '\n'); 												//skip bad input
	    			cout<<"Wrong option."<<endl;										//print appropriate message
	    			return 2;															//return 2 which means that something wrong happened
				}

	    		cin.ignore(100, '\n');													//ignore the bad input
	    		cout<<"Wrong option."<<endl;											//print message
	    		return 2;																//return 2 which means that something wrong happened
	}
	return 0;																			//the hero didn't use a potion and everything was great
}


/*addWeapon*/
void Inventory::addWeapon(Weapon weapon){
	Weapons.push_back(weapon);
}

/*addArmor*/
void Inventory::addArmor(Armor armor){
	Armors.push_back(armor);
}

/*addPotion*/
void Inventory::addPotion(Potion potion){
	Potions.push_back(potion);
}

/*addSpell*/
void Inventory::addSpell(Spell* spell){//i *&
	Spells.push_back(spell);
}

/*printOptionsForSeeing*/
void Inventory::printOptionsForSeeing(void){
	cout<<"Options:"<<endl
		<<"1)Weapons"<<endl
		<<"2)Armors"<<endl
		<<"3)Potions"<<endl
		<<"4)Spells"<<endl<<endl;
	cout<<"Press 1,2,3,4 or anything else to exit"<<endl;
}