#include <iostream>
int main()
{	
	using namespace std;
	int small;
	int big;
	cout << "Enter two number:";
	cin >> small;
	cin >> big;
	int sum =0;
	
	for (;small <= big;small++)
	{
	cout << small << "\t";
	sum += small;
	}
	cout << endl << sum;
}