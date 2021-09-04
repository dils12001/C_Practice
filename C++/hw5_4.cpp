#include <iostream>

int main()
{	
	using namespace std;
	double daphne = 100;
	double cleo = 100;
	int year = 1;
	daphne += 10;
	cleo *= 1.05;
	
	for (;daphne > cleo;year++)
	{
		daphne += 10;
		cleo *= 1.05;
	}
	cout << "After " << year << " years," << "Cleo's money will bigger than Daphne." << endl
		 << "Cleo has " << cleo << endl
		 << "Daphne has " << daphne << endl;
}