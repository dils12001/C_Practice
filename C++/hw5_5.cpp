#include <iostream>

int main()
{	
	using namespace std;
	int sales[12];
	const char* months[12]{"Jan","Feb","Mar","Apr","May","June","July","Aug","Sept","Oct","Nov","Dec"};
	
	cout << "Enter how many books we sale per month last year.\n";
	for (int i = 0;i < 12;i++)
	{
		cout << months[i] << ": ";
		cin >> sales[i];
	}
	int sum = 0;
	for (int i:sales)
		sum += i;
	cout << "Total books we sales last year are " << sum;
	
}