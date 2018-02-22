#ifndef EXOSKELETON
#define EXOSKELETON

#include "Monster.hpp"

class Exoskeleton:public Monster{
	private:

	public:
		/*Constructor*/
		Exoskeleton(string Name,int Level)
				   :Monster(Name,Level){
	   	defense += 5;
		}

};

#endif