#ifndef DRAGON
#define DRAGON

#include "Monster.hpp"

class Dragon:public Monster{
	private:
	
	public:
		/*Constructor*/
		Dragon(string Name,int Level)
			 :Monster(Name,Level){
		maxDamageRange += 5;	 	
		}

};

#endif