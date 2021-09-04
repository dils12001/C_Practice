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
	int c[Y];   // 一條陣列就夠了
	
	// [Initial]
	for (int j=0; j<Y; ++j) c[j] = 1;
 
	// [Compute]
	for (int i=1; i<X; i++)
		for (int j=1; j<Y; j++)
			c[j] += c[j-1];
 
	// 輸出結果
	cout << "由(0,0)走到(7,3)有" << c[3] << "種走法";
	//  cout << "由(0,0)走到(7,7)有" << c[Y-1] << 種走法;
}