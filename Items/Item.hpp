#ifndef ITEM
#define ITEM

class Item{
	protected:
		string name;
		int value;
		int minLevel;

	public:
		/*Constructor*/
		Item(string Name,int Value,int MinLevel);

};
#endif