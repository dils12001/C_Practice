#include <iostream>

using namespace std;
double add(double,double);
double calculate(double,double,double (*p1)(double,double));
double input();

int main()
{
	double (*pf[3])(double,double)={add,add,add};
	double x,y;
	for(int i = 0;i < 3;i++)
	{
		x = input();
		y = input();
		cout << calculate(x,y,pf[i]) << endl;
	}
}

double input()
{
	cout << "Enter number: ";
	double num;
	while(!(cin >> num))
		{	
			cin.clear();
			while(cin.get() != '\n')
				continue;
			cout << "Pussy!!!Enter a number: ";
		}
	return num;
}

double add(double x,double y)
{
	return x + y;
}

double calculate(double x,double y,double (*p1)(double,double))
{
	return p1(x,y);
}