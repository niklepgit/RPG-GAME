#ifndef DRAGON
#define DRAGON

#include "Monster.hpp"

class Dragon:public Monster{
	private:
	
	public:
		/*Constructor*/
		Dragon(string Name,int MinDamageRange,int MaxDamageRange,int Defense,int Probability)
						   :Monster(Name,MinDamageRange,MaxDamageRange,Defense,Probability){}

};

#endif