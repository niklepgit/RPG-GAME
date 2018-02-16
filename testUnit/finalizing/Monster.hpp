#ifndef MONSTER
#define MONSTER

#include "Living.hpp"

class Monster:public Living{
	protected:
		int minDamageRange;
		int maxDamageRange;
		int defense;
		int probability;
		int maxProbability;

	public:
		int undoSpellDamageRange;
		int undoSpellDefense;
		int undoSpellProbability;

	public:
		/*Constructor*/
		Monster(string Name,int Level);

		/*Accessors*/
		int getDefense() const { return defense; }
		int getProbability() const { return probability; }
		int getMaxProbability() const { return maxProbability; }
		int getMinDamageRange() const { return minDamageRange; }
		int getMaxDamageRange() const { return maxDamageRange; }


		/*Mutators*/
		void reduceDefense(int defenseToSub);
		void reduceProbability(int probabilityToSub);
		void reduceDamageRange(int maxDamageToSub);

		void increaseDefense(int defenseToAdd);
		void increaseProbability(int probabilityToAdd);
		void increaseDamageRange(int maxDamageToAdd);

		/*Others*/
		void attackToMonster(int DamageValue);
		int generateHit();
};

#endif