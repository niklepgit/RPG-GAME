#ifndef _TYPE_OF_GRID_
#define _TYPE_OF_GRID_

#define MY_MARKET 'M'
#define NON_ACCESIBLE '#'
#define COMMON ' '
#define BORDERS '*'
#define PLAYER '@'

#include <iostream>

using namespace std;

class typeOfGrid{
private:
	int common;
	int nonAccessible;
	int market;
	int borders;
	int player;
public:
	/*Constructor*/
	typeOfGrid(int Common, int NonAccessible, int Market, int Borders, int Player): common(Common), nonAccessible(NonAccessible), market(Market), borders(Borders), player(Player) {}
	typeOfGrid(): common(0), nonAccessible(0), market(0), borders(0), player(0) {}

	/*Accessors*/
	int isCommon() const { return common; }
	int isNonAccessible() const { return nonAccessible; }
	int isMarket() const { return market; }

	/*displayTypeOfGrid*/
	void displayTypeOfGrid(){
		if (common)
			cout << COMMON;
		else if (nonAccessible)
			cout << NON_ACCESIBLE;
		else if (market)
			cout << MY_MARKET;
		else if (borders)
			cout << BORDERS;
		else
			cout << PLAYER;
	}
};

#endif