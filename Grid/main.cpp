#include "Grid.hpp"
#include <cstdio>

int main()
{
	Grid* g = new Grid;
	do {
		g->displayMap();
	} while (g->getmv() != 'q');

	return 0;
}