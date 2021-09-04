#include <iostream>
//#include <string>
int main()
{	
	using namespace std;
	cout << "???";
	string a;
	cin >> a;
	
	cout << "What is your first name?";	
	string first = "\n";//先用cin再用getline(cin,str)時 要先打這兩行
	getline(cin,first);//先用cin再用getline(cin,str)時 要先打這兩行
	getline(cin,first);
	
	cout << "What is your last name?";
	char last[10];
	cin.get(last,10);
	cin.get();
	
	cout << "What letter grade do you deserve?";
	char grade[2];
	cin.get(grade,2);
	cin.get();
	
	cout << "What is your age?";
	int age;
	cin >> age;
	
	cout << "\nName: " << last << ", " << first
		 << "\nGrade: " << grade 
		 << "\nAge: " << age;
}