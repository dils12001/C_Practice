#include <iostream>
#include <string>
using namespace std;
struct pizza
	{
		string name;
		double diameter;
		double weight;
	};
	
	
int main()
{
	pizza*  test = new pizza;
	cout << "Pizza's diameter: ";
	cin >> (*test).diameter;
	cout << "Pizza's Coroperation: ";
	cin >> (*test).name;
	cout << "Pizza's weight: ";
	cin >> (*test).weight;
	
	cout << "\nCoroperation: " << (*test).name 
		 << "\ndiameter:" << (*test).diameter 
		 << "\nweight: " << (*test).weight;
	
	delete test;
}