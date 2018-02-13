#include "Spell.hpp"
#include "Hero.hpp"

/*Constructor*/
Spell::Spell(string Name,int MinLevel)
		:name(Name),minLevel(MinLevel){

	inUse=new int[3];
	for(int i=0;i<3;i++){
		inUse[i]=0;
	}
			
	switch(MinLevel){

		case 1:value=rand()%(10-5+1)+5;
			   minDamage=rand()%(5-0+1)+0;
			   maxDamage=rand()%(10-5+1)+5;
			   magicPower=rand()%(10-5+1)+5;
			   impactForNRounds=1;
			   break;
		case 2:value=rand()%(20-10+1)+10;
			   minDamage=rand()%(15-10+1)+10;
			   maxDamage=rand()%(20-15+1)+15;
			   magicPower=rand()%(20-10+1)+10;
			   impactForNRounds=2;
			   break;
		case 3:value=rand()%(30-20+1)+20;
			   minDamage=rand()%(25-20+1)+20;
			   maxDamage=rand()%(30-25+1)+25;
			   magicPower=rand()%(30-20+1)+20;
			   impactForNRounds=3;
			   break;
		case 4:value=rand()%(40-30+1)+30;
			   minDamage=rand()%(35-30+1)+30;
			   maxDamage=rand()%(40-35+1)+35;
			   magicPower=rand()%(40-30+1)+30;
			   impactForNRounds=4;
			   break;
		case 5:value=rand()%(50-40+1)+40;
			   minDamage=rand()%(45-40+1)+40;
			   maxDamage=rand()%(50-45+1)+45;
			   magicPower=rand()%(50-40+1)+40;
			   impactForNRounds=5;
			   break;
		case 6:value=rand()%(60-50+1)+50;
			   minDamage=rand()%(55-50+1)+50;
			   maxDamage=rand()%(60-55+1)+55;
			   magicPower=rand()%(60-50+1)+50;
			   impactForNRounds=6;
			   break;
		case 7:value=rand()%(70-60+1)+60;
			   minDamage=rand()%(35-30+1)+30;
			   maxDamage=rand()%(40-35+1)+35;
			   magicPower=rand()%(40-30+1)+30;
			   impactForNRounds=7;
			   break;
		case 8:value=rand()%(80-70+1)+70;
			   minDamage=rand()%(75-70+1)+70;
			   maxDamage=rand()%(80-75+1)+75;
			   magicPower=rand()%(80-70+1)+70;
			   impactForNRounds=8;
			   break;
		case 9:value=rand()%(90-80+1)+80;
			   minDamage=rand()%(85-80+1)+80;
			   maxDamage=rand()%(90-85+1)+85;
			   magicPower=rand()%(90-80+1)+80;
			   impactForNRounds=9;
			   break;
		case 10:value=rand()%(100-90+1)+90;
				minDamage=rand()%(95-90+1)+90;
			    maxDamage=rand()%(100-95+1)+95;
			    magicPower=rand()%(100-90+1)+90;
			    impactForNRounds=10;
			    break;
	}	

}

/*Destructor*/
Spell::~Spell(){
	delete[] inUse;
}

/*printSpell*/
void Spell::printSpell(void){
	cout<<"Name:"<<name<<endl;
	cout<<"Value:"<<value<<" coins"<<endl;
	cout<<"MinLevel:"<<minLevel<<endl;
	cout<<"MinDamage:"<<minDamage<<endl;
	cout<<"MaxDamage:"<<maxDamage<<endl;
	cout<<"MagicPower:"<<magicPower<<endl;
	cout<<"Impact for:"<<impactForNRounds<<" rounds."<<endl;
	printTypeOfSpell();
}

/*castSpell*/
void Spell::castSpell(Hero&hero){
	hero.reduceMagicPower(magicPower);
}


/*generateHit*/
int Spell::generateHit(int Dexterity){
	int hit;
	if((hit=rand()%((maxDamage - minDamage) + 1) + minDamage+Dexterity)>maxDamage)
		return maxDamage;
	else
		return hit;
}