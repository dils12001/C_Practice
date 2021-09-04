#include <iostream>

struct car
	{
		int produtionTime;
		char deviceVendor[15];	
	};
	
int main()
{	
	using namespace std;
	cout << "How many cars U want to catelog: ";
	int cars;
	cin >> cars;
	
	car* manyCars = new car[cars];
	for (int i = 0;i < cars;i++)
	{
		cout << "Car #" << i+1 << ":\n"
			 << "Please enter the make: ";
		cin.get();
		cin.getline(manyCars[i].deviceVendor,15);
		
		cout << "Please enter the year made: ";
		int proYear;
		cin >> proYear;
		manyCars[i].produtionTime = proYear;		
	}
	
	cout << "Hear is your collection:\n";
	for (int i = 0;i < cars;i++)
	{
		cout << manyCars[i].produtionTime << "\t"
			 << manyCars[i].deviceVendor << endl;
	}
	
	delete [] manyCars;
}