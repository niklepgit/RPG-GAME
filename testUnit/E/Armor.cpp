
#include "Armor.hpp"

/*Constructor*/
Armor::Armor(string Name,int MinLevel)
		   :Item(Name,MinLevel),inUse(0){

		switch(MinLevel){

		case 1:damageSave=rand()%(10-5+1)+5;
			   break;
		case 2:damageSave=rand()%(20-10+1)+10;
			   break;
		case 3:damageSave=rand()%(30-20+1)+20;
			   break;
		case 4:damageSave=rand()%(40-30+1)+30;
			   break;
		case 5:damageSave=rand()%(50-40+1)+40;
			   break;
		case 6:damageSave=rand()%(60-50+1)+50;
			   break;
		case 7:damageSave=rand()%(70-60+1)+60;
			   break;
		case 8:damageSave=rand()%(80-70+1)+70;
			   break;
		case 9:damageSave=rand()%(90-80+1)+80;
			   break;
		case 10:damageSave=rand()%(100-90+1)+90;
			   break;
	}	
}

/*printArmor*/
void Armor::printArmor(void){
	cout<<"Name:"<<name<<endl;
	cout<<"Value:"<<value<<" coins"<<endl;
	cout<<"MinLevel:"<<minLevel<<endl;
	cout<<"DamageSave:"<<damageSave<<endl;
}