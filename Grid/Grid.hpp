#ifndef _GRID_H_
#define _GRID_H_

class Grid{

private:
	char **map;
	int xLoc;
	int yLoc;

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
	char getmv();

	/*ClearScreen*/
	void ClearScreen();
};

#endif