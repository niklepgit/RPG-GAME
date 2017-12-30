#include "Monster.hpp"

/*attackToMonster*/
void Monster::attackToMonster(int DamageValue){
	if(DamageValue > defese)
		DamageValue -= defense;
	else
		return ;
	
	healthPowerReduce(DamageValue);
}