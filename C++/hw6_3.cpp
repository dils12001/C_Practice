#include <iostream>

int main()
{	
	using namespace std;
	cout << "Enter one of the following choices\n"
		 << "(c)\t(p)\t(t)\t(g)\n";
	char ch;
	while(cin >> ch and ch != '@')
	{
		switch(ch)
		{
			case 'c':	cout << "U enter \'c\'\nEnter again: ";
						break;
			case 'p':	cout << "U enter \'p\'\nEnter again: ";
						break;
			case 't':	cout << "U enter \'t\'\nEnter again: ";
						break;
			case 'g':	cout << "U enter \'g\'\nEnter again: ";
						break;
			default :	cout << "fuck U!!!\nEnter again: ";
						continue;
		}
	}
}