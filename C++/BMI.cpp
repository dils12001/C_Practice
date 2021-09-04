#include <iostream>
int main()
{	
	using namespace std;
	
	const double footToInch = 12;//一英尺等於12吋
	const double InchToMeter = 0.0254;//一寸等於0.0254公尺
	const double PoundToKg = 2.2;//1磅除以2.2等於公斤
	double foot;
	double inch;
	double pound;
	
	cout << "Enter your foots:___\b\b\b";
	cin >> foot;
	cout << "Enter your inches:___\b\b\b";
	cin >> inch;
	cout << "Enter your pounds:___\b\b\b";
	cin >> pound;
	double BMI = (pound/PoundToKg)/((foot*footToInch+inch)*InchToMeter*(foot*footToInch+inch)*InchToMeter);
	cout << "Heh man!Your BMI is " << (pound/PoundToKg)/((foot*footToInch+inch)*InchToMeter*(foot*footToInch+inch)*InchToMeter) << endl << BMI;
}