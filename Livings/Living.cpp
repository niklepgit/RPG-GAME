#include "Living.hpp"

/*Constructor*/
Living::Living(string Name)
			  :name(Name),level(1),HealthPower(100){}

Living::healthPowerReduce(int number){
	if(number<healthPower)
		healthPower -= number;
	else
		healthPower = 0;
}
