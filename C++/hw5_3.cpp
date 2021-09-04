#include <iostream>

int main()
{	
	using namespace std;
	int num;
	int sum = 0;
	
	cout << "Enter some number:";
	cin >> num;
	for (;num != 0;)
	{
		sum += num;
		cout << sum << endl
			 << "Enter some number again:";
		cin >> num;
	}
	cout << "Bye~";
}