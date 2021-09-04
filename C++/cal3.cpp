#include <iostream>
#include <typeinfo>
int main()
{	
	using namespace std;
	auto a = 8.25f/2.5;
	cout << a << endl;
	cout << typeid(a).name();
}