#include <iostream>

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};


void show(box);
void calVolume(box*);

using namespace std;

int main()
{
	box test = {"Dennis",10,20,30,0};
	cout << "Here is a box information:\n";
	show(test);
	calVolume(&test);
	cout << "\nNow box's information:\n";
	show(test);
	
}

void show(box a)
{
	cout << "Box's maker: " << a.maker
		 << "\nBox's maker: " << a.height
		 << "\nBox's maker: " << a.width
		 << "\nBox's maker: " << a.length
		 << "\nBox's maker: " << a.volume;
}

void calVolume(box* a)
{
	a->volume = (*a).height*a->width*a->length;
}