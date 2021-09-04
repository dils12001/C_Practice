#include <iostream>
int main()
{	
	using namespace std;
	double x1 = 12.3;
	double x2 = 45.8;
	
	int a = int(x1)+int(x2);
	int b = x1+x2;
	int c = double(x1) + double(x2);
	
	cout << a << endl
		 << b << endl
		 << c << endl;
}