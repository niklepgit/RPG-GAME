#include "Hero.hpp"
#include "Potion.hpp"

/* Constructor */
Hero::Hero(string Name,int Strength,int Dexterity,int Agility)
		  :Living(Name),strength(Strength),dexterity(Dexterity),
		  agility(Agility),currMagicPower(100),maxMagicPower(100),money(10),experience(0),experienceToLevelUp(10),
		  Lhand(nullptr),Rhand(nullptr),MyArmor(nullptr),MySpell(nullptr){}
	
/*printHero*/
void Hero::printHero()const{
	cout << "Name: " << name << endl
		 << "Level: " << level << endl;
	if (level < 10)
		cout << "Experience: " << experience << "/" << experienceToLevelUp << endl;
	cout << "HP: " << currHealthPower << "/" << maxHealthPower << endl
		 << "MP: " << currMagicPower << "/" << maxMagicPower << endl
		 << "Money: " << money << endl
		 << "Strength: " << getStrength() << endl //na bgalw tis sinartisis
		 << "Dexterity: " << getDexterity() << endl
		 << "Agility: " << getAgility() << endl << endl;

	if(MyArmor!=nullptr){
		cout << "Armor: " << endl;
		MyArmor->printArmor();
	}
	cout<<endl;

	if(Lhand==Rhand && Rhand!=nullptr){
			cout << "Both hands use:" << endl; 
			Rhand->printWeapon();
	}
	else if(Lhand==nullptr && Rhand==nullptr)
			cout << "Both hands are empty" << endl;
	else if(Lhand!=nullptr && Rhand!=nullptr){
		cout << "Right hand uses:" << endl;
	    Rhand->printWeapon();
	    cout<<endl;
	    cout << "Left hand uses:" << endl;
	    Lhand->printWeapon();
	}
	else if(Rhand==nullptr){
			cout << "Right hand is empty." << endl;
		  	cout << "Left hand uses:" << endl; 
		  	Lhand->printWeapon();
	}	
	else{
		cout << "Left hand is empty." << endl;
		cout << "Right hand uses:" << endl; 
		Rhand->printWeapon();
	}
	cout<<endl;
}

/*increaseMagicPower*/
void Hero::increaseMagicPower(int magicPowerToIncrease){
	if (currMagicPower + magicPowerToIncrease > maxMagicPower){
		currMagicPower = maxMagicPower;
		return;
	}
	currMagicPower += magicPowerToIncrease;
}

/*levelUp*/
void Hero::levelUp(){
	level++;
	increaseAttributes();
	experienceToLevelUp+=level*8;
}

int Hero::checkIfLevelUp(){
/*
	if(experience>=experienceToLevelUp)
		return 1;
	else
		return 0;
*/
	return (experience>=experienceToLevelUp);
}

/*weaponEquip*/
void Hero::weaponEquip(int position){
	list<Weapon>::iterator it;
	int counter=1;
	int Hands;
	for(it=inventory.Weapons.begin();it!=inventory.Weapons.end();it++){ //for evey weapon 
		if(counter==position){ //if you find the weapon the hero want to equip
			Hands=it->getHands(); //get how many hands it requires
			if(Hands==1) //if the weapon uses 1 hand
				if(Lhand==&(*it) || Rhand==&(*it)) //if the hero has it already in his hand
					return;	//don't equip it again..exit
			if(Hands==2) //if it requires 2 hands
				Lhand=Rhand=&(*it); 
			else //if it requires 1 hand
				if(Lhand==nullptr) //if left is empty put it there
					Lhand=&(*it);
				else if(Rhand==nullptr) //if right is empty put it there
					Rhand=&(*it);
				else{ //if the weapon requires 1 hand but the hero uses a weapon with his 2 hands
					Lhand=nullptr; //throw the weapon
					Rhand=&(*it); //take weapon in the right hand
				}
			return;
		}
		counter++;
	}
}

/*findPotion*/
void Hero::findAndUsePotion(int position){
	list<Potion>::iterator it;
	int counter=1;
	for(it=inventory.Potions.begin();it!=inventory.Potions.end();it++){
		if(counter==position){
			it->usePotion(*this);
			it=inventory.Potions.erase(it);
			it--;
			return;
		}
		counter++;
	}
}

/*spellEquip*/
void Hero::spellEquip(int position){
	list<Spell*>::iterator it;
	int counter=1;
	for(it=inventory.Spells.begin();it!=inventory.Spells.end();it++){
		if(counter==position){
			MySpell=(*it);
			return;
		}
		counter++;
	}
}



/*armorEquip*/
void Hero::armorEquip(int position){
	list<Armor>::iterator it;
	int counter=1;
	for(it=inventory.Armors.begin();it!=inventory.Armors.end();it++){
		if(counter==position){
			MyArmor=&(*it);
			return;
		}
		counter++;
	}
}

/*attackToHero*/
void Hero::attackToHero(int DamageValue){
	if(MyArmor==nullptr)
		healthPowerReduce(DamageValue);
	else 
		if(DamageValue > MyArmor->getDamageSave())
		DamageValue -= MyArmor->getDamageSave();
	else{
		//MyArmor->getDamageSave()-= DamageValue; //should armor get destroyed?
		return;
	}
	healthPowerReduce(DamageValue);
}

/*reduceMoneyAfterLosing*/
void Hero::reduceMoneyAfterLosing(void){
	money = money/2; //almost the half 
}

/*regenerateHealthPowerAfterLosing*/
void Hero::regenerateHealthPowerAfterLosing(void){
	currHealthPower = maxHealthPower/2; //almost the half
}

/*regenerateMagicPowerAfterRound*/
void Hero::regenerateMagicPowerAfterRound(int round){
	if(currMagicPower+round*2<maxMagicPower)
		currMagicPower += round*2;
	else
		currMagicPower = maxMagicPower; //attention
}

int Hero::reduceMagicPower(int magicPowerToSub){
	if (currMagicPower >= magicPowerToSub){
		currMagicPower -= magicPowerToSub;
		return 1;
	}
	else
		return 0;

}

void Hero::reduceMoney(int moneyLosted){
	money -= moneyLosted;
}