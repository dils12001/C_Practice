#include <iostream>
#include <string>

int main()
{	
	using namespace std;
	cout << "Enter words (to stop, type word \"done\"): \n";
	string word;
	cin >> word;
	int count;
	
	for (;word != "done";)
	{	
		count++;
		cin >> word;
	}
	
	cout << "U entered a total of " << count << " words.";
}