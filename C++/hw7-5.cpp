#include <iostream>

int input();
long double cal(int);

using namespace std;

int main()
{
	while(1)
	{
		cout << "Enter a number (negetive to quit): ";
		long double result = cal(input());
		if(result == -1)
			break;
		cout << result << endl;
	}
	cout << "bye~";
}

int input()
{
	int number;
	while(!(cin >> number))
		{	
			cin.clear();
			while(cin.get() != '\n')
				continue;
			cout << "Pussy!!!Enter a number: ";
		}
	return number;
}

long double cal(int num)
{
	if(num < 0)
		return -1;
	if(num == 0)
		return 1;
	return num*cal(num-1);
}