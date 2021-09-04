#include <iostream>

using namespace std;
int input(double*,double*);
void show(const double*,int);
double gradeAvg(double*,int);

int main()
{
	double grade[10];
	int realSize = input(grade,grade+10);
	show(grade,realSize);
	cout << "Your average grade is " << gradeAvg(grade,realSize);
}

int input(double* begin,double* end)
{
	double* pt = begin;
	int size = 0;
	for(;pt != end;pt++)
	{
		cout << "Enter your grade: ";
		while(!(cin >> *pt))
			{	
				cin.clear();
				while(cin.get() != '\n')
					continue;
				cout << "Pussy!!!Enter a number: ";
			}
		if(*pt < 0)
			break;
		size++;
	}
	return size;
}

void show(const double* array,int size)
{	
	cout << "Here are your inputs:\n";
	for(int i = 0;i < size;i++)
		cout << array[i] << "\t\n";
}

double gradeAvg(double* array,int size)
{
	double sum = 0;
	for(int i = 0;i < size;i++)
		sum += array[i];
	return sum/size;
}