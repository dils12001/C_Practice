#include <iostream>
using namespace std;
double CelsiusConvert(double);

int main()
{
	cout << "Enter a Celsius value: ";
	double Celsius;
	cin >> Celsius;
	cout << Celsius << " degrees Celsius is " << CelsiusConvert(Celsius) << " degrees Fahrenheit.";
}

double CelsiusConvert(double Celsius)
{
	double F = Celsius*1.8+32;
	return F;
}