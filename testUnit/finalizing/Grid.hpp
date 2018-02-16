#ifndef _GRID_H_
#define _GRID_H_

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>

#include <sys/ioctl.h>		// needed to get terminal's size (defines winsize structure)
#include <termios.h>		// needed for getchar_silent
#include <unistd.h>			// needed for getchar_silent

#define MY_MARKET 'M'
#define NON_ACCESIBLE 'x'
#define COMMON ' '
#define BORDERS '*'
#define PLAYER 'h'


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

	/*Destructor*/
	~Grid();

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