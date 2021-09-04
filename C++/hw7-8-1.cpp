#include <iostream>

const int Seasons = 4;
const char Snames[4][7] = {"Spring","Summer","Fall","Winter"};

void fill(double*);
void show(double*);

using namespace std;

int main()
{
	double expenses[Seasons];
	fill(expenses);
	show(expenses);
	
}

void fill(double* expenses)
{
	for(int i = 0;i < Seasons;i++)
	{
		cout << "Enter " << Snames[i] << " expense: ";
		
		while(!(cin >> expenses[i]))
		{
			cin.clear();
			while(cin.get() != '\n')
				continue;
			cout << "Enter a number: ";
		}
	}
}

void show(double* expenses)
{
	double total = 0;
	cout << "\nEXPENSES\n";
	for(int i = 0;i < Seasons;i++)
	{
		cout << Snames[i] << ": $" << expenses[i] << endl;
		total += expenses[i];
	}
	cout << "Total Expenses: $" << total << endl;
}