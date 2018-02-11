#ifndef SPELL
#define SPELL

#include "Monster.hpp"
#include <string>
#include <iostream>
using namespace std;
class Hero;

class Spell{
	protected:
		string name;
		int value;
		int minLevel;
		int minDamage;
		int maxDamage;
		int magicPower;
		int impactForNRounds;
		int* inUse;

	public:
		/*Constructor*/
		Spell(string Name,int MinLevel);
		/*Others*/
		void printSpell(void);
		virtual void printTypeOfSpell()=0;
		virtual void castSpell(Monster& monster)=0;
		virtual void undoSpell(Monster& monster)=0;
		int getValue() {return value;}
		int generateHit(int Dexterity);
		void setInUse1(int i) {inUse[i]=1;}
		void setInUse0(int i) {inUse[i]=0;}
		int getInUse(int i) const {return inUse[i];} //attention i should be 0-2
		int getImpactForNRounds(){return impactForNRounds;}
		int getMagicPower() {return magicPower;}

		void castSpell(Hero& hero);
		virtual void castFireSpell(){};
		virtual void castIceSpell(){};
		virtual void castLightingSpell(){};
		//function to decrease the magicPower from Hero
		//function to check the dexterity
		//fuck lalala
};
#endif