#include <iostream>
#include <cstring>
int main()
{
	using namespace std;
	cout << "Enter your first name?";
	char first[10];
	cin >> first;
	cout << "Enter your last name?";
	char last[10];
	cin >> last;
	
	char name[20];
	strcpy(name,last);
	strcat(name,", ");
	strcat(name,first);	
	cout << "Hey! " << name;
}