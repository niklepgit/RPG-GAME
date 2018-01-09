#include "Hero.hpp"

/* Constructor */
Hero::Hero(string Name,int Strength,int Dexterity,int Agility)
		  :Living(Name),strength(Strength),dexterity(Dexterity),
		  agility(Agility),currMagicPower(100),money(0),experience(0){}

void Hero::printHero(){
	cout << "Name: " << name << endl
		 << "Level: " << level << endl
		 << "HP: " << currHealthPower << "/" << healthPowerMax << endl
		 << "MP: " << currMagicPower << "/" magicPowerMax << endl;
}

void Hero::increaseMagicPower(int magicPowerToIncrease){
	if (currMagicPower + magicPowerToIncrease > magicPowerMax){
		currMagicPower = magicPowerMax;
		return;
	}
	currMagicPower += magicPowerToIncrease;
}

void Hero::levelUp(){
	level++;
	setMaxHealthPower();
	magicPowerMax += 10;
	setCurrHealthPower();
	currMagicPower = magicPowerMax;
}