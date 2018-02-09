#include "Weapon.hpp"

/*Constructor*/
Weapon::Weapon(string Name,int MinLevel):Item(Name,MinLevel),
		       hands(rand()%(2-1+1)+1){

		switch(MinLevel){

		case 1:damageValue=rand()%(10-5+1)+5;
			   break;
		case 2:damageValue=rand()%(20-10+1)+10;
			   break;
		case 3:damageValue=rand()%(30-20+1)+20;
			   break;
		case 4:damageValue=rand()%(40-30+1)+30;
			   break;
		case 5:damageValue=rand()%(50-40+1)+40;
			   break;
		case 6:damageValue=rand()%(60-50+1)+50;
			   break;
		case 7:damageValue=rand()%(70-60+1)+60;
			   break;
		case 8:damageValue=rand()%(80-70+1)+70;
			   break;
		case 9:damageValue=rand()%(90-80+1)+80;
			   break;
		case 10:damageValue=rand()%(100-90+1)+90;
			   break;
	}	

}

/*weaponAttack
void Weapon::weaponAttack(Monster& monster){
	if(inUse==1){
		monster.attackToMonster(damageValue);
	}	
}
*/

/*printWeapon*/
void Weapon::printWeapon(void){
	cout<<"Name:"<<name<<endl;
	cout<<"Value:"<<value<<" coins"<<endl;
	cout<<"MinLevel:"<<minLevel<<endl;
	cout<<"DamageValue:"<<damageValue<<endl;
	cout<<"Hands:"<<hands<<endl;
}