#include "Living.hpp"

/*Constructor for Heroes*/
Living::Living(string Name)
			  :name(Name),level(1),currHealthPower(100),maxHealthPower(100){}

/*Constructor for Monsters*/
Living::Living(string Name,int Level)
			  :name(Name),level(Level),maxHealthPower(100),currHealthPower(100){}

/*healthPowerReduce*/
void Living::healthPowerReduce(int healthPowerToReduce){
	if (healthPowerToReduce < currHealthPower){
		currHealthPower -= healthPowerToReduce;
		return;
	}
	currHealthPower = 0;
}

/*healthPowerIncrease*/
void Living::healthPowerIncrease(int healthPowerToIncrease){
	if (healthPowerToIncrease > maxHealthPower){
		//maxHealthPower sto curr stin if
		currHealthPower = maxHealthPower;
		return;
	}
	currHealthPower += healthPowerToIncrease;
}

/*setCurrHealthPower*/
void Living::setCurrHealthPower(){
	currHealthPower = maxHealthPower;
}

/*regenerateHealthPowerAfterRound*/
void Living::regenerateHealthPowerAfterRound(int round){
	currHealthPower += rand()%10;
	if (currHealthPower > maxHealthPower)
		currHealthPower = maxHealthPower;
}
