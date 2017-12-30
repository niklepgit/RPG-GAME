#ifndef ITEM
#define ITEM

#include <string>

class Item{
	protected:
		string name;
		int value;
		int minLevel;

	public:
		/*Constructor*/
		Item(string Name,int Value,int MinLevel);

};
#endif