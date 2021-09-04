#include <iostream>
#include <cctype>

int main()
{	
	using namespace std;
	double number[10];
	int i;//記錄已寫入多少數字進陣列
	cout << "Enter a double: ";
	double num;
	double sum;

	while(i < 10 and cin >> num)
	{
		number[i] = num;
		sum += num;
		i++;
	}
	
	double avg = sum/i;
	int count;
	for (int j = 0;j < i;j++)
	{
		if(number[j] > avg)
			count++;
	}
	
	cout << "avg: " << avg << endl
		 << "total of bigger than avg: " << count;
}