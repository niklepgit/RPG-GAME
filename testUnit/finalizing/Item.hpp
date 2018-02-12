#ifndef ITEM
#define ITEM
#include <iostream>
#include <string>
using namespace std;
class Item{
	protected:
		string name;
		int value;
		int minLevel;

	public:
		/*Constructor*/
		Item(string Name,int MinLevel);
		int getValue() {return value;}

		int getMinLevel()const {return minLevel;}
};
#endif