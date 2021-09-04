#include <iostream>

int Fill_array(double*,int);
void Show_array(double*,int);
void Reverse_array(double*,int);

using namespace std;

int main()
{
	double myArr[10];
	int realSize = Fill_array(myArr,10);
	Show_array(myArr,realSize);
	Reverse_array(myArr,realSize);
	Show_array(myArr,realSize);
	Reverse_array(myArr+1,realSize-2);
	Show_array(myArr,realSize);
}

int Fill_array(double* arr,int size)
{
	double temp = 0;
	int count = 0;
	cout << "Enter a number (char to quit): ";
	while(cin >> temp and size > 0)
	{
		*arr = temp;
		cout << *arr << endl;
		arr++,size--,count++;
		if(size == 0)
			break;
		cout << "Enter a number (char to quit): ";
	}
	return count;
}

void Show_array(double* arr,int size)
{
	cout << "Here is your array\n";
	while(size--)
	{
		cout << *arr << endl;
		arr++;
	}	
}

void Reverse_array(double* arr,int size)
{
	int maxIndex = size - 1;
	int mid = maxIndex/2;
	double temp;
	for(int i = maxIndex;i > mid;i--)
	{
		temp = arr[i];
		arr[i] = arr[maxIndex-i];
		arr[maxIndex-i] = temp;
	}
}