#include <iostream>
using namespace std;
#include "Item.hpp"
#include "Weapon.hpp"
#include "Potion.hpp"
#include "Armor.hpp"
#include "Market.hpp"

int main(){

	Weapon w1("sword",1);
	w1.printWeapon();
	cout<<endl;
	Potion p1("Potion",2,"magicPower");
	p1.printPotion();
	cout<<endl;
	Armor a1("Armor",3);
	a1.printArmor();
	cout<<endl;
	Market m1;
	m1.addWeapon("sword",1);
	m1.addPotion("Potion",2,"magicPower");
	m1.addArmor("Armor",3);
	m1.checkMarket();
	return 0;
}