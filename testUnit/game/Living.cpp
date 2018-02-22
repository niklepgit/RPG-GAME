#include "Living.hpp"

/*Constructor for Heroes*/
Living::Living(string Name)
			  :name(Name),level(1),currHealthPower(100),maxHealthPower(100){}

/*Constructor for Monsters*/
Living::Living(string Name,int Level)
			  :name(Name),level(Level),currHealthPower(100),maxHealthPower(100){}

/*healthPowerReduce*/
void Living::healthPowerReduce(int healthPowerToReduce){				// healthPower is reduced by healthPowerToReduce
	if (healthPowerToReduce < currHealthPower){
		currHealthPower -= healthPowerToReduce;
		return;
	}
	currHealthPower = 0;
}

/*healthPowerIncrease*/
void Living::healthPowerIncrease(int healthPowerToIncrease){			// healthPower is increased by healthPowerToIncrease
	if (currHealthPower + healthPowerToIncrease > maxHealthPower){
		currHealthPower = maxHealthPower;
		return;
	}
	currHealthPower += healthPowerToIncrease;
}

/*regenerateHealthPowerAfterRound*/
void Living::regenerateHealthPowerAfterRound(){
	currHealthPower += rand()%10;
	if (currHealthPower > maxHealthPower)
		currHealthPower = maxHealthPower;
}
