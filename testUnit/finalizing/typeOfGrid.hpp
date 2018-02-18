#ifndef _TYPE_OF_GRID_
#define _TYPE_OF_GRID_

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
			cout << ' ';
		else if (nonAccessible)
			cout << '#';
		else if (market)
			cout << 'M';
		else if (borders)
			cout << '*';
		else
			cout << '@';
	}
};

#endif