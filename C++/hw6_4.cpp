#include <iostream>

struct bop{
	char fullname[20];
	char title[20];
	char bopname[20];
	int preference;
};

int main()
{	
	using namespace std;
	cout << "(a)Display by fullname\t" << "(b)Display by title\n"
		 << "(c)Display by bopname\t" << "(d)Display by preference\n"
		 << "(q)quit\n";
	bop  me = {"dennis","professor","ghost",2};
	char ch;
	while(cin >> ch and ch != 'q')
	{
		switch(ch)
		{
			case 'a':	cout << "Hi Mr. " << me.fullname << endl;	break;
			case 'b':	cout << "Hi Mr. " << me.title << endl;	break;
			case 'c':	cout << "Hi Mr. " << me.bopname << endl;	break;
			case 'd':	switch(me.preference)
						{
							case 0 :cout << "Hi Mr. " << me.fullname << endl;	continue;
							case 1 :cout << "Hi Mr. " << me.title << endl;	continue;
							case 2 :cout << "Hi Mr. " << me.bopname << endl;	continue;
						}					
			default :	cout << "fuck U!!!\nEnter again: ";	continue;
		}
	}
}