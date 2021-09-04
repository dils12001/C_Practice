#include <iostream>
int main()
{	
	using namespace std;
	
	const double sec_min = 60;
	const double min_degree = 60;
	double degree;
	double minute;
	double second;
	
	cout << "Enter a latitude in degrees,minutes,and seconds:\n"
		 << "First,enter the degrees: ";
	cin >> degree;
	cout << "Next,enter the minutes of arc: ";
	cin >> minute;
	cout << "Finally,enter the seconds of arc: ";
	cin >> second;
	
	cout << degree << " degrees, " 
		 << minute << " minutes, " 
		 << second << " seconds = " 
		 << (second/sec_min+minute)/min_degree+degree 
		 << " degrees";
}