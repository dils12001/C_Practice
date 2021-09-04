#include <iostream>
using namespace std;
double DistanceConvert(double);

int main()
{
	cout << "Enter the number of light years: ";
	double LightYears;
	cin >> LightYears;
	cout << LightYears << " light years = " << DistanceConvert(LightYears) << " astronomical units.";
}

double DistanceConvert(double LightYears)
{
	double AU = LightYears*63240;
	return AU;
}