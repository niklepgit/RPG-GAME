#ifndef SPELL
#define SPELL

#include <string>

class Spell{
	private:
		string name;
		int value;
		int minLevel;
		int minDamage;
		int maxDamage;
		int magicPower;
		int inUse;

	public:
		/*Constructor*/
		Spell(string Name,int MinLevel);
		/*Others*/
		void printSpell(void);
		int getValue() {return value;}
		void useSpell();
		//function to decrease the magicPower from Hero
		//function to check the dexterity
		//fuck lalala
};
#endif