#include <iostream>
#include <cstdlib>
using namespace std;

#include "Living.hpp"
#include "Paladin.hpp"
#include "Sorcerer.hpp"
#include "Warrior.hpp"

int main(){

	Hero**H=new Hero*[1];
	H[0]=new Paladin("Paladinos");
	H[0]->printHero();
	H[0]->printSkills();
	H[0]->levelUp();
	H[0]->printHero();
	H[0]->printSkills();
/*
	H[1]=new Sorcerer("Sorcererinos");
	H[1]->printHero();
	H[1]->printSkills();
	H[2]=new Warrior("Warriorinos");
	H[2]->printHero();
	H[2]->printSkills();
*/
	return 0;
}