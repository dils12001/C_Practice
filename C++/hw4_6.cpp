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
	candybar candyArray[]=
	{
		{"Mocha Munch1",2.3,350},
		{"Mocha Munch2",3.3,450},
		{"Mocha Munch3",4.3,550}
	};
	
	cout << candyArray[0].name << candyArray[0].weight << candyArray[0].cal << endl;
	cout << candyArray[1].name << candyArray[1].weight << candyArray[1].cal << endl;
	cout << candyArray[2].name << candyArray[2].weight << candyArray[2].cal << endl;
}