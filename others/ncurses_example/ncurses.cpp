#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Player.hpp"

using namespace std;

int main()
{
	/* NCURSES START */
	initscr();	// initialization
	noecho();	// ??
	cbreak();	// ??

	// get screen size
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	// create a window for out input
	WINDOW *playwin = newwin(20, 50, (yMax/2)-10, 10);
	box(playwin, 0, 0);
	refresh();
	wrefresh(playwin);

	Player *p = new Player(playwin, 1, 1, 'A');
	do {
		p->display();
		wrefresh(playwin);
	} while (p->getmv() != 'q');

	endwin();
	/* NCURSES END */

	return 0;
}