#ifndef GAME
#define GAME

#include "Weapon.hpp"
#include "Potion.hpp"
#include "Armor.hpp"
#include "Living.hpp"
#include "Hero.hpp"
#include "Paladin.hpp"
#include "Sorcerer.hpp"
#include "Warrior.hpp"
#include "Inventory.hpp"
#include "Market.hpp"
#include "Spell.hpp"
#include "Grid.hpp"
#include "Monster.hpp"
#include "Dragon.hpp"
#include "Spirit.hpp"
#include "Exoskeleton.hpp"

#include <string>
#include <iostream>

using namespace std;

class Game{

public:

	/*gameplay*/
	void gameplay(Market& market);

	/*endOfSpell*/
	void endOfSpell(Hero**&heroes,Monster**&monsters,int NumberOfHeroes,int*const&checkLifeOfSpell,int*const&monsterHitWithSpell,int counter,int*const&whichMonsterWasHit);

	/*heroesAfterWinning*/
	void heroesAfterWinning(Hero**& heroes,int NumberOfHeroes);

	/*heroesAfterRound*/
	void heroesAfterRound(Hero**&heroes,int NumberOfHeroes);

	/*monstersAfterRound*/
	void monstersAfterRound(Monster**&monsters,int NumberOfHeroes);

	/*destroyMonsters*/
	void destroyMonsters(Monster**& monsters,int NumberOfHeroes);

	/*heroesAfterLosing*/
	void heroesAfterLosing(Hero**& heroes,int NumberOfHeroes);

	/*monstersAreDead*/
	int monstersAreDead(Monster**&monsters,int NumberOfHeroes);

	/*heroesAreDead*/
	int heroesAreDead(Hero**&heroes,int NumberOfHeroes);

	/*attack*/
	void attack(Hero& hero,Monster**& monsters,int NumberOfHeroes);

	/*attackWithSpell*/
	int attackWithSpell(Hero& hero,Monster**& monsters,int NumberOfHeroes,int*const& monsterHitWithSpell,int whoHitTheMonster,int*const&whichMonsterWasHit);

	/*getAverageLevelOfHeroes*/
	int getAverageLevelOfHeroes(Hero**& heroes,int NumberOfHeroes);

	/*displayStats*/
	void displayStats(Hero**& heroes, Monster**& monsters,int NumberOfHeroes);
};

#endif