#include <iostream>

int main()
{	
	using namespace std;
	cout << "Enter words (q to quit):\n";
	string word;
	int vowels = 0;
	int consonants = 0;//不知為啥排第二的一定要初始化 不然預設=10
	int others = 0;

	while(cin >> word and word != "q")
	{
		if(isalpha(word[0]))
		{
			switch(tolower(word[0]))
			{
				case 'a': vowels++;break;
				case 'e': vowels++;break;
				case 'i': vowels++;break;
				case 'o': vowels++;break;
				case 'u': vowels++;break;
				default : consonants++;
			}
		}
		else
			others++;		
	}
	cout << vowels << " words beginning with vowels\n"
		 << consonants << " words beginning with consonants\n"
		 << others << " others";
}