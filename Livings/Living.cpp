#include "Living.hpp"

/*Constructor*/
Living::Living(string Name)
			  :name(Name),level(1),healthPowerMax(100),healthPower(100){}

/*healthPowerReduce*/
void Living::healthPowerReduce(int number){
	if (number < healthPower)
		healthPower -= number;
	else
		healthPower = 0;
}

/*levelUp*/
void Living::levelUp(){
	level++;
	healthPowerMax += 10;
}
