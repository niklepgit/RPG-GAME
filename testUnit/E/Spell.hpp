#ifndef SPELL
#define SPELL

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Spell{
	private:
		string name;
		int value;
		int minLevel;
		int minDamage;
		int maxDamage;
		int magicPower;

	public:
		/*Constructor*/
		Spell(string Name,int MinLevel);
		/*Others*/
		void printSpell(void);
		int getValue() {return value;}
		//function to decrease the magicPower from Hero
		//function to check the dexterity
		//fuck lalala
};
#endif