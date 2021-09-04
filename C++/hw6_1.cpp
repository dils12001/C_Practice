#include <iostream>
#include <cctype>

int main()
{	
	using namespace std;
	cout << "Enter something: \n";
	char ch;
	cin >> ch;

	while(ch != '@')
	{
		if(islower(ch))
		{
			ch = toupper(ch);
			cout << ch << endl;
		}
			
		else if(isupper(ch))
		{
			ch = tolower(ch);
			cout << ch << endl;
		}
		else
			cout << ch << endl;
		cout << "Enter something: \n";
		cin >> ch;
	}
	
	cout << "done";
}