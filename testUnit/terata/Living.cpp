#include "Living.hpp"

/*Constructor for Heroes*/
Living::Living(string Name)
			  :name(Name),level(1),maxHealthPower(100),currHealthPower(100){}

/*Constructor for Monsters*/
Living::Living(string Name,int Level)
			  :name(Name),level(Level),maxHealthPower(100+Level*10),currHealthPower(100+Level*10){}

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

void Living::setMaxHealthPower(){
	maxHealthPower += 10;
}

void Living::setCurrHealthPower(){
	currHealthPower = maxHealthPower;
}