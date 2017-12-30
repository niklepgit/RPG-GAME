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

	public:
		/*Constructor*/
		Spell(string Name,int Value,int MinLevel,int MinDamage,int MaxDamage,int MagicPower);
		/*Others*/
		void printSpell(void);
		//function to decrease the magicPower from Hero
		//function to check the dexterity
		//fuck lalala

#endif