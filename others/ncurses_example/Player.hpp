#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <ncurses.h>

class Player
{
private:
	int xLoc, yLoc, xMax, yMax;
	char character;
	WINDOW *curwin;
public:
	// Constructor
	Player(WINDOW*,int,int,char);

	// Move
	void mvup();
	void mvdown();
	void mvleft();
	void mvright();
	void display();
	int getmv();

};

#endif