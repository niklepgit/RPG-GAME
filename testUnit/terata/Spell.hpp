#ifndef SPELL
#define SPELL

#include <string>
#include <iostream>
using namespace std;
class Hero;

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
		int generateHit(int Dexterity);

		void castSpell(Hero& hero);
		virtual void castFireSpell(){};
		virtual void castIceSpell(){};
		virtual void castLightingSpell(){};
		//function to decrease the magicPower from Hero
		//function to check the dexterity
		//fuck lalala
};
#endif