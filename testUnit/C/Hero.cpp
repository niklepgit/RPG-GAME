#include "Hero.hpp"

/* Constructor */
Hero::Hero(string Name,int Strength,int Dexterity,int Agility)
		  :Living(Name),strength(Strength),dexterity(Dexterity),
		  agility(Agility),currMagicPower(100),money(0),experience(0){}

void Hero::printHero()const{
	cout << "Name: " << name << endl
		 << "Level: " << level << endl
		 << "HP: " << currHealthPower << "/" << maxHealthPower << endl
		 << "MP: " << currMagicPower << "/" <<maxMagicPower << endl;
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
}