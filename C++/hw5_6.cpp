#include <iostream>

int main()
{	
	using namespace std;
	int sales[3][12];
	const char* months[12]{"Jan","Feb","Mar","Apr","May","June","July","Aug","Sept","Oct","Nov","Dec"};
	
	cout << "Enter how many books we sale per month in last three years.\n";
	
	for (int year = 0;year < 3;year++)
		for (int month = 0;month < 12;month++)
		{
		cout << "�� " << year+1 << " �~ " << months[month] << ": ";
		cin >> sales[year][month];
		}
	
	cout << endl;
	int yearNum = 1;//cout �O���ĴX�~
	for (auto &peryear:sales)
	{		
		int sum = 0;
		for (auto month:peryear)
			sum += month;
		cout << "�� " << yearNum << " �~���P��q��: " << sum << " ��\n";
		yearNum++;
	}

}