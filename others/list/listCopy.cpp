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

	//print the list numbers
	list<int>::iterator it;

	for(it=numbers.begin();it!=numbers.end();it++){
		cout<<*it<<endl;
		numbers1.push_back(*it); //copy the number from list numbers to list numbers1
	}

	//print the list numbers1
	cout<<endl;
	for(it=numbers1.begin();it!=numbers1.end();it++){
		cout<<*it<<endl;
	}

	return 0;
}