#include <iostream>

int main()
{	
	using namespace std;
	cout << "Enter something: \n";
	char ch;
	cin.get(ch);

	while(ch != '.')
	{
		if(ch == '\n')
			cout << ch;
		else
			cout << ch+1;
		cin.get(ch);
	}
	
	cout << "done";
}