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

		/*Destructor*/
		virtual ~Spell();
		
		/*Accessors*/
		int getInUse(int i) const {return inUse[i];} //attention i should be 0-2
		int getImpactForNRounds() const {return impactForNRounds;}
		int getMagicPower() const {return magicPower;}
		int getMinLevel() const {return minLevel;}
		int getValue() const {return value;}

		/*abstruct functions*/
		virtual void printTypeOfSpell()=0;
		virtual void castSpell(Monster& monster)=0;
		virtual void undoSpell(Monster& monster)=0;

		/*Others*/
		void printSpell(void);
	
		int generateHit(int Dexterity);
		void setInUse1(int i) {inUse[i]=1;}
		void setInUse0(int i) {inUse[i]=0;}	
		
		/*castSpells*/
		void castSpell(Hero& hero);
		virtual void castFireSpell(){};
		virtual void castIceSpell(){};
		virtual void castLightingSpell(){};

};
#endif