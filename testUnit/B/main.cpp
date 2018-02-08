#include <iostream>
using namespace std;

#include "Market.hpp"
#include "Hero.hpp"

int main(){
	Market m1;
	Hero**H=new Hero*[2];
	H[0]=new Hero("Hero1",10,10,10);
	H[1]=new Hero("Hero2",10,10,10);
	m1.menuMarket(H,2);

	return 0;
}