#include "Potion.hpp"

Potion::Potion(string Name,int Value,int MinLevel,string WtIncrease)
		 :Item(Name,Value,MinLevel),wtIncrease(WtIncrease),used(0){}