#include "Monster.hpp"

/*Constructor*/
Monster::Monster(string Name,int Level)
					:Living(Name,Level){
    	switch(Level){

		case 1:probability=rand()%(10-5+1)+5;
			   minDamageRange=rand()%(5-0+1)+0;
			   maxDamageRange=rand()%(10-5+1)+5;
			   defense=rand()%(10-5+1)+5;
			   break;
		case 2:probability=rand()%(20-10+1)+10;
			   minDamageRange=rand()%(15-10+1)+10;
			   maxDamageRange=rand()%(20-15+1)+15;
			   defense=rand()%(20-10+1)+10;
			   break;
		case 3:probability=rand()%(30-20+1)+20;
			   minDamageRange=rand()%(25-20+1)+20;
			   maxDamageRange=rand()%(30-25+1)+25;
			   defense=rand()%(30-20+1)+20;
			   break;
		case 4:probability=rand()%(40-30+1)+30;
			   minDamageRange=rand()%(35-30+1)+30;
			   maxDamageRange=rand()%(40-35+1)+35;
			   defense=rand()%(40-30+1)+30;
			   break;
		case 5:probability=rand()%(50-40+1)+40;
			   minDamageRange=rand()%(45-40+1)+40;
			   maxDamageRange=rand()%(50-45+1)+45;
			   defense=rand()%(50-40+1)+40;
			   break;
		case 6:probability=rand()%(60-50+1)+50;
			   minDamageRange=rand()%(55-50+1)+50;
			   maxDamageRange=rand()%(60-55+1)+55;
			   defense=rand()%(60-50+1)+50;
			   break;
		case 7:probability=rand()%(70-60+1)+60;
			   minDamageRange=rand()%(35-30+1)+30;
			   maxDamageRange=rand()%(40-35+1)+35;
			   defense=rand()%(40-30+1)+30;
			   break;
		case 8:probability=rand()%(80-70+1)+70;
			   minDamageRange=rand()%(75-70+1)+70;
			   maxDamageRange=rand()%(80-75+1)+75;
			   defense=rand()%(80-70+1)+70;
			   break;
		case 9:probability=rand()%(90-80+1)+80;
			   minDamageRange=rand()%(85-80+1)+80;
			   maxDamageRange=rand()%(90-85+1)+85;
			   defense=rand()%(90-80+1)+80;
			   break;
		case 10:probability=rand()%(100-90+1)+90;
				minDamageRange=rand()%(95-90+1)+90;
			    maxDamageRange=rand()%(100-95+1)+95;
			    defense=rand()%(100-90+1)+90;
			    break;
	}

}

/*attackToMonster*/
void Monster::attackToMonster(int DamageValue){
	if(DamageValue > defense)
		DamageValue -= defense;
	else{
		defense-= DamageValue;
		return;
	}
	healthPowerReduce(DamageValue);
}

/*generateHit*/
int Monster::generateHit(){
	return rand()%((maxDamageRange - minDamageRange) + 1) + minDamageRange;
}
