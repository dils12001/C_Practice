#include <iostream>
void Three(void);
void See(void);
using namespace std;

int main()
{
	Three();
	Three();
	See();
	See();
}

void Three()
{	
	cout << "Three blind mice" << endl;
}

void See()
{
	cout << "See how they run" << endl;
}