#include <iostream>
#include <cstring>

int main()
{	
	using namespace std;
	cout << "Enter words (to stop, type word \"done\"): \n";
	char word[12];//注意輸入的字別溢出
	cin >> word;
	int count;
	
	for (;strcmp(word,"done");)
	{	
		count++;
		cin >> word;
	}
	
	cout << "U entered a total of " << count << " words.";
}