#include <iostream>
#include <array>

int main()
{	
	using namespace std;
	array<long double,101> factorials;//0!~100!
	factorials[1] = factorials[0] = 1;
	for (int i = 2;i < 101;i++)
		factorials[i] = i*factorials[i-1];
	for (int i = 0;i < 101;i++)
		cout << i << "! = " << factorials[i] <<endl;
}