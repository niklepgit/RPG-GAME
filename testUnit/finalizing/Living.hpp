#ifndef LIVING
#define LIVING

#include <string>
#include <cstdlib>
using namespace std;

class Living{
	protected:
		string name;
		int level;
		int currHealthPower;
		int maxHealthPower;

	public:
		/*constructor for Heroes*/
		Living(string Name);
		/*constructor for Monsters*/
		Living(string Name,int Level);

		/*Accessors*/
		int getLevel() const { return level; }
		string getName() const { return name; }
		int getCurrHealthPower() const { return currHealthPower; }
		int getMaxHealthPower() const { return maxHealthPower; }

		/*Mutators*/
		void healthPowerReduce(int);
		void healthPowerIncrease(int);
		//void setCurrHealthPower();	// MALLON AXRHSTO
		void regenerateHealthPowerAfterRound();

		/*Check if hero/monster is alive*/
		int isAlive(){ return (currHealthPower>0); }
};

#endif