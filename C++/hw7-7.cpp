#include <iostream>

double* Fill_array(double*,double*);
void Show_array(double*,double*);
void revalue(double* arr,double* end,int n);

using namespace std;

int main()
{
	double myArr[10];
	double* realEnd = Fill_array(myArr,myArr+10);
	while(realEnd == myArr)
		realEnd = Fill_array(myArr,myArr+10);
	Show_array(myArr,realEnd);
	
	cout << "Enter revaluation factor: ";
	double factor;
	while(!(cin >> factor))
	{
		cin.clear();
		while(cin.get() != '\n')
			continue;
		cout << "Enter a number: ";
	}
	revalue(myArr,realEnd,factor);
	Show_array(myArr,realEnd);

}

double* Fill_array(double* arr,double* end)
{
	double temp = 0;
	int count = 0;
	cout << "Enter value #" << ++count <<" (char to quit): ";
	while(cin >> temp)
	{
		*arr = temp;
		arr++;
		if(arr == end)
			break;
		cout << "Enter value #" << ++count <<" (char to quit): ";
	}
	return arr;
}

void Show_array(double* arr,double* end)
{
	cout << "Here is your array\n";
	while(arr != end)
	{
		cout << *arr << endl;
		arr++;
	}	
}

void revalue(double* arr,double* end,int n)
{
	while(arr != end)
	{
		*arr = (*arr)*n;
		arr++;
	}	
}