#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

#include "Market.hpp"
#include "Grid.hpp"
#include "Living.hpp"
#include "Paladin.hpp"
#include "Sorcerer.hpp"
#include "Warrior.hpp"

int main(){

	Market m1;
	Hero**H=new Hero*[1];
	H[0]=new Paladin("Paladinos");
/*
	H[0]->printHero();
	H[0]->printSkills();
	H[0]->levelUp();
	H[0]->printHero();
	H[0]->printSkills();
*/
	Grid* g = new Grid;
	do {
		g->displayMap();
		if (getchar() == 'm'){
			g->clearScreen();
			m1.menuMarket(H,1);
		}
		g->clearScreen();
	} while (g->getmv() != 'q');

	return 0;
}