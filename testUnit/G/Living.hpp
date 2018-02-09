#ifndef LIVING
#define LIVING

#include <string>
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

		/*Mutators*/
		void healthPowerReduce(int);
		void healthPowerIncrease(int);
		void setMaxHealthPower();
		void setCurrHealthPower();
};

#endif