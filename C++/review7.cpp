#include <iostream>

struct applicant
{
	char name[30];
	int credit_ratings[3];
};

void fillarray1(int*,int,int);
void fillarray2(int*,int*,int);
double maxInArray(const double*,double*);
int replace(char* str,char c1,char c2);
void showApplicant1(applicant);
void showApplicant2(applicant*);
void f1(applicant* a);
const char* f2(const applicant* a1,const applicant a2);
typedef const char* (**type_pa2)(const applicant* a1,const applicant a2);
typedef const char* (*p_p2)(const applicant* a1,const applicant a2);

using namespace std;

int main()
{	

	//double a[5] = {1,2,60,3,4};
	//fillarray2(a,a+5,7);
	//for(int i = 0;i < 5;i++)
		//cout << a[i] << endl;
	//cout << maxInArray(a,a+5);
	
	//char str1[] = "aaabbbp";
	//int count = replace(str1,'b','g');
	//cout << str1 << endl << count;
	
	//applicant a = {"Dennis",{1,2,3}};
	//showApplicant1(a);
	//showApplicant2(&a);
	
	void (*p1)(applicant* a) = f1;
	const char* (*p2)(const applicant* a1,const applicant a2) = f2;
	void (*ap1[5])(applicant* a) = {f1,f1,f1,f1,f1}; //ap是一陣列 內含5個 p1同型態的指標
	//39行(p1)直接改成(ap[5])
	const char* (*ap2[10])(const applicant* a1,const applicant a2) = {f2,f2,f2,f2,f2,f2,f2,f2,f2,f2};
	const char* (**pa2)(const applicant* a1,const applicant a2) = ap2;
	p_p2 p2_2 = f2;
	type_pa2 a = ap2;
	p_p2 a2[10] = {f2,f2,f2,f2,f2,f2,f2,f2,f2,f2};
	p_p2 (*pa2_2) = ap2;
	
	
}

void fillarray1(int* array,int size,int fillvalue)
{
	for(int i = 0;i < size;i++)
		array[i] = fillvalue;
}

void fillarray2(int* begin,int* end,int fillvalue)
{	
	int* pt = begin; 
	for(;pt != end;pt++)
		*pt = fillvalue;
}

double maxInArray(const double* begin,double* end)
{	
	const double* pt = begin;
	double max;
	for(;pt != end;pt++)
		if(*pt > max)
			max = *pt;
	return max;
}

int replace(char* str,char c1,char c2)
{
	int count = 0;
	while(*str)
	{
		if(*str == c1)
		{
			*str = c2;
			count++;
		}
		str++;
	}
	return count;
}

void showApplicant1(applicant* a)
{
	cout << (*a).name
		 << endl << (*a).credit_ratings[0]
		 << endl << a->credit_ratings[1]
 		 << endl << (*a).credit_ratings[2];
}

void showApplicant2(applicant* a)
{
	cout << a->name
		 << endl << a->credit_ratings[0]
		 << endl << (*a).credit_ratings[1]
 		 << endl << a->credit_ratings[2];
}

void f1(applicant* a)
{
	cout << "hi";
}
const char* f2(const applicant* a1,const applicant a2)
{
	return "hello";
}
