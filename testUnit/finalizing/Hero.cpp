#include "Hero.hpp"
#include "Potion.hpp"

/* Constructor */
Hero::Hero(string Name,int Strength,int Dexterity,int Agility,int MaxStrength,int MaxDexterity,int MaxAgility)
		  :Living(Name),strength(Strength),dexterity(Dexterity),
		  agility(Agility),maxStrength(MaxStrength),maxDexterity(MaxDexterity),maxAgility(MaxAgility),currMagicPower(100),
		  maxMagicPower(100),money(25),experience(0),experienceToLevelUp(10),
		  Rhand(nullptr),Lhand(nullptr),MyArmor(nullptr),MySpell(nullptr){}
	
/*printHero*/
void Hero::printHero()const{
	cout << "Name: " << name << endl
		 << "Level: " << level << endl;
	if (level < 10)
		cout << "Experience: " << experience << "/" << experienceToLevelUp << endl;
	cout << "HP: " << currHealthPower << "/" << maxHealthPower << endl
		 << "MP: " << currMagicPower << "/" << maxMagicPower << endl
		 << "Money: " << money << endl
		 << "Strength: " << strength << endl //na bgalw tis sinartisis
		 << "Dexterity: " << dexterity << endl
		 << "Agility: " << agility << endl << endl;

	//If I have equiped an armor print
	if(MyArmor != nullptr){
		cout << "Armor: " << endl;
		MyArmor->printArmor();
	}
	cout<<endl;

	//If both hands use the same weapon print this weapon
	if(Lhand == Rhand && Rhand != nullptr){
			cout << "Both hands use:" << endl; 
			Rhand->printWeapon();
	}
	//If both hands don't use a weapon print empty hands
	else if(Lhand == nullptr && Rhand == nullptr)
			cout << "Both hands are empty" << endl;
	//If both hands use different weapons print these weapons
	else if(Lhand != nullptr && Rhand != nullptr){
		cout << "Right hand uses:" << endl;
	    Rhand->printWeapon();
	    cout<<endl;
	    cout << "Left hand uses:" << endl;
	    Lhand->printWeapon();
	}
	//If only left hand uses weapon print this weapon
	else if(Rhand == nullptr){
			cout << "Right hand is empty." << endl;
		  	cout << "Left hand uses:" << endl; 
		  	Lhand->printWeapon();
	}	
	//If only right hand uses weapon print this weapon
	else{
		cout << "Left hand is empty." << endl;
		cout << "Right hand uses:" << endl; 
		Rhand->printWeapon();
	}
	cout<<endl;
}

/*increaseMagicPower*/
void Hero::increaseMagicPower(int magicPowerToIncrease){
	//Increases Magic Power to magicPowerToIncrease
	if (currMagicPower + magicPowerToIncrease > maxMagicPower){
		currMagicPower = maxMagicPower;
		return;
	}
	currMagicPower += magicPowerToIncrease;
}

/*levelUp*/
void Hero::levelUp(){
	// level = level + 1
	level++;
	increaseAttributes();
	// experience to reach next level
	experienceToLevelUp += level*8;
}

/*checkIfLevelUp*/
int Hero::checkIfLevelUp(){
	return (experience >= experienceToLevelUp);
}

/*weaponEquip*/
int Hero::weaponEquip(int position){	// position => position of the weapon you want to equip
	list<Weapon>::iterator it;
	int counter = 1;
	int Hands;
	for(it = inventory.Weapons.begin(); it != inventory.Weapons.end(); it++){ //for every weapon 
		if(counter == position){ //if you find the weapon you want to equip to your Hero
			Hands = it->getHands(); //get how many hands it requires
			if(Hands == 1) //if the weapon uses 1 hand
				if(Lhand == &(*it) || Rhand == &(*it)) //if the hero has it already in his hand
					return 2;	//don't equip it again & exit
			if(Hands == 2) //if it requires 2 hands
				Lhand = Rhand = &(*it); 
			else //if it requires 1 hand
				if(Lhand == nullptr) //if left is empty put it there
					Lhand = &(*it);
				else if(Rhand == nullptr) //if right is empty put it there
					Rhand = &(*it);
				else if(Rhand->getHands() == 2){ //if the weapon requires 1 hand but the hero uses a weapon with his 2 hands
					Lhand = nullptr; //throw the weapon
					Rhand = &(*it); //take weapon in the right hand
				} else	// if the weapon requires 1 hand and the hero uses two different weapons just throw one of them and use the new one
					Rhand = &(*it);
			return 1;
		}
		counter++;
	}
	return 2;
}

/*findPotion*/
int Hero::findAndUsePotion(int position){ // position => position of the potion you want to use
	list<Potion>::iterator it;
	int counter = 1; // counter to find "position" of potion in the list of potions
	for(it = inventory.Potions.begin(); it != inventory.Potions.end(); it++){
		if(counter == position){ // if you find it
			it->usePotion(*this);	// use potions
			it = inventory.Potions.erase(it);	// and erase it from your inventory
			it--;
			return 1;
		}
		counter++;
	}
	return 2;
}

/*spellEquip*/
int Hero::spellEquip(int position){ // position => position of the spell you want to equip
	list<Spell*>::iterator it;
	int counter = 1; // counter to find "position" of spell in the list of spells
	for(it = inventory.Spells.begin(); it != inventory.Spells.end(); it++){
		if(counter == position){	// if you find it
			MySpell = (*it);	// "equip" spell
			cout << "To ekana equip!!!!" << endl;
			return 0;
		}
		counter++;
	}
	return 2;
}



/*armorEquip*/
int Hero::armorEquip(int position){ // position => position of armor you want to equip
	list<Armor>::iterator it;
	int counter = 1;	// counter to find "position" of armor in the list of armors
	for(it = inventory.Armors.begin(); it != inventory.Armors.end(); it++){
		if(counter == position){	// if you find it
			MyArmor = &(*it);	// equip armor
			return 1;
		}
		counter++;
	}
	return 2;
}

/*attackToHero*/
void Hero::attackToHero(int DamageValue){	// hero is being attacked by a monster with damage = DamageValue
	if(MyArmor == nullptr)	// if hero don't equip an armor reduce as usual his healthPower (by DamageValue)
		healthPowerReduce(DamageValue);	// reduces health power by DamageValue
	else if(DamageValue > MyArmor->getDamageSave())	// if hero equip an armor reduce damage that he will be hitted by
		DamageValue -= MyArmor->getDamageSave();
	else		// armor is too good that hero didn't lose health power cause of his armor
		return;
}

/*reduceMoneyAfterLosing*/
void Hero::reduceMoneyAfterLosing(){
	money = money/2; //almost the half 
}

/*regenerateHealthPowerAfterLosing*/
void Hero::regenerateHealthPowerAfterLosing(){
	currHealthPower = maxHealthPower/2; //almost the half
}

/*regenerateMagicPowerAfterRound*/
void Hero::regenerateMagicPowerAfterRound(){
	currMagicPower += rand()%10;
	if (currMagicPower > maxMagicPower)
		currMagicPower = maxMagicPower;
}

/*reduceMagicPower*/
int Hero::reduceMagicPower(int magicPowerToSub){	// return 1 or 0 to check if you can cast a spell
	if (currMagicPower >= magicPowerToSub){
		currMagicPower -= magicPowerToSub;
		return 1;
	}
	else
		return 0;

}

/*reduceMoney*/
void Hero::reduceMoney(int moneySpented){ // after you buy an item for example
	money -= moneySpented;
}

/*increaseStrength*/
void Hero::increaseStrength(int strengthToIncrease){
	if (strength + strengthToIncrease >= maxStrength)
		strength = maxStrength;
	else
		strength += strengthToIncrease;
}

/*increaseDexterity*/
void Hero::increaseDexterity(int dexterityToIncrease){
	if (dexterity + dexterityToIncrease >= maxDexterity)
		dexterity = maxDexterity;
	else
		dexterity += dexterityToIncrease;
}

/*increaseAgility*/
void Hero::increaseAgility(int agilityToIncrease){
	if (agility + agilityToIncrease >= maxAgility)
		agility = maxAgility;
	else
		agility += agilityToIncrease;
}