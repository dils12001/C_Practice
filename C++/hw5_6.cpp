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
		cout << "第 " << year+1 << " 年 " << months[month] << ": ";
		cin >> sales[year][month];
		}
	
	cout << endl;
	int yearNum = 1;//cout 記錄第幾年
	for (auto &peryear:sales)
	{		
		int sum = 0;
		for (auto month:peryear)
			sum += month;
		cout << "第 " << yearNum << " 年的銷售量為: " << sum << " 本\n";
		yearNum++;
	}

}