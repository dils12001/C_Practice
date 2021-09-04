#include <iostream>

int main()
{	
	using namespace std;
	cout << "Enter something: ";
	int choice;
	cin >> choice;
	cout << choice << endl;
	cin.clear(); //important
	char choice1;
	cin >> choice1;
	cout << choice1 << endl;	
	while(true)
	{		
		int choice2;
		cin >> choice2;
		cout << choice2 << endl;
		cout << "------------";
	}
	/*while (choice != 5)
	{
		switch(choice)
		{
			case 1 : cout << 1 << endl;
					 break;
			case 2 : cout << 2 << endl;
					 break;
			case 3 : cout << 3 << endl;
					 break;
			case 4 : cout << 4 << endl;
					 break;
			default : cout << "defalt" << endl;
		}
		cout << "Enter something: ";
		cout << choice;
		cin >> choice;
	}*/
	cout << "Bye!";	
}