#include <iostream>

struct expenses
{
	double a[5];
};

const int Seasons = 4;
const char Snames[4][7] = {"Spring","Summer","Fall","Winter"};

void fill(expenses*);
void show(expenses);

using namespace std;

int main()
{
	expenses temp;
	fill(&temp);
	show(temp);
	
}

void fill(expenses* temp)
{
	for(int i = 0;i < Seasons;i++)
	{
		cout << "Enter " << Snames[i] << " expense: ";
		
		while(!(cin >> (*temp).a[i]))
		{
			cin.clear();
			while(cin.get() != '\n')
				continue;
			cout << "Enter a number: ";
		}
		cout << (*temp).a[i];
	}
}

void show(expenses temp)
{
	double total = 0;
	cout << "\nEXPENSES\n";
	for(int i = 0;i < Seasons;i++)
	{
		cout << Snames[i] << ": $" << (temp.a)[i] << endl;
		total += (temp.a)[i];
	}
	cout << "Total Expenses: $" << total << endl;
}