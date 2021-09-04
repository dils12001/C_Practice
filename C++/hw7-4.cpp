#include <iostream>

double input();
long double probability(unsigned,unsigned,unsigned);

using namespace std;

int main()
{
	double total = 0;
	double choice = 0;
	double total2 = 0;
	
	do
	{
		cout << "Enter total number: ";
		total = input();
		if(total <= 0)
			break;
		cout << "Enter the number of picks allowed: ";
		choice = input();
		if(choice <= 0)
			break;
		if(total < choice)
			continue;
		cout << "Enter total2 number: ";
		total2 = input();
		if(total2 <= 0)
			break;
		cout << "You have one choice in "
			 << probability(total,choice,total2)
			 << "of winning.\n"
			 << "Next round (number <= 0 to quit)\n";
	}while(1);
	cout << "bye~";
}

double input()
{
	double number;
	while(!(cin >> number))
		{	
			cin.clear();
			while(cin.get() != '\n')
				continue;
			cout << "Pussy!!!Enter a number: ";
		}
	return number;
}

long double probability(unsigned total,unsigned choice,unsigned total2)
{
	long double result = 1;
	for(;choice > 0;total--,choice--)
		result = result*total/choice;
	return result*total2;
}