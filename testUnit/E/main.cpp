#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

#include "Market.hpp"
#include "Grid.hpp"
#include "Living.hpp"
#include "Hero.hpp"
#include "Paladin.hpp"
#include "Sorcerer.hpp"
#include "Warrior.hpp"


int main(){

	Market m1;
	Hero**H=new Hero*[3];
	H[0]=new Paladin("Paladinos");
	H[0]->increaseMoney(100);
	H[1]=new Warrior("Warrior1");
	H[2]=new Sorcerer("Magoulinos");
	Weapon weapon("weapooon",1);
	H[0]->inventory.addWeapon(weapon);
	m1.addWeapon("weapon",1);

	Grid* g = new Grid;
	char keyInput;
	do {

		g->displayMap();
		keyInput = g->getmv();
		switch(keyInput){
			case 'm':
				if (!g->nextToMarket())
					break;
				g->clearScreen();
				m1.menuMarket(H,3);
				break;
			case 'p':
				g->clearScreen();
				for (int i = 0; i < 3; ++i){
					H[i]->printHero();
					H[i]->printSkills();
				}
				cout << "Press enter to continue...";
				getchar();
				break;
			case 'i':
				g->clearScreen();
				cout << "For which hero you want to see inventory?" << endl;
				switch(getchar()){
					case '1':
						H[0]->inventory.checkInventory();
						getchar();
						cout << "Press enter to continue";
						getchar();
						break;
					case '2':
						H[1]->inventory.checkInventory();
						getchar();
						cout << "Press enter to continue";
						getchar();
						break;
					case '3':
						H[2]->inventory.checkInventory();
						getchar();
						cout << "Press enter to continue";
						getchar();
						break;
					default:
						break;
				}
				break;
			default:
				break;
		};
		g->clearScreen();
	} while (keyInput != 'q');

	return 0;
}