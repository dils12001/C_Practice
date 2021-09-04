#include <iostream>
#include <string>
using namespace std;
struct candybar
	{
		string name;
		double weight;
		int cal;
	};
	
	
int main()
{
	candybar* test = new candybar[3];
	test[0]={"Mocha Munch1",2.3,350};
	test[1]={"Mocha Munch2",3.3,450};
	test[2]={"Mocha Munch3",4.3,550};
	
	
	cout << test[0].name << test[0].weight << test[0].cal << endl;
	cout << test[1].name << test[1].weight << test[1].cal << endl;
	cout << test[2].name << test[2].weight << test[2].cal << endl;
}