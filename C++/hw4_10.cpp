#include <iostream>
#include <string>
#include <array>
#include <cstring>
using namespace std;
	
int main()
{
	cout << "Enter some dash three times\n";	
	array<string,3> a;
	array<int,3> b;
	
	cout << "first: ";
	cin >> a[0];
	b[0] = a[0].size();
	cout << "second: ";
	cin >> a[1];
	b[1] = a[1].size();
	cout << "third: ";
	cin >> a[2];
	b[2] = a[2].size();
	
	cout << "first,you type " << b[0] << " dashes\n"
		 << "second,you type " << b[1] << " dashes\n"
		 << "third,you type " << b[2] << " dashes\n"
		 << "the average of dash you type is " << (double(b[0])+double(b[1])+double(b[2]))/3;
}