#include <iostream>
	
double function(double,double);
double input();

using namespace std;

int main()
{	

	double x,y;
	cout << "Enter two numbers,and we'll calculate them\n";
	
	while(1)
	{
		cout << "x: ";
		x = input();
		cout << "y: ";
		y = input();
		if(x == 0 or y == 0)
			break;
		cout << function(x,y) << endl;
	}
	cout << "Bye~";
}

double function(double x,double y)
{
	return 2*x*y/(x+y);
}

double input()
{	
	double x;
	while(!(cin >> x))
			{	
				cin.clear();
				while(cin.get() != '\n')
					continue;
				cout << "Pussy!!!Enter a number: ";
			}
	return x;
}