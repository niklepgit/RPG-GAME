#include "Potion.hpp"
#include "Hero.hpp"

Potion::Potion(string Name,int MinLevel,string WtIncrease)
		 :Item(Name,MinLevel),used(0),wtIncrease(WtIncrease){
		 	
	switch(MinLevel){

		case 1:hmtIncrease=rand()%(10-5+1)+5;
			   break;
		case 2:hmtIncrease=rand()%(20-10+1)+10;
			   break;
		case 3:hmtIncrease=rand()%(30-20+1)+20;
			   break;
		case 4:hmtIncrease=rand()%(40-30+1)+30;
			   break;
		case 5:hmtIncrease=rand()%(50-40+1)+40;
			   break;
		case 6:hmtIncrease=rand()%(60-50+1)+50;
			   break;
		case 7:hmtIncrease=rand()%(70-60+1)+60;
			   break;
		case 8:hmtIncrease=rand()%(80-70+1)+70;
			   break;
		case 9:hmtIncrease=rand()%(90-80+1)+80;
			   break;
		case 10:hmtIncrease=rand()%(100-90+1)+90;
			   break;
	}	

}

/*usePotion*/
void Potion::usePotion(Hero& hero){

	if(wtIncrease=="magicPower")
		hero.increaseMagicPower(hmtIncrease);
	else if(wtIncrease=="strength")
		hero.increaseStrength(hmtIncrease);
	else if(wtIncrease=="dexterity")
		hero.increaseDexterity(hmtIncrease);
	else if(wtIncrease=="agility")
		hero.increaseAgility(hmtIncrease);

}


/*printPotion*/
void Potion::printPotion(void){
	cout<<"Name:"<<name<<endl;
	cout<<"Value:"<<value<<" coins"<<endl;
	cout<<"MinLevel:"<<minLevel<<endl;
	cout<<"wtIncrease:"<<wtIncrease<<endl;
	cout<<"hmtIncrease:"<<hmtIncrease<<endl;
}
