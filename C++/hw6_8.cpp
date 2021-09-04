#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{	
	using namespace std;
	ifstream myfile;
	cout << "Enter a fileName: ";
	string fileName;
	cin >> fileName;
	myfile.open(fileName);
	if(!myfile.is_open())
	{
		cout << "could not open the file " << fileName << endl
			 << "program terminating!!!";
		exit(EXIT_FAILURE);
	}
	
	int count = 0;
	char ch;
	myfile >> ch;
	while(myfile.good())
	{
		++count;
		myfile >> ch;
	}
	
	if(myfile.eof())
		cout << "End of file reached\n";
	else if(myfile.fail())
		cout << "Input terminated by data mismatch\n";
	else
		cout << "Input terminated for unknown reason\n";
	
	if(count == 0)
		cout << "No data processed\n";
	else
		cout << "Char read: " << count;
	
	myfile.close();	
}