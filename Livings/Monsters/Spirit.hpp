#ifndef SPIRIT
#define SPIRIT

#include "Monster.hpp"

class Spirit:public Monster{
	private:

	public:
		/*Constructor*/
		Spirit(string Name,int Level)
			:Monster(Name,Level){
		probability += 5;		
		}
};

#endif