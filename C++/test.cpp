#include <iostream>
int main()
{	
	using namespace std;
	cout << "Enter something:";
	int limit;
	cin >> limit;
	int i = 2;
	int b = 5;
	cout << i << endl;
	for (i=limit;b;i++)
	{
		cout << "i = " << i << endl;
		cout << "b = " << b << endl;
	}
	cout << "done, i = " << i;
}