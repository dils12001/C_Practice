#include <iostream>
using namespace std;

int main()
{
	cout << "Enter a char: " << endl;
	char ch;
	cin >> ch;
	int num;
	num = ch;
	cout << "You gave a " << ch << endl
		 << "and its number is " << num;
}