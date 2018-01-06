#include <iostream>
#include <list>
using namespace std;

int main(void){
	list<int> numbers;
	list<int> numbers1;
	int i;

	//fill the list numbers
	for(i=0;i<10;i++)
		numbers.push_back(i+1);
	
	list<int>::iterator it;

	it=numbers.begin();
	int counter=1;
	while(it!=numbers.end())
	{	counter++;
		it++;
		if(counter==3)
			break;
	}
	//now it points to the third integer from list numbers

	numbers1.push_back(*it); //push the integer to list numbers1

	//print the list numbers1
	for(it=numbers1.begin();it!=numbers1.end();it++){
		cout<<*it<<endl;
	}

	return 0;
}