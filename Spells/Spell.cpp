#include "Spell.hpp"

/*Constructor*/
Spell::Spell(string Name,int Value,int MinLevel,int MinDamage,int MaxDamage,int MagicPower)
						   :name(Name),value(Value),minLevel(MinLevel),minDamage(MinDamage)
			                                 ,maxDamage(MaxDamage),magicPower(MagicPower){}

/*printSpell*/
void Spell::printSpell(void){
	cout<<"Name:"<<name<<endl;
	cout<<"Value:"<<value<<" coins"<<endl;
	cout<<"MinLevel:"<<MinLevel<<endl;
	cout<<"MinDamage:"<<minDamage<<endl;
	cout<<"MaxDamage:"<<MaxDamage<<endl;
	cout<<"MagicPower:"<<magicPower<<endl;
}