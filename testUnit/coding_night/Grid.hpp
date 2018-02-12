#ifndef _GRID_H_
#define _GRID_H_

class Grid{

private:
	char **map;
	int xLoc;
	int yLoc;
	int xMax;
	int yMax;

public:
	/*Constructor*/
	Grid();

	/*DisplayMap*/
	void displayMap();

	/*Movement*/
	void mvUp();
	void mvDown();
	void mvRight();
	void mvLeft();
	char getmv(int& battle);

	/*ClearScreen*/
	void clearScreen();

	/*getchar without enter*/
	int getchar_silent();

	/*nextToMarket*/
	int nextToMarket();
};

#endif