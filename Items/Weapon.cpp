#include "Weapon.hpp"

/*Constructor*/
Weapon::Weapon(string Name,int Value,int MinLevel,int DamageValue,
			               int Hands):Item(Name,Value,MinLevel),
		          damageValue(DamageValue),hands(Hands),inUse(0){}

void Weapon::WeaponAttack(void){
	if(inUse==1){
		
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