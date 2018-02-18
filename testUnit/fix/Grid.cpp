#include "Grid.hpp"

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
		map[0][j] = BORDERS;
		map[w.ws_row-1][j] = BORDERS;
	}
	for (int i = 1; i < w.ws_row; ++i){
		map[i][0] = BORDERS;
		map[i][w.ws_col-1] = BORDERS;
	}

	/*Generate random map*/

	/*Generate non accessible fields*/
	for (int i = 1; i < w.ws_row-1; ++i)
		for (int j = 1; j < w.ws_col-1; ++j){
			if (rand()%100 < 5){
				map[i][j] = NON_ACCESIBLE;
			} else {map[i][j] = COMMON;}
		}

	/*Hero's start position*/
	for (int j = 1; j < w.ws_col-1; ++j){
		if (map[1][j] == COMMON){
			map[1][j] = PLAYER;
			xLoc = 1;
			yLoc = j;
			break;
		}
	}

	/*Market*/
	for (int i = 1; i < w.ws_row-1; ++i)
		for (int j = 1; j < w.ws_col-1; ++j){
			if (rand()%100 < 10){
				if (map[i][j] == COMMON){
					map[i][j] = MY_MARKET;
				}
			}
		}
}

/*Destructor*/
Grid::~Grid(){
	for (int i = 0; i < xMax; i++)
		delete map[i];
	delete[] map;
}

/*mvUp*/
void Grid::mvUp(){
	int x2 = xLoc - 1;
	if (map[x2][yLoc] == COMMON){
		map[xLoc][yLoc] = COMMON;
		map[x2][yLoc] = PLAYER;
		xLoc = x2;
	}
}

/*mvDown*/
void Grid::mvDown(){
	
	int x2 = xLoc + 1;
	if (map[x2][yLoc] == COMMON){
		map[xLoc][yLoc] = COMMON;
		map[x2][yLoc] = PLAYER;
		xLoc = x2;
	}
}

/*mvRight*/
void Grid::mvRight(){
	int y2 = yLoc + 1;
	if (map[xLoc][y2] == COMMON){
		map[xLoc][yLoc] = COMMON;
		map[xLoc][y2] = PLAYER;
		yLoc = y2;
	}
}

/*mvLeft*/
void Grid::mvLeft(){
	int y2 = yLoc - 1;
	if (map[xLoc][y2] == COMMON){
		map[xLoc][yLoc] = COMMON;
		map[xLoc][y2] = PLAYER;
		yLoc = y2;
	}
}

/*getmv*/
char Grid::getmv(int& battle){
	char choice = getchar_silent();		// get input from user without need of 'enter'
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
	if(choice=='w' || choice=='s'|| choice=='a'|| choice=='d')	// probability of battle
		if (rand()%100 < 5){
			battle=1;
			choice = 'b';
		}
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

/*clearScreen*/
void Grid::clearScreen(){
	cout << string( 100, '\n' );
}

/*getchar_silent*/
int Grid::getchar_silent(){  /*I took it ready*/
	int ch;
	struct termios oldt,newt;

	//tcgetattr: gets the parameters associated with the object referred
    //by fd(STDIN_FILENO) and stores them in the termios structure referenced by termios_p(oldt)
    //This function may be invoked from a background process.
    //However, the terminal attributes may be subsequently changed by a foreground process.
	tcgetattr(STDIN_FILENO,&oldt);	// #define STDIN_FILENO 0 (standard input)

	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );	
	//c.lflag => (local modes) flag constants:
	//ECHO => echo input characters
	//ICANON => canonical mode
	//The setting of the ICANON canon flag in c_lflag determines whether
    //the terminal is operating in canonical mode (ICANON set) or noncanon‐
    //ical mode (ICANON unset).  By default, ICANON is set.
	//Input is made available line by line. An input line is available
    //when one of the line delimiters is typed (NL, EOL, EOL2; or EOF at
    //the start of line).

	//tcsetattr: sets the parameters associated with the terminal (unless
    //support is required from the underlying hardware that is not available)
    //from the termios structure referred to by termios_p(newt).
    //optional_actions (TCSANOW) specifies when the changes take effect.
	tcsetattr(STDIN_FILENO,TCSANOW,&newt);	// TCSANOW => the change occurs immediately

	ch = getchar();
	tcsetattr(STDIN_FILENO,TCSANOW,&oldt);

	return ch;	
}

/*nextToMarket*/
int Grid::nextToMarket(){
	if ((map[xLoc-1][yLoc] == MY_MARKET) || (map[xLoc][yLoc-1] == MY_MARKET) || (map[xLoc+1][yLoc] == MY_MARKET) || (map[xLoc][yLoc+1] == MY_MARKET))
		return 1;
	return 0;
}