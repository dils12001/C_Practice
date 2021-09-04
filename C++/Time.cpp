#include <iostream>
using namespace std;
void Time(int,int);

int main()
{
	cout << "Enter the number of hours: ";
	int hours;
	cin >> hours;
	cout << "Enter the number of minutes: ";
	int minutes;
	cin >> minutes;
	Time(hours,minutes);
}

void Time(int hours,int minutes)
{
	cout << "Time: " << hours << ":" << minutes;
}