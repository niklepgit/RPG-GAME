#ifndef SPIRIT
#define SPIRIT

#include "Monster.hpp"

class Spirit:public Monster{
	private:

	public:
		/*Constructor*/
		Spirit(string Name,int MinDamageRange,int MaxDamageRange,int Defense,int Probability)
						   :Monster(Name,MinDamageRange,MaxDamageRange,Defense,Probability){}
};

#endif