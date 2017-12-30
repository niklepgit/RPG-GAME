#include "Armor.hpp"

/*Constructor*/
Armor::Armor(string Name,int Value,int MinLevel,int DamageSave)
		   :Item(Name,Value,MinLevel),damageValue(DamageSave){}

/*printArmor*/
void Armor::printArmor(void){
	cout<<"Name:"<<name<<endl;
	cout<<"Value:"<<value<<" coins"<<endl;
	cout<<"MinLevel:"<<MinLevel<<endl;
	cout<<"DamageValue:"<<damageValue<<endl;
	cout<<"DamageSave:"<<damageSave<<endl;
}