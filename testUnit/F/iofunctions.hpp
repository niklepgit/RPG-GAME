#ifndef IOFUNCTIONS
#define IOFUNCTIONS

#include <string>
#include <fstream>

void readWeapon(int& stop,fstream& weapons_txt,string& Name,int& MinLevel);
void readArmor(int& stop,fstream& armors_txt,string& Name,int& MinLevel);
void readPotion(int& stop,fstream& potions_txt,string& Name,int& MinLevel,string& WtIncrease);
void readSpell(int& stop,fstream& spells_txt,string& Name,int& MinLevel);

#endif