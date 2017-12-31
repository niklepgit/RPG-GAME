#ifndef EXOSKELETON
#define EXOSKELETON

#include "Monster.hpp"

class Exoskeleton:public Monster{
	private:

	public:
		/*Constructor*/
		Exoskeleton(string Name,int MinDamageRange,int MaxDamageRange,int Defense,int Probability)
						   :Monster(Name,MinDamageRange,MaxDamageRange,Defense,Probability){}

};

#endif