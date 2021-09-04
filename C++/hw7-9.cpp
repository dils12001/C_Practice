#include<iostream>
#include <cstring>

using namespace std;
const int SLEN = 30;
struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;	
};

int getinfo(student pa[],int n);
void display1(student st);
void display2(const student* ps);
void display3(const student pa[],int n);

int main()
{
	cout << "Enter class size: ";
	int class_size;
	while(!(cin >> class_size)) //使用者輸入student陣列大小,並防止輸入字元
	{
		cin.clear();
		while(cin.get() != '\n')
			continue;
		cout << "Enter a number: ";
	}
	while(cin.get() != '\n') //因為後面還需要使用者輸入,清掉換行字元
			continue;
	
	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu,class_size);
	for(int i = 0;i < entered;i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu,entered);
	delete [] ptr_stu;
	cout << "done\n";
}

int getinfo(student pa[],int n)
{
	int entered = 0;
	for(int i = 0;i < n;i++)
	{
		cout << "Name (blank to quit): "; 
		cin.getline(pa[i].fullname,SLEN);//不考慮超陣列
		int nameSize =  sizeof(pa[i].fullname);
		if(strlen(pa[i].fullname) == 0)
			return entered;
		for(int j = 0;j < nameSize;j++) \\有Bug 可以都是空白建
		{
			cout << j << "*" << nameSize-1 << "*" << (pa[i].fullname)[j] << "*";
			if((pa[i].fullname)[j] != ' ' and (pa[i].fullname)[j] != '\0')
				break;
			if(j == nameSize-1)
				return entered;
		}
		cout << (pa[i].fullname);
		cout << "Hobby: ";
		cin.getline(pa[i].hobby,SLEN);
		cout << "ooplevel: ";
		while(!(cin >> pa[i].ooplevel))
		{
			cin.clear();
			while(cin.get() != '\n')
				continue;
			cout << "Enter a number: ";
		}
		while(cin.get() != '\n') //因為後面還需要使用者輸入(cin接cin.getline),清掉換行字元
			continue;
		entered++;
	}
	return entered;
}



void display1(student st)
{
	cout << "fullname: " << st.fullname << endl
		 << "hobby: " << st.hobby << endl
		 << "ooplevel: " << st.ooplevel << endl;
}

void display2(const student* ps)
{
	cout << "fullname: " << ps->fullname << endl
		 << "hobby: " << ps->hobby << endl
		 << "ooplevel: " << ps->ooplevel << endl;
}

void display3(const student pa[],int n)
{
	for(int i = 0;i < n;i++)
	{
		display1(pa[i]);
	}
}


