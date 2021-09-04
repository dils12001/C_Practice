#include <iostream>
//#include <string>
int main()
{
	using namespace std;
	cout << "Enter your first name?";
	string first;
	cin >> first;
	cout << "Enter your last name?";
	string last;
	cin >> last;
	
	string name;
	name = last + ", " + first;
	cout << "Hey! " << name << name.size();
}