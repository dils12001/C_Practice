#include <iostream>

int main()
{	
	using namespace std;
	cout << "Enter your earning: ";
	double earning;
	while(cin >> earning and earning >= 0)
	{
		double pay;
		if(earning > 35000)
			cout << "U have to pay $" << 4000+(earning-35000)*0.2;
		else if(earning > 15000)
			cout << "U have to pay $" << 1000+(earning-15000)*0.15;
		else if(earning > 5000)
			cout << "U have to pay $" << (earning-5000)*0.1;
		else
			cout << "U are too pool to pay =.=";
		
		cout << "\nEnter your earning: ";
	}
}