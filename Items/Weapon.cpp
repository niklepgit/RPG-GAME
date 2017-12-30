#include "Weapon.hpp"

/*Constructor*/
Weapon::Weapon(string Name,int Value,int MinLevel,int DamageValue,
			               int Hands):Item(Name,Value,MinLevel),
		          damageValue(DamageValue),hands(Hands),inUse(0){}

/*weaponAttack*/
void Weapon::weaponAttack(Monster& monster){
	if(inUse==1){
		monster.attackToMonster(damageValue);
	}	
}

/*printWeapons*/
void Weapon::printWeapon(void){
	cout<<"Name:"<<name<<endl;
	cout<<"Value:"<<value<<" coins"<<endl;
	cout<<"MinLevel:"<<MinLevel<<endl;
	cout<<"DamageValue:"<<damageValue<<endl;
	cout<<"Hands:"<<hands<<endl;
}