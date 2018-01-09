#include "Living.hpp"

/*Constructor*/
Living::Living(string Name)
			  :name(Name),level(1),healthPowerMax(100),currHealthPower(100){}

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
	if (healthPowerToIncrease > currHealthPower){
		currHealthPower = healthPowerMax;
		return;
	}
	currHealthPower += healthPowerToIncrease;
}

void Living::setMaxHealthPower(){
	healthPowerMax += 10;
}

void Living::setCurrHealthPower(){
	currHealthPower = healthPowerMax;
}