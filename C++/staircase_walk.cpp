#include <iostream>

void staircase_walk();

using namespace std;

int main()
{
	staircase_walk();

}

void staircase_walk()
{
	const int X = 8, Y = 4;
	int c[Y];   // �@���}�C�N���F
	
	// [Initial]
	for (int j=0; j<Y; ++j) c[j] = 1;
 
	// [Compute]
	for (int i=1; i<X; i++)
		for (int j=1; j<Y; j++)
			c[j] += c[j-1];
 
	// ��X���G
	cout << "��(0,0)����(7,3)��" << c[3] << "�ب��k";
	//  cout << "��(0,0)����(7,7)��" << c[Y-1] << �ب��k;
}