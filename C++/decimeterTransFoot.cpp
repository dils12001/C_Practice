#include <iostream>
int main()
{	
	using namespace std;
	const int footToInch = 12;//一英尺等於12吋
	auto a = 8.25f/2.5;
	int height;
	cout << "type your height in (int)Inch:___\b\b\b";//吋轉為尺和寸
	cin >> height;
	cout << "You are " << height/footToInch << " foots and " << height%footToInch << " inches tall";
}