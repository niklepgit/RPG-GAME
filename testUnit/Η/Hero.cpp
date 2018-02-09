#include "Hero.hpp"

/* Constructor */
Hero::Hero(string Name,int Strength,int Dexterity,int Agility)
		  :Living(Name),strength(Strength),dexterity(Dexterity),
		  agility(Agility),currMagicPower(100),maxMagicPower(100),money(0),experience(0),Lhand(nullptr),Rhand(nullptr),MyArmor(nullptr){}

void Hero::printHero()const{
	cout << "Name: " << name << endl
		 << "Level: " << level << endl
		 << "Experience: "<< experience << endl
		 << "HP: " << currHealthPower << "/" << maxHealthPower << endl
		 << "MP: " << currMagicPower << "/" << maxMagicPower << endl
		 << "Money: " << money << endl;
		 
	if(Lhand==Rhand && Rhand!=nullptr){
			cout << "Both hands use:" << endl; 
			Rhand->printWeapon();
	}
	else if(Lhand==nullptr && Rhand==nullptr)
			cout << "Both hands are empty" << endl;
	else if(Rhand==nullptr){
			cout << "Right hand is empty." << endl;
		  	cout << "Left hand uses:" << endl; 
		  	Lhand->printWeapon();
	}	
	else{
		cout << "Right hand uses:" << endl;
	    Rhand->printWeapon();
	}
}

void Hero::printSkills()const{
	cout << "Strength: " << getStrength() << endl
		 << "Dexterity: " << getDexterity() << endl
		 << "Agility: " << getAgility() << endl << endl;
}

void Hero::increaseMagicPower(int magicPowerToIncrease){
	if (currMagicPower + magicPowerToIncrease > maxMagicPower){
		currMagicPower = maxMagicPower;
		return;
	}
	currMagicPower += magicPowerToIncrease;
}

void Hero::levelUp(){
	level++;
	setMaxHealthPower();
	maxMagicPower += 10;
	setCurrHealthPower();
	currMagicPower = maxMagicPower;
	increaseAttributes();
}
/*weaponEquip*/
void Hero::weaponEquip(int position){
	list<Weapon>::iterator it;
	int counter=1;
	int Hands;
	for(it=inventory.Weapons.begin();it!=inventory.Weapons.end();it++){
		if(counter==position){
			Hands=it->getHands();
			if(Hands==2)
				Lhand=Rhand=&(*it);
			else
				if(Lhand==nullptr)
					Lhand=&(*it);
				else if(Rhand==nullptr)
					Rhand=&(*it);
				else{
					Rhand=&(*it);
					Lhand=nullptr;
				}
			return;
		}
		counter++;
	}
}

/*armorEquip*/
void Hero::armorEquip(int position){
	list<Armor>::iterator it;
	int counter=1;
	int Hands;
	for(it=inventory.Armors.begin();it!=inventory.Armors.end();it++){
		if(counter==position){
			MyArmor=&(*it);
			return;
		}
		counter++;
	}
}