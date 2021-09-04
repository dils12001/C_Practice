#include <iostream>
//#include <string>

using namespace std;
struct donator
{
	string name;
	double money;
};

int main()
{	
	
	cout << "Enter the number of donation people: ";
	int numPeople;
	while(!(cin >> numPeople))
			{	
				cin.clear();
				while(cin.get() != '\n')
					continue;
				cout << "Pussy!!!Enter a number: ";
			}
	
	if(numPeople > 0)
	{
		donator* Patrons = new donator[numPeople];
	
		double tempMoney;
		for(int i;i < numPeople;i++)
		{	
			cout << "Enter his name: ";
			getline(cin,Patrons[i].name);
			getline(cin,Patrons[i].name);
			cout << "Enter the money he donate: ";
			while(!(cin >> tempMoney))
			{	
				cin.clear();
				while(cin.get() != '\n')
					continue;
				cout << "Pussy!!!Enter a number: ";
			}
			Patrons[i].money = tempMoney;
		}
		

		cout << "\n\nGrand Patrons\n--------------------\n";
		for(int i=0;i < numPeople;i++)
		{
			
			if(Patrons[i].money > 10000)
				cout << Patrons[i].name << "\t";
		}

		cout << "\n\nPatrons\n--------------------\n";
		for(int i=0;i < numPeople;i++)
		{
			
			if(Patrons[i].money <= 10000)
				cout << Patrons[i].name << "\t";
		}
		delete [] Patrons;
	}
	else
		cout << "none";
}