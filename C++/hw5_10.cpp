#include <iostream>

int main()
{	
	using namespace std;
	cout << "Enter number of rows: ";
	int num;
	cin >> num;
	
	for(int row = 1;row <= num;row++)
	{
		for(int col = 1;col <= num;col++)
		{
			if(col == num)
				cout << "*\n";
			else if(col > (num-row))
				cout << "*";
			else
				cout << ".";		
		}		
	}
	
	cout << "\n\n\n";	
	for(int i = 0;i < num;i++)
	{	
		int j = 0;
		for(;j < (num-i-1);j++)
			cout << ".";	
		for(;j < num;j++)
			cout << "*";
		cout << "\n";
	}
}