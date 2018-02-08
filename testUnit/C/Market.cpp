#include "Market.hpp"
#include <cstdlib>

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
	cout<<"Spells are:"<<endl;
	for(it=Spells.begin();it!=Spells.end();it++){ //for every spell
		cout<<"<------"<<++i<<"------>"<<endl;
		it->printSpell(); //call the print function for the spell
		cout<<endl; //leave one line empty
	}
}

/*printWeapons*/
void Market::printWeapons(void){
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
void Market::printArmors(void){
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
void Market::printPotions(void){
	int i=0;
	list<Potion>::iterator it;
	cout<<"Potions are:"<<endl;
	for(it=Potions.begin();it!=Potions.end();it++){ //for every spell
		cout<<"<------"<<++i<<"------>"<<endl;
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
	printOptionsForMenu();
	int i;
	cin>>ch;
	switch(ch){
		case '1':cout<<"For which Hero you want to buy?"<<endl;
				 for(i=0;i<numberOfHeroes;i++){
				 	cout<<i+1<<":"<<endl;
				 	heroes[i]->printHero();
				 }
				 cin>>ch1;
				 //call buy
				 break;
		case '2':cout<<"For which Hero you want to sell?"<<endl;
				 for(i=0;i<numberOfHeroes;i++){
				 	cout<<i+1<<":"<<endl;
				 	heroes[i]->printHero();
				 }
				 cin>>ch1;
				 Sell(*heroes[ch1]);
				 break;

		case 'q':return;
				 
	}
}

/*Sell*/
void Market::Sell(Hero& hero){
	char ch,ch1;
	cout<<"What do you want to sell?"<<endl;
	printOptionsForSelling();
	cin>>ch;
	int Money;
	switch(ch){
		case '1':hero.inventory.printWeapons();
				cout<<"Which weapon you want to sell?"<<endl;
				cout<<"press q to quit"<<endl;
				cin>>ch1;
				if(ch1=='q')
					return;
				hero.inventory.deleteWeapon(ch1,Money);
				hero.increaseMoney(Money/2);
				break;
		case '2':hero.inventory.printArmors();
				cout<<"Which armor you want to sell?"<<endl;
				cout<<"press q to quit"<<endl;
				cin>>ch1;
				if(ch1=='q')
					return;
				hero.inventory.deleteArmor(ch1,Money);
				hero.increaseMoney(Money/2);
				break;
		case '3':hero.inventory.printPotions();
				cout<<"Which Potion you want to sell?"<<endl;
				cout<<"press q to quit"<<endl;
				cin>>ch1;
				if(ch1=='q')
					return;
				hero.inventory.deletePotion(ch1,Money);
				hero.increaseMoney(Money/2);
				break;
		case '4':hero.inventory.printSpells();
				cout<<"Which spell you want to sell?"<<endl;
				cout<<"press q to quit"<<endl;
				cin>>ch1;
				if(ch1=='q')
					return;
				hero.inventory.deleteSpell(ch1,Money);
				hero.increaseMoney(Money/2);
				break;
		case 'q':return;		
	}
}

/*printOptions*/
void Market::printOptionsForMenu(void){
	cout<<"Options:"<<endl
		<<"1)Buy"<<endl
		<<"2)Sell"<<endl<<endl;
	cout<<"Press 1,2 or q to exit"<<endl;
}

/*printOptionsForSelling*/
void Market::printOptionsForSelling(void){
	cout<<"Options:"<<endl
		<<"1)Weapons"<<endl
		<<"2)Armors"<<endl
		<<"3)Potions"<<endl
		<<"4)Spells"<<endl<<endl;
	cout<<"Press 1,2,3,4 or q to exit"<<endl;
}