#ifndef MONSTER
#define MONSTER

#include "../Living.hpp"

class Monster:public Living{
	private:
		int minDamageRange;
		int maxDamageRange;
		int defense;
		int probability;
	public:
};

#endif