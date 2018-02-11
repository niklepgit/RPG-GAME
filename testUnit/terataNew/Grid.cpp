#include "Grid.hpp"
#include <sys/ioctl.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <termios.h>
#include <unistd.h>

using namespace std;

/*Constructor*/
Grid::Grid(){
	/*Needed to take terminal's dimensions*/
	struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    xMax = w.ws_row;
    yMax = w.ws_col;

    /*Allocate memory for grid*/
    map = new char*[w.ws_row];
    for (int i = 0; i < w.ws_row; ++i)
    	map[i] = new char[w.ws_col];

    /*Initialization grid*/

    /*Making borders*/
	for (int j = 0; j < w.ws_col; ++j){
		map[0][j] = '*';
		map[w.ws_row-1][j] = '*';
	}
	for (int i = 1; i < w.ws_row; ++i){
		map[i][0] = '*';
		map[i][w.ws_col-1] = '*';
	}

	/*Generate random map*/

	/*Generate non accessible fields*/
	for (int i = 1; i < w.ws_row-1; ++i)
		for (int j = 1; j < w.ws_col-1; ++j){
			if (rand()%100 < 5){
				map[i][j] = 'x';
			} else {map[i][j] = ' ';}
		}

	/*Hero's start position*/
	for (int j = 1; j < w.ws_col-1; ++j){
		if (map[1][j] == ' '){
			map[1][j] = 'h';
			xLoc = 1;
			yLoc = j;
			break;
		}
	}

	/*Market*/
	for (int i = 1; i < w.ws_row-1; ++i)
		for (int j = 1; j < w.ws_col-1; ++j){
			if (rand()%100 < 15){
				if (map[i][j] == ' '){
					map[i][j] = 'M';
				}
			}
		}
}

void Grid::mvUp(){
	int x2 = xLoc - 1;
	if (map[x2][yLoc] == ' '){
		map[xLoc][yLoc] = ' ';
		map[x2][yLoc] = 'h';
		xLoc = x2;
	}
}

void Grid::mvDown(){
	
	int x2 = xLoc + 1;
	if (map[x2][yLoc] == ' '){
		map[xLoc][yLoc] = ' ';
		map[x2][yLoc] = 'h';
		xLoc = x2;
	}
}

void Grid::mvRight(){
	int y2 = yLoc + 1;
	if (map[xLoc][y2] == ' '){
		map[xLoc][yLoc] = ' ';
		map[xLoc][y2] = 'h';
		yLoc = y2;
	}
}

void Grid::mvLeft(){
	int y2 = yLoc - 1;
	if (map[xLoc][y2] == ' '){
		map[xLoc][yLoc] = ' ';
		map[xLoc][y2] = 'h';
		yLoc = y2;
	}
}

char Grid::getmv(){
	char choice = getchar_silent();
	switch(choice)
	{
		case 'w':
			mvUp();
			break;
		case 's':
			mvDown();
			break;
		case 'a':
			mvLeft();
			break;
		case 'd':
			mvRight();
			break;
		default:
			break;	
	}
	if(choice=='w' || choice=='s'|| choice=='a'|| choice=='d')
		if (rand()%100 < 5)
			choice = 'b';
	return choice;
}

/*displayMap*/
void Grid::displayMap(){
	clearScreen();
	for (int x = 0; x < xMax; ++x){
		for (int y = 0; y < yMax; ++y)
			cout << map[x][y];
		cout << endl;
	}
}

void Grid::clearScreen(){
	cout << string( 25, '\n' );
}

int Grid::getchar_silent(){  /*I took it ready*/
	int ch;
	struct termios oldt,newt;

	tcgetattr(STDIN_FILENO,&oldt);

	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );

	tcsetattr(STDIN_FILENO,TCSANOW,&newt);

	ch = getchar();
	tcsetattr(STDIN_FILENO,TCSANOW,&oldt);

	return ch;	
}

/*nextToMarket*/
int Grid::nextToMarket(){
	if ((map[xLoc-1][yLoc] == 'M') || (map[xLoc][yLoc-1] == 'M') || (map[xLoc+1][yLoc] == 'M') || (map[xLoc][yLoc+1] == 'M'))
		return 1;
	return 0;
}