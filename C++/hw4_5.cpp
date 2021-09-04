#include <iostream>
//#include <string>
int main()
{
	using namespace std;
	struct candybar
	{
		string name;
		double weight;
		int cal;
	};
	
	candybar snack =
	{
		"Mocha Munch",
		2.3,
		350
	};
	
	cout << snack.name << snack.weight << snack.cal;
}