#include "Monster.hpp"

/*attackToMonster*/
void Monster::attackToMonster(int DamageValue){
	if(DamageValue > defese)
		DamageValue -= defense;
	else
		return ;
	
	healthPowerReduce(DamageValue);
}

/*Constructor*/
Monster::Monster(string Name,int MinDamageRange,int MaxDamageRange,int Defense,int Probability)
					Living(Name),minDamageRange(MinDamageRange),maxDamageRange(MaxDamageRange),
													defense(Defense),probability(Probability){}


