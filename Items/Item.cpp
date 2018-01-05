#include "Item.hpp"
#include <ctime>

/*Constructor*/
Item::Item(string Name,int MinLevel)
	:name(Name),minLevel(MinLevel){

	switch(MinLevel){

		case 1:value=rand()%(10-5+1)+5;
			   break;
		case 2:value=rand()%(20-10+1)+10;
			   break;
		case 3:value=rand()%(30-20+1)+20;
			   break;
		case 4:value=rand()%(40-30+1)+30;
			   break;
		case 5:value=rand()%(50-40+1)+40;
			   break;
		case 6:value=rand()%(60-50+1)+50;
			   break;
		case 7:value=rand()%(70-60+1)+60;
			   break;
		case 8:value=rand()%(80-70+1)+70;
			   break;
		case 9:value=rand()%(90-80+1)+80;
			   break;
		case 10:value=rand()%(100-90+1)+90;
			   break;
	}	


}