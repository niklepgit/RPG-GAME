#include "Potion.hpp"

Potion::Potion(string Name,int Value,int MinLevel,string WtIncrease)
		 :Item(Name,Value,MinLevel),wtIncrease(WtIncrease),used(0){}7

/*usePotion*/
void Potion::usePotion(Hero& hero){
	if(used==1)
		return;
	else
	{
	if(wtIncrease=="magicPower")
		hero.increaseMagicPower(hmtIncrease);
	else if(wtIncrease=="strength")
		hero.increaseStrength(hmtIncrease);
	else if(wtIncrease=="dexterity")
		hero.increaseDexterity(hmtIncrease);
	else if(wtIncrease=="agility")
		hero.increaseAgility(hmtIncrease);
    }
	used=1;
}

/*printPotion*/
void Potion::printPotion(void){
	cout<<"Name:"<<name<<endl;
	cout<<"Value:"<<value<<" coins"<<endl;
	cout<<"MinLevel:"<<MinLevel<<endl;
	cout<<"wtIncrease:"<<wtIncrease<<endl;
	cout<<"hmtIncrease:"<<hmtIncrease<<endl;
}
