#ifndef LIVING
#define LIVING

#include <string>

class Living{
	private:
		string name;
		int level;
		int currHealthPower;
		int healthPowerMax;

	public:
		/*constructor*/
		Living(string Name);

		/*Accessors*/
		int getLevel() const { return level; }

		/*Mutators*/
		void healthPowerReduce(int);
		void healthPowerIncrease(int);
		void setMaxHealthPower();
		void setCurrHealthPower();
};

#endif